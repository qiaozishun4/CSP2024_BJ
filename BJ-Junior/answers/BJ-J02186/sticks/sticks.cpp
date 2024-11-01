#include <cstdio>
#include <iostream>
using namespace std;
int t,n,cnt;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n >= 7)
        {
            int tmp = n % 7;
            tmp += 7;
            if(tmp == 13) cout << 68;
            if(tmp == 12) cout << 60;
            if(tmp == 11) cout << 20;
            if(tmp == 10) cout << 40;
            if(tmp == 9) cout << 17;
            if(tmp == 8) cout << 10;
            if(tmp == 7) cout << 8;
            for(int i = 2; i <= n/7; i++)
            {
                cout << 8;
            }
        }
        else if(n == 6) cout << 6;
        else if(n == 5) cout << 2;
        else if(n == 4) cout << 4;
        else if(n == 3) cout << 7;
        else if(n == 2) cout << 1;
        else cout << -1;
        cout << endl;
    }
    return 0;
}
