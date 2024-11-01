#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define M_D
const ll oo=3e18;
const int N=2e5;
int T;
int n,k,q;
set<pair<int,int>> mp[N+5];
int r,c;
int l[N+5];
vector<int> s[N+5];

bool dfs(int x,int i,int step){
	#ifdef M_D
	for(int i=1;i<=step;i++)
		cout<<"    ";
	cout<<"dfs s["<<x<<"]["<<i<<"],step="<<step<<endl;
	#endif
	if(step==r){
		for(int j=i-1;j>=max(i-k+1,1);j--)
			if(s[x][j]==1)
				return 1;
		return 0;
	}
	for(int j=i-1;j>=max(i-k+1,1);j--){
		#ifdef M_D
		for(int i=0;i<=step;i++)
			cout<<"    ";
		cout<<x<<"'s range "<<"["<<j<<","<<i<<"]"<<" s's val is  "<<s[x][j]<<endl;
		#endif
		for(auto it=mp[s[x][j]].begin();it!=mp[s[x][j]].end();it++){
			if((*it).first==x)
				continue;
			if(dfs((*it).first,(*it).second,step+1))
				return 1;
		}
	}
	return 0;
}
void init(){
	for(int i=1;i<=n;i++)
		s[i].erase(s[i].begin(),s[i].end());
	for(int i=1;i<=2e5;i++)
		mp[i].erase(mp[i].begin(),mp[i].end());
	return ;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		init();
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			s[i].push_back(-1);
			for(int j=1;j<=l[i];j++){
				int k;
				cin>>k;
				s[i].push_back(k);
				if(j>1)
					mp[k].insert(make_pair(i,j));
			}
		}
		while(q--){
			cin>>r>>c;
			bool flag=0;
			for(auto it=mp[c].begin();it!=mp[c].end();it++)
				if(dfs((*it).first,(*it).second,1)){
					flag=1;
					break;
				}
			if(flag)
				cout<<1<<"\n";
			else
				cout<<0<<"\n";
		}
	}
	return 0;
}
//LXT5201314