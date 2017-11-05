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
	unsigned int index;
	vector<char> letters;
	vector<int> indexes;
	bool exists;


	while (true){

		character = input;

		character += to_string(counter);

		if (checkIf5Zeros(md5(character))){
			if( (md5(character)[5] > 47) && (md5(character)[5] < 56)){

//				for(int i = 0; i < indexes.size(); i++){
//					if(md5(character)[5] == indexes.at(i)){
//						exists = true;
//					}
//				}

//				if(!exists){
					letters.push_back(md5(character)[6]);
					indexes.push_back(md5(character)[5]);
					cout << "New element" << endl;
					cout << md5(character)[6] << " " << md5(character)[5] << endl;
					if(letters.size() == 25){
						break;
					}
				//}
			}
		}

		else{
			index = character.find_last_of(to_string(counter));
			character.erase(index, to_string(counter).size());
		}

	//	exists = false;
		counter++;
	}



	for (unsigned int i = 0; i < letters.size(); i++){
		cout << endl << letters.at(i) << "  " << indexes.at(i) << endl;
	}
}


