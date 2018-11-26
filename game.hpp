//
//  game.hpp
//  coursework
//
//  Created by Curtis Gibson on 13/11/2018.
//  Copyright © 2018 Curtis Gibson. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include "robot.hpp"

#include <string>
#include <vector>
#include <map>

class game
{
    std::map <std::string, robot> robotMap; // 2D Map containing Robots
    
public:
    // Returns total number of robots in the game.
    int num_robots() const;
    
    // Move the named robot one step in the specified direction (0 = north, 1 = east, 2 = south, 3 = west).
    void move(const std::string &name, int dir);
    
    // Returns the number of robots no more than 10 steps from the origin.
    int num_close() const;
    
    // Returns the furthest distance of any robot from the origin.
    int max_distance() const;
    
    // Returns all the robots, arranged in increasing order of total distance travelled.
    std::vector<robot> robots_by_travelled() const;
    
    // Returns name of the robot that is the furthest distance from origin
    std::string furthest() const;
};

// Sort method to sort distances by ascending order
bool compare_distance(const robot &x, const robot &y);

#endif /* game_hpp */
