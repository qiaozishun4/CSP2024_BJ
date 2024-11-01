#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("duel.in");
ofstream cout("duel.out");
const int NR=1e5+5;
bool cmp(int a,int b)
{
    return a>b;
}
int cnt[NR];
int a[NR],maxn,minn,n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
        cnt[a[i]]++;
    }
    for(int i=minn;i<=maxn;i++)
    {
        ans=max(ans,cnt[i]);
    }
    cout<<ans<<endl;
    return 0;
}
