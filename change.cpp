#include<iostream>
using namespace std;
int rc[50001];
int solve(int n,int s,int arr[]){
	for(int i=0;i<=s;i++){
		for(int j=n;j>0;j--){
			if(i<arr[j-1])
				continue;
			if(rc[i]>rc[i-arr[j-1]]+1)
				rc[i]=rc[i-arr[j-1]]+1;
		}
	}
	return rc[s];
}
int main(){
	int t,n,s;
	cin>>t;
	while(t--&&cin>>n>>s){
		if(n==0&&s==0)
			break;
		for(int i=0;i<=s;i++)
			rc[i]=1e7;
		rc[0]=0;
		int narr[101];
		for(int i=0;i<n;i++)
			cin>>narr[i];
		cout<<solve(n,s,narr)<<endl;
	}
}