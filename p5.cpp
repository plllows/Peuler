#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
ll smallestMult;
ll largestMult=1;
bool isMissing = true;
for (int i=1; i<21; i++) {
  largestMult*=i;
}
cout<<"largestmult is: "<<largestMult<<endl;

while (isMissing) {
for (ll i=20; i<=largestMult; i++) {
  isMissing=false;
  //cout<<"now testing i is: "<<i<<endl;
  for (int j=2; j<21; j++) {
    if (i%j!=0) {isMissing=true; break;}
  }
  if (!isMissing) {cout<<"smallestfound at: "<<i<<endl;smallestMult=i; break;}
}
}


cout<<smallestMult<<endl;
return 0;
}
