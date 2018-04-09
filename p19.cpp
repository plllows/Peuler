#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int main() {
	vector<int> monthDays = {31,28,31,30,31,30,31,31,30,31,30,31};
	vector<int> leapDays =  {31,29,31,30,31,30,31,31,30,31,30,31};

	int dayCounter=1;
	int sunCounter=0;

	for (int i=1900; i<2001; i++) {
		if ((i%4==0)&&(i%100!=0)&&(i!=2000)) {
			for (int j=0;j<12; j++) {
				//for every month in the year
				for (int k=0; k<leapDays[j]; k++) {
					//count up all the days in each month
					if ((dayCounter%7==0)&&(k==0)&&(i>1900)) {sunCounter++;}
					dayCounter++;
				}
			}
		} else {
			//for non-leap years
			for (int j=0;j<12; j++) {
				//for every month in the year
				if (i==1901) {cout<<leapDays[j]<<endl;}
				for (int k=0; k<monthDays[j]; k++) {

					//count up all the days in each month
					if ((dayCounter%7==0)&&(k==0)&&(i>1900)) {sunCounter++;}
					dayCounter++;
				}
			}
		}
		
	}
	cout<<sunCounter<<endl;
	//1 Jan 1900 is a monday
	//Sep, Apr, June, Nov have 30 days
	//reset has 31
	//feb has 28 - 29 on leap years
	//count the sundays that fell on the first of month during the
	//20th century: 1 Jan 1901 to 31 Dec 2000
	

	return 0;
}


