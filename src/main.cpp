#include<iostream>
#include<string>
#include <thread>
#include <chrono>
#include <cmath>

const int WIDTH = 40;
const int HEIGHT = 40;

void clearScreen()
{
	std::cout << "\x1B[2J\x1B[H";
}

int main()
{
	int frame = 0;

	int centreX = WIDTH / 2;
	int centreY = HEIGHT / 2;
	

	while (true)
	{
		std::string buffer;
		buffer.reserve((WIDTH + 1) * HEIGHT);
		
		float t = (sin(frame / 20.0) + 1.0) / 2.0;
		int rayonExt = 5+t *11;
		int rayonInt = rayonExt -3;

		for (int y = 0; y < HEIGHT; y++)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				int dx = x-centreX;
				int dy = (y-centreY) * 2;
				int distanceXY = dx * dx + dy * dy;
				bool on =  (rayonInt * rayonInt <= distanceXY) && (distanceXY <= rayonExt * rayonExt);

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
