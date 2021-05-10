Rapidly exploring random trees* (RRT*)

Language used – C++

Libraries used - 

iostream
cmath
cstdlib
vector
SFML
time.h
random
utility

Description – The setup consists of a (500*500) screen. The top left corner represents the co-ordinates (0,0). The x co-ordinate increases to the right and the y co-ordinate increases towards the bottom. All obstacles are rectangular in shape and blue in colour. The starting co ordinate is represented by a green circle. The destination is represented by a red circle. The path is shown by a white line that connects various nodes. These connections will change in real time, in case a shorter connection is found.

Input Format – The program takes various inputs for interacting with the user -
1. starting co-ordinates – Enter the starting co-ordinate for the path. Make sure it is between 0 and 500 for both the x and y co-ordinates. Input the x co-ordinate first then the y co-ordinate, as prompted by the program.
2. Destination co-ordinates – Enter the destination co-ordinates in the same format as starting co-ordinates.
3. Iterations – Enter an integer value for the number of iterations. This would represent how many nodes it will add to the tree before giving up.
4. Number of obstacles – Enter an integer value for the number of obstacles you want to add to the map.
5. Obstacle dimensions – For each obstacle you want to add to the map, enter its dimensions. First enter the x and y value of the top left corner, as prompted by the program. Then input the length and breadth of the obstacle. Make sure that the obstacles don't enclose the destination point within themselves.
6. Continue – If the destination is reached before the end of iterations, the program would ask if the user wants to continue iterating, in case a shorter path can be found. Enter 1 to continue and 0 to exit.
 
You are done! Now watch the program design a path from the start to the destination using the RRT* algorithm.

Note – The program uses the SFML library that needs to be separately downloaded and set up for the system. For my local machine, the program was run through the command line, using the following flags “clang++ RRT2.cpp -lsfml-graphics -lsfml-window -lsfml-system -o RRT2”

Output – The program will visually depict this map. It will show how nodes are added, how the path is formed and changes with time. The program ends when the number of iterations expire.

Example - 
Enter starting co-ordinates
x: 0
y: 0
Enter destination co-ordinates
x: 250
y: 250
Enter number of iterations to run 1000
Enter number of obstacles
3
Enter top left co-ordinates
x: 50
y: 0
Enter length 50
Enter breadth 100
Enter top left co-ordinates
x: 50
y: 150
Enter length 50
Enter breadth 150
Enter top left co-ordinates
x: 300
y: 300
Enter length 200
Enter breadth 100
Length 12
Destination reached
Do you want to continue to find a shorter path ?
1 for yes, 0 for no 1
Length 11
Destination reached
Do you want to continue to find a shorter path ?
1 for yes, 0 for no 0
Ending program...
End of iterations

Future modifications – Since the project has been built as a proof of concept, there are many modifications and optimizations that can be performed in its code.
1. Implement exception handling to check for runtime errors.
2. Improve the graphical interface and take input/output on the graphical interface only, instead of on the command line.
3. Trace the final path to the destination.
