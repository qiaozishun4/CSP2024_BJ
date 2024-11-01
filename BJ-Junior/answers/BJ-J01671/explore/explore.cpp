#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,X,Y,D,x,y,d,answer,x2,y2;
int fxx[4]={0,1,0,-1}, fxy[4]={1,0,-1,0};
int l[1005][1005]; // l[i][j] means the j th number in row i ;  i,j starts from 1  ;
//l value    0:can't pass  >0:can pass  1:haven't passed  2:have passed
string w;
bool torf;
int main()
{
	freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	cin>>T;
	for (int tt=0;tt<T;tt++)
	{
		cin>>n>>m>>k;
		cin>>X>>Y>>D;
		for(int i=1;i<=n;i++)
		{
			cin>>w;
			for (int j=1;j<=m;j++)
			{
				l[i][j]=(w[j-1]=='.')?1:0;
			}
		}
		// above: input
		x=X;y=Y;d=D;
		
		answer=1;
		l[x][y]=2;
		for (int step=0;step<k;step++)
		{
			
			x2=x+fxx[d];y2=y+fxy[d];
			if (1<=x2<=n and 1<=y2<=m and l[x2][y2]>0)
			{
				x=x2;y=y2;
			}
			else
			{
				d=(d+1)%4;
			}
			if (l[x][y]==1)
			{
			    l[x][y]=2;
			    answer++;
			}
		}
		cout << answer << endl;
	}
	return 0;
} 


