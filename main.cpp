#include <iostream>
#include <string>
#include <array>
#include "dealer.h"
using namespace std;


int main(int argc, char **argv) {

    //char input = *argv[1];

    int input = atoi(argv[1]);

    cout << input << " is my input." << endl;


    //Need to read in args and convert to int data type

    Dealer d1;

    d1.cardsToDeck();



    if(input < 1 || input > 5){
        cout << "You must ask for a number between 1 and 5" << endl;
        return 0;
    } else{

        //d1.myDeck.shuffle();

        //d1.myDeck.
        d1.shuffle();

        d1.deal(input);


        cout << "You drew (";
        //Iterate through vector, print each card
        for(int i = 0; i < input ; i++){

        }



        cout << ")" << endl;


    }









    cout << "Hello, World!" << endl;





    return 0;
}
