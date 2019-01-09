// Grid class

class Grid
{

public:
	// public static class constants, for direction indicators
	static const int NORTH = 0; // if 
	static const int WEST = 1;
	static const int SOUTH = 2;
	static const int EAST = 3;

	// public member funcitons

	Grid();			// build 1 x 1 grid with mover in only
					//  square, facing east
	Grid(int r, int c);		// build grid with r rows, c cols,
							//  blocks around edge with random exit
							//  and random mover position and direction

	Grid(int r, int c, int mr, int mc, int d);
	bool PlaceBlock(int r, int c);	// put a block at (r,c), if possible
	void PutDown();		// put down an item at the mover's position
	bool PutDown(int r, int c);  // put down an item at (r,c), if possible
	void Display() const;	// display the grid on screen
	void TurnLeft();		// turn the mover to the left
	bool Move(int s);		// move forward s spaces, if possible
	bool FrontIsClear() const;	// check to see if space in front of 
								//  mover is clear
	bool RightIsClear() const;	// check to see if space to right of 
								//  mover is clear
	void TogglePath();		// toggle whether or not moved path is shown

	int GetRow() const;		// return row of the mover
	int GetCol() const;		// return column of the mover
	int GetNumRows() const;	// return number of rows in the grid
	int GetNumCols() const;	// return number of columns in the grid
	bool PickUp();		// pick up item at current position
	void Grow(int gr, int gc);	// grow the grid by gr rows, gc columns
								/*
								// build empty grid with r rows, c cols, and mover
								//  at row mr, col mc, and facing direction d









								*/
private:
	char grid[40][40];
	int rows;
	int columns;
	char mover;
	int moverrowindex;
	int movercolumnindex;
	int blockcolumntrack;
	int blocktrackrow;
	int direction;
	bool path; //initialize in the constructor



};


