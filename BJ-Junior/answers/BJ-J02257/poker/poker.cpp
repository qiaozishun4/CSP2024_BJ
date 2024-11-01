#include<iostream>
#include<set>
using namespace std;
set<string> s;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    long long n;
    cin>>n;
    string ch;
    for(long long i=1;i<=n;i++)
    {
        cin>>ch;
        s.insert(ch);
    }
    cout<<52-s.size();
    return 0;
}
