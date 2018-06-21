#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> permstore;

void perm(string pool, string construct="") {
	if (construct.length()==2) {
		permstore.push_back(construct);
		return;
	}
	string newcons;	
	for (int i=0; i<pool.length(); i++) {
		newcons = construct;
		newcons+=pool[i];
		perm(pool,newcons);
	}
}

vector<string> simplifiable;

void simplify(string a, string b) {
	double realsum = stod(a)/stod(b);
	//no trivial cases for us today
	if (realsum>=1) return;
	string str = a+b;
	string ta;
	string tb;
	double tempsum;
	//try to remove each digit and calculate division sum
	//and check that it is equal to realsum
	for (int i=0; i<str.length(); i++) {
		ta = a;
		tb = b;
		for (int j=0; j<ta.length(); j++) {
			if (ta[j]==str[i]) {
				ta.erase(j,1);
				j--;
			}
		}
		for (int j=0; j<tb.length(); j++) {
			if (tb[j]==str[i]) {
				tb.erase(j,1);
				j--;
			}
		}
		//it repeats because you remove the same digit equal to
		//the number of times it appears
		//we're not dividing by zero today boys
		if (tb=="" || ta=="") continue;
		tempsum = stod(ta)/stod(tb);
		if (tempsum==realsum) {
			cout<<"FOUND ONE: "<<str<<endl;
			simplifiable.push_back(str);
		}
	}
}

void show(vector<string> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	} cout<<endl;
}

int main() {
	string digits="123456789";
	perm(digits);
	for (int i=0; i<permstore.size(); i++) {
		for (int j=0; j<permstore.size(); j++) {
			simplify(permstore[i], permstore[j]);
		}
	}
	// show(simplifiable);
	show(permstore);
	return 0;
}
