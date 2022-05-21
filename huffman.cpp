#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<char, string> mymap;
struct tree{
	char chr;
	int fre;
	struct tree* right = NULL;
	struct tree* left = NULL;
};
int tab[52]={0},id = 0;
string tochr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
bool cmp(struct tree* a,struct tree* b){
	return a->fre>b->fre;
}
bool mapcmp(string ta ,string tb){
	string a=ta, b=tb;
	while(a.length()>1){
		if(a[0]=='0'){
			for(int i=0;i<a.length()-1;i++)
				a[i]=a[i+1];
		}
		else break;
	}
	while(b.length()>1){
		if(b[0]=='0'){
			for(int i=0;i<b.length()-1;i++)
				b[i]=b[i+1];
		}
		else break;
	}
	if(a.length()>b.length()) return 1;
	if(a.length()<b.length()) return 0;
	return a>b;
}
int chrtoidx(char c){
	if(c<='Z'&&c>='A')
		return int(c-'A');
	return int(c-'a')+26;
}
void travel(string str, struct tree* now){
	if(now->left!=NULL&&now->left->chr!='+')
		mymap[now->left->chr] = str+"0";
	if(now->right!=NULL&&now->right->chr!='+')
		mymap[now->right->chr] = str+"1";
	if(now->left!=NULL)
		travel(str+"0",now->left);
	if(now->right!=NULL)
		travel(str+"1",now->right);
	return;
}
int main(){
	tree* arr[20];
	string ip;
	cin>>ip;
	for(int i=0;i<ip.length();i++)
		tab[chrtoidx(ip[i])]++;
	int mn = 999, idx;
	while(1){
		idx = -1,mn = 999;
		for(int i=0;i<52;i++)
			if(tab[i]&&tab[i]<mn){
				mn = tab[i];
				idx = i;
			}
		if(idx<0) break;
		tab[idx] = 0;
		struct tree* nn = (tree*)malloc(sizeof(tree));
		nn->fre = mn;
		nn->chr = tochr[idx];
		arr[id++] = nn;
	}
	int d = id;
	while(id>1){
		sort(arr,arr+id,cmp);
		struct tree* newnode = (tree*)malloc(sizeof(tree));
		newnode->fre = arr[id-1]->fre + arr[id-2]->fre;
		newnode->chr = '+';
		newnode->left = arr[id-1];
		newnode->right = arr[id-2];
		arr[id-2] = newnode;
		id = id-1;
	}
	struct tree* pt = arr[0];
	travel("",pt);
	while(!mymap.empty()){
		string ms="99999999";
		char mem;
		for(auto it = mymap.begin(); it != mymap.end();it++){
			if(mapcmp(ms,it->second)){
				ms = it->second;
				mem = it->first;
			}
		}
		cout<<mem<<":"<<ms<<endl;
		mymap.erase(mem);
	}
}