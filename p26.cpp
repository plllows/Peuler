#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define pb push_back

int main() {
	cout<<fixed<<setprecision(30);

	string tail;

	bool doRepeat;

	int longest=0;
	int longIndex;

	stringstream s;
	for (double i=1; i<100; i++) {
		//tail = to_string((double)1/(double)i);
		s<<(double)1/(double)i;
		s>>tail;
		cout<<"i is: "<<i<<" tail is: "<<tail<<endl;
		cout<<"real division is: "<<(double)1/(double)i<<endl;
		tail = tail.substr(2, tail.length()-1);
		cout<<tail<<endl;
		for (int j=0; j<tail.length(); j++) {
			doRepeat=false;
		}
	}

	cout<<longIndex<<endl;
	return 0;
}
