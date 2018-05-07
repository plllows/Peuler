#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

//for every number under 10000
//find the sum of its proper divisors
//then for the sum, find the sum of its proper divisors 
//and check that this derived sum is equal to the original number

//if true, puch back that number into a vector to be summed

int main() {
	map<int, int> dSum;
	//assuming pairs are unique
	set<int> amiNums;
	int firstSum=0;
	int secondSum=0;

	dSum[1]==1;
	
	for (int i=1; i<10000; i++) {
		firstSum=0;
		secondSum=0;

		if (dSum.find(i)==dSum.end()) {
			//cout<<"STARTING WITH: "<<i<<endl;
			//cout<<"dividers are: ";
			for (int j=1; j<i; j++) {
				//finds all proper divisors of i
				//and sum them into firstSum
				if (i%j==0) {firstSum+=j;/*cout<<j<<" ";*/}
			} //cout<<endl;
			//enter key-value pair of i and its pdSum
			//into dSum[i]
			dSum[i]=firstSum;
			//cout<<"the sum is: "<<firstSum<<endl;
			
			//has firstSum's pdsum already been calculated?
			if (dSum.find(firstSum)!=dSum.end()) {
				//cout<<"searching complement: "<<firstSum<<endl;
				//cout<<"dividers are: ";
				for (int j=1; j<firstSum; j++) {
					//find all proper divisors of d(i) 
					//(the sum of proper divisors of i) 
					//and sums them into secondSum
					//into dSum[firstSum]
					if (firstSum%j==0) {secondSum+=j;/*cout<<j<<" ";*/}
				} if (firstSum==1) {secondSum+=1;/*cout<<1<<" ";*/} //cout<<endl;
				dSum[firstSum]=secondSum;
				//cout<<"the second sum is: "<<secondSum<<endl;
			} 
		} 
		
		//checks that the dSums of both the first and second
		//pdSums are equal
		if ((firstSum!=0)&&(secondSum!=0)&&(i==secondSum)&&(firstSum<10000)&&(secondSum<10000)&&(i!=firstSum)) {
			amiNums.insert(firstSum); amiNums.insert(secondSum);
		}//cout<<endl;
	}

	int amiSum=0;

	cout<<"ANNOUNCING ALL THE AMINUMS:"<<endl;
	cout<<"set size is: "<<amiNums.size()<<endl;
	for (set<int>::iterator i=amiNums.begin(); i!=amiNums.end(); i++) {
		if (*i<10000) {amiSum+=*i;}
		cout<<*i<<endl;
	}

	cout<<"THE FINAL SUM IS: "<<amiSum<<endl;

	return 0;
}
