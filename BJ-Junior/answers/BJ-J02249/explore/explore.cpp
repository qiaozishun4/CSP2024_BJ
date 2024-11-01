#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	int c[T+5];
	for(int i=1;i<=T;i++){
		int n,m,k,sum=0;
		int xc,yc,dc;
		cin>>n>>m>>k;
		cin>>xc>>yc>>dc;
		char a[n+5][m+5];
		int b[n+5][m+5];
		for(int j=1;j<=n;j++){
			for(int s=1;s<=m;s++){
				b[j][s]=0;
			}
		}
		for(int j=1;j<=n;j++){
			for(int s=1;s<=m;s++){
				cin>>a[j][s];
			}
		}
		for(int j=1;j<=k;j++){
			b[xc][yc]++;
			if(dc==0){	
				if(yc+1>m){
					dc=(dc+1)%4;
					continue;
				}
				else{
					if(a[xc][yc+1]=='x'){
						dc=(dc+1)%4;
						continue;
					}
					else{
						yc=yc+1;
					}
				}
			}
			else if(dc==1){	
				if(xc+1>n){
					dc=(dc+1)%4;
					continue;
				}
				else{
					if(a[xc+1][yc]=='x'){
						dc=(dc+1)%4;
						continue;
					}
					else{
						xc=xc+1;
					}
				}
			}
			else if(dc==2){
				if(yc-1<1){
					dc=(dc+1)%4;
					continue;
				}
				else{
					if(a[xc][yc-1]=='x'){
						dc=(dc+1)%4;
						continue;
					}
					else{
						yc=yc-1;
					}
				}	
			}
			else if(dc==3){	
				if(xc-1<1){
					dc=(dc+1)%4;
					continue;
				}
				else{
					if(a[xc-1][yc]=='x'){
						dc=(dc+1)%4;
						continue;
					}
					else{
						xc=xc-1;
					}
				}
			}	
		}
		b[xc][yc]++;
		for(int j=1;j<=n;j++){
			for(int s=1;s<=m;s++){
				if(b[j][s]!=0){
					sum++;
				}
			}
		}
		c[i]=sum;
	}
	for(int i=1;i<=T;i++){
		cout<<c[i]<<endl;
	}
	return 0;
}
