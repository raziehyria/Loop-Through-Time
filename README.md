# Loop-Through-Time
Learning how to Output data all over the Console Window.


CmpSc472 Lab

# Requirement
1. Create a  ”C” program.  Name the program LoopThruTime

2. Display the clock on row 3, col 20.  The clock format will be as follows:  
'''
[  5 : 59 : 13 ]
'''

3. Loop thru all of the seconds in the day, from 0:0:0 to 23:59:59.

4. Have the user hit any key to start the clock.

5. The clock will sleep after displaying each second.  The initial sleep time will be 100ms.

6. By hitting keys, the user will be able to change the sleep time anywhere between min: 
100ms  to max: 2000ms.

7. In real time, detect, these keystrokes:
    a. “+” : This will increase the sleep time by 100ms.  Do not go over the maximum 
limit.
    b. “-“ : This will decrease the sleep time by 100ms. Do not go below the minimum 
limit.
    c. <esc> : will exit the program. Move the cursor to bottom of console window 
before exiting.
    d. F5  : Start the clock over at 0:0:0.
    e. If any other key is hit, go to row 1, col 50 to display this     invalid keystroke.

8. The program will end by 1 of 2 ways:
    a. It loops thru all of the seconds in a day.
    b. User hits <escape>
# Programming Tips
1. You will need nested loops.  It would be easier if you use nested FOR loops, but I want 
you to use nested WHILE loops.

2. Annotations
