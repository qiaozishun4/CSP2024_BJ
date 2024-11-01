#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    set<string>s;int n;cin>>n;
    while(n--)
    {
        string tmp;cin>>tmp;
        s.insert(tmp);
    }
    int len=s.size();
    cout<<52-len;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
