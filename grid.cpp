#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <iomanip>
#include "grid.h"
using namespace std;
Grid::Grid()
{
	path = true;
	rows = 1;
	columns = 1;
	grid[rows][columns];
	mover = '>';
	grid[0][0] = mover;

}
Grid::Grid(int r, int c)
{
	path = true;
	srand((unsigned int)time(0));
	if (r < 3 || c < 3)
	{
		r = 3;
		c = 3;
	}
	if (r > 40 || c > 40)
	{
		r = 40;
		c = 40;
	}
	rows = r;
	columns = c;


	for (int i = 0; i < r; i++)    //rows
		for (int j = 0; j < c; j++) //columns.
		{

			if (i == 0 || i == r - 1 || j == 0 || j == c - 1) // first and last of c and r
			{
				grid[i][j] = '#';
				//random wall between 1-4 // pick edge /// rand() % 4 + 1; 
				//cannot be a corner
			}
			else
			{
				grid[i][j] = '.'; //initialize all as dots, get whatever characters you need to put inside 
			}
		}
	int temp = rand() % 4; // 0 - 3 //NESW //random number tells what border youre in, there, extract what number goes with the border // temp = 0; //columns -1 // east temp on the right 
	int yes = rand() % (columns - 2) + 1; //exit randomization for grid
	int no = rand() % (rows - 2) + 1; //exit row randomization for grid
	
	/* each has this content
		grid[rows - 1][yes] = ' ';//last row, //random column + 1 // this is okay
		int randmoverrow = rand() % (rows - 2) + 1; //exit randomization for grid
		int randcolumn = rand() % (columns - 2) + 1;  //exit row randomization for grid 
		moverrowindex = randmoverrow;
		movercolumnindex = randcolumn; 
		*/ 
		if (temp == EAST)
		{
			grid[no][columns-1] = ' ';

			int randmoverrow = rand() % (rows - 2) + 1; //exit randomization for grid
			int randcolumn = rand() % (columns - 2) + 1;  //exit row randomization for grid 
			moverrowindex = randmoverrow;
			movercolumnindex = randcolumn;

			mover = '>';
			grid[moverrowindex][movercolumnindex] = mover;
			direction = EAST;
			
		}

		//update the other cpp

		else if (temp == WEST)
		{
			grid[no][0] = ' ';

			int randmoverrow = rand() % (rows - 2) + 1; //exit randomization for grid
			int randcolumn = rand() % (columns - 2) + 1;  //exit row randomization for grid 
			moverrowindex = randmoverrow;
			movercolumnindex = randcolumn;

			mover = '^';
			grid[moverrowindex][movercolumnindex] = mover;
			direction = WEST;
	}
	else if (temp == NORTH)
	{
		grid[0][yes] = ' ';
		int randmoverrow = rand() % (rows - 2) + 1; //exit randomization for grid
		int randcolumn = rand() % (columns - 2) + 1;  //exit row randomization for grid 
		moverrowindex = randmoverrow;
		movercolumnindex = randcolumn;
		grid[moverrowindex][movercolumnindex] = '^';
		direction = NORTH;
		mover = '^';
		grid[moverrowindex][movercolumnindex] = mover;
	
	}
	else if (temp == SOUTH)
	{
		grid[no][columns - 1] = ' ';
		int randmoverrow = rand() % (rows - 2) + 1; //exit randomization for grid
		int randcolumn = rand() % (columns - 2) + 1;  //exit row randomization for grid 
		moverrowindex = randmoverrow;
		movercolumnindex = randcolumn;
		mover = 'v';
			grid[moverrowindex][movercolumnindex] = mover;
		direction = SOUTH;

	}
}
	void Grid::Display() const	// display the grid on screen; togglepath is accounted for already.
	{
		cout << "The Grid: " << endl;
	for (int i = 0; i < rows; i++)    //This loops on the rows.
	{
		for (int j = 0; j < columns; j++)
		{
			
			if (path == false && grid[i][j] == ' ')
			{
				cout << '.' << " ";
			}
			else 
				cout << grid[i][j] << " ";
		}

		cout << endl;
	}
	

}

