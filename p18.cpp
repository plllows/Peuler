#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

/*int factorial(int n) {
	if (n==0) {return 1;}
	if (n==1) {return 1;}
	return n*factorial(n-1);
}*/

int main() {
	vector<string> triangle;
	vector<vector<int>> numbers;
	vector<int> numRow;
	string row;
	string _num;
	
	int counter=0;
	while (getline(cin, row)) {
		triangle.pb (row);
		numRow.clear();

		for (int i=0; i<=counter; i++) {
			_num=row.substr(0, row.find(" "));	
			//will use this array to output the string for the winner	
			numRow.pb (stoi(_num));
			row = row.substr(row.find(" ")+1);
		}
		
		numbers.pb (numRow);
		counter++;
	}

	/*
	for (int i=0; i<triangle.size(); i++) {
		cout<<triangle[i]<<endl;
	}
	for (int i=0; i<numbers.size(); i++) {
		for (int j=0; j<numbers[i].size(); j++) {
			cout<<numbers[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	int _sum;
	int maxSum=0;
	int rowCount=numbers.size();
	int maxPaths=1; for (int i=1; i<numbers.size(); i++) {maxPaths*=2;}

	vector<int> colCounter (rowCount,0);
	vector<int> colIter (rowCount,0);

	cout<<"NOW SUMMING:"<<endl;
	cout<<"#paths IS: "<<maxPaths<<endl;

	for (int i=0; i<maxPaths; i++) {
		_sum=0; 
		//cout<<"PATH NUMBER:"<<i<<endl;
		for (int j=0; j<rowCount; j++) {
			_sum+=numbers[j][colCounter[j]+colIter[j]]; //add all the numbers in a particular path
		}
		for (int j=rowCount-1; j>=0; j--) { //from the lowest node, search upwards for the first cc==0	
			if (colCounter[j]==0) {
				colCounter[j]++; //increment that to a one
				for (int k=rowCount-1; k>j; k--) {
					colCounter[k]=0; //change all the cc below that node to 0 (start at leftmost branch)
					colIter[k]=colCounter[j]+colIter[j]; 
					//iterators below are changed to equal the counter of the above (0 or 1) and the iter of the above
				}		
				break;
			}
		}
		if (_sum>maxSum) {maxSum=_sum;}
	}

	/*ngl, I have no idea why this works.*/

	cout<<maxSum<<endl;
	
	

	return 0;
}


