#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

string reverseString(string letters) {
	//input is letters with the rightmost letter removed 
	string input = letters;
	input.erase(input.length()-1);
	//character is the removed letter from input
	string character;
	character+= letters[input.length()];
	//if input still has characters inside it
	if (input.length()!=0) {
		return character+=reverseString(input);
	} else {
		return character;
	}
}

int main() {
	string number;
	int fullSum=0;
	int letterSum=0;
	bool hasSmallerUnits;

	for (int i=1; i<=1000; i++) {
		//for every number between 1 and 1000
		number=to_string(i);
		cout<<number<<" ";
		number=reverseString(number);
		hasSmallerUnits=false;
		letterSum=0;
		for (int j=0; j<number.length(); j++) {
		//for every digit in that letter 	
			if (j==0) { //the units
				switch (number[j]) {
					//adds length of numbers
					case '1':
					letterSum+=3;//one
					hasSmallerUnits=true;
					break;
					case '2':
					letterSum+=3;//two
					hasSmallerUnits=true;
					break;
					case '3':
					letterSum+=5;//three
					hasSmallerUnits=true;
					break;
					case '4':
					letterSum+=4;//four
					hasSmallerUnits=true;
					break;
					case '5':
					letterSum+=4;//five
					hasSmallerUnits=true;
					break;
					case '6':
					letterSum+=3;//six
					hasSmallerUnits=true;
					break;
					case '7':
					letterSum+=5;//seven
					hasSmallerUnits=true;
					break;
					case '8':
					letterSum+=5;//eight
					hasSmallerUnits=true;
					break;
					case '9':
					letterSum+=4;//nine
					hasSmallerUnits=true;
					break;
				}
			} else if (j==1) { //the tens
				switch (number[j]) {
					case '1':
					//special cases between 10-20
					letterSum=0; //reset letterSum
					hasSmallerUnits=true;
					switch (number[j-1]) {
						//adds length of numbers
						case '0':
						letterSum+=3;//ten
						break;
						case '1':
						letterSum+=6;//eleven
						break;
						case '2':
						letterSum+=6;//twelve
						break;
						case '3':
						letterSum+=8;//thirteen
						break;
						case '4':
						letterSum+=8;//fourteen
						break;
						case '5':
						letterSum+=7;//fifteen
						break;
						case '6':
						letterSum+=7;//sixteen
						break;
						case '7':
						letterSum+=9;//seventeen
						break;
						case '8':
						letterSum+=8;//eighteen
						break;
						case '9':
						letterSum+=8;//nineteen
						break;
					}
					break;
					case '2':
					letterSum+=6;//twenty
					hasSmallerUnits=true;
					break;
					case '3':
					letterSum+=6;//thirty
					hasSmallerUnits=true;
					break;
					case '4':
					letterSum+=5;//forty
					hasSmallerUnits=true;
					break;
					case '5':
					letterSum+=5;//fifty
					hasSmallerUnits=true;
					break;
					case '6':
					letterSum+=5;//sixty
					hasSmallerUnits=true;
					break;
					case '7':
					letterSum+=7;//seventy
					hasSmallerUnits=true;
					break;
					case '8':
					letterSum+=6;//eighty
					hasSmallerUnits=true;
					break;
					case '9':
					letterSum+=6;//ninety
					hasSmallerUnits=true;
					break;
				}
			} else if (j==2) {
				switch (number[j]) {
					case '1':
					letterSum+=10;//one hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
					case '2':
					letterSum+=10;//two hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
					case '3':
					letterSum+=12;//three hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
					case '4':
					letterSum+=11;//four hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
					case '5':
					letterSum+=11;//five hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
					case '6':
					letterSum+=10;//six hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
					case '7':
					letterSum+=12;//seven hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
					case '8':
					letterSum+=12;//eight hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
					case '9':
					letterSum+=11;//nine hundred
					if (hasSmallerUnits) {letterSum+=3;}//and
					break;
				}
			} else if (j==3) {
				letterSum=11;//one thousand
			}
		}
		cout<<letterSum<<endl;
		fullSum+=letterSum;
	}
	cout<<fullSum<<endl;
	
	return 0;
}

