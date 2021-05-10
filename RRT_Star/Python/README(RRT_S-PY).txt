Rapidly exploring random trees* (RRT*)

Language used – Python

Libraries used - 
random
numpy
math
matplotlib

Description – The setup is of a 100 by 100 co-ordinate system. The centre of the map is marked by the co ordinate (0,0). The x values range from -50 to +50 and the y values range from -50 to +50. All obstacles are rectangular in shape and grey in colour.  The nodes are presented as a blue scatter plot, with paths joining the various nodes. The origin has been marked separately and the destination is the big black node. If a path between the origin and the destination is found, it is presented in black.

Input Format – The program takes various inputs for interacting with the user -
1. starting co-ordinates – Enter the starting co-ordinate for the path. Make sure it is between -50 and +50, separated by a comma. Make sure there is no space in between.
2. Destination co-ordinates – Enter the destination co-ordinates in the same format as starting co-ordinates. 
3. Iterations – Enter an integer value for the number of iterations. This would represent how many nodes it will add to the tree before giving up.
4. Number of obstacles – Enter an integer value for the number of obstacles you want to add to the map.
5. Obstacle dimensions – For each obstacle you want to add to the map, enter its dimensions. First enter the x and y value of the top left corner, as prompted by the program. Then input the length and breadth of the obstacle. Make sure that the obstacles don't enclose the destination point within themselves.
6. Continue – If you want to continue to find a shorter path, enter 1, else enter 0.
 
You are done! Now watch the program design a path from the start to the destination using the RRT* algorithm.

Output – The program plots the designed map and tries to find a path from the start to the destination. If found, it traces this path as a separate black path and displays the results to the user.

Example - 
Please enter Starting co-ordinates separated by a comma
-50,0
Please enter Destination co-ordinates
0,0
Enter number of iterations to run
500
Enter number of obstacles
1
Enter co-ordinates of the top left point for obstacle 1
-30,20
Enter length of obstacle
20
Enter breadth of obstacle
40
Reached Destination 
Length of path 22
Do you want to continue to find a shorter path?
1 for yes, 0 for no
1
Destination not reached 


Future modifications – Since the project has been built as a proof of concept, there are many modifications and optimizations that can be performed in its code.
1. Animate the rerouting process so that user can see when rewiring takes place.
2. Make the program more interactive and user friendly.
3. Handle user mistakes at runtime.
