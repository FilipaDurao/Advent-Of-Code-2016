/*
 * Day8 Part1.cpp
 *
 *  Created on: 07/11/2017
 *      Author: filipa
 */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int ledScreen[6][50];



void printScreen(){

	for(unsigned int i = 0; i < 6; i++){
		for(unsigned int j = 0; j < 50; j++){
			cout << ((ledScreen[i][j] == 0) ? " " : "#") << " ";

		}

		cout << endl;
	}
}

void makeRect(string inst){
	int x, y, xIndex;

	xIndex = inst.find_first_of("x");

	x = stoi(inst.substr(0,xIndex));
	y = stoi(inst.substr(xIndex+1));

	for(unsigned int i = 0; i < y; i++){
		for(unsigned int j = 0; j < x; j++){
			ledScreen[i][j] = 1;
		}
	}
}


void rotCol(string inst){
	int index = inst.find_first_of("="), index2 = inst.find_first_of(" ");

	unsigned int col = stoi(inst.substr(index +1, index2-index -1));
	index = inst.find_last_of(" ");
	inst.erase(0, index+1);
	unsigned int rots = stoi(inst);
	unsigned int temp;

	rots = rots%6;

	for(unsigned int i = 0; i < rots; i++){
		temp = ledScreen[0][col];
		ledScreen[0][col] = ledScreen[5][col];
		for(unsigned int j = 5; j > 1; j--){
			ledScreen[j][col] = ledScreen[j-1][col];
		}

		ledScreen[1][col] = temp;
	}


}


void rotRow(string inst){

	int index = inst.find_first_of("="), index2 = inst.find_first_of(" ");
	unsigned int row = stoi(inst.substr(index +1, index2-index -1));
	index = inst.find_last_of(" ");
	inst.erase(0, index+1);
	unsigned int rots = stoi(inst);
	unsigned int temp;
	rots = rots%50;



	for(unsigned int i = 0; i < rots; i++){
		temp = ledScreen[row][0];
		ledScreen[row][0] = ledScreen[row][49];

		for(unsigned int j = 49; j > 1; j--){
			ledScreen[row][j] = ledScreen[row][j-1];
		}

		ledScreen[row][1] = temp;
	}

}


int main(){

	ifstream in_stream("Input Day 8.txt");

	vector<string> instructions;
	string instruction;
	unsigned int counter = 0;

	while(!in_stream.eof()){
		getline(in_stream, instruction);
		instructions.push_back(instruction);
	}

	unsigned int index;
	string instructionName;

	for(unsigned int i = 0; i < instructions.size(); i++){

		instruction = instructions.at(i);

		index = instruction.find_first_of(" ");

		instructionName = instruction.substr(0, index);


		if(instructionName == "rect"){

			instruction.erase(0, index+1);
			makeRect(instruction);
		}

		if(instructionName == "rotate"){

			instruction.erase(0, index+1);
			index = instruction.find_first_of(" ");

			instructionName = instruction.substr(0, index);

			if(instructionName == "row"){
				instruction.erase(0, index+1);
				rotRow(instruction);
			}
			if(instructionName == "column"){
				instruction.erase(0, index+1);
				rotCol(instruction);
			}

		}
	}

	for(unsigned int i = 0; i < 6; i++){
		for(unsigned int j = 0; j < 50; j++){
			if(ledScreen[i][j] == 1)
				counter++;
		}
	}

	cout << "Counter: " << counter << endl;
	printScreen();
}







