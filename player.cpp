#include"pokerPlayer.h"
#include"deck.h"
#include"card.h"
#include<cstdlib>
#include<iostream>
#include<ctime>
#include<string>
#include<string.h>

/*
Author: Maliak Green.
Creation Date: 9/28/18
Last Update: 10/12/18
Description: Object Oriented Programming used to create a simulation of the "5 card draw" poker game. The game will allow
between 2 - 6 players.
Notes:
*/



pokerPlayer::pokerPlayer()
{
  rank = 0;
  bestValue = 0;
}

/*
Description: Non-default constructor deals each player a hand of 5 cards.
Parameters: Playing deck pointer.
Return: None.
Notes: None.
*/

pokerPlayer::pokerPlayer(deck pDeck, int &top)
{
  // Fill hand of poker player object.
/*
    for(int i = 0; i < 5; i++)
    {
      hand[i] = pDeck.dealCard(top);
    }
*/
}

/*
Description: Class function handles the main functionality of the game using nested for loops.
Parameters: pokerPlayer pointer; deck object; Integer by refference; Integer for players.
Return: None.
Notes: None.
*/

void pokerPlayer::oneRoundOf5(pokerPlayer *Game, deck pDeck, int &top, int players)
{
  pokerPlayer access; // Object to help with other functions.
  // Nested for loop to deal cards to each player.
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < players; j++)
  {
    Game[j].hand[i] = pDeck.dealCard(top);
  }





  int cards2Draw = 0; // Amount of cards to replace if any.
  for(int i = 0; i < players; i++)
  {
    std::string res = access.determineHand(i, Game);
    std::cout << "Player " << i+1 <<": ";

     for(int j = 0; j < 5; j++) // Loop for displaying each player's hand.
      {
        Game[i].hand[j].displayCard(); // Display hand.
      }

    Game[i].handType = res; // Set type of hand equal to result.

    std::cout << "*** " << res << std::endl; // For next player's hand.
    std::cout <<"Input number of cards to draw (0-3): ";
    std::cin >> cards2Draw;

    // Input validation.
    if(cards2Draw < 0 || cards2Draw > 3)
    {
      while(cards2Draw < 0 || cards2Draw > 3)
      {
        std::cout << "Error. Please enter in a value between 0 - 3: ";
        std::cin >> cards2Draw;
      }
    }

    int draw[cards2Draw]; // To store positions.
    for(int k = 0; k < cards2Draw; k++) // Loop for replacing cards for each player.
    {
        int pos = 0;
        std::cout << "Card to replace (1-5) : ";
        std::cin >> pos;

        // Input validation.
        if(pos < 1 || pos > 5)
        {
          while(pos < 1 || pos > 5)
          {
            std::cout << "Please enter a valid card number (1-5): ";
            std::cin >> pos;
          }
        }

        // For loop to change cards.
        for(int l = 0; l < cards2Draw; l++)
        {
          // Input validation.
          if(pos == draw[l])
          {
            while(pos == draw[l])
            {
            std::cout << "You already chose that card. Please choose another: ";
            std::cin >> pos;
            }
          }
        }

        draw[k] = pos; // If position is valid.
        Game[i].hand[pos-1] = pDeck.dealCard(top); // Replace card(s) with remaining card(s) left in deck.
      }
  }

  // Display final hand of each player after card replacement.
  for(int i = 0; i < players; i++)
  {
    std::string res = access.determineHand(i, Game); // Get final result.
    handType = res; // Set hand's type to result.
    access.rankHands(Game, i); // Rank value of each player's hand.




    std::cout << "Player " << i+1 <<": ";

    for(int j = 0; j < 5; j++) // Display final hands.
    {
      Game[i].hand[j].displayCard();
    }
    std::cout << "*** " << res << " rank: " << Game[i].rank << std::endl; // Type of hand.
  }

  int winner = access.whoWins(Game, players); // Determine who won the game.

  // For loop to print the winner based on the winning iteration.
  for(int i = 0; i < players; i++)
  {
    if(i == winner)
    {
      std::cout << "Player " << i+1 <<" has won the round. \n";
      break;
    }
  }

}

/*
Description: Class function to determine if a player has a special type of hand.
Parameters: pokerPlayer object.
Return: None.
Notes: None.
*/

