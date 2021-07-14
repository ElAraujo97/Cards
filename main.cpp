#include <iostream>
#include <string>
#include <array>
#include "dealer.h"
using namespace std;


int main(int argc, char **argv) {

    //char input = *argv[1];

    int input = atoi(argv[1]);

    char* inputString = argv[1];

    cout << input << " is my numerical input." << endl;

    cout << inputString << " is my string input." << endl;

    //Need to read in args and convert to int data type


    //If inputString == play, need 2 have 2 dealers and play the hands
    //If inputString != play, check for 5 cards and find hands
    //Check bound



    Dealer d1;

    d1.cardsToDeck();



    if(input < 1 || input > 5){
        cout << "You must ask for a number between 1 and 5" << endl;
        return 0;
    } else{

        //d1.myDeck.shuffle();

        //d1.myDeck.
        d1.shuffle();

        vector<string> cardsDealt = d1.deal(input);


        cout << "You drew (";
        //Iterate through vector, print each card
        //vector<string>::iterator iter = vector.begin();

        for(int i = 0; i < cardsDealt.size(); i++){

            cout << cardsDealt.at(i);
            if(i < cardsDealt.size() - 1){
                cout << " ";
            }
        }



        cout << ")" << endl;


        if(input == 5){
            //Check for special hand
        }

    }









    cout << "Hello, World!" << endl;





    return 0;
}
