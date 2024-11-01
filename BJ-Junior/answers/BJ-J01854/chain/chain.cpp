#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q,a[1001][1001];
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>a[i][0];
			for(int j=1;j<=a[i][0];j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<q;i++){
			int r,c;
			cin>>r>>c;
			if(k==1){
				cout<<0;
				continue;
			}
			if(r==1){
				bool flag=false;
				for(int i=0;i<n;i++){
					for(int j=1;j<=a[i][0];j++){
						if(a[i][j]==1){
							for(int x=j;x<=j+k;x++){
								if(a[i][x]==c){
									flag=true;
									break;
								}
							}
						}
					}
					if(flag){
						break;
					}
				}
				cout<<flag<<endl;
			}
		}
	}
	return 0;
}

