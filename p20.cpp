#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define pb push_back

//need to implement own multiplication function
//use a string vector to store successive multiplication 
//results, and carry digits over to the next place as 
//necessary

ul factorial(ul n) {
	if (n==0) {return 1;}
	if (n==1) {return 1;}
	return n*factorial(n-1);
}

int main() {
	//each element stores up to 6 digits
	//a multiplication by factorial is done to each element
	//and then, all digits beyond 6 are carried over to the element to the left
	//if no more element to the left, a new element is inserted at the beginning position
	string tempStr;

	vector<string> bigMult = {"1"}; 
	const ul FACTOF = 100;
	const ul digLim=6;

	int currentlength;

	string pushForward;

	/*THE ISSUE WAS NOT WITH STRING SPLITTING
	ITS WITH YOU CHANGING THE INCREMENT/ENDING CONDITION
	IN A LOOP YOU FUCKIN IDIOT*/

	//cout<<"we're calculating factorial of "<<FACTOF;
	//cout<<" and it is: "<<factorial(FACTOF)<<endl;

	for (int i=1; i<=FACTOF; i++) {
		currentlength=bigMult.size();
		pushForward="";
		for (int j=0; j<currentlength; j++) {
			//multiplies elements of bigMult by i starting from the largest
			bigMult[j]=to_string(stoi(bigMult[j])*i);
			//cout<<bigMult[j]<<endl;
			if (bigMult[j].length()>digLim) {
				//if it causes the element to exceed the digit count
				if (j==0) {
					//cout<<"[j==0] ";
					//if our element is the leftmost
					//extract the extra digits
					pushForward=bigMult[0].substr(0,bigMult[0].length()-digLim);
					//cout<<"pushing back: "<<pushForward<<" ";
					//replace original element with not extra digits
					tempStr=bigMult[0].substr(bigMult[0].length()-digLim, bigMult[0].length());
					//cout<<"leaving behind: "<<tempStr<<endl;
					bigMult[0]=tempStr;

				} else {
					tempStr=bigMult[j].substr(0,bigMult[j].length()-digLim);
					bigMult[j-1]=to_string(stoi(bigMult[j-1])+stoi(tempStr));
					//cout<<"adding forward: "<<tempStr<<" ";
					//replace original element with not extra digits
					tempStr=bigMult[j].substr(bigMult[j].length()-digLim, bigMult[j].length());
					//cout<<"leaving behind: "<<tempStr<<endl;
					bigMult[j]=tempStr;
				}
			}
		}
		if(pushForward!="") {bigMult.insert(bigMult.begin(), pushForward);}

		//cout<<factorial(i)<<" ";
		//cout<<"FACT CURRENT: ";
		for (int j=0; j<bigMult.size(); j++) {
			if (j!=0) {while(bigMult[j].length()<digLim) {bigMult[j].insert(0,"0");}}
			//cout<<bigMult[j]<<" ";
		} //cout<<endl;
	}

	string res = "";
	for (int i=0; i<bigMult.size(); i++) {
		cout<<bigMult[i]<<"";
		res+=bigMult[i];
	} cout<<endl;

	int sum=0;
	for (int i=0; i<res.length(); i++) {
		sum+=res[i]-'0';
	}

	cout<<"SUM IS: "<<sum<<endl;

return 0;
}
