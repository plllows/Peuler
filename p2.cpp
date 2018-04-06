#include <bits/stdc++.h>
using namespace std;

int main() {
int sum=2;
vector<int> fibonacci;
for (int i=0; i<3; i++) {
  fibonacci.push_back(i+1);
}
while (fibonacci.back()<4000000) {
	//cout<<"we're goin in boys"<<endl;
	fibonacci.push_back (fibonacci.back()+fibonacci[fibonacci.size()-2]);
	cout<<fibonacci.back()<<endl;
	if (fibonacci.back()%2==0) {
		sum+=fibonacci.back();
	}
}
cout<<sum<<endl;
return 0;
}
