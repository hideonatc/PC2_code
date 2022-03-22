#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
void init(int arr[]){
	arr[0]=1;
	int ind=0;
	int it2=0,it3=0,it5=0;
	int n2=arr[it2]*2,n3=arr[it3]*3,n5=arr[it5]*5;
	while(ind<1000){
		arr[++ind]=min(n2,min(n3,n5));
		//cout<<arr[ind]<<endl;
		if(arr[ind]==n2){
			it2++;
			n2=arr[it2]*2;
		}
		if(arr[ind]==n3){
			it3++;
			n3=arr[it3]*3;
		}
		if(arr[ind]==n5){
			it5++;
			n5=arr[it5]*5;
		}
	}
	return;
}
int main(){
	int ul[1001];
	int k,n;
	cin>>k;
	init(ul);
	while(k--){
		cin>>n;
		printf("%d\n",ul[n-1]);
	}
}