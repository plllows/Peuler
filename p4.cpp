#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

ll largestPalindrome = 1;
string testPal;
bool isPal;

for (ll i=100; i<1000; i++) {
  for (ll j=100; j<1000; j++) {
    testPal=to_string(i*j);
    isPal=true;
    for (ll k=0; k<testPal.length()/2; k++) {
      if (testPal[k]!=testPal[testPal.length()-1-k]) {isPal=false; break;}
    }
    if (!isPal) {continue;};
    cout<<"found a palindrome: "<<i*j<<endl;
    if (i*j>largestPalindrome) {largestPalindrome=i*j;}
  }
}
cout<<"biggest palindrome: "<<largestPalindrome<<endl;
return 0;
}
