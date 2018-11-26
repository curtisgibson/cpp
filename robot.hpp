//
//  robot.hpp
//  coursework
//
//  Created by Curtis Gibson on 13/11/2018.
//  Copyright © 2018 Curtis Gibson. All rights reserved.
//

#ifndef robot_hpp
#define robot_hpp

#include <string>
#include <vector>

class robot
{
    std::string robotName;
    int map_origin = 0;
    int distanceTravelled = 0;
    int stepsNorth, stepsEast;
    
public:
    // Initialize Robot
    explicit robot(const std::string &n);
    
    void move_north();      // Move one step north
    void move_east();       // Move one step east
    void move_south();      // Move one step south
    void move_west();       // Move one step west
    
    // Returns name of robot
    const std::string & name() const { return robotName; };
    
    // Returns current distance north of the robot
    int north() const { return stepsNorth; };
    
    // Returns current distance east of the robot
    int east() const { return stepsEast; };
    
    // Returns total distance travelled by robot
    int travelled() const { return distanceTravelled; };
};

// Returns distance of robot from the origin
int distance(const robot &r);

#endif /* robot_hpp */
