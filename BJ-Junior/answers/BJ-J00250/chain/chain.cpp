#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int l,r,c;
bool flag;
int a[50][50],b[200010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=40;i++){
			for(int j=1;j<=40;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>b[l];
			}
			for(int j=1;j<l;j++){
				for(int o=j+1;o<=l;o++){
					a[b[j]][b[o]]++;
				}
			}
		}
		
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			flag=true;
			for(int j=1;j<=10;j++){
				if(a[j][c]==1){
					flag=false;
				}
			}
			if(flag){
				cout<<"0"<<endl;
			}else{
				cout<<"1"<<endl;
			}
		}
	}
	return 0;
}
//一等奖
