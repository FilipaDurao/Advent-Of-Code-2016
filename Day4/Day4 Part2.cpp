/*
 * Day4 Part2.cpp
 *
 *  Created on: 03/11/2017
 *      Author: filipa
 */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Letter_Freq{
public:
	char letter;
	unsigned int frequency;

	Letter_Freq(char letter){
		this->letter = letter;
		this->frequency = 1;
	}

	void incrementFreq(){ frequency++; }

	bool operator < (Letter_Freq l2){

		if(frequency < l2.frequency)
			return true;
		else if (frequency > l2.frequency)
			return false;
		else if (frequency == l2.frequency){
			if(letter > l2.letter){
				return true;
			}
			else
				return false;
		}
	}

	bool operator == (char l2){
		if(letter == l2)
			return true;
		else
			return false;
	}
};


vector<string> realRooms;

void getRealRooms(){

	string room;
	ifstream in_stream("Input Day 4.txt");

	vector<string> rooms;

	while(!in_stream.eof()){
		getline(in_stream, room);
		rooms.push_back(room);
	}


	char letter;
	vector<char> letters;
	vector<Letter_Freq> lettersFreqs;
	bool foundLetter = false;
	long int sum = 0;


	for (unsigned int i = 0; i < rooms.size(); i++){

		room = rooms.at(i);			// Get the current room


		for (unsigned int j = 0; j < room.size() - 11; j++){		// Analise the letters in the code


			letter = room.at(j);

			if(letter != '-'){						// Get the letters to the vector
				letters.push_back(letter);
			}

		}

		sort(letters.begin(), letters.end());		// Sort them alfabetically

		for(int k = 0; k < letters.size(); k++){					// Store them with their frequencies

			for(int z = 0; z < lettersFreqs.size(); z++){

				if (lettersFreqs.at(z).letter == letters.at(k)){		// If the letter is already stored, increment the frequency
					lettersFreqs.at(z).incrementFreq();
					foundLetter = true;
				}
			}

			if(!foundLetter){
				lettersFreqs.push_back(Letter_Freq(letters.at(k)));		// If its not already stored, store it
			}

			foundLetter = false;
		}


		sort(lettersFreqs.begin(), lettersFreqs.end());


		// At this point the vector is ordered by the rule we need
		// So we will just pick the final 5 to compare

		char code1 = (lettersFreqs.at(lettersFreqs.size() - 1)).letter;
		char code2 = (lettersFreqs.at(lettersFreqs.size() - 2)).letter;
		char code3 = (lettersFreqs.at(lettersFreqs.size() - 3)).letter;
		char code4 = (lettersFreqs.at(lettersFreqs.size() - 4)).letter;
		char code5 = (lettersFreqs.at(lettersFreqs.size() - 5)).letter;


		char input1 = room.at(room.size()-6);
		char input2 = room.at(room.size()-5);
		char input3 = room.at(room.size()-4);
		char input4 = room.at(room.size()-3);
		char input5 = room.at(room.size()-2);


		if ( (code1 == input1) && (code2 == input2) && (code3 == input3) && (code4 == input4) && (code5 == input5) ){
			realRooms.push_back(room);
		}


		letters.clear();
		lettersFreqs.clear();

	}
}


int getSector (string room){

	int index = distance(room.begin(), room.end()-10);
	string sector = room.substr(index, 3);
	int numSector = stoi(sector);


	return numSector;
}


char makeRotation(char letter, int numRots){

	string alfabet = "abcdefghijklmnopqrstuvwxyz";
	int index;

	if(letter == '-')
		return ' ';

	for(int i = 0; i < alfabet.size(); i++){
		if(letter == alfabet[i]){
			index = i;
			break;
		}
	}

	index = (index + numRots)%26;

	return alfabet[index];
}

int main(){

	getRealRooms();

	vector<string> decodedRooms;
	string room;
	int sector;

	for(unsigned int i = 0; i < realRooms.size(); i++){

		room = realRooms.at(i);

		sector = getSector(room);	// How many rotations

		for (unsigned int j = 0; j < room.size()-11; j++){
			room[j] = makeRotation(room[j], sector);
		}

		decodedRooms.push_back(room);
	}


	sort(decodedRooms.begin(), decodedRooms.end());

	for(int i = 0; i < decodedRooms.size(); i++){
		cout << decodedRooms.at(i) << endl;
	}

}










