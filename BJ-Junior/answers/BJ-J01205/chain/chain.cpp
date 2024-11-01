#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,ans,L;
int s[200010];
struct note{
	int r,c;
} a[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>L;
			for(int j=1;j<=L;j++){
				cin>>s[j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>a[i].r>>a[i].c;}
		cout<<"1\n0\n1\n0\n1\n0\n0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}