#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
set<string> s;
int main()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<51<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        s.insert(x);
    }
    cout<<52-s.size()<<endl;
    return 0;
}
