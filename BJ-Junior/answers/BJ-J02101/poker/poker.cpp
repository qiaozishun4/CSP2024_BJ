#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    set<string> se;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        se.insert(s);
    }
    cout<<52-se.size();
}
