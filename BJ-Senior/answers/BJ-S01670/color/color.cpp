#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int N=2e5+7;
const int M=1e6+7;
int a[N],l[N],lst[M],f[N];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(l,0,sizeof(l));
        memset(lst,0,sizeof(lst));
        memset(f,0,sizeof(f));
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i]==a[i-1]) ans+=a[i];
            l[i]=lst[a[i]];
            lst[a[i]]=i;
        }
        for(int i=1; i<=n; i++)
        {
            if(l[i] && l[i]!=i-1)
                f[i]=max(f[i-1],f[l[i]+1]+a[i]);
            else f[i]=f[i-1];
        }
        cout<<f[n]+ans<<endl;
    }
    return 0;
}
