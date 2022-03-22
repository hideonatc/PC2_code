#include<iostream>
using namespace std;
void solve(int k){
	int sum=0;
	for(int i=1;;i++){
		sum+=i;
		if(sum>k&&sum-k<=i){
			printf("%d %d\n",sum-k,i);
			return;
		}
	}
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		solve(k);
	}
}