#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,sz[200005],tot;
vector<int> s[200005];
struct node{
	int wzi,wzj,val,bj;
};
int qs[2][200005][2];
unordered_map<int,int> mpzh[200005];
vector<node> v[200005];
vector<node> st;
bool vis[200005][10],can[200005][105];
int zh(int x,int y){
	if(mpzh[x][y]) return mpzh[x][y];
	mpzh[x][y]=++tot;
	return tot;
}
void paobfs(){
	memset(vis,0,sizeof(vis));
	memset(can,0,sizeof(can));
	queue<node> q;
	for(int i=0;i<st.size();++i) q.push((node){st[i].wzi,st[i].wzj,0,0});
	while(!q.empty()){
		node x=q.front();q.pop();
		if(vis[zh(x.wzi,x.wzj)][x.val]) continue;
		//if(x.val==0)cout<<x.wzi<<" "<<x.wzj<<" "<<x.val<<" "<<x.bj<<"\n";
		vis[zh(x.wzi,x.wzj)][x.val]=1;
		if(x.bj) can[s[x.wzi][x.wzj]][x.val+1]=1;
		for(int i=0;i<v[zh(x.wzi,x.wzj)].size();++i){
			node y=v[zh(x.wzi,x.wzj)][i];
			//if(x.wzi==1&&x.wzj==1) cout<<y.wzi<<" "<<y.wzj<<"\n";
			if(x.val+y.val>101||vis[zh(y.wzi,y.wzj)][y.val+x.val]) continue;
			if((x.wzi==y.wzi&&x.bj+1>=k)||(x.wzi!=y.wzi&&!x.bj)) continue;
			int tmp=0;
			if(x.wzi==y.wzi) tmp=x.bj+1;
//			if(x.wzi==1&&x.wzj==1) cout<<y.wzi<<" "<<y.wzj<<"\n";
			q.push((node){y.wzi,y.wzj,y.val+x.val,tmp});
		}
	}
}
void jiejue(){
	cin>>n>>k>>q;
	for(int i=0;i<=tot+1;++i) v[i].clear();
	tot=0;
	for(int i=1;i<=n;++i){
		cin>>sz[i];
		s[i].clear();
		for(int j=0,x;j<sz[i];++j) cin>>x,s[i].push_back(x);
	}
	for(int i=1;i<=n;++i){
		memset(qs[i&1],0,sizeof(qs[i&1]));
		for(int j=0;j<sz[i];++j){
			int k=s[i][j];
			if(!qs[i&1][k]) qs[i&1][k][0]=qs[i-1&1][k][0];
			if(j) v[zh(i,j-1)].push_back((node){i,j,0});
			if(k==1) st.push_back((node){i,j});
			if(qs[i-1&1][k][0]){
				v[zh(qs[i-1&1][k][0],qs[i-1&1][k][1])].push_back((node){i,j,1});
				v[zh(i,j)].push_back((node){qs[i-1&1][k][0],qs[i-1&1][k][1],1});
			}
			if(!qs[i&1][k][j]) qs[i&1][k][1]=j;
			qs[i&1][k][0]=i;
		}
	}
	/*for(int i=1;i<=1;++i){
		for(int kk=0;kk<sz[i];++kk){
			int k=s[i][kk];
			cout<<"VX:"<<i<<" "<<kk<<"\n";
			for(int j=0;j<v[zh(i,kk)].size();++j){
				cout<<v[zh(i,kk)][j].wzi<<" "<<v[zh(i,kk)][j].wzj<<" "<<v[zh(i,kk)][j].val<<"\n";
			}
		}
	}*/
	paobfs();
	while(q--){
		int rj,cj;
		cin>>rj>>cj;
		cout<<can[cj][rj]<<"\n";
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--) jiejue();
	return 0;
}