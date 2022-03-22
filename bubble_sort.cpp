#include<iostream>
using namespace std;
int bubblesort(int l,int arr[]){
	int s=0;
	for(int i=l-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				s++;
			}
		}
	}
	return s;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int l;
		cin>>l;
		int arr[51];
		for(int i=0;i<l;i++)
			cin>>arr[i];
		printf("Optimal swapping takes %d swaps.\n",bubblesort(l,arr));
	}
}