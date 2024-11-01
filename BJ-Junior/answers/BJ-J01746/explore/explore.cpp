#include <bits/stdc++.h>
using namespace std;
int n,a[1005][1005],b[1005][1005],ans,t,x,y,z,m,k;
char c;
bool bol;
int main()
{

    freopen("explore.in","r",stdin);

    freopen("explore.out","w",stdout);
    cin>>t;

    while(t--)

    {
        cin>>n>>m>>k>>x>>y>>z;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='.')
                {
                    a[i][j]=1;
                }
                else
                {
                    a[i][j]=0;
                }


            }

        }
        int x1,y11;

        b[x][y]=1;
        ans++;
        while(k>=0)

        {
        bol=false;
        while(bol==false)
        {


        if(z==0)

        {
            x1=x;

            y11=y+1;
        }

        if(z==1)

        {
            x1=x+1;

            y11=y;
        }

        if(z==2)

        {
            x1=x;

            y11=y-1;
        }

        if(z==3)

        {
            x1=x-1;

            y11=y;
        }

        if(x1>=1&&x1<=n)

        {
            if(y11>=1&&y11<=m)


            {
                if(a[x1][y11]==1)

                {
                    bol=true;
                }
            }
        }
        if(bol==false)
        {
            z+=1;


            z%=4;


            k--;
        }

        }

        //cout<<"k"<<k<<endl;
        if(k<=0)
        {
            break;
        }
        x=x1;
        y=y11;
        if(b[x][y]==0)
        {
            b[x][y]=1;
            ans++;
          //  cout<<ans<<x<<y<<endl;
        }
        k--;
        //cout<<x<<" "<<y<<endl;

        }


        cout<<ans<<endl;
        for(int i=1;i<=n;i++)

        {
            for(int j=1;j<=m;j++)

            {
                b[i][j]=0;
            }
        }
        ans=0;

    }


    return 0;
}

