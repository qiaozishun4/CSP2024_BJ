#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, m, k, x, y, d, sum=1;
        char a[1010][1010];
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        x--;
        y--;
        for(long long i=0;i<=n-1;i++)
        {
            string s;
            cin>>s;
            for(long long j=0;j<=m-1;j++)
            {
                a[i][j]=s[j];
            }
        }
        //cout<<a[5][1]<<endl;
        for(long long i=0;i<=k-1;i++)
        {
            //cout<<d<<' ';
            if(d==0)
            {
                if(y+1<=m-1&&a[x][y+1]=='.')
                {
                    sum++;
                    y++;
                    //cout<<"true"<<endl;
                }
                else
                {
                    d=(d+1)%4;
                    //cout<<"false"<<endl;
                }
            }
            else if(d==1)
            {
                if(x+1<=n-1&&a[x+1][y]=='.')
                {
                    sum++;
                    x++;
                    //cout<<"true"<<endl;
                }
                else
                {
                    d=(d+1)%4;
                    //cout<<"false"<<endl;
                }
            }
            else if(d==2)
            {
                if(y-1>=0&&a[x][y-1]=='.')
                {
                    sum++;
                    y--;
                    //cout<<"true"<<endl;
                }
                else
                {
                    d=(d+1)%4;
                    //cout<<"false"<<endl;
                }
            }
            else if(d==3)
            {
                if(x-1>=0&&a[x-1][y]=='.')
                {
                    sum++;
                    x--;
                    //cout<<"true"<<endl;
                }
                else
                {
                    d=(d+1)%4;
                    //cout<<"false"<<endl;
                }
            }
            //cout<<x<<' '<<y<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}
