#pragma once

#ifndef battleship_H
#define battleship_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // for printf and scanf
#include <stdlib.h> //for standard library
#include <math.h> //for math calculations
#include <time.h> //for random num gen
#include <string.h> //for my fav strings, which are really just arrays of characters ending in a null character
#define MAX_ROWS 10
#define MAX_COLS 10 
#define VALID 1
#define INVALID 0



//FUNCTIONS
void display_title(FILE *infile);
void display_welcome_screen(void);
void init_board(char board[][MAX_COLS], int num_rows, int num_cols);
void print_p1_board(char board[][MAX_COLS], int num_rows, int num_cols);
int who_starts(void);
void man_place_ships(char board[][MAX_COLS], int rows, int cols);
void auto_place_ships(char board[][MAX_COLS], int rows, int cols);
void print_p2_board(char board[][MAX_COLS], int rows, int cols);
int check_shot(char board[][MAX_COLS], int target_row, int target_col, char *target_ship);
int update_board(int shot);
int display_board(int flag);




#endif