#include<iostream>
#include<cstdio>
#include<inttypes.h>
#define ulli unsigned long long int
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ulli tmp = ((n+1)/2);
		tmp = tmp * tmp;
		tmp = tmp*2 - 1;
		ulli ans = tmp;
		ans = ans * (tmp-2);
		ans = ans * (tmp-4);
		printf("%llu\n",ans);
	}
}