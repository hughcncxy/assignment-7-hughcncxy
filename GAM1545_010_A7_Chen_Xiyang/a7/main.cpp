//Xiyang Chen 040995747 GAME 1545 A7 

#include <iostream>
#include <random>
using namespace std;

int RandomInt(int min, int max);
//This function is used to generate a random number within certain range.
int GetInteger();
//This function will make sure the input is an integer.

int main()
{
	const int size = 500; //size of arr
	int arr[size] = {}; //an arr contains 500 
	int input = 0; //to store the input as a local variable

	//generate the array
	for (int i = 0; i < 10000; i++) arr[RandomInt(1, size) - 1] += 1;

	//user interface
	cout << "Welcome to my amazing number generator!"
		<< endl << "I have randomly generated 10,000 numbers."
		<< endl << "Enter a number, and I shall tell you the amount of times it appears."
		<< endl << "(To exit from the app, please enter -1.)"
		<< endl << "Please enter your number: " << endl;

	//input a number, and answer repetition.
	input = GetInteger();
	cout << input << " appears " << arr[input - 1] << " times. " << endl;

	//in case the user wants to re-enter a number or exit
	do {	
		cout << endl << endl << "Would you like to enter another number?" 
			<< endl	<< "(To exit from the app, please enter -1.)" << endl;

		//re-enter a number or check to exit
		input = GetInteger();
		cout << input << " appears " << arr[input - 1] << " times. " << endl;

	} while (input != -1);//checking condition, -1 to exit

	return 0;

}

int RandomInt(int min, int max) {
	random_device seed;
	mt19937 mersenneTwister(seed());
	uniform_int_distribution<int> distribution(min, max);
	return distribution(mersenneTwister);

}

int GetInteger() {
	int a = 0;
	while (!(cin >> a)) {// make sure the input is an integer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

	if (a == -1) { //exit when user enter -1
		cout << "\nThank you for using number generator. Bye-bye!\n\n\n" << endl;
		system("pause");
		exit(0);

	}
	else if (a < 1 || a > 500) { // if the input is out of range, exit the app.
		cout << "ERROR: You must enter an integer between 1 and 500!\n\n\n" << endl;
		system("pause");
		exit(0);

	} else return a;

}

