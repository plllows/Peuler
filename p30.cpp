#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int finalsum;

void show(vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
		finalsum+=v[i];
	} cout<<endl;
}

int main() {
	vector<int> po5 = vector<int> (10,10);
	for (int i=0; i<10; i++) {
		po5[i] = pow(i, 5);
	}

	int sum=0;
	string str;
	vector<int> fifthsums;
	for (int i=0; i<10000000; i++) {
		str=to_string(i);
		sum=0;
		for (int j=0; j<str.length(); j++) {
			//cout<<str[i]-'0'<<endl;
			sum+=po5[str[j]-'0'];
		}
		if (sum==i) {
			fifthsums.pb(i);
		}
	}
	show(fifthsums);
	cout<<finalsum-1<<endl;
	return 0;
}
