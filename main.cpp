#include <iostream>
#include <string>
#include <array>
#include "dealer.h"

int checkHand(array<Card, 52> myDeck);

using namespace std;


int main(int argc, char **argv) {


    //char input = *argv[1];

    int input = atoi(argv[1]);

    char* inputStringPointer = argv[1];

  //  cout << input << " is my numerical input." << endl;

   // cout << inputStringPointer << " is my string input." << endl;

    //Need to read in args and convert to int data type


    bool wantToPlay = false;
    string play = "play";
    string inputString = inputStringPointer;



    if(inputString.compare(play) == 0){
        wantToPlay = true;
    }

    //If inputString == play, need 2 have 2 dealers and play the hands
    //If inputString != play, check for 5 cards and find hands
    //Check bound
    if(wantToPlay){
        // cout << "Starting game" << endl;
        Dealer player1;


        player1.cardsToDeck();


        player1.shuffle();


        vector<string> p1cards = player1.deal(5);



        cout << "Player one drew (";
        for (int i = 0; i < p1cards.size(); i++) {

            cout << p1cards.at(i);
            if (i < p1cards.size() - 1) {
                cout << " ";
            }
        }
        cout << ")";

        int p1Hand = checkHand(player1.myDeck);
        if(p1Hand == 0){
            cout << endl;
        }
        //Check p1 cards print hand



        Dealer player2;

        player2.cardsToDeck();

        player2.shuffle();
        vector<string> p2cards = player2.deal(5);

        cout << "Player two drew (";
        //Print p2 cards, print hand
        for (int i = 0; i < p2cards.size(); i++) {

            cout << p2cards.at(i);
            if (i < p2cards.size() - 1) {
                cout << " ";
            }
        }
        cout << ")";



        //Print winner "PLayer X wins" or tie

        int p2Hand = checkHand(player2.myDeck);

        if(p2Hand == 0){
            cout << endl;
        }

        if(p1Hand > p2Hand){
            cout << "Player one wins" << endl;
        } else if (p1Hand < p2Hand){
            cout << "Player two wins" << endl;
        } else{
            //Check tiebreaker, otherwise "Tie"
            cout << "Tie" << endl;
        }




    } else{


    Dealer d1;

    d1.cardsToDeck();



    if(input < 1 || input > 5){
        cout << "You must ask for a number between 1 and 5" << endl;
        return 0;
    } else {

        //d1.myDeck.shuffle();

        //d1.myDeck.
        d1.shuffle();

        vector<string> cardsDealt = d1.deal(input);


        cout << "You drew (";
        //Iterate through vector, print each card
        //vector<string>::iterator iter = vector.begin();

        for (int i = 0; i < cardsDealt.size(); i++) {

            cout << cardsDealt.at(i);
            if (i < cardsDealt.size() - 1) {
                cout << " ";
            }
        }


        //Logic error here, need comma if 5 cards, otherwise just print
        cout << ")";


        if (input == 5) {

            //cout << "," << endl <<endl;
            //Check for special hand
            int hand = checkHand(d1.myDeck);


        }
    }

    }



    cout << "Hello, World!" << endl;





    return 0;
}

