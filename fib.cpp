#include<iostream>
using namespace std;
int rec[1000]={0};
int fib(int n){
	if(rec[n])
		return rec[n];
	rec[n]=fib(n-1)+fib(n-2);
	return rec[n];
}
int main(){
	int k;
	cin>>k;
	rec[0]=rec[1]=1;
	while(k--){
		int n;
		cin>>n;
		printf("%d\n",fib(n-1));
	}
}