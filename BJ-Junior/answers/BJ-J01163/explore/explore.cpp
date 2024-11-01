#include<bits/stdc++.h>
using namespace std;
char mp[1010][1010];
bool iscome[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(iscome,0,sizeof(iscome));
        int n,m,k,x,y,d,ans=1;
        scanf("%d %d %d\n%d %d %d",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        iscome[x][y]=1;
        while(k--)
        {
            switch(d)
            {
                case 0:y++;break;
                case 1:x++;break;
                case 2:y--;break;
                case 3:x--;break;
            }
            if(x>n||y>m||mp[x][y]!='.')
            {
                switch(d)
                {
                    case 0:y--;break;
                    case 1:x--;break;
                    case 2:y++;break;
                    case 3:x++;break;
                }
                d=(d+1)%4;
            }
            if(iscome[x][y]==0)ans++;
            iscome[x][y]=1;

        }
        printf("%d\n",ans);
    }
    return 0;
}