int checkHand(array<Card, 52> myDeck) {
    int rank = 0;
    bool sameSuit = false;
    bool threeOfKind = false;
    bool pair = false;
    //char cardArray[10];

    array<Card, 5> myCards;

    for(int i = 0; i < 5; i++){
        myCards.at(i) = myDeck.at(i);

    }

    //Sort from least to greatest
    for(int i =0; i < myCards.size(); i++){
        for(int j = i + 1; j < myCards.size(); j++) {
            if (myCards[i].getValue() > myCards[j].getValue()) {
                Card tempCard = myCards.at(i);
                myCards.at(i) = myCards.at(j);
                myCards.at(j) = tempCard;
            }
        }
    }

    //Check for same suit
    if(myCards.at(0).getSuit() == myCards.at(1).getSuit()){
        if(myCards.at(1).getSuit() == myCards.at(2).getSuit()){
            if(myCards.at(2).getSuit() == myCards.at(3).getSuit()){
                if(myCards.at(3).getSuit() == myCards.at(4).getSuit()){
                    sameSuit = true;
                    cout << "We have a flush";
                }
            }
        }
    }


    //Check for royal flush
    if(sameSuit) {
        if (myCards.at(0).getValue() == 1) {
            if (myCards.at(1).getValue() == 10) {
                if (myCards.at(2).getValue() == 11) {
                    if (myCards.at(3).getValue() == 12) {
                        if(myCards.at(4).getValue() == 13){
                            cout << ", a royal flush" << endl;
                            rank = 9;
                            return rank;
                        }

                    }
                }
            }
        }
    }
    //Check for straight flush
    if(sameSuit) {
        if (myCards.at(0).getValue() + 1 == myCards.at(1).getValue()) {
            if (myCards.at(1).getValue() + 1 == myCards.at(2).getValue()) {
                if (myCards.at(2).getValue() + 1 == myCards.at(3).getValue()) {
                    if (myCards.at(3).getValue() + 1 == myCards.at(4).getValue()) {

                            cout << ", a straight flush" << endl;
                            rank = 8;
                        return rank;


                    }
                }
            }
        }
    }
    //Check for 4 of a kind
    if((myCards.at(0).getValue() == myCards.at(1).getValue() && myCards.at(1).getValue() == myCards.at(2).getValue() &&
            myCards.at(2).getValue() == myCards.at(3).getValue()) || (myCards.at(1).getValue() == myCards.at(2).getValue()
            && myCards.at(2).getValue() == myCards.at(3).getValue() && myCards.at(3).getValue() == myCards.at(4).getValue())){
        cout << " a four of a kind" << endl;
        rank = 7;
        return rank;
    }

    //Check for flush
    if(sameSuit){
        cout << ", a flush" << endl;
        rank = 5;
        return rank;
    }
    //Check for straight
    if (myCards.at(0).getValue() + 1 == myCards.at(1).getValue()) {
        if (myCards.at(1).getValue() + 1 == myCards.at(2).getValue()) {
            if (myCards.at(2).getValue() + 1 == myCards.at(3).getValue()) {
                if (myCards.at(3).getValue() + 1 == myCards.at(4).getValue()) {

                    cout << ", a straight " << endl;
                    rank = 4;
                    return rank;


                }
            }
        }
    }
    //Check for 3 of a kind
    if((myCards.at(0).getValue() == myCards.at(1).getValue() && myCards.at(1).getValue() == myCards.at(2).getValue()) ||
            (myCards.at(1).getValue() == myCards.at(2).getValue() && myCards.at(2).getValue() == myCards.at(3).getValue()) ||
                (myCards.at(2).getValue() == myCards.at(3).getValue() && myCards.at(3).getValue() == myCards.at(4).getValue())){
        //cout << "a three of a kind" << endl;
        threeOfKind = true;
        rank = 3;
        //return rank;
    }

    //Check for pair
    if((myCards.at(0).getValue() == myCards.at(1).getValue() || myCards.at(1).getValue() == myCards.at(2).getValue()) ||
       (myCards.at(2).getValue() == myCards.at(3).getValue() || myCards.at(3).getValue() == myCards.at(4).getValue())){
        //cout << ", a pair" << endl;
        rank = 1;
        pair = true;
    }



    //Check for full house
    if(((myCards.at(0).getValue() == myCards.at(1).getValue() && myCards.at(1).getValue() == myCards.at(2).getValue()) &&
            (myCards.at(3).getValue() == myCards.at(4).getValue())) || ((myCards.at(2).getValue() == myCards.at(3).getValue() &&
                myCards.at(3).getValue() == myCards.at(4).getValue()) && (myCards.at(0).getValue() == myCards.at(1).getValue()) )){
        cout << ", a full house" << endl;
        rank = 6;
        return rank;
    }

    //Check for 2 pair
    if((myCards.at(0).getValue() == myCards.at(1).getValue() && myCards.at(2).getValue() == myCards.at(3).getValue()) ||
            (myCards.at(0).getValue() == myCards.at(1).getValue() && myCards.at(3).getValue() == myCards.at(4).getValue()) ||
                (myCards.at(1).getValue() == myCards.at(2).getValue() && myCards.at(3).getValue() == myCards.at(4).getValue())){
        //cout << ", two pairs" << endl;
        rank = 2;

    }

    if(rank == 3){
        cout << "three of a kind" << endl;
    } else if (rank == 2) {
        cout << ", two pairs" << endl;
    } else if (rank == 1) {
        cout << ", a pair" << endl;
    }


    return rank;
}
