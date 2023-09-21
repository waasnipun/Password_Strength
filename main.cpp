// C++ program to check if a given password is
// strong or not.
#include <iostream>
#include "src/passchecker.h"

using namespace std;

int main(int argc, char** argv)
{   
    string input;
    cout<<"Enter your password:\n";
    cin>>input;
	 
	string results = passchecker(input);
	cout << "Strength of password: " << results << endl;;
	return 0;
}