Grid::Grid(int r, int c, int mr, int mc, int d)
{
	path = true;
	
	if (r < 1 || c < 1)
	{
		r = 1;
		c = 1;
	}
	if (r > 40 || c > 40)
	{
		r = 40;
		c = 40;
	}
	rows = r;
	columns = c;
	for (int i = 0; i < r; i++)
	{

	for (int j = 0; j < c; j++) //columns.
	{
			grid[i][j] = '.'; //initialize all as dots, get whatever characters you need to put inside 
	}
	}


	if (mr > r-1)
	{
		int temp = r / 2; //12 / 2
		if (mr > temp)
		{
			mr = r - 1;
		}
		else
			mr = r - (r-1);
	}
	if (mc > c - 1)
	{
		int jemp = c / 2; //12 / 2
		if (mc > jemp)
		{
			mc = c - 1;
		}
		else
			mc = c - (c - 1);
	}
	moverrowindex = mr;
	movercolumnindex = mc;



	if (d == NORTH)
	{
		mover = '^'; 
		direction = d;
	}
	if (d == WEST)
	{
		mover = '<';
		direction = d;
	}
	if (d == EAST)
	{
		mover = '>';
		direction = d;
	}
	if (d == SOUTH)
	{
		mover == 'v';
		direction = d;
	}

	grid[moverrowindex][movercolumnindex] = mover;
	

}
bool Grid::PlaceBlock(int r, int c)
{
	if (r < 0 || c < 0)
	{
		return false;
	}
	if (r > rows || c > columns)
	{
		return false;
	}
	if (grid[r][c] == mover || grid[r][c] == '0' || grid[r][c] == '#')
		return false;
	else 
	{
		grid[r][c] = '#';
		return true;
	}


}
void Grid::PutDown()
{
	grid[moverrowindex][movercolumnindex] = '0';
	if (grid[moverrowindex][movercolumnindex] == '0')
	{
		grid[moverrowindex][movercolumnindex] = '@';
	}
	

}
bool Grid::PutDown(int r, int c) 
{
	if (r > 40 || c > 40 || r < 0 || c < 0)
	{
		return false;
	}
	if (grid[r][c] == '0' || grid[r][c] == '#')
	{
		return false;
	}
	else
	{
		grid[r][c] = '0';
		return true;
	}



}
void Grid::TurnLeft()
{
	if (mover == '^' || direction == NORTH)
	{
		mover = '<';
		direction = WEST;
	//	grid[moverrowindex][movercolumnindex] = mover;
	}
	else if (mover == '>' || direction == EAST)
	{
		mover = '^';
		direction = NORTH;
	//	grid[moverrowindex][movercolumnindex] = mover;
	}
	else if (mover == 'v' || direction == SOUTH)
	{
		mover = '>';
		direction = EAST;
	//	grid[moverrowindex][movercolumnindex] = mover;
	}
	else if (mover == '<' || direction == WEST)
	{
		mover = 'v';
		direction = SOUTH;
		//grid[moverrowindex][movercolumnindex] = mover;
	}

}
bool Grid::Move(int s)
{
	bool check = true; // use for invalid indices
	bool wasitem = true;
	int temprowindex = moverrowindex; //save originals
	int tempcolumnindex = movercolumnindex; // save originals 
	if (s < 0) //error check the negative 
	{
		check = false;
	}

		for (int i = 0; i < s; i++)
		{ //could use switch	
			if (grid[moverrowindex][movercolumnindex] == '#') //error check
			{
				grid[moverrowindex][movercolumnindex] = grid[temprowindex][tempcolumnindex];
				check = false;
				break;
			}
			if (moverrowindex >= rows || movercolumnindex >= columns) //error check
			{
				grid[moverrowindex][movercolumnindex] = grid[temprowindex][tempcolumnindex];
				check = false;
				break; // leave the loop
			}
			if (path == true)
			{
				if (grid[moverrowindex][movercolumnindex] == '0' || grid[moverrowindex][movercolumnindex] == '@')
					grid[moverrowindex][movercolumnindex] = '0';
				else
					grid[moverrowindex][movercolumnindex] = ' ';
			}
			if (path == false)
			{
				if (grid[moverrowindex][movercolumnindex] == '0' || grid[moverrowindex][movercolumnindex] == '@')
					grid[moverrowindex][movercolumnindex] = '0';
			/*else
				{
					//grid[moverrowindex - i][movercolumnindex - i] = '.';
					
					for (int i = 0; i < rows; i++)
						for (int j = 0; j < columns; j++)
						{
							if (grid[i][j] == ' ')
								grid[i][j] = '.';
						} 
				} */
			}
			if (direction == SOUTH || mover == 'v')
			{
				moverrowindex = moverrowindex++;
			}
			if (direction == NORTH || mover == '^') //moving the mover
			{
				moverrowindex = moverrowindex--;

			}
			if (direction == WEST || mover == '<')
			{
				movercolumnindex = movercolumnindex--;
			}
			if (direction == EAST || mover == '>')
			{
				movercolumnindex = movercolumnindex++;
			}

		}
		
	if (check == false)
	{
		return false;
	}
	else
	{
		if (grid[moverrowindex][movercolumnindex] == '0')
		{
			grid[moverrowindex][movercolumnindex] = '@';
		}
		else
		grid[moverrowindex][movercolumnindex] = mover;
		
	}
		return true;
	}
