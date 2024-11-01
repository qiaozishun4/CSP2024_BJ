#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string a;
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        getline(cin,a);
    }
    cout<<52-n;
    return 0;
}