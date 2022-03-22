#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(!n) break;
		int arr[2000001];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n-1;i++)
			printf("%d ",arr[i]);
		printf("%d\n",arr[n-1]);
	}
}