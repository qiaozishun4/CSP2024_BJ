#include <bits/stdc++.h>
using namespace std;

int w[] = {6,2,5,5,4,5,6,3,7,6};
int n;

int f(int n,int deep)
{
    int res = 0x7f7f7f7f;
    if(n == 1)
    {
        cout << -1 << endl;
    }

    for (int i = 0 ; i <= 9 ; i ++)
    {
        if (i - w[i] >= 0)
        {
            res = min(res,f(i - w[i],deep + 1) + i);
        }

    }
    return res;
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> g;

    for (int i = 1 ; i <= n ; i++)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
        }
        cout << f(n,1) << endl;
    }




    return 0;
}
