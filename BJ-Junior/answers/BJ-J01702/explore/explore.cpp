#include <bits/stdc++.h>
using namespace std;
int n,m,d;
int nexts [4] [2] = {{0,1},{1,0},{0,-1},{-1,0}};
char mape [1001] [1001];
bool vis [1001] [1001];
int ans;
void dfs(int x,int y,int k)
{
	if (vis[x] [y]==0)  ans++;
	vis[x] [y]=1;
	if (k==0)  return;
	int tx = x+nexts[d] [0];
	int ty = y+nexts[d] [1];
	if (tx>0 && tx<=n && ty>0 && ty<=m && mape[tx] [ty]=='.')
    {
        dfs(tx,ty,k-1);
    }else
    {
        d=(d+1)%4;
        dfs(x,y,k-1);
    }
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >>t;
	for (int z = 1;z<=t;z++)
    {
        ans=0;
        int x,y,k;
        cin >>n >>m >>k;
        cin >>x >>y >>d;
        for (int i = 1;i<=n;i++)
        {
            for (int j = 1;j<=m;j++)
            {
                cin >>mape[i] [j];
                vis[i] [j]=0;
            }
        }
        dfs(x,y,k);
        cout <<ans <<endl;
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
