#include<bits/stdc++.h>
using namespace std;
set<string> s;
string a;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.ans","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        s.insert(a);
    }
    cout<<52-s.size();
    return 0;
}
