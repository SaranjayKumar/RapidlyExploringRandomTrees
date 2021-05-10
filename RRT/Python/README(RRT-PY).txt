Rapidly exploring random trees (RRT)

Language used – Python

Libraries used - 
random
numpy
math
matplotlib

Description – The setup is of a 100 by 100 co-ordinate system. The centre of the map is marked by the co ordinate (0,0). 
The x values range from -50 to +50 and the y values range from -50 to +50. All obstacles are rectangular in shape and grey in colour.  The nodes are presented as a blue scatter plot, with paths joining the various nodes. The origin has been marked separately and the destination is the big black node. If a path between the origin and the destination is found, it is presented in black.

Input Format – The program takes various inputs for interacting with the user -
1. starting co-ordinates – Enter the starting co-ordinate for the path. Make sure it is between -50 and +50, separated by a comma. 
   Make sure there is no space in between.
2. Destination co-ordinates – Enter the destination co-ordinates in the same format as starting co-ordinates. 
3. Iterations – Enter an integer value for the number of iterations. This would represent how many nodes it will add to the tree before giving up.
4. Number of obstacles – Enter an integer value for the number of obstacles you want to add to the map.
5. Obstacle dimensions – For each obstacle you want to add to the map, enter its dimensions. First enter the x and y value of the top left corner, as prompted by the program. Then input the length and breadth of the obstacle. Make sure that the obstacles don't enclose the destination point within themselves.
 
You are done! Now watch the program design a path from the start to the destination using the RRT algorithm.

Output – The program plots the designed map and tries to find a path from the start to the destination. If found, it traces this path as a separate black path and displays the results to the user.

Example - 
Please enter Starting co-ordinates separated by a comma
0,0
Please enter Destination co-ordinates
50,50
Enter number of iterations to run
1000
Enter number of obstacles
1
Enter co-ordinates of the top left point for obstacle 1
-50,0
Enter length of obstacle
40
Enter breadth of obstacle
20

Future modifications – Since the project has been built as a proof of concept, there are many modifications and optimizations that can be performed in its code.
1. Implement exception handling to check for runtime errors.
2. Animate the plotting process using Pygame or similar library.
3. Allow user to pick and drop the various objects on the map, rather than through a co-ordinate system.
