#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int a[N][N];
int s[N];
struct node{
	int x,l,r;
	int num;
};
int main(){
	freopen("chain.in","r",stdin);
	 freopen("chain.out","w",stdout);
	int T,n,k,q;
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			for(int j=1;j<=s[i];j++) cin>>a[i][j];
		}
		for(int i=1;i<=q;i++){
			int r,z;
			cin>>r>>z;
			queue<node> q;
			a[0][1]=1;
			q.push({0,0,1,0});
			bool bb=0;
			while(q.size()){
				node t=q.front();
				q.pop();
				if(t.num==r && a[t.x][t.r]==z){
					cout<<1<<"\n";
					bb=1;
					break;
				}
				if(t.num==r+1){
					cout<<0<<"\n";
					bb=1;
					break;
				}
				for(int o=1;o<=n;o++){
					if(o==t.x) continue;
					for(int j=1;j<=s[o];j++){
						if(a[o][j]!=a[t.x][t.r]) continue;
						for(int ii=1;ii<k;ii++){
							if(j+ii<=s[o]){
								q.push({o,j,j+ii,t.num+1});
							}
						}
					}
				}
			}
			if(bb==0) cout<<"0\n";
			
		}
	}
	return 0;
}
