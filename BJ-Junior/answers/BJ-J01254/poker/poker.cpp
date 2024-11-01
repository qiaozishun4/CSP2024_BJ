#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
set<string> a;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        a.insert(s);
    }
    cout<<(52-(int)a.size())<<endl;
    cout<<flush;
    return 0;
}
