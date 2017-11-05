/*
 * Day5 Part1.cpp
 *
 *  Created on: 03/11/2017
 *      Author: filipa
 */


#include <iostream>
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


	while (true){

		character = input;

		character += to_string(counter);

		if (checkIf5Zeros(md5(character))){
			password += md5(character)[5];
			cout << "\n\n\n\n\nELEMENT\n\n\n\n\n" << endl;
			if(password.size() == 8){
				break;
			}
		}

		else{
			index = character.find_last_of(to_string(counter));
			character.erase(index, to_string(counter).size());
		}

		cout << counter << endl;
		counter++;
	}

	cout << password;
}








