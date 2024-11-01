#include<bits/stdc++.h>
using namespace std;
int n,k,q,r,c;
int a[100010][50];
int l[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			cin>>a[i][j];
		}
	}
	while(q--){
		cin>>r>>c;
		if(r==1){
			int flag=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=l[i];j++){
					if(a[i][j]==c){
						int x=max(1,j-k+1);
						for(int k=j;k>=x;k--){
							if(a[i][k]==1){
								cout<<"1\n";
								flag=1;
								break;
							}
						}
					}
					if(flag==1){
						break;
					}
				}
				if(flag==1){
					break;
				}
			}
			if(flag==0){
				cout<<"0\n";
			}
		}
	}
	return 0;
}