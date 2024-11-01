#include<bits/stdc++.h>
using namespace std;
string a[55];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.in","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        bool flag=0;
        for(int j=1;j<i;j++)
        {
            if(s==a[j])
            {
                ans++;
                break;
            }
        }
        a[i]=s;
    }
    cout<<52-n+ans;
    return 0;
}
