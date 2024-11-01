#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
		int n,k,q,l[2005],a[1005][2005],r[1005],c[1005];
		cin>>n>>k>>q;
		bool f=false,t=false;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			t=false;
			for(int j=1;j<=n;j++){
				f=false;
				for(int k=1;k<=l[i];k++){
					if(a[j][k]==1)f=true;
					if(a[j][k]==c[i]&&f==true){
						t=true;
						break;
					}
				}
				if(t)break;
			}
			if(t){
				cout<<"1"<<endl;
			}
			else cout<<"0"<<endl;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
