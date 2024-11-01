#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt[100005],xiao;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int sum=0;
    a[0]=-1e9;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            sum++;
            cnt[sum]++;
        }else{
            cnt[sum]++;
        }
    }
    int ans=n;
    for(int i=2;i<=sum;i++)
    {
        if(cnt[i]>=cnt[i-1])
        {
            ans-=cnt[i-1];
            int t=cnt[i]-cnt[i-1];
            if(xiao>=t){
                ans-=t;
                xiao-=t;
            }else{
                ans-=xiao;
                xiao=0;
            }
        }else{
            ans-=cnt[i];
            xiao+=(cnt[i-1]-cnt[i]);
        }
    }
    cout<<ans;
    return 0;
}
