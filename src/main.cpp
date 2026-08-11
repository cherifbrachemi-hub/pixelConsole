#include<iostream>
#include<string>
#include <thread>
#include <chrono>

const int WIDTH = 40;
const int HEIGHT = 20;

void clearScreen()
{
	std::cout << "\x1B[2J\x1B[H";
}

int main()
{
	int frame = 0;

	while (true)
	{
		std::string buffer;
		buffer.reserve((WIDTH + 1) * HEIGHT);

		for (int y = 0; y < HEIGHT; y++)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				bool on = (x % 2==0) == (y % 2==0);
				buffer += on ? '#' : ' ';
			}
			buffer += '\n';
		}

		clearScreen();
		std::cout << buffer;
		std::cout.flush();

		std::this_thread::sleep_for(std::chrono::milliseconds(60));
		frame++;
	}

	return 0;
}
