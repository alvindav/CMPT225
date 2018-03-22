#include <iostream>
#include <iomanip>
#include <fstream>
#include "char_stack.h"
using namespace std;

bool pairChecker(char opening, char closing);
char correctPair(char opening);
void printError(string currentLine, int lineLength, int numIndex, int numTabs);

int main() {
	string currentLine; //strings of code
	string openBrackets = "({[";
	string closeBrackets = "]})";
	char_stack stack;
	char currentBracket, topBracket, correctBracket;

	//index handling
	int index = -1;
	int line = 0;
	int length = 0;
	int tabs = 0;

	//error checkers
	bool pairCheck = false;
	bool error = false;

	while (getline(cin, currentLine))
	{
		if(error) break;
		index = -1;
		tabs = 0;
		line++;
		length = currentLine.length();
		while(index < length)
		{
			index++;
			currentBracket = currentLine[index];

			if(currentLine[index] == '\t')
				tabs++;

			//found open bracket
			if(openBrackets.find(currentBracket) != string::npos )
				stack.push(currentBracket);

			//found closing bracket
			else if(closeBrackets.find(currentBracket) != string::npos ){
				if(stack.empty()){
					cout << "Error on line " << line << ": Too many " << currentBracket << endl;
					printError(currentLine, length, index, tabs);
					error = true;
					break;
				}

				topBracket = stack.pop(); //pop the opening bracket in the stack
				correctBracket = correctPair(topBracket); //determine the correct closing bracket
				pairCheck = pairChecker(topBracket, currentBracket); //are the brackets correspondent to each other?

				if(!pairCheck){
					cout << "Error on line " << line << ": Read " << currentBracket << ", expected " << correctBracket << endl;
					printError(currentLine, length, index, tabs);
					error = true;
					break;
				}
			}
		}//end while
	}//end while

	if(!stack.empty() && !error){
		currentBracket = stack.pop();
		cout << "Error at end of file: Too many " << currentBracket << endl;
	}
	else if (error == false)
		cout << "No Errors Found" << endl;

	return 0;
}//end main

bool pairChecker(char opening, char closing){
	//pairChecker function takes in two char values.
	//"opening" contains an opening bracket, "closing" contains a closing bracket
	//pairChecker compares the values to see if the brackets are correspondent to each other.
	//Returns false if they are not correspondent.

	bool paired = false;
	if(opening == '(' && closing == ')')
		paired = true;
	else if(opening =='{' && closing == '}')
		paired = true;
	else if(opening == '[' && closing == ']')
		paired = true;

	return paired;
}

char correctPair(char opening){
	//This function takes in the top bracket from the stack.
	//Depending on the input, we determine its corresponding closing bracket
	//Returns the proper closing bracket

	char closing = 0;
	switch(opening){
		case '(': { closing = ')'; break; }
		case '{': { closing = '}'; break; }
		case '[': { closing = ']'; break; }
		default: break;
	}
	return closing;
}

void printError(string currentLine, int lineLength, int numIndex, int numTabs){
	//This function is only called when there is an error within the input source code
	//printError takes the current line, its length, the index, and the number of tabs ('\t') at which the error occurred
	//printError prints the current line in such a way that it is easy to see where the error was located in the line.

	//print up to the error character
	for(int i = 0; i <= numIndex; i++){ cout << currentLine[i]; }

	//print number of tabs and characters as spaces
	cout << endl;
	for(int i = 0; i < numTabs; i++){ cout << '\t'; }
	for(int i = 0; i <= numIndex-numTabs; i++){ cout << ' ';}

	//print characters that appear after error
	for(int i = numIndex+1; i < lineLength; i++){ cout << currentLine[i]; }
	cout << endl;
}
