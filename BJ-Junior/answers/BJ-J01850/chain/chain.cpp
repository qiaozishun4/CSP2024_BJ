//白哥保佑T4，暴力出奇迹，打表出省一！
#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;

bool flag;
vector<int>G[N];
vector<pair<int,int> >num[N];
int T,n,k,q,r,c,lun;
bool check(int x,int y,int fid){
	int s=G[x].size();
	for(int i=y+1;i<s;i++){
		if(y+k-1<i)break;
		if(G[x][i]==fid)return 1;
	}
	return 0;
}
void dfs(int x,int y,int las,int h){
	//变成这样了还能不能转移 我要以las结尾 正在进行第h轮
	if(flag)return;
	if(h>r)return;
	if(h==r){
		//cout<<"to"<<x<<' '<<y<<"end find?="<<check(x,y,las)<<endl;
		flag=check(x,y,las);
		return;
	}
	int s=G[x].size();
	for(int i=y+1;i<s;i++){
		if(y+k-1<i)break;
		for(auto v:num[G[x][i]]){
			if(v.first==x)continue;
			dfs(v.first,v.second,las,h+1);
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		for(int i=1;i<N;i++){
			num[i].clear();
		}
		for(int i=1;i<=n;i++){
			int x;cin>>x;
			for(int j=0;j<x;j++){
				int d;
				cin>>d;
				G[i].push_back(d);
				num[d].push_back({i,j});
			}
		}
		while(q--){
			cin>>r>>c;
			flag=0;
			for(auto v:num[1]){
				int X=v.first;
				int Y=v.second;
				dfs(X,Y,c,1);
			}
			cout<<flag<<endl;
		}
	}
	return 0;
}
