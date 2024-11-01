#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<string> s;
string a;
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>a;
        s.insert(a);
    }
    cout<<52-s.size()<<endl;
    return 0;
}
