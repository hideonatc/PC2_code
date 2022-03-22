#include<iostream>
#include<map>
using namespace std;
int dis(string str,int r){
	int k=0;
	for(int i=r+1;i<str.length();i++){
		if(str[i]<str[r])
			k++;
	}
	return k;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int l,n;
		cin>>l>>n;
		string arr[101];
		int ans[101];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++){
			int k=0;
			for(int j=0;j<l;j++){
				k+=dis(arr[i],j);
				//cout<<k<<endl;
			}	
			ans[i]=k;
		}
		for(int i=0;i<n;i++){
			int mn=1e7,o;
			for(int j=0;j<n;j++){
				if(mn>ans[j]){
					o=j;
					mn=ans[j];
				}
			}
			cout<<arr[o]<<endl;
			//cout<<ans[o]<<endl;
			ans[o]=1e7;
		}
		cout<<endl;
	}
}