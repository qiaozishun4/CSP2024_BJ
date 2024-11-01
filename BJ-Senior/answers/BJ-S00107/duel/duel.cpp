#include <iostream>
#include <set>
#include <cmath>
using namespace std;
constexpr int N=1e5+3;
multiset<int> gong,shou;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        gong.insert(x);
    }
    while(!gong.empty())
    {
        bool use_shou=false;
        multiset<int>::iterator ss,ss2;
        int s,s2;
        multiset<int>::iterator gg;
        int g;
        if (shou.size()!=0)
        {
            ss=gong.begin(),ss2=shou.begin();
            s=*ss,s2=*ss2;
            if (s>=s2)
            {
                s=s2;
                ss=ss2;
                use_shou=true;
            }
            gg=gong.upper_bound(s);
            if (gg==gong.end())
            {
                break;
            }
            g=*gg;
            /*
            gg=gong.upper_bound(s);
            gg2=gong.upper_bound(s2);

            if (gg==gong.end()&&gg2==gong.end())
            {
                break;
            }
            if (gg==gong.end()||abs(s2-g2)<=abs(s-g))
            {
                gg=gg2;
                g=g2;
                ss=ss2;
                s=s2;
                use_shou=true;
            }*/
        }
        else
        {
            ss=gong.begin();
            s=*ss;
            gg=gong.upper_bound(s);
            if (gg==gong.end())
            {
                break;
            }
            g=*gg;

        }
        //cout<<"gong:"<<g<<" shou:"<<s<<endl;
        gong.erase(gg);

        //cout<<"ins "<<g<<endl;
        if (use_shou)
        {
            //cout<<"erase "<<s<<endl;
            shou.erase(ss);
        }
        else
        {
            gong.erase(ss);
        }
        shou.insert(g);
        /*cout<<"round finished"<<endl;
        for (auto x:gong) cout<<x<<" ";
        cout<<endl;
        for (auto x:shou) cout<<x<<" ";
        cout<<endl;*/
    }
    cout<<shou.size()+gong.size()<<endl;
}
