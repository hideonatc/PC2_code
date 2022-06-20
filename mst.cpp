#include<iostream>
#include<cstdlib>
#include<cmath>
#include<set>
using namespace std;
struct D{
	int x;
	int y;
};
int len[999][999];
bool used[999];
set<set<int>> s;
D getsmallest(int n){
	D r;
	int mn=1e8;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(len[i][j]<mn){
				r.x=i;
				r.y=j;
				mn=len[i][j];
			}
		}
	}
	return r;
}
/*void printset(set<int> st){
	for(set<int>::iterator i=st.begin();i!=st.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	return;
}*/
bool cycle(D pair){
	//for(set<set<int>>::iterator it=s.begin();it!=s.end();it++)
		//printset(*it);
	//printf("check cycle %d %d\n",pair.x,pair.y);
	set<int> a,b;
	for(set<set<int>>::iterator it=s.begin();it!=s.end();it++){
		//cout<<"check set ";
		//printset(*it);
		if((*it).count(pair.x)&&(*it).count(pair.y))
			return 1;
		if((*it).count(pair.x)){
			for(set<int>::iterator nit=it->begin();nit!=it->end();nit++)
				a.insert(*nit);
		}
		if((*it).count(pair.y)){
			for(set<int>::iterator nit=it->begin();nit!=it->end();nit++)
				b.insert(*nit);
		}
	}
	s.erase(a);
	s.erase(b);
	set<int> c;
	for(set<int>::iterator it=a.begin();it!=a.end();it++)
		c.insert(*it);
	for(set<int>::iterator it=b.begin();it!=b.end();it++)
		c.insert(*it);
	//printset(c);
	//cout<<"====="<<endl;
	s.insert(c);
	return 0;
}
int kruskal(int n){
	s.clear();
	for(int i=0;i<n;i++)
		used[i]=0;
	for(int i=0;i<n;i++){
		set<int> ns;
		ns.insert(i);
		s.insert(ns);
	}
	int flag=0,r=0;
	while(flag<n-1){
		D pair=getsmallest(n);
		if(cycle(pair)){
			len[pair.x][pair.y]=1e8;
			continue;
		}
		r+=len[pair.x][pair.y];
		len[pair.x][pair.y]=1e8;
		used[pair.x]=1;
		used[pair.y]=1;
		flag++;
	}
	return r;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		D list[999];
		for(int i=0;i<n;i++)
			cin>>list[i].x>>list[i].y;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				len[i][j]=abs(list[i].x-list[j].x)+abs(list[i].y-list[j].y);
		cout<<kruskal(n)<<endl;
	}
}