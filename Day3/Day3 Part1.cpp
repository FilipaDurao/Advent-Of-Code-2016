/*
 * Day3 Part1.cpp
 *
 *  Created on: 01/11/2017
 *      Author: filipa
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){

	unsigned int index, cont = 0;
	int side1, side2, side3;
	string triangle;
	ifstream in_stream("Input Day 3.txt");
	vector <string> triangles;


	while (getline(in_stream, triangle)){
		triangles.push_back(triangle);
	}


	for(unsigned int i = 0; i < triangles.size(); i++){

		triangle = triangles.at(i);

		index = triangle.find_first_not_of(" ");				// Encontrar o primeiro que nao é um espaço
		triangle.erase(0, index);								// Cortar os espaços
		index = triangle.find_first_not_of("1234567890");		// Ver o tamanho do número
		side1 = stoi(triangle.substr(0, index));				// Isolar o número
		triangle.erase(0, index);								// Remover o número

		index = triangle.find_first_not_of(" ");
		triangle.erase(0, index);
		index = triangle.find_first_not_of("1234567890");
		side2 = stoi(triangle.substr(0, index));
		triangle.erase(0, index);

		index = triangle.find_first_not_of(" ");
		triangle.erase(0, index);
		index = triangle.find_first_not_of("1234567890");
		side3 = stoi(triangle.substr(0, index));
		triangle.erase(0, index);


		cout << "(" << side1 << ", " << side2 << ", " << side3 << ")" << endl;

		if((side1 > side2) && (side1 > side3)){				// Side 1 is the biggest
			if((side2 + side3) <= side1){
				cont++;
			}
		}

		else if((side2 > side1) && (side2 > side3)){		// Side 2 is the biggest
			if((side1 + side3) <= side2){
				cont++;
			}
		}

		else if((side3 > side1) && (side3 > side2)){		// Side 3 is the biggest
			if( (side1 + side2) <= side3){
				cont++;
			}
		}



	}


	cout << triangles.size() - cont << endl;








}


