#include <bits/stdc++.h>
using namespace std;
short t,n,m,x,y,d,nox,noy,nex,ney;
char mp[1010][1010];
bool aw[1010][1010];
int k,sum;
string s;
int main(){freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t!=0){cin>>n>>m>>k;
		cout<<n<<m;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)aw[i][j]=0;
		sum=1;
		for(int k=1;k<=n;k++)for(int l=1;l<=m;l++)cin>>mp[k][l];
		nox=x;
		noy=y;
		while(k!=0){if(d==0)ney=noy+1;
			else if(d==1)nex=nox+1;
			else if(d==3)ney=noy-1;
			else nex=nox-1;
			if(nex>0&&ney>0){if(mp[nex][ney]=='.'){nox=nex;
				noy=ney;
				if(aw[nex][ney]==0){sum++;
					aw[nex][ney]=1;}
				k--;}}
			else{d=(d+1)%4;
				k--;}}
			cout<<sum<<"\n";
			t--;}
	fclose(stdin);
	fclose(stdout);
	return 0;}