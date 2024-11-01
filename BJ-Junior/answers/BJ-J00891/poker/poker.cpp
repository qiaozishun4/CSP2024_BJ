#include<bits/stdc++.h>
using namespace std;
map<string,int> hsh;
string ls;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ls;
        hsh[ls]=1;
    }
    cout<<52-hsh.size()<<endl;
    return 0;
}