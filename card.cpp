#include"card.h"
#include"deck.h"
#include<iostream>
#include<string>

/*
Author: Maliak Green.
Creation Date: 9/10/18
Last Update: 10/12/18
Description: Object Oriented Programming used to create a class of type "card" and "deck" which implements
real-world functionality such as shuffling a deck or comparing two cards.
Notes: the deck of card objects in the .h was made public for the comparison in the main program.
*/

card :: card()
{
 value = 'A';
 suit = 'S';
}

card::card(std::string val, char suitMain)
{
  value = val;
  suit = suitMain;
}

void card::displayCard()
{
  std::cout << value << suit << " ";
}

bool card::equal(card nextC)
{
  //use this to refer to calling object.
  if(this->value == nextC.value && this->suit == nextC.suit)
    return true;

    return false;
}

//to be used by card objects in decks.
void card::setCard(std::string val, char suitCpp)
{
  value = val;
  suit = suitCpp;

}

std::string card::getValue()
{
  return this->value;
}

char card::getSuit()
{
  return this->suit;
}


std::ostream &operator<<(std::ostream &strm,  const card &right)
{
  strm << right.value << right.suit;

  return strm;
}
