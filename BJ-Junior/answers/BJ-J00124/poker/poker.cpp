#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, cnt;
    cin >> n;
    string s[60];
    cnt = n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(s[i] == s[j] && s[i] != "00" && s[j] != "00" && i != j)
            {
                s[j] = "00";
                cnt--;
            }
        }
    }
    cout << 52 - cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
