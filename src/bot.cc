#include "bot.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <list>


std::string Robot::report(bool verbose)
{
	std::string str;
	if (!m_isPlaced)
		str = "Not yet placed!";
	else
	{
		str += std::to_string(m_x) + "," + std::to_string(m_y) + ",";
		if (m_dir == NORTH)
			str += "NORTH";
		else if (m_dir == SOUTH)
			str += "SOUTH";
		else if (m_dir == WEST)
			str += "WEST";
		else if (m_dir == EAST)
			str += "EAST";

	}
	if(verbose)
		std::cout << str << std::endl;
	return str;
}

void Robot::rotate_left()
{
	if (m_isPlaced)
	{
		if (m_dir == 1)
			m_dir = 4;
		else
			m_dir -= 1;
	}
}

void Robot::rotate_right()
{
	if (m_isPlaced)
	{
		m_dir += 1;
		if (m_dir > 4)
			m_dir = 1;
	}
}

void Robot::place(int x, int y, int dir)
{
	if (inBoundCheck(x) && inBoundCheck(y) && dir > 0 && dir < 5) {
		m_isPlaced = true;
		m_dir = dir;
		m_x = x;
		m_y = y;
	}

}

void Robot::move()
{
	if (m_isPlaced)
	{
		if (m_dir == NORTH && inBoundCheck(m_y + 1))
			m_y += 1;
		else if (m_dir == SOUTH && inBoundCheck(m_y - 1))
			m_y -= 1;
		else if (m_dir == EAST && inBoundCheck(m_x + 1))
			m_x += 1;
		else if (m_dir == WEST && inBoundCheck(m_x - 1))
			m_x -= 1;
	}
}

void Robot::run_instructions(std::list<Instruction> list, bool verbose)
{
	for (auto const& i : list) {
		if (i.m_type == REPORT)
			report(verbose);
		else if (i.m_type == PLACE)
			place(i.m_x, i.m_y, i.m_dir);
		else if (i.m_type == MOVE)
			move();
		else if (i.m_type == RIGHT)
			rotate_right();
		else if (i.m_type == LEFT)
			rotate_left();
	}

}

std::list<Instruction> Robot::parseInstructions(std::string file)
{
	using namespace std;

	fstream fileStream;
	fileStream.open(file);

	std::list<Instruction> list;

	if (fileStream.is_open()) {   //checking whether the file is open
		string tp;
		while (std::getline(fileStream, tp)) { //read data from file object and put it into string.

			if (tp.find("PLACE") != string::npos) {
				const char c = tp[6];
				int x = std::atoi(&c);

				const char cc = tp[8];
				int y = std::atoi(&cc);

				int direction = INIT;
				if (tp.find("NORTH") != string::npos) {
					direction = NORTH;
				}
				else if (tp.find("SOUTH") != string::npos)
				{
					direction = SOUTH;
				}
				else if (tp.find("WEST") != string::npos)
				{
					direction = WEST;
				}
				else if (tp.find("EAST") != string::npos)
				{
					direction = EAST;
				}

				list.push_back(Instruction(x, y, direction, PLACE));
			}
			else if (tp.find("MOVE") != string::npos)
			{
				list.push_back(Instruction(MOVE));
			}
			else if (tp.find("REPORT") != string::npos)
			{
				list.push_back(Instruction(REPORT));
			}
			else if (tp.find("LEFT") != string::npos)
			{
				list.push_back(Instruction(LEFT));
			}
			else if (tp.find("RIGHT") != string::npos)
			{
				list.push_back(Instruction(RIGHT));
			}
		}
		fileStream.close(); //close the file object.
	}
	
	return list;
}

bool Robot::inBoundCheck(int i)
{
	if (i < 0 || i > 4)
		return false;
	else
		return true;
}