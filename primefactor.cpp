#include<iostream>
using namespace std;
int main(){
	int n,flag=0,m;
	cin>>n;
	m=n;
	cout<<n<<"=";
	for(int i=2;i<=m;i++){
		int cnt=0;
		if(m%i==0)
			flag=(flag?2:1);
		while(m%i==0){
			m/=i;
			cnt++;
		}
		if(cnt&&flag==2)
			cout<<"*";
		if(cnt==1)
			cout<<i;
		else if(cnt>1)
			printf("%d^%d",i,cnt);
	}
	cout<<endl;
}