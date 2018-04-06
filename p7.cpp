#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main() {
bool isPrime;
vector<int> primes;

for (ll i=2; i<2147483647; i++) {
 isPrime=true;
 //j skips 0 and 1 and checks all up to the number itself
 for (ll j=2; j<i; j++) {
  if (i%j==0) {isPrime=false; break;}
 }
 if (isPrime) {primes.pb(i);}
 if (primes.size()==10001) {break;}
}
cout<<"first prime is: "<<primes.front()<<endl;
cout<<"primes' size is: "<<primes.size()<<endl;
cout<<"big prime is: "<<primes.back()<<endl;


return 0;
}
