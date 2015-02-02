/*
*  File    : nim.c
*  Program : Nim game
*  Author  : ...
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>     

#define _CRT_SECURE_NO_WARNINGS
#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

int human_choice(int pile);
void write_winner(int player);
int play_again();
int computer_choice(int pile);
int toggle(int player);
void clear_stdin();

/***************************************************
*
*    MAIN
*
***************************************************/
int main()
{
	int pile,			/* This is how many coins we have */
		player,			/* Who is playing? */
		n_coins;			/* Number of coins taken */

	srand(time(0));		/* Setup random */

	printf("Välkommen till NIM by ...");


	do {

		pile = MAX_COINS;		/* Set start values (= init) */
		player = HUMAN;

		/*
		*  Program main loop
		*/
		while (true) {

			printf("Det ligger %d  mynt i högen\n", pile);

			if (player == HUMAN) {
				n_coins = human_choice(pile);
			}
			else {
				n_coins = computer_choice(pile);
				printf("- Jag tog %d\n", n_coins);
			}
			pile -= n_coins;
			if (pile <= 1) {
				break;
			}
			player = toggle(player);

		}
		/*
		* end main loop
		*/

		write_winner(player);
	} while (play_again());

	printf("Avslutat\n");

	return 0;
}

/******************************************************
*
*  DEFINITIONS
*
******************************************************/


void clear_stdin()
{
	while (getchar() != '\n') {
		;
	}
}

/*
* human_choice
* Get human choce as an int from stdin.
* Clears stdin.
* in: pile
* out: int-value in range 1-3 (and also less than pile)
*/
int human_choice(int pile)
{
	while (1) {
		int choice;
		scanf_s("%d", &choice);
		clear_stdin();
		if (choice > 0 && choice < 4 && choice <= pile)
			return choice;
		printf("Wrong pick, try again");
	}
	return 0;
}

/*
* computer_choice
* Get computers choice (including some AI,
* if 4 coins or less left, function makes a
* smart choice else random).
* in: pile
* out: int-value in range 1-3 (and also less than pile)
*/
int computer_choice(int pile)
{
	if (pile > 4) {
		return 1 + rand() % 3;
	}
	else {
		return pile - 1;
	}

}
/*
* write_winner
* Write winner as a string on stdout.
* in: Values HUMAN or COMPUTER.
* out:
*/
void write_winner(int player)
{
	if (player == HUMAN) {
		printf("HUMAN won!\n");
	}
	if (player == COMPUTER) {
		printf("COMPUTER won!\n");
	}
}

/*
* play_again
* Ask human if he/she wants to play
* another round. If 'n' or 'N' selected
* (single char) return false else true.
* Clears stdin.
* in:
* out: true or false
*/
int play_again()
{
	char c;
	printf("Do you want to play again?");
	scanf_s("%c", &c);
	clear_stdin();
	if (c == 'n' || c == 'N')
		return 0;
	return 1;
}

/*
* toggle
* Switches player, if HUMAN in COMPUTER out
* etc.
* in:  actual player
* out: next player
*/
int toggle(int player)
{
	return 1 - player;
}
