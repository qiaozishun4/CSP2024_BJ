#include<bits/stdc++.h>
using namespace std;
long long n,ans=52,tot=0;
string a[105],shu;
bool p;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>shu;
        for(int j=1;j<=tot;j++)
        {
            if(a[i]==shu)
            {
                p=1;
                break;
            }
        }
        if(p==0)
        {
            ans--;
        }
        p=0;
        tot++;
        a[tot]=shu;
    }
    cout<<ans;
    return 0;
}