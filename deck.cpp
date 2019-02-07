#include"card.h"
#include"deck.h"
#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>

/*
Author: Maliak Green.
Creation Date: 9/10/18
Last Update: 10/12/18
Description: Object Oriented Programming used to create a class of type "card" and "deck" which implements
real-world functionality such as shuffling a deck or comparing two cards.
Notes: the deck of card objects in the .h was made public for the comparison in the main program.
*/

// Default constructor populates deck in order given in lab instructions.
deck::deck()
{

 int cardCounter = 0;// Counter for numbered cards either than A, J, Q, or K.

for(int i = 0; i <= 52; i++)
{



  if(i < 13)// First suit condition.
  {
    if(i == 0)// First card.
    {
    playDeck[i].setCard("A", 'D');
    }
    else
    {
      cardCounter = i + 1;// Reset card counter for new deck.
      if(cardCounter == 11)// Jack for 11.
      {
        playDeck[i].setCard("J",'D');
      }
      else if(cardCounter == 12)// Queen for 12.
      {
        playDeck[i].setCard("Q",'D');
      }
      else if(cardCounter == 13)// King for 13.
      {

        playDeck[i].setCard("K", 'D');
      }
      else // Numbered cards.
      {

        playDeck[i].setCard(std::to_string(cardCounter), 'D');

      }

    }
  }

else if (i >= 13 && i < 26)// Second suit.
{

  if(i == 13)
  {
  playDeck[i].setCard("A", 'C');
  }
  else
  {
    cardCounter = i + 1 - 13;

      if(i == 23)
      {
        playDeck[i].setCard("J",'C');
      }
      else if(i == 24)
      {
        playDeck[i].setCard("Q",'C');
      }
      else if(i == 25)
      {
        cardCounter = 2;
        playDeck[i].setCard("K", 'C');
      }
      else
      playDeck[i].setCard(std::to_string(cardCounter), 'C');
    }
  }

else if(i >= 26 && i < 39)//third suit.
{
  if(i == 26)
  {
    playDeck[i].setCard("A",'H');
  }
  else
  {
    cardCounter = i + 1 - 26;
    if(i == 36)
    {
      playDeck[i].setCard("J", 'H');
    }
    else if(i == 37)
    {
      playDeck[i].setCard("Q", 'H');
    }
    else if(i == 38)
    {
      playDeck[i].setCard("K", 'H');
    }
    else
    playDeck[i].setCard(std::to_string(cardCounter), 'H');
  }
}
else if(i >= 39)// Fourth suit.
{

   if(i == 39)
    playDeck[i].setCard("A", 'S');

  else
  {
    cardCounter = i + 1 - 39;
    if(i == 49)
    {
      playDeck[i].setCard("J",'S');
    }
    else if(i == 50)
    {

      playDeck[i].setCard("Q", 'S');
    }
    else if(i == 51)
    {
    playDeck[i].setCard("K", 'S');

  }
    else
    playDeck[i].setCard(std::to_string(cardCounter), 'S');
  }
}

}
}


// Function uses card class getter functions to display card contents.
void deck :: displayDeck()
{
  for(int i = 0; i < 52; i++)
  {
    std::cout<<playDeck[i].getValue() << playDeck[i].getSuit() << " pos: " << i <<std::endl;
  }
}

void deck::shuffleDeck()
{
  srand(time(0)); // Seed for random cards.
  card tmp;// Temporary card object to be swapped.

  for(int i = 0; i < 52; i++)
  {
    int r = i + rand() % 52 - i;

    tmp = playDeck[i];
    playDeck[i] =  playDeck[r];
    playDeck[r] = tmp;
  }
}


card deck::getCard(int &top)
{
  card c = playDeck[top];
  return c;
}


card deck::dealCard(int &top)
{

card c = playDeck[top]; // Card to be dealt.
 // Move next card.
 top++;
return c;
}
