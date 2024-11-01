// #define debug
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+3 , L = 2e4+3 , C = 2e4+3 , R = 103 ;

int t,n,k,q,r,c,s[N][L];
bool ans[R][C];
vector<pair<int,int>> g[C],g2[N][C];

void dfs(int dep,int plc){
    ans[dep][plc]=true;
    if(dep==r){
        return;
    }else{
        for(int i=1;i<=s[plc][0];i++){
            for(auto j:g[s[plc][i]]){
                dfs(dep+1,j.second);
            }
        }
    }
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
        memset(ans,false,sizeof(ans));
		cin>>n>>k>>q;
        s[0][0]=1;
        s[0][1]=1;
        dfs(0,0);
		for(int i=1;i<=n;i++){
			cin>>s[i][0];
			for(int j=1;j<=s[i][0];j++){
				cin>>s[i][j];
                g[s[i][j]].push_back({i,j});
			}
		}
		while(q--){
			cin>>r>>c;
            cout<<ans[r][c]<<"\n";
		}
	}
	return 0;
}
// zhu wo 350+