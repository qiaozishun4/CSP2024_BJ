#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ok[105][200005];
vector<int>p[100005];
int cur[200005];
int main(){
freopen("chain.in","r",stdin);
freopen("chain.out","w",stdout);
ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,len,q;
		cin>>n>>len>>q;
		memset(ok,0,sizeof(ok));
		for(int i=1;i<=n;i++){
			int l;cin>>l;
			p[i].clear();
			p[i].push_back(0);
			for(int j=1;j<=l;j++){
				int x;cin>>x;
				p[i].push_back(x);
			}
		}
		
		ok[0][1]=1e6;
		for(int i=1;i<=100;i++){
			for(int j=1;j<=n;j++){
				int lt=p[j].size();
				for(int k=1;k<lt;k++){
					if(ok[i-1][p[j][k]]==1e6||ok[i-1][p[j][k]]&&ok[i-1][p[j][k]]!=j){
						if(k+1<lt)cur[k+1]++;
						if(k+len<lt)cur[k+len]--;
					}
				}
				int tmp=0;
				for(int k=1;k<lt;k++){
					cur[k]+=tmp;
					tmp=cur[k];
					if(!cur[k])continue;
					if(ok[i][p[j][k]]&&ok[i][p[j][k]]!=j)ok[i][p[j][k]]=1e6;
					else ok[i][p[j][k]]=j;
					cur[k]=0;
				}
			}
		}
		/*if(t==4){
		for(int i=1;i<=5;i++){
			cout<<i<<endl;
			for(auto j:p[1])cout<<j<<" "<<ok[i][j]<<"\n";
			cout<<endl;
		}
		}*/
		while(q--){
			int r,c;cin>>r>>c;
			cout<<(bool)ok[r][c]<<"\n";
		}
	}
	return 0;
}