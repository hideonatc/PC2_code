#include<iostream>
using namespace std;
int left2(int a[]){
	if(a[1]){
		a[1] -= 1;
		return 1;
	}
	if(a[0]){
		a[0] = max(a[0]-4,0);
		return 1;
	}
	return 0;
}
int case5(int a[]){
	if(a[4]==0)
		return 0;
	int r = a[4];
	a[0] = max(a[0]-r*11,0);
	return r;
}
int case4(int a[]){
	if(a[3]==0)
		return 0;
	int r = a[3], tmp;
	for(int i=0;i<5*r;i++)
		tmp = left2(a);
	return r;
}
int case3(int a[]){
	int r = 0;
	while(1){
		r++;
		int flag;
		if(a[2]>=4){
			a[2] -= 4;
			continue;
		}
		if(a[2]==1){
			for(int i=0;i<5;i++)
				flag = left2(a);
			a[0] = max(a[0]-7,0);
			r++;
			break;
		}
		else if(a[2]==2){
			for(int i=0;i<3;i++)
				flag = left2(a);
			a[0] = max(a[0]-6,0);
			r++;
			break;
		}
		else if(a[2]==3){
			flag = left2(a);
			a[0] = max(a[0]-5,0);
			r++;
			break;
		}
		else
			break;
	}
	return r-1;
}
int case2(int a[]){
	int r = 0;
	while(++r){
		int flag = 1;
		for(int i=0;i<9;i++)
			flag = left2(a);
		if(!flag)
			break;
	}
	return r-1;
}
int case1(int a[]){
	return !a[0]?0:(a[0]/36)+1;
}
void pt(int a[],int ans){
	printf("%d %d %d %d %d %d\n%d\n",a[0],a[1],a[2],a[3],a[4],a[5],ans);
	return;
}
int main(){
	int arr[6];
	while(1){
		cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5];
		if(!(arr[0]||arr[1]||arr[2]||arr[3]||arr[4]||arr[5]))
			break;
		int ans = 0;
		//pt(arr,ans);
		ans += arr[5];
		//pt(arr,ans);
		ans += case5(arr);
		//pt(arr,ans);
		ans += case4(arr);
		//pt(arr,ans);
		ans += case3(arr);
		//pt(arr,ans);
		ans += case2(arr);
		//pt(arr,ans);
		ans += case1(arr);
		//pt(arr,ans);
		cout<<ans<<endl;
	}
}