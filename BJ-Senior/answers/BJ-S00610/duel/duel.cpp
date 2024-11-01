#include<bits/stdc++.h>
using namespace std;
struct p
{
    int id,v;
    friend bool operator < (const p _a,const p _b)
    {
        return _a.v<_b.v;
    }
};
priority_queue<p> q,q1;
//q max,q1
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0,t;i<n;i++)
    {
        cin>>t;
        q.push({i,-t});
    }
    while(!q.empty())
    {
        p t=q.top();
        q.pop();
        if(!q1.empty() && -t.v>-q1.top().v)
        {
            q1.pop();
            q1.push(t);
        }
        else
        {
            if(-t.v>-q.top().v)
            {
                q.pop();
                q1.push(t);
            }
            else if(-t.v<-q.top().v)
            {
                q1.push(q.top());
                q.pop();
            }
            else q1.push(t);
        }
    }
    cout<<q1.size();
    return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
