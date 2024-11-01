#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int>m;
string s;
int main()
{
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        m[s]++;
    }
    if(m.size()<=52) cout<<52-m.size();
    else    cout<<0;
    return 0;
}
