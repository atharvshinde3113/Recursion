#include<bits/stdc++.h>
using namespace std;

void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
	if(ind == n) {
		if(s == sum) {
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



int main() {

	int arr[] = {1, 2, 1};
	int n = 3;
	int sum = 2;
	vector<int> ds;
	printS(0, ds, 0, sum, arr, n);
	return 0;
}
//----------------------------------------------------------------
//String Subsequences
void func(vector<string> &ans, string output, int index, string s){
    if(index>=s.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    func(ans,output,index+1,s);
    //include
    char a = s[index];
    output.push_back(a);
    func(ans,output,index+1,s);    
}


vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> ans;
    string output;
    int index = 0;
    func(ans,output,index,s);
    return ans;

}