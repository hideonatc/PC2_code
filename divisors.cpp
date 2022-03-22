#include<iostream>
#include<cmath>
using namespace std;
void solve(long int l,long int u){
	long int mx=-1,pos;
	for(long int i=l;i<=u;i++){
		int cnt=0;
		for(long int j=1;j<=sqrt(i);j++){
			if(i%j==0){
				if(j*j==i)
					cnt++;
				else
					cnt+=2;
			}
		}
		if(cnt>mx){
			mx=cnt;
			pos=i;
		}
	}
	printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",l,u,pos,mx);
}
int main(){
	int t;
	cin>>t;
	//int div[10001]={0};
	while(t--){
		long int l,u;
		cin>>l>>u;
		solve(l,u);
	}
}