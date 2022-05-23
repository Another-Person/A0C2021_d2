#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream commands;
	commands.open("commands.txt");

	if (commands.good())
	{
		std::string direction;
		int x = 0;

		int horizontalPos = 0;
		int depth = 0;
		int aim = 0;

		while (!commands.eof())
		{
			commands >> direction >> x;
			if (direction == "forward")
			{
				horizontalPos += x;
				depth += aim * x;
			}
			else if (direction == "down")
			{
				aim += x;
			}
			else if (direction == "up")
			{
				aim -= x;
			}
		}

		std::cout << "Final result: " << horizontalPos * depth << "\n";
	}
	else
	{
		std::cerr << "Could not open file \"commands.txt\". Please check that it exists and is not open somewhere else.\n";
		return 1;
	}

	return 0;
}