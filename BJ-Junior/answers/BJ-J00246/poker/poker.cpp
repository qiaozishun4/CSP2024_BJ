#include <iostream>
#include <set>
using namespace std;
#define ll long long
ll n;
string str;
set <string> se;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(ll i = 1;i <= n;i ++){
        cin >> str;
        se.insert(str);
    }
    cout << 52 - se.size();
    return 0;
}
