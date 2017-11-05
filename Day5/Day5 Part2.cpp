/*
 * Day5 Part2.cpp
 *
 *  Created on: 05/11/2017
 *      Author: filipa
 */

#include <iostream>
#include <vector>
#include "md5.h"


using namespace std;

bool checkIf5Zeros(string hashed){
	if(hashed.substr(0,5) == "00000"){
		return true;
	}

	else
		return false;
}

int main(){

	string password = "", input = "ojvtpuvg";
	string character;
	int counter = 367403;
	unsigned int index, newIndex;
	vector<pair<char, int>> lettersIndexes;


	while (true){

		character = input;

		character += to_string(counter);

		if (checkIf5Zeros(md5(character))){
			if( (md5(character)[5] < 7) && (md5(character)[5] > 0)){
				newIndex = md5(character)[5];
				lettersIndexes.push_back(make_pair(md5(character)[6],newIndex));
				if(lettersIndexes.size() == 2){
					break;
				}
			}
		}

		else{
			index = character.find_last_of(to_string(counter));
			character.erase(index, to_string(counter).size());
		}

		cout << counter << endl;
		counter++;
	}



	for (unsigned int i = 0; i < lettersIndexes.size(); i++){
		cout << endl << lettersIndexes.at(i).first << "  " << lettersIndexes.at(i).second << endl;
	}
}


