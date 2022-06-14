#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
using namespace std;
queue<vector<vector<int>>> Myq;
set<vector<vector<int>>> Mys;
int tarArr[3][3],dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool eq(vector<vector<int>> arr){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(arr[i][j]!=tarArr[i][j])
				return false;
	return true;
}
bool legalmove(int x,int y,int d){
	if(x+dir[d][0]<3&&x+dir[d][0]>=0){
		if(y+dir[d][1]<3&&y+dir[d][1]>=0)
			return true;
	}
	return false;
}
void printArr(vector<vector<int>> arr){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j];
			if(j!=2)
				cout<<" ";
			else
				cout<<endl;
		}
	}
	return;
}
vector<vector<int>> move(vector<vector<int>> arr,int x,int y,int d){
	//printf("move %d %d %d\n",x,y,d);
	//printArr(arr);
	int tmp = arr[x+dir[d][0]][y+dir[d][1]];
	arr[x+dir[d][0]][y+dir[d][1]]=0;
	arr[x][y]=tmp;
	return arr;
}
int findx(vector<vector<int>> arr){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(arr[i][j]==0)
				return i;
}
int findy(vector<vector<int>> arr){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(arr[i][j]==0)
				return j;
}
bool flag=0;
void bfs(vector<vector<int>> arr,int x,int y){
	if(flag)
		return;
	printArr(arr);
	if(eq(arr)){
		flag=1;
		return;
	}
	//printf("bfs %d %d\n",x,y);	
	vector<vector<int>> v{{0,0,0},{0,0,0},{0,0,0}};
	for(int i=0;i<4;i++){
		if(legalmove(x,y,i)){
			v=arr;
			v=move(v,x,y,i);
			if(Mys.count(v))
				continue;
			Mys.insert(v);
			Myq.push(v);
		}
	}
	if(flag)
		return;
	vector<vector<int>> bu = Myq.front();
	int nx=findx(bu),ny=findy(bu);
	Myq.pop();
	bfs(bu,nx,ny);
	return;
}
int main(){
	vector<vector<int>> initArr{{0,0,0},{0,0,0},{0,0,0}};
	int x,y;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			cin>>initArr[i][j];
			if(initArr[i][j]==0){
				x=i;
				y=j;
			}
		}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>tarArr[i][j];
	Mys.insert(initArr);
	bfs(initArr,x,y);
}