#include <bits/stdc++.h>
using namespace std;
long long T,n,k,q,l,r,c,temp;
bool flag;
struct pos{
	int x;
	int y;
};
pos tmp;
vector <pos>s[1010];
long long a[1010][1010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>a[i][j];
				tmp.x=i;
				tmp.y=j;
				s[a[i][j]].push_back(tmp);
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			flag=1;
			for(int j=0;j<s[c].size();j++){
				//cout<<s[c][j].x<<' '<<s[c][j].y<<endl;
				for(int ii=1;ii<s[c][j].y-1;ii++){
					if(s[c][j].y-ii>=1 && a[s[c][j].x][s[c][j].y-ii]==1){
						flag=1;
						cout<<1<<endl;
					}
				}
			}
			if(!flag) cout<<0<<endl;
		}
	}
	return 0;
}
