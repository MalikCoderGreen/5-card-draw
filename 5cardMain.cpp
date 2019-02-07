#include "deck.h"
#include "card.h"
#include "pokerPlayer.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

/*
Author: Maliak Green.
Creation Date: 9/28/18
Last Update: 10/12/18
Description: Object Oriented Programming used to create a simulation of the "5 card draw" poker game. The game will allow
between 2 - 6 players.
Notes:
*/



void menu(int &players)
{
  std::cout << "|| *** Welcome to 5 CARD DRAW *** ||" << std::endl;
  std::cout << "This poker game will deal each player a hand of 5 cards. Depending on who\n"
  << "has the best hand, the pot will be awarded to the player and the round is over.\n";

  std::cout << "How many players will you be playing with? (choose from 2-6): ";
  std::cin >> players;

  // Input validation.
  if(players < 2 || players > 6)
  {
    while(players < 2 || players > 6)
    {
      std::cout << "Please enter in a valid number of players for the game: ";
      std::cin >> players;
    }
  }
}



int main()
{

deck playingD; // Deck for the game.
playingD.shuffleDeck(); // Shuffle before cards are dealt.

int players; // Number of players the user wants to play with.
int top = 0; // Top "card" of deck.
char choice;

pokerPlayer dealer; // Dealer object for poker players.

pokerPlayer *Game;

do
{

menu(players);
Game = new pokerPlayer[players]; // Array of n players.


std::cout << "\n\n";
std::cout << "Alright... lets get started!\n";
std::cout << "Game is set for " << players << " players\n\n\n";

dealer.oneRoundOf5(Game, playingD, top, players); // Begin game.

// Once round is over.
std::cout << "Would you like to play again? (y/n)  : ";
std::cin >> choice;




}while(choice == 'y');



  return 0;
}
