#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,r[N],ans;
bool f[N],exs[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    sort(r+1,r+1+n);
    ans=n;
    int st=1,atk=2,lv=n;
    while(atk<=n)
    {
        while(f[atk]) atk++;
        while(exs[st]) st++;
        if(r[atk]>r[st])
        {
            ans--;
            exs[st]=true;
            f[st]=true;
        }
        f[atk]=true;
    }
    cout<<ans;
    return 0;
}