#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){

	string in, line;
	vector<string> input;
	ifstream in_stream("Input Day 2.txt");


	while(getline(in_stream,in)){
		input.push_back(in);
	}

	int keypad[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

	unsigned char x = 1, y = 1;

	for(unsigned int i = 0; i < input.size(); i++){

		line = input.at(i);

		for(int j = 0; j < line.size(); j++){

			if(line.at(j) == 'U'){
				if(y != 0)
					y--;
			}

			if(line.at(j) == 'D'){
				if(y != 2)
					y++;
			}

			if(line.at(j) == 'L'){
				if(x != 0)
					x--;
			}

			if(line.at(j) == 'R'){
				if(x != 2)
					x++;
			}
		}

		cout << keypad[y][x];
	}




}
