#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    set<string> st;
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        st.insert(s);
    }
    cout << 52 - st.size() << endl;
    return 0;
}