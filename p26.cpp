#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define pb push_back

int main() {
	cout<<fixed<<setprecision(30);

	string tail;

	bool doRepeat;

	int longest=0;
	int longIndex;

	stringstream s;
	for (double i=1; i<100; i++) {
		//tail = to_string((double)1/(double)i);
		s<<(double)1/(double)i;
		s>>tail;
		cout<<"i is: "<<i<<" tail is: "<<tail<<endl;
		cout<<"real division is: "<<(double)1/(double)i<<endl;
		tail = tail.substr(2, tail.length()-1);
		for (int j=0; j<tail.length(); j++) {
			doRepeat=false;
			//for each digit in the tail, find all the reappearances
			//of that digit and continue to compare digits following
			//if they repeat all the way, record the i and the length
			//otherwise, start from the next digit until you've done
			//them all
			for (int k=j+1; k<tail.length(); k++) {
				if ((tail[j]==tail[k])&&(k!=j+1)) {
					doRepeat=true;
					for (int l=0; l<(k-j); l++) {
						if (tail[j+l]!=tail[k+l]) {
							doRepeat=false;
							break;
						}
					}
				}
				if (doRepeat) {
					if ((k-j)>longest) {
						cout<<"i is: "<<i<<" tail is: "<<tail<<endl;
						longest=k-j;
						longIndex=i;
					}
				}
			}
		}
	}

	cout<<longIndex<<endl;
	return 0;
}
