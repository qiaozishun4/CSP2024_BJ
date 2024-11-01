#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,x,y,d;
int k,ans[15];
int a[1010][1010];
int f[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	int t=T;
	while(T--){
		n=0;m=0;k=0;x=0;y=0;d=0;
		cin>>n>>m>>k>>x>>y>>d;
		f[1010][1010]={0};
		a[1010][1010]={0};
		f[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char q;
				cin>>q;
				if(q=='.'){
					a[i][j]=1;
				}
			}
		}
		int iii=x,jjj=y;
		while(1){
			if(k==0)break;
			if(d==0&&k!=0){
				if(a[iii][jjj+1]){
					jjj+=1;f[iii][jjj]=1;k-=1;
				}
				else {d=(d+1)%4;k-=1;}
			}
			if(d==1&&k!=0){
				if(a[iii+1][jjj]){
					iii+=1;f[iii][jjj]=1;k-=1;
				}
				else {d=(d+1)%4;k-=1;}
			}
			if(d==2&&k!=0){
				if(a[iii][jjj-1]){
					jjj-=1;f[iii][jjj]=1;k-=1;
				}
				else {d=(d+1)%4;k-=1;}
			}
			if(d==3&&k!=0){
				if(a[iii-1][jjj]){
					iii-=1;f[iii][jjj]=1;k-=1;
				}
				else {d=(d+1)%4;k-=1;}
			}
		}
		for(int ii=1;ii<=n;ii++){
			for(int jj=1;jj<=n;jj++){
				if(f[ii][jj])ans[T]+=1;
			}
		}
	}
	while(t--){
		cout<<ans[t]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}