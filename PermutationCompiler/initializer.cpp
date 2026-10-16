#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(char * argv[], int argc)
{
	ofstream mein_file("permutation.h", ios::app);
	int p1;
	cout << "How many numbers do you want to permute?" << endl;
	cin >> p1;
	string func = "p";
	string temp = "";
	printf(" string is: %s\n",func);
	for(int i = p1; i>=6; i--)
	{
		temp = func;
		temp+=to_string(i);
		temp+="()";
		mein_file << "void " << temp << ";" << endl;	
	}
		mein_file << "};" << endl;

	ofstream mein_file2("permutation.cpp", ios::app);
	for(int j = p1; j>=6; j--)
	{
		temp = func;
		temp+=to_string(j);
	string append_cpp = "void permutation::p" + to_string(j) + "(){ \n for(int i = 0; i<this->size; i++) { \n 	swap(i,this->size-1,this->DataField);"  + temp + "();"  + "\n this->reset(); } }";
		mein_file2 << append_cpp << endl;
	}
	return 0;
}
