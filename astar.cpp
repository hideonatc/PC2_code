#include<iostream>
#include<algorithm>
using namespace std;
int tab[24][2]={{0,1},{0,2},{0,3},{1,4},{1,5},{1,6},{2,4},{2,5},{2,6},{3,4},{3,5},{3,6},{4,7},{4,8},{4,9},{5,7},{5,8},{5,9},{6,7},{6,8},{6,9},{7,10},{8,10},{9,10}};
int mp[11][11],stageTab[6]={-1,0,3,6,9,11};
void init(void){
	for(int i=0;i<11;i++)
		for(int j=0;j<11;j++)
			mp[i][j]=1e8;
	for(int i=0;i<24;i++)
		cin>>mp[tab[i][0]][tab[i][1]];
	return;
}
int findmn(int arr[], bool v[]){
	int r=-1,mn=1e7;
	for(int i=0;i<81;i++){
		if(mn>arr[i]&&!v[i]){
			mn=arr[i];
			r=i;
		}
	}
	return r;
}
int checkStage(int n){
	for(int i=0;i<6;i++)
		if(n<=stageTab[i])
			return i;
	return -1;
}
int g[81][3];
int findans(int idx,int tar){
	int mn=1e8;
	for(int i=0;i<idx;i++){
		//printf("check g(%d,%d,%d) stage=%d\n",g[i][0],g[i][1],g[i][2],checkStage(g[i][2]));
		if(checkStage(g[i][2])==tar&&mn>g[i][0])
			mn=g[i][0];
	}
	return mn;
}
void astar(int tar){
	int f[81],idx=0;
	bool vis[81]={0};
	for(int i=0;i<81;i++)
		f[i]=1e8;
	for(int i=1;i<=3;i++){
		int h=1e8;
		for(int j=0;j<11;j++)
			if(mp[i][j]<h)
				h=mp[i][j];
		g[idx][0]=mp[0][i];
		g[idx][1]=0;
		g[idx][2]=i;
		f[idx]=g[idx][0]+h;
		//printf("f[%d]=%d+%d\n",idx,g[idx][0],h);
		idx++;
	}
	while(1){
		int mn=findmn(f,vis);
		//printf("mn=%d g[mn]=(%d,%d,%d) stage=%d\n",mn,g[mn][0],g[mn][1],g[mn][2],checkStage(g[mn][2]));
		if(tar==checkStage(g[mn][2])){
			cout<<findans(idx,tar)<<endl;
			break;
		}
		for(int i=1;i<11;i++){
			if(mp[g[mn][2]][i]<1e8){
				g[idx][0]=g[mn][0]+mp[g[mn][2]][i];
				g[idx][1]=g[mn][2];
				g[idx][2]=i;
				int h=1e8;
				for(int j=0;j<11;j++)
					if(mp[i][j]<h)
						h=mp[i][j];
				f[idx]=g[idx][0]+(h==1e8?0:h);
				//printf("f[%d]=%d+%d\n",idx,g[idx][0],h);
				idx++;
			}
		}
		vis[mn]=true;
	}
	return;
}
int main(){
	int t,tarStage;
	cin>>t;
	while(t--){
		init();
		cin>>tarStage;
		astar(tarStage+1);
	}
}
/*
7 9 1 65 88 79 84 103 88 99 77 120 65 97 50 96 69 42 150 75 65 77 93 810 */