#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include<sys/wait.h>


// _gotoxy() _kbhit() _getch()
// https://forums.macrumors.com/threads/c-help-getch-and-kbhit.23227/ 
// https://www.tutorialspoint.com/c_standard_library/c_function_getchar.htm

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

int main(int argc, char *argv[])
{
    int cntr = 0;
    int c1, c2;

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
    }

    }
}*/