bool Grid::FrontIsClear() const 
{
	if (direction == NORTH)
	{
		int checkrow = moverrowindex - 1;
		if (grid[checkrow][movercolumnindex] == '#')
		{
			return false;
		}
		else
			return true;
	}
	if (direction == SOUTH)
	{
		int checksouthrow = moverrowindex + 1;
		if (grid[checksouthrow][movercolumnindex] == '#')
		{
			return false;
		}
		else
			return true;
	}
		if (direction == EAST)
		{
			int checkeastcolumn = movercolumnindex + 1;
			if (grid[moverrowindex][checkeastcolumn] == '#')
			{
				return false;
			}
			else
				return true;
		}
		if (direction == WEST)
		{
			int checkwestcolumn = movercolumnindex - 1;
			if (grid[moverrowindex][checkwestcolumn] == '#')
			{
				return false;
			}
			else
				return true;
		}
		//return true;
	}


bool Grid::RightIsClear() const 
{
	if (direction == NORTH)
	{
		int checkeastcolumn = movercolumnindex + 1;
		if (grid[moverrowindex][checkeastcolumn] == '#')
		{
			return false;
		}		
	}
	if (direction == SOUTH)
	{ //uses right direction coordinates
		
		
		int checkwestcolumn = movercolumnindex - 1;
		if (grid[moverrowindex][checkwestcolumn] == '#')
		{
			return false;
		}
	}
		if (direction == EAST)
		{
			int checksouthcol = moverrowindex + 1;
			if (grid[checksouthcol][movercolumnindex] == '#')
			{
				return false;
			}
			
		}
		if (direction == WEST)
		{
		int checkrow = moverrowindex - 1;
		if (grid[checkrow][movercolumnindex] == '#')
		{
			return false;
		}
		}
		return true;
	}
void Grid::TogglePath()
{
	if (path == true) //if on
	{
		path = false;
		Move(0);
	}
	else {
		path == false;
			path = true; //changes off to on 
			Move(0);
	}

}
int Grid::GetRow() const
{
	return moverrowindex;
}
int Grid::GetCol() const
{
	return movercolumnindex;
}
int Grid::GetNumRows() const
{
	return rows;
}
int Grid::GetNumCols() const
{
	return columns;
}
bool Grid::PickUp()
{
	if (grid[moverrowindex][movercolumnindex] == '0' || grid[moverrowindex][movercolumnindex] == '@')
	{
		grid[moverrowindex][movercolumnindex] = mover;
		return true;
	}
	else
		return false;
}
void Grid::Grow(int gr, int gc)
{
	rows = gr + rows;
	columns = gc + columns;

	if (rows > 40 || columns > 40)
	{
		rows = 40;
		columns = 40;
	}
	




}



