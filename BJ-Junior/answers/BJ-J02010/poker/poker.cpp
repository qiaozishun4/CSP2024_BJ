#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    string s1;
    for(int i = 1; i <= n; i++)
    {
        cin >> s1;
    }
    if(n == 1)
    {
        cout << 51;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = n; j >= i + 1; j--)
        {
            if(s1[i] / '0' == s1[j] / '0') n--;
        }
    }
    n = 52 - n;
    cout << n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}