#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define pb push_back

ul fact(ul n) {
	if ((n==0)||(n==1)) {return 1;}
	return n*fact(n-1);
}

void show(vector<string> v) {
	if (v.size()==0) return;

	for (int i=v.size()-1; i>=0; i--) {
		cout<<v[i]<<" ";
	} cout<<endl;
}

//fib sequence: 1, 1, 
//where first term is the 1th term BENFORD'S LAW

int main() {
	vector<string> MINUSONE = {"1"};
	vector<string> MINUSTWO = {"1"}; 
	vector<string> NEWTERM;
	// ul mOneTerm;
	// ul mTwoTerm;
	ul sum;
	ul carry;
	int counter=2;
	while (true/*MINUSONE.size()<111*/) {
		/*add every digit in minus one and minus two into minus three*/
		/*start adding from the lower digits and carry over if length exceeds 10*/
		carry=0;
		NEWTERM = {};
		cout<<"calculating: "<<counter+1<<"th fib"<<endl;
		for (int i=0; i<MINUSTWO.size(); i++) {

			sum = stoul(MINUSTWO[i])+stoul(MINUSONE[i])+carry;
			/*if sum exceeds 10 digits, subtract by 10 billion to remove carry, which is at most one*/
			//cout<<sum<<endl;
			carry=0;
			if (sum>999999999) {
				//cout<<"sum exceeded 999,999,999!"<<endl;
				//cout<<"sum is: "<<sum<<endl;
				//cout<<"stoi n-1 is: "<<stoul(MINUSONE[i])<<endl;
				//cout<<"stoi n-2 is: "<<stoul(MINUSTWO[i])<<endl;
				sum-=1000000000; 
				carry=1;

			}
			/*resulting term stored in newterm*/
			NEWTERM.pb(to_string(sum)); 
		}

		MINUSTWO = MINUSONE;
		MINUSONE = NEWTERM;

		show(NEWTERM);
		/*if we still have a term being carried over*/
		if (carry==1) {
			//cout<<"appending new slot"<<endl;
			MINUSTWO.pb("0");
			MINUSONE.pb("1");
		}

		cout<<"n-1 size: "<<MINUSONE.size()<<endl;
		cout<<"n-2 size: "<<MINUSTWO.size()<<endl;

		/*tracking which fibonacci is being calculated right now*/
		counter++; 
		if ((MINUSONE.size()>111)||(MINUSTWO.size()>111)) {
			cout<<"BROKEN"<<endl;
			break;
		}
	}

	// cout<<"n-1 size: "<<MINUSONE.size()<<endl;
	// cout<<"n-2 size: "<<MINUSTWO.size()<<endl;
	return 0;
}
