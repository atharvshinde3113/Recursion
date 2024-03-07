#include<bits/stdc++.h>
using namespace std;
// print subarray with sum k

//bool flag = false;
void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
	if(ind == n ) {
		if(s == sum) { //&& flag == false
			//flag = true;
			for(auto it: ds){
				cout << it << " ";				
			} 
			cout << endl;
		}
		return;
	}
	ds.push_back(arr[ind]);
	s += arr[ind];
	printS(ind+1, ds, s, sum, arr, n);
	s-= arr[ind];
	ds.pop_back();
	// not pick
	printS(ind+1,ds, s, sum, arr, n);
}

bool printSbool(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
	if(ind == n ) {
		//condition satisfied
		if(s == sum) { 
			for(auto it: ds){
				cout << it << " ";				
			} 
			cout << endl;
			return true;
		}
		//condition not satisfied
		else return false;
	}
	ds.push_back(arr[ind]);
	s += arr[ind];
	if(printSbool(ind+1, ds, s, sum, arr, n) == true){
		return true;
	}
	s-= arr[ind];
	ds.pop_back();
	// not pick
	if(printSbool(ind+1,ds, s, sum, arr, n) == true){
		return true;
	}
	return false;
}


int numberofsubseq(int ind, int s, int sum, int arr[], int n) {
	if(s>sum){
		return 0;
	}
	if(ind == n ) {
		if(s == sum) { 
			//condition satisfied
			return 1;
		}
		//condition not satisfied
		return 0;
	}
	//ds not required here
	//ds.push_back(arr[ind]);
	s += arr[ind];
	int l = numberofsubseq(ind+1,  s, sum, arr, n);
	s-= arr[ind];
	//ds.pop_back();
	// not pick
	int r = numberofsubseq(ind+1, s, sum, arr, n);
	return l+r;
}


int main() {

	int arr[] = {1, 2, 1};
	int n = 3;
	int sum = 2;
	vector<int> ds;
	//printSbool(0, ds, 0, sum, arr, n);
	cout<<numberofsubseq(0, 0, sum, arr, n);
	return 0;
} 
