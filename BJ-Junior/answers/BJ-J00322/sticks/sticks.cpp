#include <bits/stdc++.h>
using namespace std;

// let me rp += 2147483647;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, ans = 0;
        string s;
        cin >> n;
        while(n > 13)
        {
            s = '8' +s;
            n -= 7;
        }
        if(n == 13) s = "80" + s;
        if(n == 12) s = "60" + s;
        if(n == 11) s = "20" + s;
        if(n == 10) s = "23" + s;
        if(n == 9) s = "24" + s;
        if(n == 8) s = "10" + s;
        if(n == 7) s = '8' + s;
        if(n == 6) s = '6' + s;
        if(n == 5) s = '2' + s;
        if(n == 4) s = '4' + s;
        if(n == 3) s = '7' + s;
        if(n == 2) s = '1' + s;
        if(n == 1)
        {
            cout <<-1 <<endl;
            continue;
        }
        cout << s << endl;
    }
    // want 🥇🥇🥇
    return 0;
}
