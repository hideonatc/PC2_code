#include<iostream>
using namespace std;
int ans[999],len=0;
struct tree{
	int val;
	bool emp;
	tree* left;
	tree* right;
};
int getVal(string s){
	int r=0,idx=1;
	while(s[idx]!=',')
		r = r*10 + int(s[idx++]-'0');
	return r;
}
string getPath(string s){
	string r="";
	int idx=1;
	while(s[idx++]!=','){}
	while(s[idx]!=')')
		r+=s[idx++];
	return r;
}
bool error = 0;
bool printLevel(tree* nd, int level){
    if (nd==NULL) 
        return false;
    if (level==1){
        ans[len++] = nd->val;
        if(nd->emp&&(nd->left!=NULL||nd->right!=NULL)){
        	error = 1;
        	cout<<"not complete"<<endl;
        }
        return true;
    }
    bool l = printLevel(nd->left,level-1);
    bool r = printLevel(nd->right,level-1);
    return l||r;
}
void levelOrderTraversal(tree* nd)
{
    int level = 1;
    while (printLevel(nd,level)) {
        level++;
    }
    return;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		len = 0;
		tree* root = (tree*)malloc(sizeof(tree));
		root->emp = 1;
		string ip;
		while(cin>>ip){
			if(ip=="()")
				break;
			int v = getVal(ip);
			string p = getPath(ip);
			if(p==""){
				root->val = v;
				root->emp = 0;
				continue;
			}
			tree* now = root;
			for(int i=0;i<p.length()-1;i++){
				if(p[i]=='L'){
					if(now->left==NULL){
						tree* newnode = (tree*)malloc(sizeof(tree));
						newnode->emp = 1;
						now->left = newnode;
					}
					now = now->left;
				}
				else{
					if(now->right==NULL){
						tree* newnode = (tree*)malloc(sizeof(tree));
						newnode->emp = 1;
						now->right = newnode;
					}
					now = now->right;
				}
			}
			if(p[p.length()-1]=='L'){
				if(now->left!=NULL&&!now->left->emp){
					cout<<"not complete"<<endl;
					error = 1;
					break;
				}
				if(now->left==NULL){
					tree* nn = (tree*)malloc(sizeof(tree));
					now->left = nn;
				}
				now = now->left;
				now->val = v;
				now->emp = 0;
			}
			else if(p[p.length()-1]=='R'){
				if(now->right!=NULL&&!now->right->emp){
					cout<<"not complete"<<endl;
					error = 1;
					break;
				}
				if(now->right==NULL){
					tree* nn = (tree*)malloc(sizeof(tree));
					now->right = nn;
				}
				now = now->right;
				now->val = v;
				now->emp = 0;
			}
		}
		if(error){
			error = 0;
			continue;;
		}
		levelOrderTraversal(root);
		if(error){
			error = 0;
			continue;
		}
		for(int i=0;i<len-1;i++)
			cout<<ans[i]<<" ";
		cout<<ans[len-1]<<endl;
	}
}