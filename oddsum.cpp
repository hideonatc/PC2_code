#include<iostream>
using namespace std;
int main(){
	int t,cs=1;
	cin>>t;
	while(cs<t){
		int m,n;
		cin>>m>>n;
		if(m%2==0)m+=1;
		if(n%2==0)n-=1;
		printf("Case %d: %d\n",cs++,((m+n)/2)*((n-m)/2+1));
	}
}