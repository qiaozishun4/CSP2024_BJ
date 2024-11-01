#include<bits/stdc++.h>
using namespace std;
int s[1005][2005];
map<int,int> mp;
int main(){
    //freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[i][j];
				if(!mp[s[i][j]]) mp[s[i][j]]=j;
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			if(r==1&&(mp[c]>k||mp[c]<2)) cout<<0<<'\n';
			else cout<<1<<'\n';
		}
	}
    return 0;
}
