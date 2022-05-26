#include<iostream>
using namespace std;
int db(char c){
	int r = int(c-'0');
	r*=2;
	int t = r/10;
	return t+r%10;
}
int sg(char c){
	return int(c-'0');
}
int main(){
	string a[4];
	int t;
	cin>>t;
	while(t--){
		int total = 0;
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		for(int i=0;i<4;i++){
			total+=db(a[i][0])+sg(a[i][1])+db(a[i][2])+sg(a[i][3]);
		}
		if(total%10==0)
			cout<<"Valid"<<endl;
		else
			cout<<"Invalid"<<endl;
	}
}