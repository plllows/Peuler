#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define ld long double
#define pb push_back

void show(vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	} cout<<endl;
}

int main() {
	vector<int> b;
	vector<int> a;
	for (int i=0; i<=1998; i++) {
		a.pb(i-1999);
	}
	show(a);
	
	bool isPrime;
	for (int i=2; i<=1000; i++) {
		isPrime=true;
		for (int j=2; j<=(i/j); j++) {
			cout<<"comparing "<<j<<" to "<<i<<endl;
			if (i%j==0) {
				//cout<<i<<" is not prime"<<endl;
				isPrime=false; break;
			}
		}
		if (isPrime) {
			cout<<i<<" is prime"<<endl;
			b.pb(i);
		}
	}
	show(b);

return 0;
}