#include<iostream>
#include<string>
#include <thread>
#include <chrono>
#include <cmath>

const int width = 100;
const int height = 20;

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
		buffer.reserve((width + 1) * height);

		double format{ 1.5 };

		double rectW{ width/format };
		double rectH{ height/format };
		
		double dx{ (width - rectW) / 2 };
		double dy{ (height - rectH) / 2 };
		
		
		for (int y = 0; y < height; y++)
		{
			
			for (int x = 0; x < width; x++)
			{
				
							
				bool on = (dx < x && x < width - dx) && (dy < y && y < height - dy);

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
