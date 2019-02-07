
#ifndef DECK_H
#define DECK_H
#include"card.h"
/*
Author: Maliak Green.
Creation Date: 9/10/18
Last Update: 9/17/18
Description: Object Oriented Programming used to create a class of type "card" and "deck" which implements
real-world functionality such as shuffling a deck or comparing two cards.
Notes: the deck of card objects in the .h was made public for the comparison in the main program.
*/
class deck
{
private:
  card playDeck[52]; // Card object array of 52 cards.


public:
  deck(); // Default populates deck with predetermined order.

  void displayDeck(); // Shows contents of cards.
  void shuffleDeck();
  card dealCard(int&); // Function for dealing cards to user hand.
  card getCard(int&); // Function for obtaining a card from the deck.
  int getStack();

};
#endif
