/*********************************************************************************
* Programmer: Michael Smith														 *
* Class CptS 121, Fall 2017; Lab Section 21										 *
* Programming Assignment: PA6													 *
* Date: November 4, 2017														 *
* Description: This program simulates a Player vs Computer game of battleship 	 *
**********************************************************************************/
#include "battleship.h"





int main(void)
{
	//time seed for ran gen
	srand(time(NULL));


	// Opens an input file "title.txt" for reading;
	FILE *infile = NULL;

	//opening infile for reading stream
	infile = fopen("title.txt", "r");

	//display ASCII Title
	display_title(infile);

	//closes file
	fclose(infile);

	//display welcome screen
	display_welcome_screen();

	//displays menu
	display_menu();


	return 0;
}




