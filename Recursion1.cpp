#include <bits/stdc++.h>
using namespace std;

int sum1( int n){
	if(n == 0 ){
		return n;
	}
	return n+sum1(n-1);

}

int fact(int n){
	if(n==1){
		return 1;
	}
	return n*fact(n-1);
}
double myPow(double x, int n) {
      if(n==0){
          return 1;
      } 
      if(n<0){
          return 1 / myPow(x, -n);
      }
      if(n%2==1){
          return x*myPow(x,n-1);
      }
      return myPow(x*x,n-1); 
    }

int fib1(int n){
	if(n==1||n==2){
		return 1;
	}
	return fib1(n-1)+fib1(n-2);
}
//always reduce n
//base case to stop going deep
//nth term in terms of n 


	
bool isSorted(int arr[],int size){
	for(int i = 0; i< size ; i++){
		if(arr[i]>arr[i+1]){
			return false;
		}
	}
return true;
}
int sumrec(int arr[], int size){
	if(size == 0){
		return 0;
	}
	if(size == 1){
		return arr[0];
	}

	int sum = arr[0] + sumrec(arr+1,size-1);
	return sum;
}

bool isSortedRec(int arr[], int size){
	if(size == 0 || size == 1){
		return true;
	}
	if (arr[0]>arr[1]){
		return false;
	}
	else{
		return isSortedRec(arr+1,size-1);
	}
}

bool isPresent(int arr[], int size, int key){
	if(size == 0){
		return 0;
	}
	if(arr[0] == key){
		return 1;
	}
	return isPresent(arr+1,size-1,key);
}

int binarySearch(int *arr, int low, int high, int key){
	if(low>high){
		return 0;
	}
	int mid = (low + high) / 2;
	if(arr[mid] == key){
		return mid;
	}
	if(arr[mid]<key){
		binarySearch(arr,mid+1,high,key);
	}
	else{
		binarySearch(arr,low,mid-1,key);
	}
}



void reverseStr(string str){
	int i =0;
	int j = str.size() -1;
	while(i<j){
		swap(str[i],str[j]);
		i++;j--;
	}
	cout<<str;
}

void reverseStrrec2(int i, int j, string &str){
	if(i>j){
		return;
	}
	swap(str[i], str[j]);
	reverseStrrec2(i+1,j-1,str);

}



int main(){
	int sum;
	int fib = fact(5);
	//cout<<fib;
	//double a = myPow(2,10);
	//cout<<a;
	//saydigits(123);
	// vector<int> arr = {1,2,3,4,5};
	// int size = arr.size();
	int arr[5] = {1,2,3,4,5};
	int size = 5;
	//bool a = isSortedRec(arr,size);
	//bool b = isSorted(arr,size);
	//int sum2 = sumrec(arr,size);
	//cout<<sum2;
	int key = 9;
	bool  c= isPresent(arr,size,key);
	//cout<<c;
	int a = binarySearch(arr,0,5,9);
	//cout<<a;
	//reverseStr("abc");
	string str = "basado";
	reverseStrrec2(0,str.size()-1,str);
	cout<<str;
	return 0;
}