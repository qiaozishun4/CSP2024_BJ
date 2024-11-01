#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;
set<string> m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        m.insert(s);
    }
    cout<<52-(int)m.size()<<endl;
    return 0;
}
