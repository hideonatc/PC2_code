#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,h[99999],tot=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>h[i];	
			tot+=h[i];
		}
		tot=tot/n;
		int ans=0;
		for(int i=0;i<n;i++)
			if(h[i]>tot)
				ans+=h[i]-tot;
		cout<<ans<<endl;
	}
}