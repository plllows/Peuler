#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

ll number=600851475143;
ll largestPrime=1;

while (number!=1) {
  cout<<"number: "<<number<<endl;
  for (ll i=2; i<=number; i++) {
    //if i divides number, divide number by i, compare i to largest prime;
    if (number%i==0) {
      number=number/i; //if i is equal to number itself (i.e. last prime reached)
	//number will be equal to 1
      cout<<"i: "<<i<<endl;
      if (i>largestPrime) {largestPrime=i;}
      break;
    }
  }
}
cout<<"I am "<<largestPrime<<endl;
return 0;
}
