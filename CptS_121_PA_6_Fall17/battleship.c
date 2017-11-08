#include "battleship.h"


//Create a function welcome_screen() that displays an initial program welcome message along with the rules of Battleship.
void display_title(FILE *infile)
{
	//char print_title[SIZE];
	if (infile)
	{
		int i = 0;
		do
		{
			putchar(i);
		} while (i = getc(infile) != EOF);
	}

	/*do
	{
	fgets(print_title, sizeof(print_title), infile) != NULL)
	printf("%s")
	}while (!EOF)*/
}

void display_menu(void)
{
	int choice = 0;

	do {
		printf("\nWelcome to BATTLESHIP!!!\n\n");
		printf("The the exciting game of war where you blow up ships and stuff....\n\n");
		printf("What about Non-Stop, though?");
		printf("Enter a number below...\n");
		printf("1. Print the Game Rules.\n2. Play game.\n3. Exit game.\n\n");

		scanf("%d", &choice);

		if (choice == 1)
			display_rules();
		else if (choice == 2)
			play_game();
		else if (choice == 3)
			printf("If this is Opposite Day, wouldn't it be \"badbye?\"\n\n\n");

	} while (choice != 3);

}

void display_welcome_screen(void)
{

	printf("\nWelcome to BATTLESHIP!!!\n\n");

	printf("The the exciting game of war where you blow up ships and stuff....\n\n");
	printf("What about Non-Stop, though?\n\n");

	printf("\nThe Rules of Battleship! :\n\n");

	printf("Once the game board has been initilized you and your opponent will take turns",
			"calling out one shot per turn to try and hit eachothers's ships.", 
			"On your turn you must pick a target hole on the screen using the coordinate system", 
			"blah blah write the rest of this later\n\n");
}

//Create a function initialize_game_board() that sets each cell in a game board to '-'.

// initialize the game board to water ('~') symbols
void init_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

//prints the game board GRID!
void print_p1_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			//board[row_index][col_index] = '~';
			printf("%c ", board[row_index][col_index]);
		}
		putchar('\n');
	}
}

void print_p2_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			//board[row_index][col_index] = '~';
			printf("%c ", board[row_index][col_index]);
		}
		putchar('\n');
	}
}
//Create a function select_who_starts_first() that determines if Player1 or Player2 goes first in the game.
int who_starts(void)
{
	//srand(time(NULL));
	int coin = 0;
	
	printf("Here comes the coin flip...who will start first....\n\n");
	coin = rand() % 2 + 1;
	printf("It looks like Player %d goes first! The crowd goes wild!", coin);

	return coin;
}

