#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
int a;
int b;
int c;
bool isFound=false;

for (a=0; a<334; a++) {
 b=a+1;
 c=1000-b-a;
 while(b<c) {
  if ((a*a+b*b)==(c*c)) {
   cout<<"triplet found, "<<a<<", "<<b<<", "<<c<<endl;
   isFound=true;
   break;
  } else {
   b++;
   c--;
  }
 }
 if (isFound) {break;}
}
cout<<"product is: "<<a*b*c<<endl;

return 0;
}
