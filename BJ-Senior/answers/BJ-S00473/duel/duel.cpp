#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;
priority_queue<int,vector<int>,greater<int> > q1;
int t[N];
pair<int,int> f[N];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
    }
    sort(t+1,t+n+1);
    int cnt,pre=-1;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            pre=t[i];
            cnt=1;
        }
        else if(t[i]!=pre)
        {
            q.push(make_pair(pre,cnt));
            cnt=1;
            pre=t[i];
        }
        else cnt++;

    }
    if(cnt!=0) q.push(make_pair(pre,cnt));
    int ans=0;
    while(1)
    {
        if(q1.size()==0)
        {
            if(q.size()<2) break;
            pair<int,int> a,b;

            a=q.top();
            q.pop();
            b=q.top();
            q.pop();

            a.second-=1;
            b.second-=1;
            if(b.second>0) q.push(b);
            if(a.second>0) q.push(a);
            ans++;
            q1.push(b.first);


        }
        else{
            if(q.size()==0)
            {
                break;
            }
            else
            {
                int len=0;
                while(!q.empty()&&!q1.empty())
                {
                    pair<int,int> h=q.top();
                    while(h.first>q1.top()&&h.second>0)
                    {
                        q1.pop();
                        h.second-=1;
                        q1.push(h.first);
                        ans++;
                    }
                    if(h.second>0) f[++len]=h;
                    q.pop();
                }
                while(!q1.empty()) q1.pop();
                for(int i=1;i<=len;i++) q.push(f[i]);
                if(q.empty())
                {
                    break;
                }

            }
        }

    }
    cout<<n-ans;
    return 0;
}
