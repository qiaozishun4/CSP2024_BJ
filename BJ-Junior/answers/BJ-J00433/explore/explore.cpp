#include <iostream>
using namespace std;
const int N=1005;
int n,r,k,T,dr[4][2]={{0,1},{1,0},{0,-1},{-1,0}},sum;
bool p[N][N],m[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>r>>k;
        int x,y,d;
        cin>>x>>y>>d;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            s=' '+s;
            for(int j=1;j<=r;j++)
            {
                if(s[j]=='x') m[i][j]=1;
                else m[i][j]=0;
                p[i][j]=0;
            }
        }
        p[x][y]=1;
        sum++;
        while(k--)
        {
            int a=x+dr[d][0],b=y+dr[d][1];
            if(m[a][b]==0 and 1<=a and a<=n and 1<=b and b<=r)
            {
                x=a,y=b;
                if(p[a][b]==0)
                {
                    p[a][b]=1;
                    sum++;
                }
            }
            else d=(d+1)%4;
        }
        cout<<sum<<endl;
    }
    return 0;
}
