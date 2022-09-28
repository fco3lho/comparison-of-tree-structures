#include <iostream>
#include <fstream>

using namespace std;

void writeRandomNumbers(){
	float value;
	ofstream file;

	file.open("randomNumbers_500.txt");

	srand(time(nullptr));

	for(int i = 0; i < 500; i++){
		value = rand();
		file << value << endl;
	}

	file.close();
}

int main(){
	writeRandomNumbers();

	return 0;
}