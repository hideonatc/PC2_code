#include<iostream>
using namespace std;
bool s,used[300];
void solve(int v[],int m,int n,int now,int idx){
	//printf("solve(%d,%d,%d,%d)\n",m,n,now,idx);
	if(now==m){
		s = 1;
		return;
	}
	for(int i=idx;i<n;i++){
		if(used[i]||now+v[i]>m)
			continue;
		used[i]=1;
		solve(v,m,n,now+v[i],i);
		if(s) return;
		used[i]=0;
	}
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		s = 0;
		for(int i=0;i<300;i++)
			used[i] = 0;
		int m,n,v[301];
		cin>>m>>n;
		for(int i=0;i<n;i++)
			cin>>v[i];
		solve(v,m,n,0,0);
		if(!s)
			printf("impossible");
		else{
			bool f = 1;
			for(int i=0;i<n;i++)
				if(used[i]&&f){
					cout<<v[i];
					f = 0;
				}
				else if(used[i])
					cout<<" "<<v[i];
		}
		cout<<endl;
	}
}