std::string pokerPlayer::determineHand(int i, pokerPlayer *Game)
{

  pokerPlayer access;
  int checker[13]; // Array to check the hand values.
  char sameSuit = hand[0].getSuit(); // Get suit for possible straight flush.
  int flush = 0; // Flush counter.

  access.checkHand(checker, Game, i); // Check values of hand.


// Royal Flush return.
if(checker[0] == 1 && checker[9] == 1 && checker[10] == 1 && checker[11] == 1 && checker[12] == 1)
{

  return "Royal Flush";
}

// For loop to check any sequence of 5 in the hand for a straight flush.
for(int i2 = 0; i < 13; i++)
  for(int j =  0; j < 5; j++)
{  if(checker[i2] == 1 && Game[i].hand[j].getSuit() == sameSuit)
  {
    if(checker[i2+1] == 1 && Game[i].hand[j+1].getSuit() == sameSuit)
    {
      if(checker[i2+2] == 1 && Game[i].hand[j+2].getSuit() == sameSuit)
      {
        if(checker[i2+3] == 1 && Game[i].hand[j+3].getSuit() == sameSuit)
        {
          if(checker[i2+4] == 1 && Game[i].hand[j+4].getSuit() == sameSuit)
          {

            return "Straight Flush";
          }
        }
      }
    }
  }
}

// For loop to check any sequence of 5 in the hand for a straight.
for(int i = 0; i < 13; i++)
{
  if(checker[i] == 1)
  {
    if(checker[i+1] == 1)
    {
      if(checker[i+2] == 1)
      {
        if(checker[i+3] == 1)
        {
          if(checker[i+4] == 1)
          {

            return "Straight";
          }
        }
      }
    }
  }
}

// For loop for four of a kind and three of a kind.
for(int i = 0; i < 13; i++)
{
  if(checker[i] == 4)
  {

    return "Four of a Kind";
  }
  else if(checker[i] == 3)
  {

    return "Three of a Kind";
  }
  else
    continue;
}


// Full House return.
 for(int i = 0; i < 13; i++)
    for(int j = 13; j > 0; j--)
    {
      if(checker[i] == 3 && checker[j] == 2)
      {

        return "Full House";
      }
    }


 // Flush for loop and if statment.
 for(int j = 0; j < 5; j++)
 {
   if(Game[i].hand[j].getSuit() == sameSuit)
    flush++;
 }

 if(flush == 5)
 {

  return "Flush";
}




// One pair.
int oP = 0; // Counter to check for only one pair.
bool oPP = false; // Switch for one pair.
for(int i = 0; i < 13; i++)
{
  if(checker[i] == 2) // If one pair is found.
  {
    oPP = true; // Switch is on.
    oP = i; // Iteration to be ignored.
  }
}
for(int i = 0; i < 13; i++)
{
  if(i == oP)
    oP = oP + 0; // Do nothing.

  else
    {
      if(checker[i] == 2) // If another one is found, one pair is false.
        {
          oP = 2;
          oPP = false;
        }
      }
}
if(oPP == true)
{ // Return one pair.

  return "One Pair";
}

// Two pair.
for(int i = 0; i < 13; i++)
    for(int j = 13; j > 0; j--)
     {
       if(checker[i] == 2 && checker[j] == 2) // Check from both sides of array.
       {
         return "Two Pair";
       }
     }

// Default.
return "High Card";

}

/*
Description: Class function to check how many of each card the user has.
Parameters: Integer array.
Return: None.
Notes: None.
*/

