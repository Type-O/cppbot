#pragma once
#include <vector>
#include <memory>
#include <list>
#include <string>

enum direction
{
    INIT = 0,
    NORTH = 1,
    SOUTH = 3,
    EAST = 2,
    WEST = 4
};

enum type {
    PLACE = 0,
    MOVE = 1,
    LEFT = 2,
    RIGHT = 3,
    REPORT = 4,
};

class Instruction {
public:
    type m_type;
    int m_x, m_y, m_dir;


    Instruction(type type) {
        m_type = type;
        m_x = -1;
        m_y = -1;
        m_dir = -1;
    }

    Instruction(int x, int y, int dir, type type) {
        m_type = type;
        m_x = x;
        m_y = y;
        m_dir = dir;
    }

};

class Robot {

public:
    Robot(){
        m_x = -1;
        m_y = -1;
        m_isPlaced = false;
    }
    std::string report();
    void rotate_left();
    void rotate_right();
    void place(int x, int y, int dir);
    void move();
    void run_instructions(std::list<Instruction> list);
    std::list<Instruction> parseInstructions(std::string file);


private:
    int m_x;
    int m_y;
    int m_dir;
    bool m_isPlaced;

    bool inBoundCheck(int i);


};