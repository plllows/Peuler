#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
ll squaresum=0;
ll sumsquare=0;

for (int i=1; i<101; i++) {
sumsquare+=i*i;
squaresum+=i;
}

squaresum*=squaresum;
cout<<"answer is: "<< squaresum-sumsquare<<endl;
return 0;
}
