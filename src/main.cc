#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <list>

#include "math.h"
#include "bot.h"

using namespace std;

int main(int argc, char** argv) {

    std::cout << "Working diretory: " << argv[0] << std::endl;
    std::cout << "Atempting to parse file: " <<  argv[1] << std::endl;

    Robot robot;
    robot.run_instructions(robot.parseInstructions(argv[1]));
    
}
