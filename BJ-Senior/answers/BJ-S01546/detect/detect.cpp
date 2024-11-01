#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#define endl '\n'
using namespace std;

const double eps=1e-6;
int T;
int n,m,L,del,cnt;
int p[100005];
double v;

struct node
{
    double l,r;
};

priority_queue<node> q;
priority_queue<int,vector<int>,greater<int>> wt;

bool operator<(node s,node t)
{
    return s.l>t.l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        while(!q.empty()) q.pop();
        while(!wt.empty()) wt.pop();
        del=cnt=0;
        cin>>n>>m>>L>>v;
        for(int i=1;i<=n;i++)
        {
            double v0,d,a;
            cin>>d>>v0>>a;
            if(a<=0&&v0<=v) continue;
            if(a>=0&&v0>v)
            {
                q.push({d,2e9});//=
                continue;
            }
            if(a>0&&v0<=v)
            {
                double s=(v*v-v0*v0)*1.0/(2*a);
                if(s+d>=L) continue;
                q.push({s+d+eps,2e9});//-
            }
            if(a<0&&v0>v)
            {
                double s=(v0*v0-v*v)*1.0/(2*(-a));
                if(s+d>L) q.push({d,2e9});//=
                else q.push({d,s+d-eps});//= -
            }
        }
        /*while(!q.empty())
        {
            cout<<q.top().l<<" "<<q.top().r<<endl;
            q.pop();
        }*/
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        p[m+1]=2e9+1;
        for(int i=1;i<=m;i++)
        {
            bool flag=false;
            if(q.top().l>p[i]&&(wt.empty()||wt.top()>=p[i+1]))
            {
                del++;
                continue;
            }
            while(!q.empty()&&q.top().l<=p[i])
            {
                if(q.top().r>=p[i]) wt.push(q.top().r);
                q.pop();
            }
            if(!wt.empty()&&wt.top()<p[i+1])
            {
                flag=true;
                cnt+=wt.size();
                while(!wt.empty()) wt.pop();
            }
            if(!flag) del++;
        }
        cout<<cnt<<" "<<del<<endl;
    }
    return 0;
}


