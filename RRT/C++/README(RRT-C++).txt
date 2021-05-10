Rapidly exploring random trees (RRT)

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

Description – The setup consists of a (500*500) screen. The top left corner represents the co-ordinates (0,0). The x co-ordinate increases to the right and the y co-ordinate increases towards the bottom. All obstacles are rectangular in shape and blue in colour. The starting co ordinate is represented by a green circle. The destination is represented by a red circle. The path is shown by a white line that connects various nodes. 

Input Format – The program takes various inputs for interacting with the user -
1. Starting co-ordinates – Enter the starting co-ordinate for the path. Make sure it is between 0 and 500 for both the x and y co-ordinates. Input the x co-ordinate first then the y co-ordinate, as prompted by the program.
2. Destination co-ordinates – Enter the destination co-ordinates in the same format as starting co-ordinates. 
3. Iterations – Enter an integer value for the number of iterations. This would represent how many nodes it will add to the tree before giving up.
4. Number of obstacles – Enter an integer value for the number of obstacles you want to add to the map.
5. Obstacle dimensions – For each obstacle you want to add to the map, enter its dimensions. First enter the x and y value of the top left corner, as prompted by the program. Then input the length and breadth of the obstacle. Make sure that the obstacles don't enclose the destination point within themselves.
 
You are done! Now watch the program design a path from the start to the destination using the RRT algorithm.

Note – The program uses the SFML library that needs to be separately downloaded and set up for the system. For my local machine, the program was run through the command line, using the following flags “clang++ RRT.cpp -lsfml-graphics -lsfml-window -lsfml-system -o RRT”

Output – The program will visually depict this map. It will show how nodes are added and how the path is formed. The program ends when a path is found till the destination or when the number of iterations expire.

Example - 
Enter starting co-ordinates
x: 50
y: 50
Enter destination co-ordinates
x: 300
y: 300
Enter number of iterations to run 1000
Enter number of obstacles
2
Enter top left co-ordinates
x: 100
y: 0
Enter length 40
Enter breadth 200
Enter top left co-ordinates
x: 100
y: 220
Enter length 40
Enter breadth 250
Destination Reached
End of iterations


Future modifications – Since the project has been built as a proof of concept, there are many modifications and optimizations that can be performed in its code.
1. Implement exception handling to check for runtime errors.
2. Improve the graphical interface and take input/output on the graphical interface only, instead of on the command line.
3. Allow the obstacles to be of any shape.
