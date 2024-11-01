//f[i+1][i+1][k]=max(f[i+1][i+1][k],f[i][j][k]+(a[i+1]==a[j]?a[j]:0));
//f[i+1][j][i+1]=max(f[i+1][j][i+1],f[i][j][k]+(a[i+1]==a[k]?a[k]:0));
#include <iostream>
#include <cstring>
using namespace std;
int t,n,a[200005];
long long f[2][200005][2];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
            {//i=5 j=3
                f[i%2^1][j][0]=max(f[i%2^1][j][0],f[i%2][j][0]+(a[i]==a[i+1]?a[i]:0));//                equal color
                if(j==i)
                    for(int k=0;k<i;k++)
                    {
                        f[i%2^1][j][0]=max(f[i%2^1][j][0],f[i%2][k][1]+(a[k]==a[i+1]?a[k]:0));//                not equal color
                        f[i%2^1][j][1]=max(f[i%2^1][j][1],f[i%2][k][0]+(a[k]==a[i+1]?a[k]:0));//                not equal color
                    }
                f[i%2^1][j][1]=max(f[i%2^1][j][1],f[i%2][j][1]+(a[i]==a[i+1]?a[i]:0));//                equal color
            }
        long long ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<=1;j++)
                ans=max(ans,f[n%2][i][j]);
        cout<<ans<<endl;
    }
    return 0;
}
