#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    cin>>n;
    for(int o=0;o<n;o++){
		int sum=1;
		int n,m,k;
		int x,y,d;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		int a[n+2][m+2];
		memset(a,'x',sizeof(a));
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[n][m];
		a[x][y]='o';
		for(int i=0;i<=k;i++){
			if(d==0)
				if(a[x][y+1]=='.'||a[x][y+1]=='o'){
					if(a[x][y+1]!='o') sum++,a[x][y+1]='o';
					y++;
					cout<<sum<<endl;
				}
				else d++,i++;
			if(d==1&&i<k)
				if(a[x+1][y]=='.'||a[x+1][y]=='o'){
					if(a[x+1][y]!='o') sum++,a[x+1][y]='o';
					x++;
					cout<<sum<<endl;
				}
				else d++,i++;
			if(d==2&&i<k)
				if(a[x][y-1]=='.'||a[x][y-1]=='o'){
					if(a[x][y-1]!='o') sum++,a[x][y-1]='o';
					y--;
					cout<<sum<<endl;
				}
				else d++,i++;
			if(d==3&&i<k)
				if(a[x-1][y]=='.'||a[x-1][y]=='o'){
					if(a[x-1][y]!='o') sum++,a[x-1][y]='o';
					x--;
					cout<<sum<<endl;
				}
				else d=0,i++;
		}
		cout<<sum<<endl;
	}
    return 0;
}
