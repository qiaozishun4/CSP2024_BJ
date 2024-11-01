#include<bits/stdc++.h>
using namespace std;
set<string> c;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","r",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        c.insert(a);
    }
    cout<<52-c.size();
    return 0;
}
