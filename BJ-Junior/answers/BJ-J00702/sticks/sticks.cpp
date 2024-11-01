#include <bits/stdc++.h>
using namespace std;

int dif[14] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68};

void calc()
{
    int n;
    cin >> n;
    int cnt8 = n/7;
    n %= 7;
    if(cnt8 == 0)
    {
        cout << dif[n] << endl;
        return;
    }
    cnt8--;
    n += 7;
    cout << dif[n];
    for(int i=1; i<=cnt8; i++)
        cout << 8;

}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        calc();
    }
    return 0;
}
