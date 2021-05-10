#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <random>
#include <utility>

using namespace std;
using namespace sf;

// Size of display window
const int  win_width = 500, win_height = 500;
RenderWindow window(VideoMode(win_width, win_height), "RRT");
VertexArray line(Lines, 2);

//class to hold node objects
class Node
{
public:
    float x;
    float y;

    Node() {x =0; y=0;}
    Node(float x, float y) : x(x), y(y) {}

    Node operator-(const Node &t)
    {
        float tx = this->x - t.x;
        float ty = this->y - t.y;

        return Node(tx, ty);
    }

    Node power(int p)
    {
        float tx = pow(this->x, p);
        float ty = pow(this->y, p);

        return Node(tx, ty);
    }

    Node operator*(float t)
    {
        float tx = this->x * t;
        float ty = this->y * t;

        return Node(tx, ty);
    }

    Node operator/(float t)
    {
        float tx = this->x / t;
        float ty = this->y / t;

        return Node(tx, ty);
    }

    Node operator+(const Node &t)
    {
        float tx = this->x + t.x;
        float ty = this->y + t.y;

        return Node(tx, ty);
    }

    bool operator==(const Node &t)
    {
        if (x == t.x && y == t.y)
        {
            return true;
        }
        return false;
    }
};

//Structure to hold corners of the obstacles
struct obstacle_points{
    Node corners[4];
};

Node start, dest;
const int step = 50, radius = 15;
const int radius_sq = pow(radius, 2);
vector<obstacle_points>obstacles;

//returns the index of the closest node in the tree
int closest_node(const Node &n1, const vector< pair<Node,Node> > &nodes, float &dist)
{
    float min = 99999999999, dist_sq;
    Node temp;
    int index;

    for (int i = 0; i < nodes.size(); ++i)
    {
        temp = nodes.at(i).first;
        temp = temp - n1;
        temp = temp.power(2);
        dist_sq = temp.x + temp.y;

        if (dist_sq < min)
        {
            min = dist_sq;
            index = i;
        }
    }
    //distance between the closest node and n1
    dist = sqrt(dist_sq);
    return index;
}

//supporter function for check()
bool onSegment(const Node &p, const Node &q, const Node &r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

//checks orientation of line segments, supporter function for check()
int orientation(const Node &p, const Node &q, const Node &r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;

    return (val > 0) ? 1 : 2;
}

bool doIntersect(const Node &p1, const Node &q1, const Node &p2, const Node &q2)
{

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;
}

//checks if the new edge cuts any of the obstacles
bool check(Node &p1, Node &q1)
{
    for (obstacle_points ob:obstacles)
    {
        for (int p = 0; p < 4; p++)
        {
            Node p2 = ob.corners[p];
            Node q2 = ob.corners[(p + 1) % 4];
            if (doIntersect(p1, q1, p2, q2))
            {
                return false;
            }
        }
    }
    
    return true;
}

//returns true if the node lands within 'radius' distance from the destination
bool reach(Node &node)
{

    Node temp = (dest - node);
    temp = temp.power(2);
    float distance = temp.x + temp.y;

    if (distance < radius_sq)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//introduces delay in program
void wait(unsigned timeout)
{
	timeout += std::clock();
	while (std::clock() < timeout)
		continue;
}

//draw all the figures on the window
void draw(const vector< pair<Node,Node> > &nodes, const vector<RectangleShape> &rectangles)
{
    //draw obstacles
    for(int i=0;i<rectangles.size();i++)
    {
        window.draw(rectangles[i]);
    }
    
    //draw start and destination
    CircleShape center(radius), destination(radius);
    center.setPosition(Vector2f(start.x - center.getRadius(), start.y - center.getRadius()));
    center.setFillColor(Color::Green);
    window.draw(center);

    destination.setPosition(Vector2f(dest.x - destination.getRadius(), dest.y-destination.getRadius()));
    destination.setFillColor(Color::Red);
    window.draw(destination);

    //draw all the lines between the new node and its closest node
    for(int i=0;i<nodes.size();i++)
    {
		line[0].position = (Vector2f(nodes[i].first.x, nodes[i].first.y));
		line[1].position = (Vector2f(nodes[i].second.x, nodes[i].second.y));
		window.draw(line);

    }
}


int main()
{

    vector< pair<Node, Node> > nodes;
    
    //used for generating random co ordinates
    random_device rd;
    mt19937 mt(rd());
    
    int no_obstacles, sx, sy, iterations, flag=0;

    cout<<"Enter starting co-ordinates\nx: ";
    cin>>sx;
    cout<<"y: ";
    cin>>sy;
    start.x = sx;
    start.y = sy;

    cout<<"Enter destination co-ordinates\nx: ";
    cin>>sx;
    cout<<"y: ";
    cin>>sy;
    dest.x = sx;
    dest.y = sy;

    cout<<"Enter number of iterations to run ";
    cin>>iterations;

    cout<<"Enter number of obstacles\n";
    cin>>no_obstacles;

    vector<RectangleShape> rectangles(no_obstacles);
    
    //taking inputs for all the obstacle co-ordinates
    for (int i=0;i<no_obstacles;++i)
    {
        float x,y, length, breadth;
        obstacle_points points;
        cout<<"Enter top left co-ordinates\nx: ";
        cin>>x;
        cout<<"y: ";
        cin>>y;
        cout<<"Enter length ";
        cin>>length;
        cout<<"Enter breadth ";
        cin>>breadth;
        
        points.corners[0] = Node(x,y);
        points.corners[1] = Node(x+length, y);
        points.corners[2] = Node(x+length, y+breadth);
        points.corners[3] = Node(x, y+breadth);
        
        obstacles.push_back(points);

        rectangles[i].setSize(Vector2f(length, breadth));
        rectangles[i].setPosition(Vector2f(x, y));
        rectangles[i].setFillColor(Color::Blue);

    }
	
    window.clear();

    float temp_dist;

    nodes.push_back(make_pair(start,start));
    Event event;

    for (int i = 0; i < iterations and window.isOpen(); i++)
    {
        
        window.clear();
        temp_dist = 0.0f;

        uniform_real_distribution<double> r1(0.0, win_width);
        uniform_real_distribution<double> r2(0.0, win_height);
        
        //creating a random point
        Node new_point(r1(mt), r2(mt));

        int index = closest_node(new_point, nodes, temp_dist);
        Node close_node = nodes[index].first;

        //ignore if the new node is very close to an existing node
        if (temp_dist <= 10)
        {
            cout << "Distance is 0" << endl;
            i-=1;
            continue;
        }

        //calculating coordinates of new node at given distance from the close node
        Node new_node = ((new_point - close_node));
        new_node = (new_node * step);
        new_node = new_node / temp_dist;
        new_node = new_node + close_node;

        //check if new node doesnt crash into obstacles
        if (check(close_node, new_node) == false)
        {
            //cout<<"On obstacle"<<endl;
            i-=1;
            continue;
        }

        nodes.push_back(make_pair(new_node, close_node));

        draw(nodes, rectangles);   
        
        window.display();

        //check if new node lands on the destination
        if (reach(new_node))
        {
            cout << "Destination Reached\n";
            flag = 1;
            break;
        }
         

        while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
				break;
		}
        wait(80000);
    }

    if (!flag)cout<<"Destination not reached\n";
    cout<<"End of iterations\n";

    while(window.isOpen())
     while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				{window.close();
				break;}
		}
    cout<<"End of program\n";  
}