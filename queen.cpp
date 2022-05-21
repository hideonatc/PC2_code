#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2){
		if(!x1)
			break;
		int a = abs(x1-x2), b = abs(y1-y2);
		if(!a&&!b)
			printf("0\n");
		else if(a==b||a==0||b==0)
			printf("1\n");
		else
			printf("2\n");
	}
}