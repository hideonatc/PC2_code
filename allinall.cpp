#include<iostream>
using namespace std;
void check_sub(string s,string t){
	int j=0,flag=0;
	for(int i=0;i<s.length();i++){
		while(j<t.length()){
			if(s[i]==t[j]&&i==s.length()-1)
				flag=1;
			if(s[i]==t[j++]) break;
		}
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	return;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string s,t;
		cin>>s>>t;
		check_sub(s,t);
	}
}