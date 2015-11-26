/*
	Author: Alexandra Lambright (Student ID: 4401588)

	Assignment #2 - Dictionary using an array of Strings

	Purpose: This assignment is to demonstrate the use of different data
	structures on the same simple task of a dictionary. This is the second
	version of the dictionary demonstrated in Assignment #1, however the 
	dictionary is to sort the words in the array this time around. 

	We are given 5 functions that will need to be written, and we must 
	implement the use of "Typedef" as well. 
*/

#include "dictionary.cpp"


int main (void) {

	Dictionary *dict = new Dictionary();	

       dict->GetWords();// take the words from file and place into dict

	dict->DumpDictionary();

	delete dict;
}
