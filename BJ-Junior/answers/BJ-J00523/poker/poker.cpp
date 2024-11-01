#include<bits/stdc++.h>
using namespace std;

string s[53];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        for(int j = 1;j < i;j++)
        {
            if(s[i] == s[j])
            {
                cnt++;
                break;
            }
        }
    }
    cout << (52 - n + cnt);
    return 0;
}
