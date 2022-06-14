#include<iostream>
using namespace std;
int mp[26][26];
char tab[26];
int findchar(char c,int id){
	for(int i=0;i<id;i++){
		if(tab[i]==c)
			return i;
	}
	return -1;
}
void solve(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(mp[j][k]>mp[j][i]+mp[i][k])
					mp[j][k]=mp[j][i]+mp[i][k];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mp[i][j]>5000)
				cout<<"INF";
			else cout<<mp[i][j];
			if(j==n-1)
				cout<<endl;
			else
				cout<<" ";
		}
	}
}
int main(){
	int n,m,idx=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mp[i][j]=(i==j?0:1e5);
	for(int i=0;i<m;i++){
		char a,b;
		int ip,x,y;
		cin>>a>>b>>ip;
		x=findchar(a,idx);
		if(x==-1){
			x=idx;
			tab[idx++]=a;
		}
		y=findchar(b,idx);
		if(y==-1){
			y=idx;
			tab[idx++]=b;
		}
		mp[x][y]=ip;
	}
	solve(n);
}