#include<iostream>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin.tie(0),cout.tie(0);
    int n,cnt=0;
    bool p;
    cin>>n;
    string a[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p=1;
        for(int j=1;j<=i-1;j++)
        {
            if(a[j]==a[i]) p=0;
        }
        if(p==1) cnt++;
    }
    cnt=52-(cnt%52);
    if(cnt==52) cout<<0;
    else cout<<cnt;
    return 0;
}

