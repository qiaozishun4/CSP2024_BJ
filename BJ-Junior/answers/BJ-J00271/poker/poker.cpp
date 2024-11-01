#include<bits/stdc++.h>
using namespace std;
set<char> d,c,h,s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char l,t;
        cin>>l>>t;
        if(l=='D')
        {
            d.insert(t);
        }
        else if(l=='C')
        {
            c.insert(t);
        }
        else if(l=='H')
        {
            h.insert(t);
        }
        else if(l=='S')
        {
            s.insert(t);
        }
    }
    cout<<52-d.size()-c.size()-h.size()-s.size();
    return 0;
}
