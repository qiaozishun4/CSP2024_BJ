#include <bits/stdc++.h>
using namespace std;
const int N=60;
int n;
string s[N];
int ans=52;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i];
        bool flag=false;
        for (int j=1;j<i;j++)
        {
            if (s[i]==s[j])
            {
                flag=true;
                break;
            }
        }
        if (flag==false) ans--;
    }
    cout<<ans;
    return 0;
}
