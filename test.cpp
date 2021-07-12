#include "dealer.h"
#include <string>
#include <vector>
#include <iostream>

bool testCorrectCardCountReturned();
bool testCardOutputStartsWithSuitCharacter();
bool testCannotDealMoreThan52Cards();
bool testCannotDealFewerThan1Card();

int main(int argc, char **argv) {
	int numFailedTests;
	if (!testCorrectCardCountReturned()) {  ++numFailedTests; }
	if (!testCardOutputStartsWithSuitCharacter()) { ++numFailedTests; }
	if (!testCannotDealMoreThan52Cards()) { ++numFailedTests; }
	if (!testCannotDealFewerThan1Card()) {  ++numFailedTests; }

	if (numFailedTests == 0) {
		std::cout << "All tests passed" << std::endl;
	} else {
		std::cout << numFailedTests << " tests failed" << std::endl;
	}
}

bool testCorrectCardCountReturned() {
	Dealer subject = Dealer();
	std::vector<std::string> resultOne = subject.deal(5);
	if (resultOne.size() != 5) {
		std::cout << "FAIL: Expected 5 cards to be returned, got " << resultOne.size() << std::endl;
		return false;
	}

	std::vector<std::string> resultTwo = subject.deal(1);
	if (resultTwo.size() != 1) {
		std::cout << "FAIL: Expected 1 cards to be returned, got " << resultTwo.size() << std::endl;
		return false;
	}

	return true;
}

bool testCardOutputStartsWithSuitCharacter() {
	Dealer subject = Dealer();
	std::vector<std::string> resultOne = subject.deal(1);
	if (resultOne.size() == 0) {
		std::cout << "FAIL: No cards returned" << std::endl;
		return false;
	}

	std::string firstCard = resultOne.at(0);

	if (firstCard.empty()) {
		std::cout << "FAIL: Cards returned to end with a suit, got an empty string" << std::endl;
		return false;
	}
	if (firstCard.back() != '%' && 	firstCard.back() != '^' && firstCard.back() != '*' && firstCard.back() != '@') {
		std::cout << "FAIL: Cards returned to end with a suit, got '" << firstCard.back() << std::endl;
		return false;
}

	return true;
}

bool testCannotDealMoreThan52Cards() {
	Dealer subject = Dealer();
	try {
		subject.deal(53);
	} catch (std::runtime_error e) {
		return true;	
	}

	std::cout << "FAIL: Expected to throw an exception when dealing more than 52 cards" << std::endl;
	return false;
}

bool testCannotDealFewerThan1Card() {
	Dealer subject = Dealer();
	try {
		subject.deal(0);
	} catch (std::runtime_error e) {
		return true;	
	}

	std::cout << "FAIL: Expected to throw an exception when dealing fewer than 1 card" << std::endl;
	return false;

}
