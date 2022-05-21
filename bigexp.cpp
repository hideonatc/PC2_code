#include<iostream>
using namespace std;
int f[2001]={0},s[2001]={0},ans[2001]={0};
int findLen(int rt[]){
	for(int i=2000;i>0;i--)
		if(rt[i]!=0)
			return i;
	return 0;
}
void bnMul(int a,int rt[]){
	while(--a){
		int l = findLen(rt),add = 0;
		//printf("l=%d\n",l);
		for(int i=0;i<=l;i++){
			int k = rt[i]*2 + add;
			add = k/10;
			rt[i] = k%10;
			//printf("%d %d\n",add,rt[i]);
		}
		rt[l+1] = add;
	}
	//cout<<endl;
	return;
}
void bnAdd(int f[],int s[],int ans[]){
	int l = findLen(s), nn = 0;
	for(int i=0;i<=l;i++){
		int tmp = f[i]+s[i]+nn;
		nn = tmp/10;
		ans[i]=tmp%10;
	}
	ans[l+1] = nn;
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<2001;i++)
			f[i]=s[i]=ans[i]=0;
		int a,b;
		cin>>a>>b;
		int tmp = min(a,b);
		b = max(a,b);
		a = tmp;
		int c = b-a;
		//printf("a:%d b:%d c:%d\n",a,b,c);
		f[0]=2;
		bnMul(a,f);
		/*for(int i=0;i<50;i++)
			cout<<f[i];*/
		for(int i=0;i<2001;i++)
			s[i] = f[i];
		bnMul(c+1,s);
		/*for(int i=0;i<50;i++)
			cout<<s[i];
		cout<<endl;*/
		bnAdd(f,s,ans);
		int len = findLen(ans);
		for(int i=len;i>=0;i--)
			cout<<ans[i];
		cout<<endl;
	}
}