#include <bits/stdc++.h>
using namespace std;
string a[100005];
int temp;
bool cnt_found(string s)
{
    for (int i = 1; i <= temp; i++)
        if (a[i] == s)
            return true;
    return false;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,i,ans=52;
    string s;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> s;
        if (!cnt_found(s))
        {
            a[++temp] = s;
            ans--;
        }
    }
    cout << ans;
    return 0;
}