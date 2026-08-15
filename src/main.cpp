#include<iostream>


const int screenL{ 80 };
const int screenH{ 20 };

char grid[screenH][screenL];

bool condition(int i, int j) {
	if ((i == j) || (j == (screenL - 1 - i))) {
		return true;
	}
	else
		return false;
}


void fillGrid() {
	for (int i = 0; i <= (screenH - 1); i++) {
		for (int j = 0; j <= (screenL - 1); j++) {
			
			bool on{condition(i,j)};

			if (on) {
				grid[i][j] = '1';
			}
			else
				grid[i][j] = '0';
		}
	}
}

void printGrid() {
	for (int i = 0; i <= (screenH - 1); i++) {
		for (int j = 0; j <= (screenL - 1); j++) {
			std::cout << grid[i][j];
		}
		std::cout << '\n';
	}
}



int main()
{
	
	int rectLength{40};
	int rectHeight{10};

	int dx{ (screenL - rectLength) / 2 };
	int dy{ (screenH - rectHeight) / 2 };

	//fill
	fillGrid();

	//Print
	printGrid();
	return 0;
}
