/*
 * Day7 Part1.cpp
 *
 *  Created on: 05/11/2017
 *      Author: filipa
 */


#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


bool isAbba(string input){

	bool abbaFound = false;

	for(unsigned int i = 0; i < input.size()-3; i++){
		if(input[i] == input[i+3]){
			if( (input[i+1] == input[i+2]) && (input[i] != input[i+1]) ){
				abbaFound = true;
				break;
			}
		}
	}

	return abbaFound;
}



int main(){

	vector<string> IPs;
	string IP;
	ifstream in_stream("Input Day 7.txt");

	while(!in_stream.eof()){
		getline(in_stream, IP);
		IPs.push_back(IP);
	}

	int index, counter = 0;
	string auxSubstr;
	bool abbaBrackets, justAbba, thereIsOneAbba;


	for(unsigned int i = 0; i < IPs.size(); i++){

		IP = IPs.at(i);

		while(IP.size() != 0){

			if(IP[0] == '['){							// If we are inside Brackets
				index = IP.find_first_of("]");
				auxSubstr = IP.substr(1, index-1);		// Isolate the interior of the brackets
				abbaBrackets = isAbba(auxSubstr);		// Check if there is any ABBA type
				IP.erase(0, index+1);					// Remove the analyzed substring

				if(abbaBrackets)
					break;
			}
			else{
				index = IP.find_first_of("[");
				auxSubstr = IP.substr(0, index);
				justAbba = isAbba(auxSubstr);

				if(justAbba){
					thereIsOneAbba = true;
				}

				IP.erase(0, index);

			}
		}

		if( (abbaBrackets == false) && (thereIsOneAbba == true) )
			counter++;


		abbaBrackets = false;
		justAbba = false;
		thereIsOneAbba = false;
	}

	cout << counter << endl;
}

