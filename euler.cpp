#include<iostream>
using namespace std;
bool pri[100000]={0};
int mxid=2;
bool checkp(int a,int b){
	if(a<=mxid&&pri[a])
		return b%a==0?0:1;
	for(int i=2;i<a;i++){
		if(a%i==0&&b%i==0)
			return 0;
	}
	return 1;
}
int solve(int n){
	if(n<=mxid&&pri[n])
		return n-1;
	int r=1;
	for(int i=2;i<n;i++){
		if(mxid>i){
			int flag=1;
			for(int j=2;j<i/2+1;j++){
				if(i%j==0){
					flag=0;
					break;
				}
			}
			pri[i]=flag;
		}
		if(i>n/2+1&&r==i){
			r=n-1;
			break;
		}
		r+=checkp(i,n);
	}
	mxid=n;
	return r;
}
int main(){
	pri[2]=1;
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<solve(n)<<endl;
	}
}