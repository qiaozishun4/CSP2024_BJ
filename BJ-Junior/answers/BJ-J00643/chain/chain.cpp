#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a[1005][2005],n,k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j];
		}
	}
	while(q--){
		int rr,b;
		cin>>rr>>b;
		bool xx=0;
		for(int i=1;i<=n;i++){
			if(xx==1){
				break;
			}
			for(int m=1;m<=a[i][0];m++){
				if(a[i][m]==1){
					for(int j=2;j<=k;j++){
				if(a[i][j+m-1]==b){
					cout<<1<<endl;
					xx=1;
					break;
				}
			}
				}
			}
			
		}
		if(xx==0){
			cout<<xx<<endl;
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}	
	return 0;
}