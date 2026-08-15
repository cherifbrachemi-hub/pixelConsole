#include<iostream>



int main()
{
	
	const int screenL{ 80 };
	const int screenH{ 20 };

	char grid[screenH][screenL];

	int rectLength{40};
	int rectHeight{10};

	int dx{ (screenL - rectLength) / 2 };
	int dy{ (screenH - rectHeight) / 2 };


	for (int i = 0; i <= (screenH-1); i++) {
		
		for (int j = 0; j <= (screenL-1); j++) {
			if ((j >= dx && j <= (screenL - dx)) && (i >= dy) && (i <= (screenH - dy))) {
				grid[i][j] = '1';
			}
			else
				grid[i][j] = '0';
		}
	}


	//Print
	for (int i = 0; i <= (screenH-1); i++) {
		for (int j = 0; j <= (screenL-1); j++) {
			std::cout << grid[i][j];
		}
		std::cout << '\n';
	}

	return 0;
}
