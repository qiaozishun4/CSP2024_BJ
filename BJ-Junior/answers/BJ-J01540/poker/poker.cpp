#include<bits/stdc++.h>
using namespace std;
set<string> p;
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        p.insert(x);
    }
    cout<<52-p.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
