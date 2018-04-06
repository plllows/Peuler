#include <bits/stdc++.h>

using namespace std;
//first ten digits of the sum of the following 150 numbers
/*
lets try a naive solution first
*/

int main() {
	//stores all the numbers into a grid
	string grid[100];
	for (int i=0; i<100; i++) {
		//cout<<"line"<<i<<endl;
		getline(cin,grid[i]);
		//if (i<10) {cout<<grid[i]<<endl;}
	}
	
	string fineGrid[100][50];
	for (int i=0; i<100; i++) {
		for (int j=0; j<50; j++) {
			fineGrid[i][j]=grid[i][j];
			if (i<10) {cout<<fineGrid[i][j];}
		}
		if (i<10) {cout<<endl;}
	}
	cout<<"fineGrid complete"<<endl;

	int tempSum;
	int sumInts[50];

	cout<<fineGrid[0][0]<<endl;
	cout<<fineGrid[1][0]<<endl;
	cout<<fineGrid[2][0]<<endl;
	cout<<fineGrid[3][0]<<endl;

	/*for every column (50 total), sum the bits*/
	for (int i=0; i<50; i++) {
		tempSum=0;
		for (int j=0; j<100; j++) {
			//jth row, ith column - starting from first col
			tempSum+=stoi(fineGrid[j][i]);
			//if (j<10) {cout<<fineGrid[j][i]<<endl;}
		}
		sumInts[i]=tempSum;
		//cout<<tempSum<<endl;
	}
	cout<<"sumStrings done"<<endl;

	/*for every sum, take take non-rightmost digits
	and sums stoi() to the next box in sumInts*/
	string tempInt;
	string carryOver;
	string stay;
	for (int i=49; i>0; i--) {
		tempInt=to_string(sumInts[i]);
		
		carryOver=tempInt.substr(0,tempInt.length()-1); //main holdback: issues with string splitting
		stay=tempInt.substr(tempInt.length()-1,1);
		cout<<"the integer is: "<<tempInt<<", the carry is: "<<carryOver<<", the stay is: "<<stay<<endl;
		//replace current integer
		sumInts[i]=stoi(stay);
		cout<<"the integer after is: "<<sumInts[i-1]<<endl;
		sumInts[i-1]+=stoi(carryOver);
		cout<<"now it is: "<<sumInts[i-1]<<endl;
	}

	cout<<"currently we have:"<<endl;
	cout<<sumInts[0]<<" "<<sumInts[1]<<" "<<sumInts[2]<<" "<<sumInts[3]<<" "<<endl;

	string currentString;
	int counter=0;
	while (currentString.length()<=10) {
		currentString+=to_string(sumInts[counter]);
		counter++;
	} 

	currentString=currentString.substr(0,10);

	cout<<"the sum is: "<<currentString<<endl;
	return 0;
}
