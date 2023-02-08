    /*H**********************************************************************
* AUTHOR :   Razie Hyria        START DATE :    FEB 7th 2023
* FILENAME :        LoopThruTime           
* COURSE NAME:      CMPSC 472 Section 001: Operating Systems
* SEMESTER:         SPRING 2023
*
* DESCRIPTION :
*       A C programming lab on Learning how to Output data all over the Console Window.
        Will be used to display a clock, adjust speed, and exit program.
*
* NOTES :
*       These functions feature C Arithmetic Operators
*       Copyright PSU Abington
* 
*FUNCTIONS USED: // _getoxy()   _kbhit()   _getch()_sleep()
*
*H*************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>

#define R 114 //instead of f5 i used r, to restart clock
#define ESC 27
#define INC 43
#define DEC 45

//declaring variables
int sleep = 100;
int hour = 0;
int minute = 0;
int second = 0;
bool isRunning = true;

int main()
{
	int c1, c2; //will be used for displaying information about keys pressed

   // printing menu opetions to the user
	_gotoxy(20,15);
    printf("\nWelcome! Please select one of the options below, or wait for the clock to reach 23:59:59");
    printf("\n\n\n'+': Increase sleep timecloc");
    printf("\n'-': Decrease sleep time");
    printf("\n'r': restart clock to 0:0:0");
    printf("\n'esc': Exit program");

	while(isRunning) // automatically enters the main program loop
	{
		_gotoxy(15,15);
		printf("\n\nHit any key to sart the clock!");

		while(_kbhit()) // waits for user to press a key before heading into loop
		{
			c1 = _getch();
		/* using a switch statement implementation instead of 'if' statements, to adjust the status of the clock/program
			REF:
			https://www.w3schools.com/c/c_switch.php */
			switch(c1)
			{
				case ESC: // base case ; exit the loop/program
					isRunning = false;

				case INC: // increasing sleep time w respect to the limit
					if(sleep < 2000)
					{
						sleep += 100;
					}
					break; // i know you hate these, but bear with me

				case DEC: // decreasing sleep time w respect to limit
					if(sleep > 100)
					{
						sleep -= 100;
					}
					break;

				case R: // restarting the clock
					hour = 0;
					minute = 0;
					second = 0;

				default: // else an invalid keystroke was detected
					_gotoxy(50,1); //move cursor position
					if(c1==0)
					{
						c2 = _getch();
					}
					_gotoxy (35, 2); // go to lines below the counter
		            printf("Invalid keystroke:");
		            printf(" [%d : %c] [%d : %c]", c1, c1,c2,c2);
					break;
			}
		}
		second++; 
		_gotoxy(20,3); // move cursor position
		printf(" [ %d : %d : %d ] \n", hour, minute, second);
		Sleep(sleep); //telling the program to sleep
		
		
		while (second == 60) // incrementing the clock
        {
            second = 0;
            minute++;

            while (minute == 60)
            {
                minute = 0;
                hour++;

                while (hour == 23)
                {
                    if(minute==59 && second==59) // second exit condition for the program
					{
						isRunning = false;
					}
                }
            }
        }

	}
	_gotoxy(30,25);
	printf("Program will exit now!");
	return 0;
}

    
