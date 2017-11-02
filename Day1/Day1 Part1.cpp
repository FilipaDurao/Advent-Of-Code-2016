#include <iostream>
#include <fstream>

using namespace std;


int main(){

	unsigned char direction = 0;		// 0 - N, 1 - E, 2 - S, 3 - O
	unsigned long distance;
	unsigned int delta;
	long x = 0, y = 0;
	int index;
	string input, move;

	ifstream in_stream("Input Day 1.txt");

	if(in_stream.is_open())
		getline(in_stream, input);

	while(true){

		index = input.find_first_of(',');

		if(index == string::npos){

			move = input;

			if(move[0] == 'R'){
				direction = (direction + 1)%4;
			}
			else{
				if(direction == 0){
					direction = 3;
				}
				else
					direction--;
			}

			move.erase(0, 1);
			delta = stoi(move);

			switch (direction){
			case 0:
				y += delta;
				break;

			case 1:
				x += delta;
				break;

			case 2:
				y -= delta;
				break;

			case 3:
				x -= delta;
			}

			break;
		}

		move = input.substr(0, index);
		input.erase(0, index + 2);

		if(move[0] == 'R'){
			direction = (direction + 1)%4;
		}
		else{
			if(direction == 0){
				direction = 3;
			}
			else
				direction--;
		}

		move.erase(0, 1);
		delta = stoi(move);

		switch (direction){
		case 0:
			y += delta;
			break;

		case 1:
			x += delta;
			break;

		case 2:
			y -= delta;
			break;

		case 3:
			x -= delta;
		}

	}

	cout << abs(x)+abs(y);

	return 0;
}
