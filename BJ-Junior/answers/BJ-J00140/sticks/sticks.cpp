#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;

int stk[]={6,2,5,5,4,5,6,3,7,6},t,n,b;
vector<int> v,ans;
bool jmp[]={0,0,0,1,0,1,1,0,0,1};
void dfs(int stks)
{
    if(stks<=0)
    {
        //cout<<stks<<' ';
        //    for(int i=0;i<v.size();i++)cout<<v[i];
        //    cout<<' ';
        //    for(int i=0;i<ans.size();i++)cout<<ans[i];if(ans.size()==0)cout<<-1;
        //cout<<endl;
        if(stks==0)
        {
            if(ans.size()==0)
                ans=v;
            else if(v.size()<ans.size())
                ans=v;
            else if(v.size()==ans.size())
            {
                bool b=false;
                for(int i=0;i<ans.size();i++)
                    if(v[i]<ans[i])
                        {b=true;break;}
                    else if(v[i]>ans[i])break;
                if(b)
                    ans=v;
            }
        }
        return;
    }
    if(v.size()>ans.size()&&ans.size()!=0)return;
    if(v.size()==ans.size()&&ans.size()!=0)
    {
        bool b=false;
        for(int i=0;i<ans.size();i++)
            if(v[i]<ans[i])
                {b=true;break;}
            else if(v[i]>ans[i])break;
        if(!b)
            return;
    }
    for(int i=0;i<10;i++)
    {
        if(jmp[i]&&!(v.size()==0&&i==6))continue;
        if(v.size()==0&&i==0)continue;
        v.push_back(i);    //b=b*10+i;
        dfs(stks-stk[i]);
        v.pop_back();
    }
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        v.clear();
        ans.clear();
        dfs(n);
        if(ans.size()==0)
            cout<<-1;
        else
            for(int j=0;j<ans.size();j++)cout<<ans[j];
        cout<<endl;
    }

    return 0;
}
