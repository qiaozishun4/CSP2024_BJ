#include<bits/stdc++.h>
using namespace std;
bool a[3001][3001];
int ans;
int n,m,k;
void explore(int x,int y,int d,int k)
{
    while(k>0)
    {
        bool fl = 0;
        int l = 4;
        while(l--)
        {
            k--;
//            if(l==1)
//            {
//                fl = 1;
//                break;
//            }
            //cout<<d<<endl;
            if(d == 0)
            {
                if(a[x][y+1]==0&&(y+1)<=m)
                {
                    ans++;
                    a[x][y] = 1;
                    y = y+1;

                    break;
                }
            }
            if(d == 1)
            {
                if(a[x+1][y]==0&&(x+1)<=n)
                {
                    ans++;
                    a[x][y] = 1;
                    x = x+1;

                    break;
                }
            }
            if(d == 2)
            {
                if(a[x][y-1]==0&&(y-1)>0)
                {
                    ans++;
                    a[x][y] = 1;
                    y = y-1;

                    break;
                }
            }
            if(d == 3)
            {
                if(a[x-1][y]==0&&(x-1)>0)
                {
                    ans++;
                    a[x][y] = 1;
                    x = x-1;

                    break;
                }
            }
            if(l==1)
            {
                fl = 1;
                break;
            }
            d = (d+1)%4;
            if(k==0)
                return;
        }

        if(fl==1)
            break;
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int h = 0;h<t;h++)
    {

        cin>>n>>m>>k;
        int x,y,d;memset(a,1,sizeof a);
        cin>>x>>y>>d;

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                char ch;
                cin>>ch;
                if(ch == '.')
                    a[i][j] = 0;

            }
        }
        //for(int l = 1;l<=n;l++)
          //      {
            //        for(int f= 1;f<=m;f++)
              //          cout<<a[l][f];
                //    cout<<endl;
                //}
        ans = 1;
        explore(x,y,d,k);
        cout<<ans<<endl;

    }
    return 0;
}
