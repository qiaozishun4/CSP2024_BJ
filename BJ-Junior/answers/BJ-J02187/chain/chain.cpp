#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,k,q,l[N],x,r,c;
vector<int> s[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>x;
				s[i].push_back(x);
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			bool ff=0;
			for(int i=1;i<=n;i++){
				for(int pp=l[i]-1;pp>=0;pp--){
					if(s[i][pp]==c){
						for(int j=pp-1;j>=0&&pp-j+1<=k;j--){
							if(s[i][j]==1){ff=1;break;}
						}
					}
					if(ff) break;
				}
				if(ff) break;
			}
			if(ff) cout<<"1\n";
			else cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++) s[i].clear();
	}
	return 0;
}