#include<bits/stdc++.h>
using namespace std;
int p[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    sort(p+1,p+n+1);
    int k=1;
    for(int i=2;i<=n;i++)
    {
        if(p[i]>p[k])k++;
    }
    cout<<n-k+1;
    return 0;
}
