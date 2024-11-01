#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10, INF=0x7fffffff;
using namespace std;
int T;
int players,limit,q;
vector<int> dict[N];
struct word
{
    int first,last;
    int player;
    int d;
};
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>players>>limit>>q;
        for(int i=1;i<=players;i++)
        {
            int li;
            cin>>li;//wobuhuiwobuhuiwobuhui
            for(int j=1;j<=li;j++)
            {
                int c;
                cin>>c;
                dict[i].push_back(c);
            }
        }
        for(int i=1;i<=q;i++)
        {
            bool flag=0;
            int depth,last;//wobuhuiwobuhuiaaaaaaaaaa
            cin>>depth>>last;
            queue<word> chain;
            chain.push((word){last,last,0,0});
            word p;
            while(!chain.empty())
            {
                p=chain.front();
                //cout<<p.first<<","<<p.last<<",played by "<<p.player<<", depth="<<p.d<<endl;
                chain.pop();
                if(p.d==depth)
                {
                    if(p.first==1){flag=1;break;}
                    else continue;
                }
                for(int i=1;i<=players;i++)
                    if(i!=p.player)
                    {
                        int len=dict[i].size();
                        for(int j=1;j<=len;j++)
                            if(dict[i][j]==p.first and j>0)
                                for(int k=1;k<=j and k<limit;k++)
                                    chain.push((word) {dict[i][j-k], dict[i][j], i, p.d+1} );
                    }
            }
            cout<<flag<<endl;
        }
    }
    return 0;
}
