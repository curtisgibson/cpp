//
//  game.cpp
//  coursework
//
//  Created by Curtis Gibson on 13/11/2018.
//  Copyright © 2018 Curtis Gibson. All rights reserved.
//

#include "game.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Move the robot, passed via name, in a specified direction, passed by dir.
void game::move(const std::string &name, int dir)
{
    // Check if robot does not already exist within map
    if (robotMap.count(name) == 0)
        robotMap.emplace(name, robot(name)); // Create a new robot
    
    // Switch statement to move the robot
    switch(dir)
    {
        case 0: // dir == 0, move robot North
            robotMap.at(name).move_north();
            break;
        case 1: // dir == 1, move robot east
            robotMap.at(name).move_east();
            break;
        case 2: // dir == 2, move roboto south
            robotMap.at(name).move_south();
            break;
        case 3: // dir == 3, move robot west
            robotMap.at(name).move_west();
            break;
    }
}

// Return number of robots within the map
int game::num_robots () const
{
    return robotMap.size();
}

// Return the number of robots no more than 10 steps away from origin
int game::num_close() const
{
    int closest = 0;
    
    // Itererate through map to find distance for each robot
    for (map<string, robot>::const_iterator it = robotMap.begin(); it != robotMap.end(); ++it)
    {
        // If distance is greater than or equal to 10
        if (distance(it->second) <= 10)
            closest++;
    }
    return closest;
}

// Returns the furthest distance of any robot from the origin.
int game::max_distance() const
{
    // Call distance, passing through the results from furthest method.
    return distance(robotMap.at(furthest()));
}

// Returns the name of the robot that is the furthest distance from the origin.
string game::furthest() const
{
    string name;
    int furthest_distance = 0;
    
    // Itererate through map to find distance for each robot
    for (map<string, robot>::const_iterator it = robotMap.begin(); it != robotMap.end(); ++it)
    {
        // if distance of current robot is greater than current greatest distance
        if (distance(it->second) > furthest_distance)
        {
            // Make this the new furthest distance
            name = it->first; // Name of robot from iterator
            furthest_distance = distance(it->second); // Store distance from origin from iterator
        }
    }
    return name;
}

// A sort method, used to sort robots in ascending order.
bool compare_distance(const robot &x, const robot &y)
{
    return distance(x) < distance(y);
}

// Returns robots in the system, arranged in increasing order of total distance travelled
vector<robot> game::robots_by_travelled() const
{
    // Empty vector of robots
    vector<robot> robots;
    
    // Itererate through map and copy all robots to the vector
    for (map<string, robot>::const_iterator it = robotMap.begin(); it != robotMap.end(); ++it)
        robots.push_back(it->second); // Push to vector
    
    // Sort robots using the compare_distance method, to sort by ascending
    sort(robots.begin(), robots.end(), compare_distance);
    
    return robots;
}
