#include <bits/stdc++.h>
using namespace std;

#define ll long long

void show(vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	} cout<<endl;
}

int factorial(int a) {
	if (a<=1) return 1;
	int sum=1;
	for (int i=a; i>1; i--) {
		sum*=i;
	}
	return sum;
}

vector<int> fact (10,10);

int curious(int a) {
	string str = to_string(a);
	int tempsum=0;
	for (int i=0; i<str.length(); i++) {
		tempsum+=fact[str[i]-'0'];
	}
	if (tempsum==a) {
		return tempsum;
	}
	return 0;
}

int main() {
	for (int i=0; i<10; i++) {
		fact[i] = factorial(i);
	}
	show(fact);
	int sum=0;
	for (int i=3; i<99999999; i++) {
		sum+=curious(i);
	}
	cout<<sum<<endl;
	return 0;
}
