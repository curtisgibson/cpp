//
//  robot.cpp
//  coursework
//
//  Created by Curtis Gibson on 13/11/2018.
//  Copyright © 2018 Curtis Gibson. All rights reserved.
//

#include "robot.hpp"
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Robot constructor
robot::robot(const string &r) : robotName(r)
{
    // Initialise to map origin
    stepsEast = map_origin;
    stepsNorth = map_origin;
}

// Move north by 1 step
void robot::move_north()
{
    stepsNorth++;
    distanceTravelled++;
}

// Move east by 1 step
void robot::move_east()
{
    stepsEast++;
    distanceTravelled++;
}

// Move south by 1 step
void robot::move_south()
{
    stepsNorth--; // -1 from North (its opposite North)
    distanceTravelled++;
}

// Move west 1 step
void robot::move_west()
{
    stepsEast--; // -1 from East (its opposite West)
    distanceTravelled++;
}

// Return distance required to get back to origin
int distance(const robot &r)
{
    // abs returns the absolute value of r.north plus r.east
    return abs(r.north()) + abs(r.east());
}
