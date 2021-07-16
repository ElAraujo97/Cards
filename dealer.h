  #ifndef DEALER_H
#define DEALER_H

#include <vector>
#include <string>
#include <array>
using namespace std;



//Class for a single card
  class Card{
  private:
      string mySuit;
      int myValue;
  public:
      Card(){
          mySuit = "Spades";
          myValue = 1;
      }
      Card(string tempSuit, int tempValue){
          this->mySuit = tempSuit;
          this->myValue = tempValue;
      }
      void setSuit(string suit);
      string getSuit();
      void setValue(int value);
      int getValue();
      string suitValueToString(Card myCard);
  };



//Class for a deck of cards
  class Deck{
  private:
   //   int size = 52;
  public:

      Deck(){
          array<Card, 52>::iterator deckIterator;
          int index = 0;
          string tempSuit;
          for(deckIterator = myDeck.begin(); deckIterator != myDeck.end(); deckIterator++){


              if(index < 13){
                  tempSuit = "^";
              }
              else if(index >= 13 && index < 26){
                  tempSuit = "@";
              }
              else if(index >=26 && index < 39){
                  tempSuit = "%";
              }
              else{
                  tempSuit = "*";
              }

              if(index % 13 == 0){
                  myDeck.at(index) = Card(tempSuit, 1);
                  index++;
              } else{
                  myDeck.at(index) = Card(tempSuit, (index % 13) + 1);
                  index++;
              }



          }

      }


      //Card getCard(Deck myDeck);




      array<Card, 52> myDeck;
  };

  class Dealer {
  private:
      int cardsDrawn = 0;
  public:
      array<Card, 52> myDeck;
      //int cardsDrawn = 0;
      vector<string> deal(int numCards);
      void cardsToDeck();
      void shuffle();

      int getCardsDrawn();
      void setCardDrawn();

  };


#endif
