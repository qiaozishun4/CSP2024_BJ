#include<bits/stdc++.h>
using namespace std;
int stk[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string tos[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
string f[100005];

string re0(string s)
{
    while(s[0] == '0')
    {
        s.erase(0, 1);
    }
    return s == "" ? "0" : s;
}

bool cmp(string a, string b)
{
    if(a[0] == 'm') return false;
    if(b[0] == 'm') return true;
    // cout << a.size() << '/' <<  b.size() << '#';
    if(a.size() == b.size())
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) return a[i] < b[i];
        }
    }
    return a.size() < b.size();
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n % 7 == 0)
        {
            for(int i = 1; i <= n / 7; i++) cout << 8;
            cout << endl;
            continue;
        }
        else if(n % 7 == 1)
        {
            n /= 7;
            n--;
            cout << 10;
            for(int i = 1; i <= n; i++) cout << 8;
            cout << endl;
            continue;
        }
        f[0] = "0";
        f[1] = "max";
        for(int i = 2; i <= n; i++)
        {
            f[i] = "max";
            for(int j = 0; j <= 9; j++)
            {
                if(i - stk[j] < 0) continue;
                if(j == 0 && f[i - stk[j]] == "0") continue;
                string tmp = re0(f[i - stk[j]] + tos[j]);
                // cout << tmp << ',';
                f[i] = cmp(f[i], tmp) ? f[i] : tmp;
                // cout << f[i] << ' ';
            }
            // cout << endl;
        }
        // for(int i = 0; i <= n; i++) cout << f[i] << '/';
        // cout << endl;
        cout << (re0(f[n]) == "max" ? "-1" : f[n]) << endl;
        // cout << "------------------------------------" << endl;
    }
    return 0;
}
