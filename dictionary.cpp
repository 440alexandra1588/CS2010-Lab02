#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

class Dictionary{

DICT dictionary;
int count[MAX];
int word_count;

public:

Dictionary(){ // Constructor
	word_count = 0;
}
	
int LocateWord(WORD);
BOOL FullDictionary(void);
BOOL InsertWord(WORD);
void GetWords(void);
void DumpDictionary(void);
BOOL CompareWords(WORD, WORD);
void SortWords(void);

};

// adds word to dictionary, if word cant be added returns false, else returns true
BOOL Dictionary::InsertWord(WORD word)
{
	int index = LocateWord(word);
	if( index != -1) count[index]++;

	else if(FullDictionary() == 1) return 0;
	else{
		dictionary[word_count] = word;
		count[word_count]++;
		word_count++;
		return 1;
	}				
}

// Will sort dictionary and display the contents
void Dictionary::DumpDictionary() {
	int numCount = 1;
	SortWords();

	for( int i = 0; i < word_count; i++){
		printf("%3d : %s", numCount++,dictionary[i].c_str());

		for(int j = 0; j < (30 - dictionary[i].length()); j++)
			cout << " ";

		 cout << count[i] << endl;
	}
}

/*
retrieves next word in input stream. word defined as ass#1. 
returns a WORD or empty string ( if no more words in input stream.
*/
void Dictionary::GetWords(){

	WORD word;
	char ch;
	BOOL neww;

	while(cin.good()){


		ch = cin.get();

		if(isalpha(ch)){

			ch = tolower(ch);
			word += ch;
			neww = 0;
		}else{

			neww = 1;
		}

		if(neww == 1){

			InsertWord(word);
			word.clear();
		}
	}		
}



//if full, return 1, else 0
BOOL Dictionary::FullDictionary() {
	if(word_count == MAX) return 1;
	else return 0; 
}

// determine if dictionary comtains word. if yes, return position, else return val < 0
int Dictionary::LocateWord(WORD word) {
	for(int i = 0; i < MAX; i++) 
		if(dictionary[i] == word) return i;

	return -1;

}

BOOL Dictionary::CompareWords(WORD word1, WORD word2){
	if(word1<word2) return 1;
	else return 0;
}

void Dictionary::SortWords(){
	int index = 1;
	int tmpCount;
	WORD tmpWord;

	while(index < word_count){

		int i = index;
		while(i > 0){

			if(CompareWords(dictionary[i], dictionary[i-1])){
				tmpWord = dictionary[i-1];
				tmpCount = count[i-1];

				dictionary[i-1] = dictionary[i];
				count[i-1] = count[i];

				dictionary[i] = tmpWord;
				count[i] = tmpCount;

				i--;

			} else
				break;
		}

		index++;		
	}
}

