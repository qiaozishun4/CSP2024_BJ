#include<iostream>
#include<set>
using namespace std;
#define ll long long
set<string> se;
ll n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        se.insert(s);
    }
    cout<<52-se.size();
    return 0;
}
