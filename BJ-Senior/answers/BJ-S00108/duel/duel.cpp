#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> an;
vector <int> bn;
vector <int> ad;
vector <int> bd;
void sor()
{
    for(int i=0;i<ad.size();i++)
    {
        bool flag=false;
        for(int j=i+1;j<ad.size();j++)
        {
            if(ad[j]<ad[j-1])
            {
                flag=true;
                swap(ad[j],ad[j-1]);
                swap(an[j],an[j-1]);
            }
        }
        if(!flag)
        {
            break;
        }
    }
}
void add(int t,int kind)
{
    if(kind==1)
    {
        bool flag=false;
        for(int i=0;i<ad.size();i++)
        {
            if(t==ad[i])
            {
                flag=true;
                an[i]++;
            }
        }
        if(!flag)
        {
            ad.push_back(t);
            an.push_back(1);
        }
    }
    if(kind==0)
    {
        bool flag=false;
        for(int i=0;i<bd.size();i++)
        {
            if(t==bd[i])
            {
                flag=true;
                bn[i]++;
            }
        }
        if(!flag)
        {
            bd.push_back(t);
            bn.push_back(1);
        }
    }
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        add(t,1);
    }
    sor();
    while(!ad.empty())
    {
        if(bd.empty())
        {
            int key=ad.front();
            an.front()--;
            if(an.front()==0)
            {
                ad.erase(ad.begin());
                an.erase(an.begin());
            }
            bool flag=false;
            for(int j=0;j<ad.size();j++)
            {
                if(key>ad[j])
                {
                    flag=true;
                    an[j]--;
                    if(an[j]==0)
                    {
                        ad.erase(ad.begin()+j);
                        an.erase(an.begin()+j);
                    }
                    add(key,0);
                    break;
                }
            }
            if(!flag)
            {
                add(key,0);
            }
        }
        else
        {
            int key=ad.front();
            an.front()--;
            if(an.front()==0)
            {
                ad.erase(ad.begin());
                an.erase(an.begin());
            }
            bool flag=false;
            for(int j=0;j<bd.size();j++)
            {
                if(key>bd[j])
                {
                    flag=true;
                    bn[j]--;
                    if(bn[j]==0)
                    {
                        bd.erase(bd.begin()+j);
                        bn.erase(bn.begin()+j);
                    }
                    add(key,0);
                    break;
                }
            }
            if(!flag)
            {
                bool fla=false;
                for(int j=0;j<ad.size();j++)
                {
                    if(key>ad[j])
                    {
                        fla=true;
                         an.front()--;
                        if(an.front()==0)
                        {
                            ad.erase(ad.begin());
                            an.erase(an.begin());
                        }
                        add(key,0);
                        break;
                    }
                }
                if(!fla)
                {
                    add(key,0);
                }
            }

        }
    }
    long ans=0;
    for(int i=0;i<bn.size();i++)
    {
        ans+=bn[i];
    }
    cout<<ans;
    return 0;
}
