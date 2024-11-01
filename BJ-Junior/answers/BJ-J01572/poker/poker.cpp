#include<iostream>
#include<set>
using namespace std;

int n, ans = 52;

set<string> st;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        string s;
        cin >> s;
        if(st.find(s) == st.end())
        {
            ans --;
            st.insert(s);
        }
    }

    cout << ans << endl;

    return 0;
}