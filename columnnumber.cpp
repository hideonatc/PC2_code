#include<iostream>
using namespace std;
int change(char c){
	return int(c-'A');
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int sum=0;
		for(int i=0;i<s.length();i++){
			sum*=26;
			sum+=change(s[i]);
		}
		printf("%d\n",sum);
	}
}