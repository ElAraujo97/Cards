#include <iostream>
#include <string>
#include <array>
#include "dealer.h"
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
};

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

//Class for a deck of cards
class Deck{
    private:
        array<Card, 52> myDeck;
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

        void shuffle(Deck myDeck){
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

        }



};





int main(int argc, char **argv) {

    //char input = *argv[1];

    int input = atoi(argv[1]);

    cout << input << " is my input." << endl;


    //Need to read in args and convert to int data type

    Dealer d1;

    Deck tempDeck;

    tempDeck.shuffle(tempDeck);


    if(input < 1 || input > 5){
        cout << "You must ask for a number between 1 and 5" << endl;
    } else{
        //d1.deal();
        cout << "You drew (";

        //Iterate through vector, print each card


        cout << ")" << endl;


    }









    cout << "Hello, World!" << endl;





    return 0;
}
