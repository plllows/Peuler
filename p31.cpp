#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define TOTALCOINS 8
int sum=0;
int coins[] = {1,2,5,10,20,50,100,200};

void coin(int remainder, int coinlevel) {
	// cout<<"current highest: "<<coins[coinlevel]<<endl;
	if (coinlevel<0) {
		return;
	}

	int count=0;
	int contribute = coins[coinlevel]*count;
	// cout<<"initial contribute: "<<contribute<<endl;
	while (contribute<remainder) {
		// cout<<"calling coin from: "<<coinlevel<<" "<<contribute<<endl;
		coin(remainder-contribute, coinlevel-1);
		count++;
		contribute = coins[coinlevel]*count;
		// cout<<"new contribute: "<<contribute<<endl;
	}

	if (contribute==remainder) {
		sum++;
	}

	return;
}


int main() {
	coin(200, 7);
	cout<<sum<<endl;
	return 0;
}
