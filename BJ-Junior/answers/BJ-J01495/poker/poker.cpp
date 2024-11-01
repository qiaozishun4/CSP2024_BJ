#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    set<string> s;
    string st;
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>st;
        s.insert(st);
    }
    cout<<52-s.size();
    return 0;
}
