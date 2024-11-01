#include <bits/stdc++.h>
using namespace std;
int n,num;
string a[100];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++)
    {
        string b = a[i];
        for(int j=i+1; j<=n; j++)
        {
            if(a[j] == b)
            {
                a[j] = "0";
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i] != "0")
        {
            num++;
        }
    }
    cout << 52-num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
