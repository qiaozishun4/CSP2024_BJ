#include <iostream>
#include <unordered_set>

using namespace std;
string str;
unordered_set<string> st;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        cin >> str;
        st.insert(str);
    }
    cout << 52ULL - st.size();
    return 0;
}
