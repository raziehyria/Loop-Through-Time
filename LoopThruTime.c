/*H**********************************************************************
* AUTHOR :   Razie Hyria        START DATE :    FEB 7th 2023
* FILENAME :        LoopThruTime           
* COURSE NAME:      CMPSC 472 Section 001: Operating Systems
* SEMESTER:         SPRING 2023
*
* DESCRIPTION :
*       A C programming lab on Learning how to Output data all over the Console Window.
        Will be used to display a clock, adjust speed,
*
* NOTES :
*       These functions feature C Arithmetic Operators
*       Copyright PSU Abington
*H*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include<sys/wait.h>
#include <unistd.h>

const int sleep;
const int hour = 0;
const int minute = 0;
const int second = 0;

int main()
{
    int cntr = 0;
    int c1, c2;
    
    // printing menu opetions to the user
    printf("Welcome! Please select one of the options below, or wait for the clock to reach 23:59:59");
    printf("\n'+': Increase sleep timecloc");
    printf("'-': Decrease sleep time");
    printf("'f5': restart clock to 0:0:0");
    printf("'esc': Exit program");
    
    while(c1 != 27) // as long as esc hasnt been hit
    {
        cntr++;
        _gotoxy (35, 2); // takes u to row 35x2 on and starts printing counter
        printf("[ %6d ]", cntr);
        if(_kbhit) // if a key was hit
        {
            cntr = 0; // reset the timer and assess the key hit
            c2 = 0;  //created to catch an invalid first entry char. then tc2 catches
            c1 = getch();
           
            if(c1==0)
            {
                // use this loop to check if it wa escp + - etc...
                c2= getch();
            
            _gotoxy (35, 2); // go to lines below the counter
            printf(" [%d : %c]" ,c1,c2);
            printf(" [%d : %c] [%d : %c]", c1, c1,c2,c2); // and print the formatted ascii char combo
            }
        }
    }
}



/* make a function call sleep, an have the function get into a loop and waiti for a certain amount 
of time to go by
mysleep(pass it ms (numms))
{
    t1= _clock() 
    t2 = t1 + numms
    while{t2 >clock()){
// _gotoxy() _kbhit() _getch()
// https://forums.macrumors.com/threads/c-help-getch-and-kbhit.23227/ 
// https://www.tutorialspoint.com/c_standard_library/c_function_getchar.html
/*int main(int argc, char *argv[])
{
    int cntr = 0;
    int c1, c2;
    while(!_kbhit())
    {
        cntr++;
        _gotoxy (35, 2);
        printf("[ %6d ]", cntr);
    }
    c2 = 0;  //created to catch an invalid first entry char. then tc2 catches
    c1 = _getch();
    if(c1==0)
    c2= _getch();
    printf(" [%d : %c]" ,c1,c2);
    printf(" [%d : %c]" ,c2,c1);
return 0;
}*/