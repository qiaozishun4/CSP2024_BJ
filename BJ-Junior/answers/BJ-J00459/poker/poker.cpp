#include<iostream>
#include<set>
using namespace std;
set<string> a;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        a.insert(x);
    }
    cout<<52-a.size();
    return 0;
}