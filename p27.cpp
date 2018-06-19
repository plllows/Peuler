#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define ld long double
#define pb push_back

map<ll, bool> prime;

void show(vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	} cout<<endl;
}

bool isPrime(ll n) {
	if (n<0) return false;

	if (prime.find(n)!=prime.end()) {
		return prime.find(n)->second;
	}

	bool isPrime = true;
	ll limit = sqrt(n);
	//compare up to limit to determine primeness
	for (ll i=2; i<=limit; i++) {
		//cout<<"comparing "<<j<<" to "<<i<<endl;
		if (n%i==0) {
			//cout<<i<<" is not prime"<<endl;
			isPrime=false; break;
		}
	}
	if (isPrime) {
		prime[n]=true;
		return true;
	} else {
		prime[n]=false;
		return false;
	}
}

int main() {
	int maxa, maxb, maxcount, tempcount, initialb;
	ll res;
	//for each value of a
	for (int a=-999; a<=999; a++) {
		initialb = min(1, -1*a-1);
		cout<<a<<endl;
		//for each possible value of b
		for (int b=initialb; b<1000; b++) {
			tempcount=0;
			// cout<<b<<endl;
			//test n from 0 until not a prime
			for (ll n=0; n<LLONG_MAX; n++) {
				// cout<<n<<endl;
				//test if output is prime
				res = pow(n,2)+a*n+b;
				// cout<<"res is: "<<res<<endl;
				if (isPrime(res)) {
					// cout<<"prime found: "<<res<<endl;
					tempcount++;
					if (a==-1) {
						cout<<"res: "<<res<<endl;
					}
				} else if (tempcount>maxcount) {
					cout<<"highest streak: "<<tempcount<<endl;
					maxcount=tempcount;
					maxa=a;
					maxb=b;
					break;
				} else {
					break;
				}
			}
		}
	}
	cout<<"a, b: "<<maxa<<" "<<maxb<<endl;
	cout<<"a*b: "<<maxa*maxb<<endl;
return 0;
}