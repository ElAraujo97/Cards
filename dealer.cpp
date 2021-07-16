#include "dealer.h"
#include <sstream>
#include <array>
#include <iostream>
#include <unistd.h>

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

string Card::suitValueToString(Card myCard){
    string value;
    int cardValue = myCard.getValue();
    if(cardValue == 11){
        value = "J";
    } else if(cardValue == 12){
        value = "Q";
    } else if(cardValue == 13){
        value = "K";
    } else if (cardValue == 1){
        value = "A";
    } else {
        value = to_string(cardValue);
    }



    return value + myCard.getSuit();


}

vector<string> Dealer::deal(int numCards) {
    vector<string> myHand;
    string pair;

    for(int i = cardsDrawn; numCards > 0; numCards--){
        pair = myDeck.at(i).suitValueToString(myDeck.at(i));
        myHand.push_back(pair);
        this->cardsDrawn++;
        i++;
    }







	return myHand;
}


void Dealer::shuffle(){

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
    for(int i = 0; i < 52; i++){
        this->myDeck.at(i) = tempDeck.myDeck.at(i);
    }


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

int Dealer::getCardsDrawn(){
    return this->cardsDrawn;
};


void Dealer::setCardDrawn(){
    this->cardsDrawn++;
};
