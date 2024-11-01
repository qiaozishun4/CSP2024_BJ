#include<bits/stdc++.h>
using namespace std;
int n;
int sumc;
int ord[7]={7,6,6,5,4,3,2};
//        0,1,2,3,4,5,6,7,8,9
//int ha[11]={8,0,6,9,2,3,5,4,7,1};
int ha[7]={8,0,6,2,4,7,1};

bool f,ff;
string ans;
string mina(string a,string b)
{
    if(a.size()!=b.size())
    {
        return a.size()>b.size()?b:a;
    }
    else
    {
        return a<b? a:b;
    }
}
void dfs(int sum,int l,string all)
{
    if(sum==0)
    {
        if(l==0)
        {
            return;
        }
        else
        {
            //cout<<all<<endl;
            //ff=0;
            f=0;
            sumc++;
            if(ans=="Null")
            {
                ans=all;
            }
            else
            {
                ans=mina(ans,all);
            }
            if(sumc==20) ff=0;

        }
    }
    else
    {
        if(sum<=7&&sum>=2)
        {

            for(int i=0;i<7;i++)
            {
                if(!ff) break;
                if(ord[i]==sum)
                {
                    dfs(0,ha[i],char(ha[i]+'0')+all);
                }

            }
        }
        else
        {
            for(int i=0;i<7;i++)
            {
                if(!ff)break;
                //cout<<all<<endl;
                if(sum>=ord[i])
                {
                    dfs(sum-ord[i],ha[i],char(ha[i]+'0')+all);

                }


            }
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sumc=0;
        f=ff=1;
        ans="Null";
        string xy="";
        int x;
        cin>>x;
        dfs(x,0,xy);
        if(f)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<ans<<"\n";
        }
    }
    return 0;
}
