#include<bits/stdc++.h>
using namespace std;
int f[21]={0,-1,1,7,6,208,8,10,18,22,20,28,68,88,108,203,408,208,1200,1000};
int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,x;
	cin >> t;
    while(t--)
    {
        cin >> x;
        cout << f[x%20];
    }
	return 0;
}

/*
for(int i=1; i<=5; i++)
{
    for(int j=0; j<100001; j++)
    {
        for(int k=0; k<10; k++)
        {
            f[i][j][k]=f[i-1][j][k];
            if(j-cnt[k]>=0 && f[i-1][j-cnt[k]][k]!=-1)
            {
                f[i][j][k]=min(f[i][j][k],f[i-1][j-cnt[k]][k]*10+cnt[k]);
            }
        }
    }
}
while(t--)
{
    cin >> x;
    int minn=2147473640;
    for(int i=1; i<=5; i++)
    {
        for(int k=0; k<10; k++)
        {
            minn=min(f[i][x][k],minn);
        }
    }
    cout << minn;
}
*/
