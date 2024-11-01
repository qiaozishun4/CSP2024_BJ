#include <iostream>
#include <string.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N];
int f[N],pre[N];
int ans=0;
void Checks()
{
    int r_s=1,b_s=1;
    int t1=1,t2=1;
    while(f[t1]!=0&&t1<n)
    {
        t1++;
    }
    while(f[t2]!=1&&t2<n)
    {
        t2++;
    }
    r_s=t1;
    b_s=t2;
    //cout << r_s << " " << b_s << endl;
    for(int i=r_s+1;i<=n;i++)
    {
        if(f[i]==1)
        {
            continue;
        }
        pre[i]=r_s;
        r_s=i;
    }
    for(int i=b_s+1;i<=n;i++)
    {
        if(f[i]==0)
        {
            continue;
        }
        pre[i]=b_s;
        b_s=i;
    }
    int sums=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[pre[i]])
        {
            //cout << i << " " << a[i] << " " << a[pre[i]] <<endl;
            sums+=a[i];
        }
    }
    //cout <<sums << endl;
    ans=max(ans,sums);
    //cout << endl;
    return;
}
void Dfs(int x)
{
    if(x==n)
    {
        Checks();
        return;
    }
    for(int i=0;i<=1;i++)
    {
        f[x+1]=i;
        Dfs(x+1);
    }
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        memset(f,0,sizeof(f));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        ans=0;
        Dfs(0);
        cout << ans << endl;
    }
    return 0;
}
