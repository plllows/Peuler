#include <bits/stdc++.h>
using namespace std;
#define ll long long

int countFactors(ll);

int main() {
ll trinum=0;
ll i=1;
int factorCount;
bool isFound=false;

while(!isFound) {
 trinum+=i; i++;
 //cout<<"testing the number: "<<trinum<<endl;
 //we generate sequence using trinum and i, testing each for #factors
 factorCount=countFactors(trinum);
 //cout<<"number of divisors are: "<<factorCount<<endl;
 if (factorCount>500) {isFound=true;}
}
cout<<"social trig is: "<<trinum<<endl;

return 0;
}

//we need to pass the number and thats it
int countFactors(ll num) {
 int counter=0;
 int limit = num;
 for (int i=1; i<limit; i++) {
  if (num%i==0) {counter++; limit = num/i;};
 }
 return 2*counter;
}
