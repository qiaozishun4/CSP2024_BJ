#include<bits/stdc++.h>
using namespace std;
int n,t,m,l,v;
int a[100009],b[100009],c[100009],d[100009];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=m;i++)cin>>d[i];
		int mx=0;
		for(int i=1;i<=n;i++){
			if(a[i]>mx)mx=a[i];
		}
		for(int i=1;i<=m;i++){
			if(d[i]<mx){
				cout<<m-i;
				break;
			}
		}
	}
	
	return 0;	
}
	