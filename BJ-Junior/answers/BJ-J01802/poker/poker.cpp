#include<bits/stdc++.h>
using namespace std;
const int N=59;
set<char> mp[N];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        char c1,c2;
        cin>>c1>>c2;
        if(c1=='D'||c1=='C'||c1=='H'||c1=='S')
        {
            if((c2>='2'&&c2<='9')||c2=='A'||c2=='T'||c2=='J'||c2=='Q'||c2=='K')
            {
                if(c1=='D')
                {
                    if(mp[1].count(c2)==0)
                    {
                        cnt++;
                        mp[1].insert({c1,c2});

                    }
                }
                if(c1=='C')
                {
                    if(mp[2].count(c2)==0)
                    {
                        cnt++;
                        mp[2].insert({c1,c2});
                    }
                }
                if(c1=='H')
                {
                    if(mp[3].count(c2)==0)
                    {
                        cnt++;
                        mp[3].insert({c1,c2});
                    }
                }
                if(c1=='S')
                {
                    if(mp[4].count(c2)==0)
                    {
                        cnt++;
                        mp[4].insert({c1,c2});
                    }
                }
            }
        }
    }
    cout<<52-cnt;
    return 0;
}
