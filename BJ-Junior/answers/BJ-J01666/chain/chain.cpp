#include <bits/stdc++.h>
using namespace std;
int q,n,t,ks,l[100001],c,r;
vector<int> v[100001];
vector<pair<int,int> > num[200001];
queue<pair<int,pair<int,int> > > qu;
set<pair<int,int> > s[110];
set<int> se[110];
pair<int,int> mp(int i,int j){
	return make_pair(i,j);
}
int bfs(){
	qu.push(make_pair(1,mp(0,-1)));
	while(!qu.empty()){
		int now=qu.front().first,t=qu.front().second.first,cano=qu.front().second.second;
		qu.pop();
		if(!se[t].count(now)) se[t].insert(now);
		if(t==100) break;
		for(int i=0;i<(int)num[now].size();i++){
			int j=num[now][i].first,k=num[now][i].second;
			if(j==cano) continue;
;			for(int l=k;l<min((int)v[j].size(),ks+k-1);l++){
				if(!s[t+1].count(mp(v[j][l],j))){
					qu.push(make_pair(v[j][l],mp(t+1,j)));
					s[t+1].insert(mp(v[j][l],j));
				}
			}
		}
	}
	for(int i=0;i<=100;i++) while(!s[i].empty()) s[i].erase(s[i].begin());
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n>>ks>>t;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>c;
				v[i].push_back(c);
				if(j!=l[i]) num[c].push_back(mp(i,j));
			}
		}
		bfs();
		while(t--){
			cin>>r>>c;
			cout<<se[r].count(c)<<'\n';
		}
		for(int i=0;i<=20000;i++) num[i].clear();
		for(int i=0;i<=10000;i++) v[i].clear();
	}
	return 0;
}
