#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int sum=1;
	int addition;
	int ctr=1;
	//limit is 1998
	for (int i=2; i<1002; i+=2) {
		for (int j=0; j<4; j++) {
			cout<<j<<" ctr is: "<<ctr<<endl;
			ctr+=i;
			sum+=ctr;
		}
	}
	cout<<"sum of diagonals is: "<<sum<<endl;
	return 0;
}
