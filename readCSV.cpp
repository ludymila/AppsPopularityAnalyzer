#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


double test_array[85][9];
int r=0;

ifstream indata;

double num1;			// variable for input value
double num2;			// variable for input value
double num3;			// variable for input value
double num4;			// variable for input value
double num5;			// variable for input value
double num6;			// variable for input value
double num7;			// variable for input value
double num8;			// variable for input value
double num9;			// variable for input value

int main(){
indata.open("test2.txt");	// opens the file

if(!indata)			// file couldn't be opened
{
	cerr << "Error: file could not be opened" << endl;
	
}

indata >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9;

test_array[r][0] = num1;
test_array[r][1] = num2;
test_array[r][2] = num3;
test_array[r][3] = num4;
test_array[r][4] = num5;
test_array[r][5] = num6;
test_array[r][6] = num7;
test_array[r][7] = num8;
test_array[r][8] = num9;

while (!indata.eof())		// keep reading until end-of-file
{
	cout << "The next number is " << num1 << num2 << num3 << num4 << num5 << num6 << num7 << num8 << num9 << endl;
	indata >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9;		// sets EOF flag if no value found

	r++;

	test_array[r][0] = num1;
	test_array[r][1] = num2;
	test_array[r][2] = num3;
	test_array[r][3] = num4;
	test_array[r][4] = num5;
	test_array[r][5] = num6;
	test_array[r][6] = num7;
	test_array[r][7] = num8;
	test_array[r][8] = num9;

}

indata.close();
cout << "End-of-file reached.." << endl;
return 0;
}