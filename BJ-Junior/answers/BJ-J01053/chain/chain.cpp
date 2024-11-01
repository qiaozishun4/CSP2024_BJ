

#include<bits/stdc++.h>
using namespace std;
int a[50000][10000];
int n,k,q;
int fl=0;
void dfs(int r,int c,int p,int s){
	//cout<<r<<c<<p<<s<<endl;
	if(fl==1){
		return;
	}
	if(r==0){
		if(c==s){
			fl=1;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(i==p){
			continue;
		}
		for(int j=1;j<=a[i][0];j++){
			if(a[i][j]==s){
				for(int o=1;o+j<=a[i][0]&&o<k;o++){
					dfs(r-1,c,i,a[i][j+o]);
				}
			}
		}
	}
}
void f(){
	cin>>n>>k>>q;
	int m;
	for(int i=0;i<n;i++){
		cin>>m;
		a[i][0]=m;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int r,c;
	for(int i=0;i<q;i++){
		cin>>r>>c;
		fl=0;
		dfs(r,c,-1,1);
		cout<<fl<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		f();
	}
}

