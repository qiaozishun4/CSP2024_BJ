#include<bits/stdc++.h>
using namespace std;
int d[100010];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int m, um;
    cin >> um;
    for(int i = 1; i <= um; i++)
    {
        cin >> d[i];
    }
    if(m % 2 != 0) m = um - 1;
    else m = um;
    m = um;
    sort(d + 1, d + um + 1);
    if(d[m / 2] != d[m / 2 + 1])
    {
        if(um % 2 == 1)
        {
            if(d[m / 2 + 1] < d[um])
            {
                cout << m / 2;
            }
            else
            {
                cout << m / 2 + 1;
            }
        }
        else
        {
            cout << m / 2;
        }
    }
    else
    {
        int l = d[m / 2];
        if(d[um] == d[1])
        {
            cout << m;
        }
        else if(um % 2 == 1)
        {
            if(d[um - 1] == d[1])
            {
                cout << um - 1;
            }
            else if(d[um] != l)
            {
                int ts = 0;
                for(int i = 1; i <= m; i++)
                {
                    if(d[i] == l) ts++;
                    else if(ts > 0) break;
                }
                if(ts <= m / 2) cout << m / 2 - 1;
                else cout << ts - 1;
            }
        }
        else
        {
            int ts = 0;
            for(int i = 1; i <= m; i++)
            {
                if(d[i] == l) ts++;
                else if(ts > 0) break;
            }
            if(ts <= m / 2) cout << m / 2;
            else cout << ts;
        }
    }
    return 0;
}
/*
that's too difficult to me
*play it like you never did before!!
10
136 136 136 2417 136 136 2417 136 136 136
*/
