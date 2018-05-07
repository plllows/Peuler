#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define pb push_back

int main() {
	vector<string> names = {};
	//cout<<names.max_size()<<endl;
	map<char, int> alphPos;

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i=0; i<alphabet.length(); i++) {
		alphPos.insert(pair<char, int> (alphabet[i], i+1));
	}

	//cout<<alphPos.find('C')->second<<endl; //returns 3

	//COLIN test
	//names.pb("COLIN"); scores.pb(0);

	string input;
	while (getline(cin, input, ',')) {
		names.pb(input.substr(1,input.length()-2));
		//cout<<"name is: "<<input.substr(1,input.length()-2)<<endl;
	}


	cout<<"name read complete"<<endl;
	for (int i=0; i<5; i++) {cout<<names[i]<<endl;}

	sort(names.begin(), names.end());
	cout<<"names sorted"<<endl;
	for (int i=0; i<5; i++) {cout<<names[i]<<endl;}

	ll tempSum = 0;
	ll grandSum = 0;
	for (int i=0; i<names.size(); i++) {
		tempSum=0;
		for (int j=0; j<names[i].length(); j++) {
			tempSum+=alphPos.find(names[i][j])->second; //returns 3
			//cout<<alphPos.find(names[i][j])->first<<" "<<alphPos.find(names[i][j])->second<<endl;
		}
		tempSum*=i+1;
		grandSum+=tempSum;
	}

	/*THE fuckers intended for the list to be non-zero indexed
	fuck them*/

	cout<<"GRANDSUM IS: "<<grandSum<<endl;

return 0;
}
