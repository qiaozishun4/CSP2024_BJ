#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string h;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>h;
        s.insert(h);
    }
    cout<<52-s.size();
    return 0;
}
