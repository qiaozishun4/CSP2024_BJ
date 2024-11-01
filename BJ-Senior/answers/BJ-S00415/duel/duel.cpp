#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("duel3.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int x=n;
    int q=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]>a[q])
        {
            q++;
            x--;
        }
    }
    cout<<x;
    return 0;
}