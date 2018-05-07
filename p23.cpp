#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define pb push_back

int main() {
	vector<int> abundant = {};

	int pdSum=0;

	//cout<<"FINDING PD SUMS"<<endl;
	//for every number up to the limit
	for (int i=12; i<=28123; i++) {
		//calculate the pd sum
		pdSum=0;
		for (int j=1; j<i; j++) {
			//by checking whether a number smaller than it
			//divides into it evenly
			if (i%j==0) {pdSum+=j;}
		}
		//check if sum exceeds the number itself
		//and if so, mark it as an abundant number
		if (pdSum>i) {
			abundant.pb(i); 
			//if (i==12) {cout<<"12 found"<<endl;}
		}
	}

	//cout<<"CREATING SET OF TWO ABUNDANT NUMBERS' SUMS"<<endl;
	//create a set of all the sums of two abundant numbers
	set<int> abundSum = {};
	//for each abundant number
	for (int i=0; i<abundant.size(); i++) {
		//add the sum of that number and all numbers (one at a time)
		//following and including itself
		for (int j=i; j<abundant.size(); j++) {
			abundSum.insert(abundant[i]+abundant[j]);
			//if (abundant[i]+abundant[j]==24) {cout<<"24 found"<<endl;}
		}
	}

	//cout<<"FINDING THE SUM OF NOT ABUNDSUM INTEGERS"<<endl;
	int grandSum=0;
	//for every positive integer from 1 to the limit
	for (int i=1; i<28123; i++) {
		if (abundSum.find(i)==abundSum.end()) {
			//if (i==24) {cout<<"SOMETHIN WRONG"<<endl;}
			//if (i==28123) {cout<<"SOMETHIN WRONG"<<endl;}
			grandSum+=i;
		}

	}
	cout<<grandSum<<endl;

return 0;
}
