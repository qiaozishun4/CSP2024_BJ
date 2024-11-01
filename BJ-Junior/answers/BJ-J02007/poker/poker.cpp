#include <iostream>
#include <set>
using namespace std;

int n;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    set<string> ans;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        ans.insert(s);
    }
    int len = 52 - ans.size();
    cout << len << endl;
    return 0;
}
