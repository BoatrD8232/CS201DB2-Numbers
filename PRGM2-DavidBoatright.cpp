//NAME: David Boatright
//PROGRAM: PGM2
//DESCRIPTION:Ask the user for four numbers, then organizes and displays those numbers.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Stores if the user wishes to repeat the program.
	char choice = 'y';
	// The size of the array of numbers. Can be changed to input more numbers.
	const int listSize = 4;
	int list[listSize];
	// The user input to be added to the array.
	int input;
	// Sum, for use in averaging.
	int sum;

	while (tolower(choice) != 'n') {
		sum = 0;
		// Gets user input, adds it to the array then adds it to a sum.
		for (int i = 0; i < listSize; i++){ 
			cout << "Enter number " << i + 1 <<": ";
			cin >> input;
			list[i] = input;
			sum += list[i];
		}

		// Selection sort- sorts the list.
		for (int i = 0; i < listSize - 1; i++) {
			// Temp stores data during a switch.
			int temp;
			// The index of the smallest item of the section of the array being searched.
			int smallestIn = i;
			// Searches for the smallest item in the array.
			for (int j = i + 1; j < listSize; j++) {
				if (list[j] < list[smallestIn]) {
					smallestIn = j;
				}
			}
			// Swaps the smallest item and the current item.
			temp = list[i];
			list[i] = list[smallestIn];
			list[smallestIn] = temp;
		}

		// Outputs the first and last numbers in the array.
		cout << "Largest: " << list[listSize - 1] << endl;
		cout << "Smallest: " << list[0] << endl;
		// Ouputs average to two decimal places.
		cout << fixed << setprecision(2) << "Average: " << sum / (float)listSize << endl;
		// Outputs the contents of the array forwards and backwards.
		cout << "Ascending Order:" << endl;
		for (int i = 0; i < listSize; i++) {
			cout << list[i] << endl;
		}
		cout << "Descending Order:" << endl;
		for (int i = listSize - 1; i >= 0; i--) {
			cout << list[i] << endl;
		}
		// Prompts the user to repeat the program.
		cout << "Go again? (y/n)";
		cin >> choice;
	}
}
