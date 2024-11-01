#include <bits/stdc++.h>

using namespace std;
  int n,m,k;
  int x,y,d;
  int ax[4]={0,1,0,-1};
  int ay[4]={1,0,-1,0};
int b[1001][1001]={0};
int main()
{
    freopen("explore.in","r",stdin);
    freoprn("explore.out","w",stdout);
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n>>m>>k;
        int a[n][m];

        int ans=0;
        cin>>x>>y>>d;

        x=x-1;
        y=y-1;
        b[x][y]=1;
        char s;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>s;
                if(s=='.')
                    a[i][j]=1;
                else
                    a[i][j]=0;
            }

        while(k)
        {


            if(ax[d]+x>=0 && ay[d]+y>=0 && ax[d]+x<n && ay[d]+y<m && a[ax[d]+x][ay[d]+y]==1)
            {


                x=ax[d]+x;
                y=ay[d]+y;
                k--;
                b[x][y]=1;
            }
            else
            {
                d=(d+1)%4;
                k--;

            }


        }
        for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
                if(b[i][j]==1  )
                    {
                       // cout<<' '<<i+1<<' ' <<j+1<<' '<<endl;
                        ans+=b[i][j];
                        b[i][j]=0;
                    }



        cout<<ans<<endl;

    }
}
