/*
 * Day6 Part1.cpp
 *
 *  Created on: 04/11/2017
 *      Author: filipa
 */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

int main(){

	vector<char> element1;
	vector<char> element2;
	vector<char> element3;
	vector<char> element4;
	vector<char> element5;
	vector<char> element6;
	vector<char> element7;
	vector<char> element8;

	vector<Letter_Freq> element1_1;
	vector<Letter_Freq> element2_1;
	vector<Letter_Freq> element3_1;
	vector<Letter_Freq> element4_1;
	vector<Letter_Freq> element5_1;
	vector<Letter_Freq> element6_1;
	vector<Letter_Freq> element7_1;
	vector<Letter_Freq> element8_1;

	ifstream in_stream("Input Day 6.txt");
	string input;

	while(!in_stream.eof()){
		getline(in_stream, input);
		element1.push_back(input[0]);
		element2.push_back(input[1]);
		element3.push_back(input[2]);
		element4.push_back(input[3]);
		element5.push_back(input[4]);
		element6.push_back(input[5]);
		element7.push_back(input[6]);
		element8.push_back(input[7]);
	}

	bool foundLetter = false;

	for(int k = 0; k < element1.size(); k++){					// Store them with their frequencies

		for(int z = 0; z < element1_1.size(); z++){

			if (element1_1.at(z).letter == element1.at(k)){		// If the letter is already stored, increment the frequency
				element1_1.at(z).incrementFreq();
				foundLetter = true;
			}
		}

		if(!foundLetter){
			element1_1.push_back(Letter_Freq(element1.at(k)));		// If its not already stored, store it
		}

		foundLetter = false;
	}


	for(int k = 0; k < element2.size(); k++){					// Store them with their frequencies

		for(int z = 0; z < element2_1.size(); z++){

			if (element2_1.at(z).letter == element2.at(k)){		// If the letter is already stored, increment the frequency
				element2_1.at(z).incrementFreq();
				foundLetter = true;
			}
		}

		if(!foundLetter){
			element2_1.push_back(Letter_Freq(element2.at(k)));		// If its not already stored, store it
		}

		foundLetter = false;
	}

	for(int k = 0; k < element3.size(); k++){					// Store them with their frequencies

		for(int z = 0; z < element3_1.size(); z++){

			if (element3_1.at(z).letter == element3.at(k)){		// If the letter is already stored, increment the frequency
				element3_1.at(z).incrementFreq();
				foundLetter = true;
			}
		}

		if(!foundLetter){
			element3_1.push_back(Letter_Freq(element3.at(k)));		// If its not already stored, store it
		}

		foundLetter = false;
	}


	for(int k = 0; k < element4.size(); k++){					// Store them with their frequencies

	    for(int z = 0; z <element4_1.size(); z++){

	        if (element4_1.at(z).letter == element4.at(k)){		// If the letter is already stored, increment the frequency
	            element4_1.at(z).incrementFreq();
	            foundLetter = true;
	        }
	    }

	    if(!foundLetter){
	        element4_1.push_back(Letter_Freq(element4.at(k)));		// If its not already stored, store it
	    }

	    foundLetter = false;
	}

	for(int k = 0; k < element5.size(); k++){					// Store them with their frequencies

	    for(int z = 0; z <element5_1.size(); z++){

	        if (element5_1.at(z).letter == element5.at(k)){		// If the letter is already stored, increment the frequency
	            element5_1.at(z).incrementFreq();
	            foundLetter = true;
	        }
	    }

	    if(!foundLetter){
	        element5_1.push_back(Letter_Freq(element5.at(k)));		// If its not already stored, store it
	    }

	    foundLetter = false;
	}

	for(int k = 0; k < element6.size(); k++){					// Store them with their frequencies

	    for(int z = 0; z <element6_1.size(); z++){

	        if (element6_1.at(z).letter == element6.at(k)){		// If the letter is already stored, increment the frequency
	            element6_1.at(z).incrementFreq();
	            foundLetter = true;
	        }
	    }

	    if(!foundLetter){
	        element6_1.push_back(Letter_Freq(element6.at(k)));		// If its not already stored, store it
	    }

	    foundLetter = false;
	}

	for(int k = 0; k < element7.size(); k++){					// Store them with their frequencies

	    for(int z = 0; z <element7_1.size(); z++){

	        if (element7_1.at(z).letter == element7.at(k)){		// If the letter is already stored, increment the frequency
	            element7_1.at(z).incrementFreq();
	            foundLetter = true;
	        }
	    }

	    if(!foundLetter){
	        element7_1.push_back(Letter_Freq(element7.at(k)));		// If its not already stored, store it
	    }

	    foundLetter = false;
	}

	for(int k = 0; k < element8.size(); k++){					// Store them with their frequencies

	    for(int z = 0; z <element8_1.size(); z++){

	        if (element8_1.at(z).letter == element8.at(k)){		// If the letter is already stored, increment the frequency
	            element8_1.at(z).incrementFreq();
	            foundLetter = true;
	        }
	    }

	    if(!foundLetter){
	        element8_1.push_back(Letter_Freq(element8.at(k)));		// If its not already stored, store it
	    }

	    foundLetter = false;
	}


	sort(element1_1.begin(), element1_1.end());

	cout << element1_1.at(element1_1.size()-1).letter;


}

