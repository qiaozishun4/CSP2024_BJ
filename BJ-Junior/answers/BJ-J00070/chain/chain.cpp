#include<bits/stdc++.h>
using namespace std;
int n,m,q,r,c,l;
int tong[200010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int i=1;i<=l;i++){
					int a;
					cin>>a;
					if(i>1) tong[a]=1;
			}
			
		}
		for(int i=1;i<=q;i++){
				cin>>r>>c;
				if(tong[c]) cout<<1<<endl;
				else cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
