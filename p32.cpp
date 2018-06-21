#include <bits/stdc++.h>
using namespace std;

#define ll long long

int pandigital(int a, int b) {
	bool bitmap[] = {false,false,false,false,false,false,false,false,false};
	string str = to_string(a) + to_string(b);
	for (int i=0; i<str.length(); i++) {
		if (str[i]=='0') {
			return 0;
		}
		if (bitmap[str[i]-'0'-1]==false) {
			bitmap[i]=true;
		} else {
			return 0;
		}
	}
	return a*b;
}

vector<string> permstore;

void perm(string pool, string construct="") {
	if (construct.length()==5) {
		permstore.push_back(construct);
		return;
	}
	string temp;
	string newcons;	
	for (int i=0; i<pool.length(); i++) {
		temp=pool;
		newcons = construct;
		newcons+=pool[i];
		temp.erase(i,1);
		perm(temp,newcons);
	}
}

void show(vector<string> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	} cout<<endl;
}

int main() {
	string digits="123456789";
	//calculate 2, 3
	perm(digits);
	show(permstore);

	int productsum=0;
	for (int i=0; i<permstore.size(); i++) {
		productsum+=pandigital(stoi(permstore[i].substr(0,1)),stoi(permstore[i].substr(1,4)));
		productsum+=pandigital(stoi(permstore[i].substr(0,2)),stoi(permstore[i].substr(2,3)));
	}
	cout<<productsum<<endl;
	//calculate 1, 4
	return 0;
}
