#include<bits/stdc++.h>
using namespace std;
int a[100001];
int mm(int n)
{
    int min_v = 100001, min_i;
    for (int i = 0; i < n; ++i)
    {
        if (!a[i])
        {
            continue;
        }
        if (a[i] < min_v)
        {
            min_v = a[i];
            min_i = i;
        }
    }
    return min_i;
}
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int s = n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {

        if (a[i])
        {
            if (a[mm(n)] < a[i])
            {
                a[mm(n)] = 0;
                --s;
            }
        }
    }
    cout << s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
