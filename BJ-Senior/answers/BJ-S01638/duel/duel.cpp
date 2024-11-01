#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn =1e5+5;
ll n,cnt;
int r[maxn];
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    sort(r+1,r+1+n,cmp);
    int i=1,j=1;
    while(i<n)
    {
        if(r[i+1]>r[j])
        {
            cnt++;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    cout<<n-cnt;
    return 0;
}
