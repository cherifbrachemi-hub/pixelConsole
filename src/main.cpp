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
	

		for (int x = 0; x < WIDTH; x++)
		{
			float valeurSin1 = sin(x * 0.3 + frame * 0.1);
			float t1 = (valeurSin1 + 1.0) / 2.0;
			int hauteurVague1 = (HEIGHT / 4) + t1 * (HEIGHT / 2);

			float valeurSin2 = sin(x * 0.3 + frame * 0.1 + 9.5);
			float t2 = (valeurSin2 + 1.0) / 2.0;
			int hauteurVague2 = (HEIGHT / 4) + t2 * (HEIGHT / 2);

			for (int y = 0; y < HEIGHT; y++)
			{
				


				bool on = (y==hauteurVague1) || (y == hauteurVague2);

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
