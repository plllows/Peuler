#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll Collatz(ll x, ll* array);

int main() {
	ll* array = new ll[1000000];
	//ll array[1000000];
	ll longestChain=0;
	ll chainProducer=0;
	ll result;
	for (ll i=0; i<999999; i++) {
		//if chain hasn't been counted
		if (array[i]==0) {
			//dont collect the return val - array[]
			//already set within Collatz
			result=Collatz(i+1, array);
			array[i]=result;
			//store longest chain
			if (result>longestChain) {longestChain=result; chainProducer=i+1;}
		}
		//if (i==624160) {cout<<"reached 624160"<<endl;}
		if (i==900000) {cout<<"reached 900k"<<endl;}
	}
	//for (int i=0; i<30; i++) {cout<<"i+1 is: "<<i+1<<", the chain length is: "<<array[i]<<endl;}
	cout<<"chain length of 12 is: "<<*(array+13)<<endl;
	cout<<"longest chain is: "<<longestChain<<", produced by: "<<chainProducer<<endl;
	return 0;
}

ll Collatz(ll x, ll* array) {
	//cout<<"now I have: "<<x<<endl;
	ll currentLink;
	if (x==1) {
		return 1;
	} else {
		//check if chain already exists
		if ((x<1000000)&&(array[x-1]!=0)) {
			return array[x-1];
		}
		//else, gets collatz length recursively
		//stores the value in appropriate place in array
		//IF it is less than 1000,000
		//then returns 1+currentLink to higher frame
		//x is even
		if (x%2==0) {
			//currentLink=Collatz(x/2, array);
			//if (((x/2)-1)<1000000) {*(array+(x/2)-1)=currentLink;}
			//return 1+currentLink;
			return 1+Collatz(x/2, array);
		}
		//x is odd
		//currentLink=Collatz(3*x+1, array);
		//if (((3*x+1)-1)<1000000) {*(array+(3*x+1)-1)=currentLink;}
		//return 1+currentLink;
		return 1+Collatz(3*x+1, array);
	}
}