
#include <iostream>
#include <vector>
#include <stdlib.h> // atoi
class basicSquare
{
public:
	basicSquare(){}
	int getW(){return width;}
	int getH(){return height;}
	void setW(int w){width = w;}
	void setH(int h){height = h;}
private:
	int width;
	int height;
};

std::vector<std::vector<basicSquare>> makeBoard(int size, int startW, int startH)
{
	std::vector<std::vector<basicSquare>> returnMe(size,std::vector<basicSquare>(size));
	for(int i=0; i<size; ++i)
	{
		for(int j=0; j<size; ++j)
		{
			returnMe[j][i].setW(j+startW);
			returnMe[j][i].setH(i+startH);
		}
	}
	return returnMe;
}

void kindaRecurse(int badW, int badH, int size, int startW, int startH)
{
	std::vector<std::vector<basicSquare>> board = makeBoard(size, startW, startH);

	basicSquare topLeft = board[size/2-1][size/2-1];
	basicSquare topRight = board[size/2][size/2-1];
	basicSquare botomLeft = board[size/2-1][size/2];
	basicSquare bottomRight = board[size/2][size/2];

	if(badW < startW + size/2)
	{
		if(badH < startH + size/2)
		{
			// top left
			std::cout << "(" << topRight.getW() << "," << topRight.getH() << "),";
			std::cout << "(" << botomLeft.getW() << "," << botomLeft.getH() << "),";
			std::cout << "(" << bottomRight.getW() << ", " << bottomRight.getH() << ")" << std::endl;
			if(size != 2)
			{
				kindaRecurse(badW, badH, size/2, startW, startH);
				kindaRecurse(startW+size/2, startH+size/2-1, size/2, startW+size/2, startH);
				kindaRecurse(startW+size/2-1, startH+size/2, size/2, startW, startH+size/2);
				kindaRecurse(startW+size/2, startH+size/2, size/2, startW+size/2, startH+size/2);
			}	
		}
		else // badh >= size/2
		{
			// bottom left
			std::cout << "(" << topLeft.getW() << ", " << topLeft.getH() << "),";
			std::cout << "(" << topRight.getW() << ", " << topRight.getH() << "),";
			std::cout << "(" << bottomRight.getW() << ", " << bottomRight.getH() << ")" << std::endl;
			if(size != 2)
			{
				kindaRecurse(startW+size/2-1, startH+size/2-1, size/2, startW, startH);
				kindaRecurse(startW+size/2, startH+size/2-1, size/2, startW+size/2, startH);
				kindaRecurse(badW, badH, size/2, startW, startH+size/2);
				kindaRecurse(startW+size/2, startH+size/2, size/2, startW+size/2, startH+size/2);
			}
		}
	}
	else // badw >= size/2
	{
		if(badH < startH + size/2)
		{
			// top right
			std::cout << "(" << topLeft.getW() << ", " << topLeft.getH() << "),";
			std::cout << "(" << botomLeft.getW() << ", " << botomLeft.getH() << "),";
			std::cout << "(" << bottomRight.getW() << ", " << bottomRight.getH() << ")" << std::endl;
			if(size != 2)
			{
				kindaRecurse(startW+size/2-1, startH+size/2-1, size/2, startW, startH);
				kindaRecurse(badW, badH, size/2, startW+size/2, startH);
				kindaRecurse(startW+size/2-1, startH+size/2, size/2, startW, startH+size/2);
				kindaRecurse(startW+size/2, startH+size/2, size/2, startW+size/2, startH+size/2);
			}
		}
		else // badh >= size/2
		{
			// bottom right
			std::cout << "(" << topLeft.getW() << ", " << topLeft.getH() << "),";
			std::cout << "(" << botomLeft.getW() << ", " << botomLeft.getH() << "),";
			std::cout << "(" << topRight.getW() << ", " << topRight.getH() << ")" << std::endl;
			if(size != 2)
			{
				kindaRecurse(startW+size/2-1, startH+size/2-1, size/2, startW, startH);
				kindaRecurse(startW+size/2, startH+size/2-1, size/2, startW+size/2, startH);
				kindaRecurse(startW+size/2-1, startH+size/2, size/2, startW, startH+size/2);
				kindaRecurse(badW, badH, size/2, startW+size/2, startH+size/2);
			}
		}
	}
}

int main(int argc, char** argv)
{
	if(argc != 4){
		std::cout << "Please pass in (int size, int badSquareW, int BadSquareH)" << std::endl;
		return 0;
	}

	int size = atoi(argv[1]);
	int badSquareW = atoi(argv[2]);
	int badSquareH = atoi(argv[3]);
 
	kindaRecurse(badSquareW, badSquareH, size, 0, 0);
	return 0;
}