//Create a function manually_place_ships_on_board() that allows the user to place each of the 5 types of ships on his / her game board.
void man_place_ships(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row = 0, col = 0; //ship_size = 0;
	char dir = '\0'; //ship_type = '\0';

	printf("\nOk, let's place your ships!\n");
	
	//print game board function here

	/////////////////////////////////////////////////////////////
	//For Carrier

	printf("Let's place your Carrier...\n"); //placing carrier
	//ship_type = 'c';
	//ship_size = 5;
	printf("Choose your ship alignment.\n");
	printf("Enter either \"H\" for horizontal or \"V\" for vertical placement. \n");
	scanf("%c ", &dir);

	if ((dir == 'H') || (dir == 'h')) //direction if statement
	{
		
		do
		{
			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column. \n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row < 0) || (row > 9) || (col < 0) || (col >= 6));
		
		for (int i = 0; i < 5; ++i)
		{
			board[row + i][col] = 'c';
		}
	}

	else if ((dir == 'V') || (dir == 'v')) //direction if statement
	{
		do
		{
		
			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column:  \n");
			printf("Remember not to place your ship out of bounds!\n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row >= 6) || (row < 0) || (col > 0) || (col > 9));
		
		for (int i = 0; i < 5; ++i)
		{
			board[row + i][col] = 'c';
		}
	}


	///////////////////////////////////////////////////////////
	//For Battleship
	printf("Let's place your Battleship...\n"); //placing carrier
											 //ship_type = 'c';
											 //ship_size = 5;
	printf("Choose your ship alignment.\n");
	printf("Enter either \"H\" for horizontal or \"V\" for vertical placement. \n");
	scanf("%c ", &dir);

	if ((dir == 'H') || (dir == 'h')) //direction if statement
	{

		do
		{
			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column. \n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row < 0) || (row > 9) || (col < 0) || (col >= 7));

		for (int i = 0; i < 4; ++i)
		{
			board[row + i][col] = 'b';
		}
	}

	else if ((dir == 'V') || (dir == 'v')) //direction if statement
	{
		do
		{

			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column:  \n");
			printf("Remember not to place your ship out of bounds!\n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row >= 7) || (row < 0) || (col > 0) || (col > 9));

		for (int i = 0; i < 4; ++i)
		{
			board[row + i][col] = 'b';
		}
	}

	///////////////////////////////////////////////////////////
	//For Cruiser
	printf("Let's place your Carrier...\n"); //placing carrier
											 //ship_type = 'c';
											 //ship_size = 5;
	printf("Choose your ship alignment.\n");
	printf("Enter either \"H\" for horizontal or \"V\" for vertical placement. \n");
	scanf("%c ", &dir);

	if ((dir == 'H') || (dir == 'h')) //direction if statement
	{

		do
		{
			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column. \n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row < 0) || (row > 9) || (col < 0) || (col >= 8));

		for (int i = 0; i < 3; ++i)
		{
			board[row + i][col] = 'r';
		}
	}

	else if ((dir == 'V') || (dir == 'v')) //direction if statement
	{
		do
		{

			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column:  \n");
			printf("Remember not to place your ship out of bounds!\n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row >= 8) || (row < 0) || (col > 0) || (col > 9));

		for (int i = 0; i < 3; ++i)
		{
			board[row + i][col] = 'r';
		}
	}

	///////////////////////////////////////////////////////////
	//For Submarine
	printf("Let's place your Carrier...\n"); //placing carrier
											 //ship_type = 'c';
											 //ship_size = 5;
	printf("Choose your ship alignment.\n");
	printf("Enter either \"H\" for horizontal or \"V\" for vertical placement. \n");
	scanf("%c ", &dir);

	if ((dir == 'H') || (dir == 'h')) //direction if statement
	{

		do
		{
			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column. \n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row < 0) || (row > 9) || (col < 0) || (col >= 8));

		for (int i = 0; i < 3; ++i)
		{
			board[row + i][col] = 's';
		}
	}

	else if ((dir == 'V') || (dir == 'v')) //direction if statement
	{
		do
		{

			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column:  \n");
			printf("Remember not to place your ship out of bounds!\n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row >= 8) || (row < 0) || (col > 0) || (col > 9));

		for (int i = 0; i < 3; ++i)
		{
			board[row + i][col] = 's';
		}
	}

	///////////////////////////////////////////////////////////
	//For Destroyer
	printf("Let's place your Destroyer...\n"); //placing carrier
											 //ship_type = 'c';
											 //ship_size = 5;
	printf("Choose your ship alignment.\n");
	printf("Enter either \"H\" for horizontal or \"V\" for vertical placement. \n");
	scanf("%c ", &dir);

	if ((dir == 'H') || (dir == 'h')) //direction if statement
	{

		do
		{
			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column. \n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row < 0) || (row > 9) || (col < 0) || (col >= 9));

		for (int i = 0; i < 2; ++i)
		{
			board[row + i][col] = 'd';
		}
	}

	else if ((dir == 'V') || (dir == 'v')) //direction if statement
	{
		do
		{

			printf("Ok, now let's place your ship and remember not to place it out of bounds!\n");
			printf("\nEnter starting Column:  \n");
			printf("Remember not to place your ship out of bounds!\n");
			scanf("%d", &col);

			printf("\nEnter starting Row: \n");
			scanf("%d", &row);

		} while ((row >= 9) || (row < 0) || (col > 0) || (col > 9));

		for (int i = 0; i < 2; ++i)
		{
			board[row + i][col] = 'd';
		}
	}


}

void auto_place_ships(void)
{

}





//Create a function randomly_place_ships_on_board() that randomly places the 5 types of ships on a given board.







//Create a function check_shot() that determines if the shot taken was a hit or a miss.
//Create a function is_winner() that determines if a winner exists.
//Create a function update_board() that updates the board every time a shot is taken. '*' indicates a hit and 'm' indicates a miss.
//Create a function display_board() that displays a board to the screen.Note that Player1's board should be displayed differently than Player2's board(see above).
//Hint: pass in a flag(int) that stores whether or not you just passed in Player1's or Player2's board.Then perform the different logic for Player1's board versus Player2's board.
//Create a function output_current_move() that writes the position of the shot taken by the current player to the log file.It also writes whether or not it was a hit, miss, and if the ship was sunk.
//Create a function check_if_sunk_ship() that determines if a ship was sunk.
//Create a function output_stats() that writes the statistics collected on each player to the log file.
//Other functions that you think are necessary!
//A main function that does the following :
//		Opens an output file battleship.log for writing;
//		Simulates the game of Battleship
//		Outputs data to logfile
//		Outputs stats to logfile
//		Closes logfile