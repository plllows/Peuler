#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
	/*vector<int> temp = {0};
	cout<<"temp length is: "<<temp.size()<<endl;
	cout<<"temp[0] is: "<<temp[0]<<endl;
	cout<<"temp[1] is: "<<temp[1]<<endl;
	cout<<"temp[2] is: "<<temp[2]<<endl;
	cout<<"temp[3] is: "<<temp[3]<<endl;
	cout<<"temp[4] is: "<<temp[25554]<<endl;
	cout<<"temp length is: "<<temp.size()<<endl;
	*/
	//string bigNumber = "70368744177664";
	//cout<<"bigNumber is: "<<bigNumber<<endl;
	const int LIMIT = 1000;
	//int littleSum=0;
	//for (int i=0; i<bigNumber.length(); i++) {littleSum+=bigNumber[i]-'0';}
	//cout<<"littlesum (pow"<<LIMIT<<") is: "<<littleSum<<endl;


	int currentSize;
	ull original = 2;
	vector<int> digits = {2};
	//vector<vector<int>> digits
	//outer loop up to 1000 times
	for (int i=2; i<=LIMIT; i++) {
		//for every element in vector ints
		currentSize=digits.size();
		for (int j=currentSize-1; j>=0; j--) {
			//*2's the number inside each element
			digits[j]=digits[j]*original;
			//if the element then contains more than 6 digits
			//move digits beyond 6th to next element in vector
			//if next element doesn't exist, we will create it
			if (to_string(digits[j]).length()>6) {
				//cout<<"length exceeded by: "<<digits[j]<<endl;		
				string stringForm = to_string(digits[j]);
				//cout<<"stringForm is: "<<stringForm<<endl;
				string carry = stringForm.substr(0,stringForm.length()-6);
				//cout<<"carry is: "<<carry<<endl;
				string stay = stringForm.substr(stringForm.length()-6, 6);			
				//cout<<"stay is: "<<stay<<endl;
				digits[j]=stoi(stay);
				if (digits[j+1]==0) {
					//initialises next element with carry
					//cout<<"pushing back"<<endl;
					digits.push_back(stoi(carry));
					//cout<<digits[1]<<endl;
				} else {
					//else adds carry to next element's value
					digits[j+1]+=stoi(carry);
				}
			}
		}
	}
	//cout<<625334*2<<endl;
	//cout<<digits[0]<<endl;
	//cout<<digits[1]<<endl;
	//note -the place value doesn't matter when summing up the digits!
	
	//do a final sweep of vector elements to make sure
	//all carryovers have been successfully completed
	bool isComplete = false;
	while (!isComplete){
		//do it once for every element in vector
		isComplete=true;
		currentSize=digits.size();
		for (int j=currentSize-1; j>=0; j--) {
			if (to_string(digits[j]).length()>6) {
				isComplete=false;
				cout<<"CARRYOVER FIX NEEDED"<<endl;
				//cout<<"length exceeded by: "<<digits[j]<<endl;		
				string stringForm = to_string(digits[j]);
				//cout<<"stringForm is: "<<stringForm<<endl;
				string carry = stringForm.substr(0,stringForm.length()-6);
				//cout<<"carry is: "<<carry<<endl;
				string stay = stringForm.substr(stringForm.length()-6, 6);			
				//cout<<"stay is: "<<stay<<endl;
				digits[j]=stoi(stay);
				if (digits[j+1]==0) {
					//initialises next element with carry
					//cout<<"pushing back"<<endl;
					digits.push_back(stoi(carry));
					//cout<<digits[1]<<endl;
				} else {
					//else adds carry to next element's value
					digits[j+1]+=stoi(carry);
				}
			}
		}
	}	

	int digitSum = 0;
	string currentElement;
	for (int i=digits.size()-1; i>=0; i--) {
		cout<< digits[i]<<" ";
	}
	cout<<endl;
	for (int i=0; i<digits.size(); i++) {
		currentElement=to_string(digits[i]);
		for (int j=0; j<currentElement.length(); j++) {
			//cout<<"adding the digit: "<<currentElement[j]<<endl;
			digitSum+=currentElement[j]-'0';
		}
	}
	cout<<"total sum is: "<<digitSum<<endl;
	//cout<<"length is: "<<to_string(base).length()<<endl;
	
	return 0;
}

