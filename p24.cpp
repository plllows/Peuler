#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define pb push_back

ul fact(ul n) {
	if ((n==0)||(n==1)) {return 1;}
	return n*fact(n-1);
}

vector<string> store = {};

void Perm(string s, int n=0) {  
	char temp = ' ';  
	if (n==s.length()-1) {
		//cout<<s<<endl; 
		store.pb(s);
		return;
	}  
	string token = s;  //cout<<"currently n is: "<<n<<endl;  
	for (int i=n; i<token.length(); i++) {   
		token = s;   
		temp=token[n];   
		token[n]=token[i];   
		token[i]=temp;   
		Perm(token, n+1);  
	}  
}

int main() {
	Perm("0123456789");
	sort(store.begin(), store.end());
	cout<<store[999999]<<endl;
	return 0;
}
