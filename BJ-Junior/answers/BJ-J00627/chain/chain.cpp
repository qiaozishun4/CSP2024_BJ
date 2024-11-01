#include<bits/stdc++.h>
using namespace std;
int p,n,k,q,a[1005][2005];
int r[1005],c[1005],t[100005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>p;
	while(p--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&t[i]);
			for(int j=1;j<=t[i];j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&r[i],&c[i]);
			if(r[i]==1){
			bool flg=false;
				for(int j=2;j<=t[1];i++){
					if(a[1][j]==c[i]){
						cout<<1<<endl;
						flg=true;
						break;
					}
				}
				if(flg==false) cout<<0<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}
