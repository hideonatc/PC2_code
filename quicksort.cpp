#include<iostream>
using namespace std;
int arr[999],n=0;
void print(void){
	for(int i=0;i<n-1;i++){
		if(i>0) cout<<" ";
		cout<<arr[i];
	}
	cout<<endl;
	return;
}
void qsort(int lb,int rb){
	if(lb>=rb)
		return;
	int p=arr[rb],l=lb,r=rb-1;
	while(1){
		while(p>arr[l])
			l++;
		while(p<=arr[r]&&r!=lb)
			r--;
		if(l<r){
			swap(arr[l],arr[r]);
			print();
		}
		else
			break;
	}
	swap(arr[rb],arr[l]);
	if(rb!=l)
		print();
	qsort(lb,l-1);
	qsort(l+1,rb);
	return;
}
int main(){
	while(cin>>arr[n++]){}
	print();
	qsort(0,n-2);
}