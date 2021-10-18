#include <gtest/gtest.h>
#include "../src/bot.h"
#include <string>


TEST(MarathonTest, BasicAssertions) {

	Robot robot;
	robot.run_instructions(robot.parseInstructions("..\\..\\test\\Marathon.txt"));
	std::string s1 = robot.report();
	std::string s2 = "0,0,WEST";
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}

TEST(TestInstructionSetOne, BasicAssertions) {

	Robot robot;
	robot.run_instructions(robot.parseInstructions("..\\..\\test\\IS1.txt"));
	std::string s1 = robot.report();
	std::string s2 = "0,1,NORTH";
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}

TEST(TestInstructionSetTwo, BasicAssertions) {

	Robot robot;
	robot.run_instructions(robot.parseInstructions("..\\..\\test\\IS2.txt"));
	std::string s1 = robot.report();
	std::string s2 = "0,0,WEST";
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}

TEST(TestInstructionSetThree, BasicAssertions) {

	Robot robot;
	robot.run_instructions(robot.parseInstructions("..\\..\\test\\IS3.txt"));
	std::string s1 = robot.report();
	std::string s2 = "3,3,NORTH";
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}
TEST(MoveYWest, BasicAssertions) {

	Robot robot;
	std::list<Instruction> list;
	list.push_back(Instruction(0, 0, WEST, PLACE));

	robot.run_instructions(list);
	std::string s1 = robot.report();
	std::string s2 = "0,0,WEST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,WEST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}

TEST(MoveXSouth, BasicAssertions) {

	Robot robot;
	std::list<Instruction> list;
	list.push_back(Instruction(0, 0, SOUTH, PLACE));

	robot.run_instructions(list);
	std::string s1 = robot.report();
	std::string s2 = "0,0,SOUTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,SOUTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}

TEST(MoveX, BasicAssertions) {

	Robot robot;
	std::list<Instruction> list;
	list.push_back(Instruction(0, 0, NORTH, PLACE));

	robot.run_instructions(list);
	std::string s1 = robot.report();
	std::string s2 = "0,0,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,1,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,2,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,3,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,4,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,4,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}

TEST(MoveY, BasicAssertions) {

	Robot robot;
	std::list<Instruction> list;
	list.push_back(Instruction(0, 0, EAST, PLACE));

	robot.run_instructions(list);
	std::string s1 = robot.report();
	std::string s2 = "0,0,EAST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "1,0,EAST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "2,0,EAST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "3,0,EAST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "4,0,EAST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(MOVE));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "4,0,EAST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}
TEST(BoundPlace, BasicAssertions) {

	Robot robot;
	std::list<Instruction> list;
	list.push_back(Instruction(6, 0, NORTH, PLACE));
	robot.run_instructions(list);
	std::string s1 = "Not yet placed!";
	std::string s2 = robot.report();
	list.pop_back();
	ASSERT_STREQ(s2.c_str(), s1.c_str());

	list.push_back(Instruction(0, 6, NORTH, PLACE));
	robot.run_instructions(list);
	s1 = "Not yet placed!";
	s2 = robot.report();
	list.pop_back();
	ASSERT_STREQ(s2.c_str(), s1.c_str());

	list.push_back(Instruction(0, 0, 1337, PLACE));
	robot.run_instructions(list);
	s1 = "Not yet placed!";
	s2 = robot.report();
	list.pop_back();
	ASSERT_STREQ(s2.c_str(), s1.c_str());

	list.push_back(Instruction(0, 0, NORTH, (type)0xBAD));
	robot.run_instructions(list);
	s1 = "Not yet placed!";
	s2 = robot.report();
	list.pop_back();
	ASSERT_STREQ(s2.c_str(), s1.c_str());

	list.push_back(Instruction(-1, 0, NORTH, PLACE));
	robot.run_instructions(list);
	s1 = "Not yet placed!";
	s2 = robot.report();
	list.pop_back();
	ASSERT_STREQ(s2.c_str(), s1.c_str());

	list.push_back(Instruction(0, -1, NORTH, PLACE));
	robot.run_instructions(list);
	s1 = "Not yet placed!";
	s2 = robot.report();
	list.pop_back();
	ASSERT_STREQ(s2.c_str(), s1.c_str());

	list.push_back(Instruction(4, 4, WEST, PLACE));
	robot.run_instructions(list);
	s1 = "4,4,WEST";
	s2 = robot.report();
	list.pop_back();
	ASSERT_STREQ(s2.c_str(), s1.c_str());
}

TEST(UninitializedTest, BasicAssertions) {
	Robot robot;
	std::string s1 = "Not yet placed!";
	std::string s2 = robot.report();
	ASSERT_STREQ(s2.c_str(), s1.c_str());
}

TEST(RotateLeft, BasicAssertions) {
	Robot robot;
	std::list<Instruction> list;
	list.push_back(Instruction(0, 0, NORTH, PLACE));

	robot.run_instructions(list);
	std::string s1 = robot.report();
	std::string s2 = "0,0,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(LEFT));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,WEST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(LEFT));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,SOUTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(LEFT));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,EAST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(LEFT));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}

TEST(RotateRight, BasicAssertions) {
	Robot robot;
	std::list<Instruction> list;
	list.push_back(Instruction(0, 0, NORTH, PLACE));

	robot.run_instructions(list);
	std::string s1 = robot.report();
	std::string s2 = "0,0,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(RIGHT));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,EAST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(RIGHT));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,SOUTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(RIGHT));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,WEST";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());

	list.push_back(Instruction(RIGHT));
	robot.run_instructions(list);
	s1 = robot.report();
	s2 = "0,0,NORTH";
	list.pop_back();
	ASSERT_STREQ(robot.report().c_str(), s2.c_str());
}