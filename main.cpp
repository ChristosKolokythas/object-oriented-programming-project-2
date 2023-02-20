#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h> 
#include <string>
#include "classes.h"

using namespace std;

int main(int argc, char *argv[]) {

	if (argc != 5) {													//checks the number of arguments
		cout << "You have entered " << argc << " arguments:" << "\n";
		return 0;
	}

	int N, NSegs, K, Percent;

	N = stoi(argv[1]);
	NSegs = stoi(argv[2]);
	K = stoi(argv[3]);
	Percent = stoi(argv[4]);

	cout << N << " " << NSegs << " " << K << " " << Percent << endl; // prints the arguments

	srand(time(NULL)); //for rand

	Attiki attiki{NSegs};

	for (int i = 0; i < N; i++) {

		attiki.Createvehicles();
		attiki.vechiclesmoving(K);
		cout << i + 1 << " cyrcle is completed" << endl;
	}

	return 0;

}