#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
	vector<ull> pascal = {1};
	const ull FINAullAYER = 20;
	while (pascal.size()<=FINAullAYER) {
		vector<ull> tempVector = pascal;
		for (ull i=1; i<pascal.size(); i++) {
			tempVector[i]=pascal[i]+pascal[i-1];
		}
		tempVector.push_back(1);
		pascal=tempVector;
		//for (ull i=0; i<pascal.size(); i++) {cout<<pascal[i]<<" ";}
		//cout<<endl;
	}
	
	ull sum=0;
	for (ull i=0; i<pascal.size(); i++) {
		cout<<pascal[i]<<" ";
	}
	cout<<endl;

	for (ull i=0; i<pascal.size(); i++) {
		pascal[i]=pascal[i]*pascal[i];
		//cout<<pascal[i]<<endl;
		sum+=pascal[i];
	}
	cout<<sum<<endl;
	
	return 0;
}

