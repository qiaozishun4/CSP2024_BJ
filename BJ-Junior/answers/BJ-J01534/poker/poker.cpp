#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[53];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<51;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        m++;
        cin>>s[i];
        for(int j=1;j<i;j++)
        {
            if(s[j]==s[i])
            {
                m--;
                break;
            }
        }
    }
    cout<<52-m;
    return 0;
}
