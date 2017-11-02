/*
 * Day3 Part2.cpp
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
	string input1, input2, input3, side1_1, side1_2, side1_3, side2_1, side2_2, side2_3, side3_1, side3_2, side3_3, triangle1, triangle2, triangle3, triangle;
	ifstream in_stream("Input Day 3.txt");
	vector <string> triangles;

	while(!in_stream.eof()){
		getline(in_stream, input1);
		getline(in_stream, input2);
		getline(in_stream, input3);

		//LINHA 1
		index = input1.find_first_not_of(" ");				// Encontrar o primeiro que nao é um espaço
		input1.erase(0, index);								// Cortar os espaços
		index = input1.find_first_not_of("1234567890");		// Ver o tamanho do número
		side1_1 = input1.substr(0, index);				// Isolar o número
		input1.erase(0, index);								// Remover o número

		index = input1.find_first_not_of(" ");
		input1.erase(0, index);
		index = input1.find_first_not_of("1234567890");
		side1_2 = input1.substr(0, index);
		input1.erase(0, index);

		index = input1.find_first_not_of(" ");
		input1.erase(0, index);
		index = input1.find_first_not_of("1234567890");
		side1_3 = input1.substr(0, index);
		input1.erase(0, index);

		//LINHA 2
		index = input2.find_first_not_of(" ");				// Encontrar o primeiro que nao é um espaço
		input2.erase(0, index);								// Cortar os espaços
		index = input2.find_first_not_of("1234567890");		// Ver o tamanho do número
		side2_1 = input2.substr(0, index);				// Isolar o número
		input2.erase(0, index);								// Remover o número

		index = input2.find_first_not_of(" ");
		input2.erase(0, index);
		index = input2.find_first_not_of("1234567890");
		side2_2 = input2.substr(0, index);
		input2.erase(0, index);

		index = input2.find_first_not_of(" ");
		input2.erase(0, index);
		index = input2.find_first_not_of("1234567890");
		side2_3 = input2.substr(0, index);
		input2.erase(0, index);

		//LINHA 3
		index = input3.find_first_not_of(" ");				// Encontrar o primeiro que nao é um espaço
		input3.erase(0, index);								// Cortar os espaços
		index = input3.find_first_not_of("1234567890");		// Ver o tamanho do número
		side3_1 = input3.substr(0, index);				// Isolar o número
		input3.erase(0, index);								// Remover o número

		index = input3.find_first_not_of(" ");
		input3.erase(0, index);
		index = input3.find_first_not_of("1234567890");
		side3_2 = input3.substr(0, index);
		input3.erase(0, index);

		index = input3.find_first_not_of(" ");
		input3.erase(0, index);
		index = input3.find_first_not_of("1234567890");
		side3_3 = input3.substr(0, index);
		input3.erase(0, index);

		triangle1 = side1_1 + " " + side2_1 + " " + side3_1;
		cout << triangle1 << endl;
		triangle2 = side1_2 + " " + side2_2 + " " + side3_2;
		cout << triangle2 << endl;
		triangle3 = side1_3 + " " + side2_3 + " " + side3_3;
		cout << triangle3 << endl;

		triangles.push_back(triangle1);
		triangles.push_back(triangle2);
		triangles.push_back(triangle3);
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

