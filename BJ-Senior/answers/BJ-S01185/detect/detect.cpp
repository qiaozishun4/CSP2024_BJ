#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct road{
    ll n;
    ll m;
    ll L;
    ll v;
};
struct car{
    ll d;
    ll v;
    ll a;
    bool pd;
};
bool b(int n,int m,const vector<pair<int,int> >& if1)
{
    for(int i=n;i<m;i++)
    {
        for(int j=0;j<if1.size();j++)
        {
            if(if1[j].first==i)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    vector<road> rs(t);
    for(int i=0;i<rs.size();i++)
    {
        cin>>rs[i].n;
        cin>>rs[i].m;
        cin>>rs[i].L;
        cin>>rs[i].v;
        vector<car> cs(rs[i].n);
        vector<pair<int,int> > if1(rs[i].n);
        int sum=rs[i].n,sum1=0;
        for(auto j:cs)
        {
            cin>>j.d;
            cin>>j.v;
            cin>>j.a;
        }
        for(int j=0;j<rs[i].m;j++)
        {
            cin>>if1[j].first;
        }
        for(int j=0;j<rs[i].n;j++)
        {
            ll t=(pow(rs[j].v,2)-pow(cs[j].d,2))/(2*cs[j].a)+cs[j].v;
            if(cs[j].a==0&&cs[j].v>=rs[j].v)
            {
                sum--;
                continue;
            }
            else if(b(cs[j].v,t,if1))
            {
                sum--;
            }
            else{
                if1[j].second++;
            }
        }
        for(int j=0;j<if1.size();j++)
        {
            if(if1[j].second==0)
            {
                sum1++;
            }
        }
        cout<<sum+2<<" "<<sum1-1<<endl;
    }
    return 0;
}
