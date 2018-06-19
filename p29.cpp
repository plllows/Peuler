#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

//fuck integers use strings

int main() {
	set<string> pairs;
	set<string>::iterator iter;
	for (int a=2; a<=100; a++) {
		for (int b=2; b<=100; b++) {
			if (pairs.find(to_string(pow(a,b)))==pairs.end()) {
				pairs.insert(to_string(pow(a,b)));
			} 
		}
	}
	for (iter=pairs.begin(); iter!=pairs.end(); iter++) {
		cout<<*iter<<" "<<endl;
	}
	cout<<"number of distinct elements: "<<pairs.size()<<endl;
	return 0;
}
