#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,tmp,pos[250000],pos_idx=0,neg[250000],neg_idx=0;
		cin>>n;
		if(n==0){
			cout<<"0"<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			cin>>tmp;
			if(tmp>0)
				pos[pos_idx++]=tmp;
			else
				neg[neg_idx++]=-1*tmp;
		}
		if(pos_idx==0||neg_idx==0){
			cout<<"1"<<endl;
			continue;
		}
		sort(pos,pos+pos_idx);
		sort(neg,neg+neg_idx);
		int ans=0,a=0,b=0,turn=neg[0]<pos[0]?1:0,now=-1;
		while(1){
			if(turn&&b>=neg_idx)
				break;
			if(!turn&&a>=pos_idx)
				break;
			if(!turn){
				if(now<pos[a++]){
					now=pos[a-1];
					turn=1;
					ans++;
				}
			}
			else{
				if(now<neg[b++]){
					now=neg[b-1];
					turn=0;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}