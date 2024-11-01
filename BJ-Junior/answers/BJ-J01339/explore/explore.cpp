#include<bits/stdc++.h>
using namespace std;
int di[5]={0,1,0,-1};
int dj[5]={1,0,-1,0};
int vis[1005][1005],a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t){
		t--;
		int n,m,k;
		cin>>n>>m>>k;
		int i0,j0,d;
		cin>>i0>>j0>>d;
		for(int i=1; i<=n; i++){
			string s;
			cin>>s;
			for(int j=1; j<=m; j++){
				if(s[j-1]=='.'){
					a[i][j]=0;
				} else{
					a[i][j]=1;
				}
			}
		}
		for(int i=1; i<=k+1; i++){
			vis[i0][j0]=1;
		//	cout<<i0<<" "<<j0<<endl;
			int i1=i0+di[d],j1=j0+dj[d];
			if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]==0){
				i0=i1;
				j0=j1;
			//	cout<<"*";
			} else{
				d=(d+1)%4;
			}
		}
		int sum=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(vis[i][j]==1){
					sum++;
				}
				vis[i][j]=0;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
