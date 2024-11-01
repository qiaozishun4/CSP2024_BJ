#include <bits/stdc++.h>
using namespace std;
int n,sum;
string s[65];
bool a;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
    }
    for(int i=1;i<=n;i++)
    {
        a=1;
        for(int j=i+1;j<=n;j++)
        {
            if(s[i]==s[j])
            {
                a=0;
                break;
            }
        }
        if(!a)n--;
    }
    cout << 52-n;
    return 0;
}