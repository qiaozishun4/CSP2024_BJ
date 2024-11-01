#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main()
{
    ios::sync_with_stdio(false);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        s.insert(tmp);
    }
    /*
    for(multiset<int> ::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<"\n";
    }*/
    int ans=0;
    for(;s.size();)
    {
        //cout<<*s.begin()<<"\n";
        multiset<int> ::iterator it=s.upper_bound(*s.begin());
        while(it!=s.end())
        {
            //cout<<*it<<"\n";
            s.erase(it);
            multiset<int> ::iterator it2=s.upper_bound(*it);
            it=it2;
        }
        //cout<<114<<"\n";
        //cout<<*it<<"\n";
        s.erase(s.begin());
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
