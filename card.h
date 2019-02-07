#ifndef CARD_H
#define CARD_H
#include<string>
/*
Author: Maliak Green.
Creation Date: 9/10/18
Last Update: 9/17/18
Description: Object Oriented Programming used to create a class of type "card" and "deck" which implements
real-world functionality such as shuffling a deck or comparing two cards.
Notes: the deck of card objects in the .h was made public for the comparison in the main program.
*/

// Class structure for card object.
class card
{
private:

  std::string value; //String such as A, 2, 3...
  char suit; // Suits H, D, C, S.

public:
  card(); //Default ace of spades.
  card(std::string, char); //Non-default specified by programmer.
  void displayCard(); //Display object contents.
  bool equal(card); //Check if two cards are equal.
  void setCard(std::string, char);
  std::string getValue(); //Get the value of a card object.
  char getSuit(); //Get the suit of a card object.
  friend std::ostream &operator<<(std::ostream &strm,  const card &right);
};
#endif
