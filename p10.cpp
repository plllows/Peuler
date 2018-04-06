#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
ll sum=0;
vector<int> primes; //stores all primes we've found so far
bool isPrime; //1 is a prime number> is it???
int pCount;
int Cap;

for (int i=2; i<2000000; i++) {
 isPrime=true;
 pCount=primes.size();
 for (int j=0; j<pCount; j++) {
  if (i%primes[j]==0) {isPrime=false; /*cout<<"NOTAPRIME"<<endl;*/} 
  else if (primes[j]>(i/primes[j])) {break;}
 }
 if (isPrime) {primes.push_back(i); sum+=i; cout<<primes.size()<<endl;/*cout<<"prime found: "<<i<<endl;*/}
}

cout<<"primesum is: "<<sum<<endl;

return 0;
}