void pokerPlayer::checkHand(int checker[], pokerPlayer *Game, int i)
{
  for(int i = 0; i < 13; i++)
    checker[i] = 0;
 // For loop checkers which values the hand contains.
  for(int j = 0; j < 5; j++)
  {
    if(Game[i].hand[j].getValue() == "A")
      checker[0]++;

    else if(Game[i].hand[j].getValue() == "2")
      checker[1]++;

    else if(Game[i].hand[j].getValue() == "3")
      checker[2]++;

    else if(Game[i].hand[j].getValue() == "4")
      checker[3]++;

    else if(Game[i].hand[j].getValue() == "5")
      checker[4]++;

    else if(Game[i].hand[j].getValue() == "6")
      checker[5]++;

    else if(Game[i].hand[j].getValue() == "7")
      checker[6]++;

    else if(Game[i].hand[j].getValue() == "8")
      checker[7]++;

    else if(Game[i].hand[j].getValue() == "9")
      checker[8]++;

    else if(Game[i].hand[j].getValue() == "10")
      checker[9]++;


    else if(Game[i].hand[j].getValue() == "J")
      checker[10]++;


    else if(Game[i].hand[j].getValue() == "Q")
      checker[11]++;


    else if(Game[i].hand[j].getValue() == "K")
      checker[12]++;
    else
      continue;
}

int max = 0; // Max value the player has in their hand.
for(int i = 0; i < 13; i++)
    max += checker[i]; // Keep reseting until the last box is checked.


Game[i].bestValue = max; // Assign that to the player.
Game[i].rank += bestValue; // For precise hand ranks.

}
/*
Description: Class function to determine who wins the round out of all players.
Parameters: None.
Return: None.
Notes: None.
*/

void pokerPlayer::rankHands(pokerPlayer *Game, int i)
{
  if(Game[i].handType == "Royal Flush")
    Game[i].rank += 9,223,372,036,854,775,807;

  else if(Game[i].handType == "Straight Flush")
    Game[i].rank += 9,000,000,000,000,000,000;

  else if(Game[i].handType == "Four of a Kind")
    Game[i].rank += 8,000,000,000,000,000,000;

  else if(Game[i].handType == "Full House")
    Game[i].rank += 7,000,000,000,000,000,000;

  else if(Game[i].handType == "Flush")
    Game[i].rank += 6,000,000,000,000,000,000;

  else if(Game[i].handType == "Straight")
    Game[i].rank += 5,000,000,000,000,000,000;

  else if(Game[i].handType == "Three of a Kind")
    Game[i].rank+= 4,000,000,000,000,000,000;

  else if(Game[i].handType == "Two Pair")
    Game[i].rank += 3,000,000,000,000,000,000;

  else if(Game[i].handType == "One Pair")
    Game[i].rank += 2,000,000,000,000,000,000;

  else if(Game[i].handType == "High Card")
    Game[i].rank += 1,000,000,000,000,000,000;

  else
    Game[i].rank = 0;

}

/*
Description: Class function that determines which player wins the round.
Parameters: Const pokerPlayer hand by refference.
Return: Bool either true or false.
Notes: None.
*/

int pokerPlayer::whoWins(pokerPlayer *Game, int players)
{
  int iWinner = 0; // Winner determined by iteration.
  pokerPlayer bestHand; // Hand to act as a max value.
  for(int i = 0; i < players; i++)
  {
    if(bestHand < Game[i]) // Get the best hand value.
    {
      iWinner = i;
      bestHand.rank = Game[i].rank;
      std::cout << "Player " << i+1 << " has the best rank of " << bestHand.rank << std::endl;
    }

    /*    else if(bestHand == Game[i])
    {
      if(bestHand.bestValue < Game[i].bestValue)
      {
        iWinner = i;
        bestHand.rank = Game[i].rank;
      std::cout << "Player " << i+1 << " has the best rank of " << bestHand.rank << std::endl;

      }
      else
      continue;
    }
    */

    else
    continue;

  }


return iWinner;
}

/*
Description: Operator overload on > for hand comparison.
Parameters: Const pokerPlayer hand by refference.
Return: Bool either true or false.
Notes: None.
*/

bool pokerPlayer::operator>(const pokerPlayer &hand)
{
  return(rank > hand.rank);
}

/*
Description: Operator overload on < for hand comparison.
Parameters: Const pokerPlayer hand by refference.
Return: Bool either true or false.
Notes: None.
*/


bool pokerPlayer::operator<(const pokerPlayer &hand)
{
  return(rank < hand.rank);
}

/*
Description: Operator overload on == for hand comparison.
Parameters: Const pokerPlayer hand by refference.
Return: Bool either true or false.
Notes: None.
*/

bool pokerPlayer::operator==(const pokerPlayer &hand)
{
  return(rank == hand.rank);
}


/*
Description: De-constructor deletes allocated memory.
Parameters: None.
Return: None.
Notes: None.
*/

pokerPlayer::~pokerPlayer()
{

}
