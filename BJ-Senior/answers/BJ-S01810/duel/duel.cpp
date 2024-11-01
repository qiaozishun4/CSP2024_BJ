#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int r;
    for(int i=1;i<=n;i++)
    {
        cin>>r;
        cnt[r]++;
    }
    int now=0;
    for(int i=1;i<=100000;i++)
    {
        now=max(0,now-cnt[i]);
        now+=cnt[i];
    }
    cout<<now<<endl;
    return 0;
}
