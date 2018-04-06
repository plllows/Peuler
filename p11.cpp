#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
const int FOUR = 4;

string grid[20][20];
for (int i=0; i<20; i++) {
 for (int j=0; j<20; j++) {
  if (j!=19) {getline(cin,grid[i][j],' ');}
  else {getline(cin,grid[i][j]);}
 }
}

//holds temp value of products
int temp;

int hMax=0;
//searching horizontally
for (int i=0; i<20; i++) {
 for (int j=0; j<20-FOUR; j++) {
  temp=1;
  for (int k=0; k<FOUR; k++) {
   temp*=stoi(grid[i][j+k]);
  }
  if (temp>hMax) {hMax=temp; /*cout<<"new hMax: "<<hMax<<endl;*/}
 }
}
cout<<"horizontal max is: "<<hMax<<endl;

int BIGMAX = hMax;

int vMax=0;
//searching horizontally: all but last four line
for (int i=0; i<20-FOUR; i++) {
 //and every element in a column
 for (int j=0; j<20; j++) {
  temp=1;
  for (int k=0; k<FOUR; k++) {
   temp*=stoi(grid[i+k][j]);
  }
  if (temp>vMax) {vMax=temp; /*cout<<"new vMax: "<<vMax<<endl;*/}
 }
}
cout<<"vertical max is: "<<vMax<<endl;

if (vMax>BIGMAX) {BIGMAX=vMax;}

int forwardMax=0;
//searching forward
for (int i=0+FOUR; i<20; i++) {
 //and every element in a column
 for (int j=0; j<20-FOUR; j++) {
  temp=1;
  for (int k=0; k<FOUR; k++) {
   temp*=stoi(grid[i-k][j+k]);
  }
  if (temp>forwardMax) {forwardMax=temp; /*cout<<"new forwardMax: "<<forwardMax<<endl;*/}
 }
}
cout<<"forward max is: "<<forwardMax<<endl;

if (forwardMax>BIGMAX) {BIGMAX=forwardMax;}

int backwardMax=0;
//searching forward
for (int i=0; i<20-FOUR; i++) {
 //and every element in a column
 for (int j=0; j<20-FOUR; j++) {
  temp=1;
  for (int k=0; k<FOUR; k++) {
   temp*=stoi(grid[i+k][j+k]);
  }
  if (temp>backwardMax) {backwardMax=temp; /*cout<<"new backwardMax: "<<backwardMax<<endl;*/}
 }
}
cout<<"backward max is: "<<backwardMax<<endl;

if (backwardMax>BIGMAX) {BIGMAX=backwardMax;}

cout<<"BIGMAX is: "<<BIGMAX<<endl;

/*
for (int i=0; i<20; i++) {
 for (int j=0; j<20; j++) {
  cout<<grid[i][j]<<" ";
 }
 cout<<endl;
}
*/

return 0;
}
