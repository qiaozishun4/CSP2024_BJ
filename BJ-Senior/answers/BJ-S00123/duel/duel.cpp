#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN];
int cnt[MAXN];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int id=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1]) id++;
        cnt[id]++;
    }
    int sum=0;
    for(int i=1;i<=id;i++)
    {
        if(sum<=cnt[i]) sum=cnt[i];
    }
    cout<<sum<<endl;
    return 0;
}
