#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
struct f{
    int r;
    int num=0;
};
f monsters[maxn];
int a[maxn];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int tmpr=a[1],tmpnum=1,cntteam=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==tmpr) tmpnum++;
        else{
            monsters[cntteam].r=tmpr;
            monsters[cntteam].num=tmpnum;
            cntteam++;
            tmpnum=1;
            tmpr=a[i];
        }
    }
    monsters[cntteam].r=tmpr;
    monsters[cntteam].num=tmpnum;

    int j=1;
    for(int i=2;i<=cntteam;i++)//攻击力第二小的怪兽才具备攻击能力
    {
        int left=monsters[i].num;
        while(j<i&&left>0)
        {
            monsters[j].num-=min(monsters[j].num,left);
            left-=min(monsters[j].num,left);
            if(monsters[j].num==0) j++;
        }
    }
    int ans=0;
    for(;j<=cntteam;j++)
    {
        ans+=monsters[j].num;
    }
    cout<<ans<<endl;
    return 0;
}
