#include<set>
#include<cstdio>
#include<iostream>
using namespace std;

int n,ans=52;
set<string> s;
set<string>::iterator it;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        s.insert(temp);
    }
    for(it=s.begin();it!=s.end();it++)ans--;
    cout<<ans;

    return 0;
}
