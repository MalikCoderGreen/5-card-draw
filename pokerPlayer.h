#ifndef POKERPLAYER_H
#define POKERPLAYER_H

#include"card.h"
#include"deck.h"
#include<cstdlib>
#include<ctime>
#include<string>

/*
Author: Maliak Green.
Creation Date: 9/28/18
Last Update: 10/12/18
Description: .h file that includes all methods of the poker game along with operator overloads.
Notes: uses updated deck and card classes in implementation.
*/



class pokerPlayer
{
private:
card hand[5]; // Hand dealt to user as array of cards.
std::string handType; // Type of poker hand.
long long int rank; // Rank of player hand.
int bestValue; // The highest ranking card in the hand.

public:
  pokerPlayer(); // Default constructor.
  pokerPlayer(deck, int&); // Cards passed into constructor to fill hand from deck object.
  ~pokerPlayer();
  void printPokerPlayer(); // Print the player's current status.
  void oneRoundOf5(pokerPlayer*, deck, int&, int); // Function for poker game.
  void checkHand(int[], pokerPlayer*, int); // Check the values of the players hands.
  std::string determineHand(int, pokerPlayer*); // Determine the type of hand each player has.
  void rankHands(pokerPlayer*, int); // Rank hand of each poker player.
  int whoWins(pokerPlayer*, int); // Determines which player wins.

  // Operator overloads for logical comparisons.
  bool operator>(const pokerPlayer &right);
  bool operator<(const pokerPlayer &right);
  bool operator==(const pokerPlayer &right);
};

#endif
