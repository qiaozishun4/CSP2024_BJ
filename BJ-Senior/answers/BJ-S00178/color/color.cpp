#include<bits/stdc++.h>
using namespace std;

const int N=110;

int T,n,a[N],f[N][N][N];

inline int xt(int x,int y)
{
    if(x==y)return x;
    return 0;
}

int d(int x,int y,int z)
{
    
    if(f[x][y][z]!=0)return f[x][y][z];
    if(x==n+1)
    {
        return 0;
    }
    int p=max(d(x+1,x,z)+xt(a[y],a[x]),d(x+1,y,x)+xt(a[z],a[x]));
    f[x][y][z]=p;
    return p;
}



int main()
{
    freopen("color.in","r",stdin);freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cout<<d(1,0,0)<<"\n";
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    f[i][j][k]=0;
                }
            }
        }

    }

    return 0;
}
