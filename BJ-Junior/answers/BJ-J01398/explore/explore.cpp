#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int num;
    cin>>num;
    while(num--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        int ans=0;

        string ditu[n+1][m+1];
        int a=1;
        int b=1;
        for(;a<=n;b++)
        {
            if(b>m)
            {
                a++;
                b=1;
            }
            cin>>ditu[a][b];
        }

        bool dao[n+1][m+1];
        int a=1;
        int b=1;
        for(;a<=n;b++)
        {
            if(b>m)
            {
                a++;
                b=1;
            }
            dao[a][b]=0;
        }
        int len=0;

        for(int i=1;i<=k;i++)
        {
            if(dao[x][y]==0)
            {
                len++;
                dao[x][y]==1;
            }

            if(d==0)
            {
                if((y+1)>m||ditu[x][y+1]=="X")
                {
                    d++;
                    continue;
                }
                y++;
            }
            if(d==1)
            {
                if((x+1)>n||ditu[x+1][y]=="X")
                {
                    d++;
                    continue;
                }
                x++;
            }
            if(d==2)
            {
                if((y-1)<1||ditu[x][y-1]=="X")
                {
                    d++;
                    continue;
                }
                y--;
            }
            if(d==3)
            {
                if((x-1)<1||ditu[x-1][y]=="X")
                {
                    d++;
                    continue;
                }
                x--;
            }
        }
        cout<<len<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

