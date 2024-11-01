#include <bits/stdc++.h>
using namespace std;
int a[100005][200005];
int t,n,k,q,s,r,c;
struct node{
	int a,i,j;
};
queue <node> qq;
queue <node> q2;
void dfs(int begin,int dep,int last_person){
	if(dep>(r+1)/2)return;
	for(int i=1;i<=n;i++)
		if(i!=last_person)
			for(int j=1;j<=s;j++)
				if(a[i][j]==begin)
					for(int c=1;c<k;c++)
						if(dep==(r+1)/2){
							qq.push((node){i,j,i+c});
						}
						else dfs(a[i][j+c],dep+1,i);
}
void dfss(int last,int dep,int next_person){
	if(dep>(r+1)/2)return;
	for(int i=1;i<=n;i++)
		if(i!=next_person)
			for(int j=1;j<=s;j++)
				if(a[i][j]==last)
					for(int c=1;c<k&&j-c>0;c++)
						if(dep==(r+1)/2){
							q2.push((node){i,j,i-c});
						}
						else dfs(a[i][j-c],dep+1,i);
	
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;i<=s;j++)cin>>a[i][j];
		}
		while(q--){
			cin>>r>>c;
			dfs(1,1,0);
			dfss(c,1,0);
			bool flag=0;
			for(int i=0;i<qq.size();qq.pop())
				for(int j=0;j<q2.size();q2.pop()){
					node x=qq.front();node y=q2.front();
					if(x.a==y.a&&x.i==y.j&&x.j==y.i)flag=1;
				}
			cout<<flag<<endl;
		}
	}
}
