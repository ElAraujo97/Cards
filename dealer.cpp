#include "dealer.h"
#include <sstream>
#include <array>

using namespace std;

void Card::setSuit(string suit) {
    this->mySuit = suit;
}

string Card::getSuit() {
    return this->mySuit;
}

void Card::setValue(int value) {
    this->myValue = value;
}

int Card::getValue() {
    return this->myValue;
}


vector<string> Dealer::deal(int numCards) {
    vector<string> myHand;
    array<Card, 52>::iterator deckIterator;


	return vector<string>();
}


void Dealer::shuffle(){
    srand(time(NULL));
    Deck tempDeck;
    int count = 52;

    //Sorting algorithm Fisher-Yates
    for(int i = count - 1; i > 0; i--){
        int randomNumber = rand() % count;
        Card tempCard;
        tempCard = tempDeck.myDeck.at(randomNumber);
        tempDeck.myDeck.at(randomNumber) = tempDeck.myDeck.at(i);
        tempDeck.myDeck.at(i) = tempCard;
    }

    //Transfer shuffled tempDeck to myDeck
    for(auto i = 0; i < 52; i++){
        this->myDeck.at(i) = tempDeck.myDeck.at(i);
    }

    return;
}

void Dealer::cardsToDeck(){

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

