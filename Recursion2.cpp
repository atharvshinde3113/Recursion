#include <bits/stdc++.h> 
using namespace std;

void reverse(int i,  string& str){
	if(i>str.size()-i-1){
		return;
	}
	swap(str[i],str[str.size()-i-1]);
	reverse(i+1,str);
}

string reverseString(string str)
{
	// Write your code here.
	reverse(0,str);
	return str;
}


bool checkPalidrome(int i, string str){
	if(i>=str.size()-i-1){
		return true;
	}
	if(str[i] != str[str.size()-i-1]){
		return false;
	}
	checkPalidrome(i+1,str);
}

int main(){
	string str = "abba";
	string strr = reverseString(str);
	cout<<strr<<"\n";
	bool isP = checkPalidrome(0,str);
	cout<<isP;
	return 0;
}