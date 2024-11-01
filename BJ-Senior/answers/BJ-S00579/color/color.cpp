#include <fstream>
using namespace std;
ifstream cin("color.in");
ofstream cout("color.out");
const int NR=2e5+5;
bool f[NR];
int a[NR],ans,n,T;
int check()
{
    int ansl=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(f[j]==f[i])
            {
                if(a[j]==a[i])
                    ansl+=a[j];
                break;
            }
        }
    }
    return ansl;
}
int dfs(int x)
{
    int ut=0;
    if(x==n)
    {
        return check();
    }
    f[x+1]=0;
    ut=max(ut,dfs(x+1));
    f[x+1]=1;
    ut=max(ut,dfs(x+1));
    return ut;
}
int main()
{
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ans=max(ans,dfs(0));
        cout<<ans<<endl;
    }
    return 0;
}
//20pts
