#include <bits/stdc++.h>
#define int long long
#define MAXN 500010

using namespace std;
int n,a[MAXN],cnt[MAXN],nn;
void solve()
{
    cin>>n;nn=n;
    for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-a-1;
    int sum=cnt[a[1]],zong=0;
    for(int i=2;i<=n;i++)
    {
        if(cnt[a[i]]>=sum)
        {
            int tmp=cnt[a[i]];
            cnt[a[i]]-=sum;
            zong+=sum;
            sum=tmp;
        }
        else
        {
            //sum-=cnt[a[i]];
            zong+=cnt[a[i]];
            cnt[a[i]]=0;
        }
        //cout<<sum<<" "<<zong<<endl;
    }
    cout<<nn-zong<<'\n';
}
signed main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    int _T=1;//cin>>_T;
    while(_T--)solve();
    return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
