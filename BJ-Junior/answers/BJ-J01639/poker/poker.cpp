#include<bits/stdc++.h>
using namespace std;
int cmp(string a, string b)
{
    if (a[0]!=b[0])
    {
        return a[0]>b[0];
    }
    else
    {
        return a[1]>b[1];
    }
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    string b[54];
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    sort(b+1, b+n+1, cmp);
    int ans=0;
    b[n+1]="00";
    for (int i=1;i<=n;i++)
    {
        if (b[i]==b[i+1])
        {
            continue;
        }
        else
        {
            ans++;
        }
    }
    cout<<52-ans<<endl;
    return 0;
}
