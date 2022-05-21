#include<iostream>
#include<cmath>
using namespace std;
long int a,b,tot;
long int cal(long int idx,long int ar[],long int n){
	a=a+ar[idx];
	b=b-ar[idx];
	long int k=(b!=0)?b/(n-idx-1):0;
	return abs(a/(idx+1)-k);
}
int main(){
	long int t,n,arr[999999];
	cin>>t;
	while(t--){
		cin>>n;
		tot = 0;
		for(long int i=0;i<n;i++){
			cin>>arr[i];
			tot += arr[i];
		}
		a=0;
		b=tot;
		long int mn = 1e9, idx;
		for(long int i=0;i<n;i++){
			long int tmp = cal(i,arr,n);
			if(tmp<mn){
				mn = tmp;
				idx = i;
			}
		}
		cout<<idx<<endl;
	}
}