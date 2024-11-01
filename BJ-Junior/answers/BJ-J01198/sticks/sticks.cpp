#include<bits/stdc++.h>
using namespace std;
int sti[15]={6,2,5,5,4,5,6,3,7,6},sti1[10]={0,0,1,7,4,2,6,8};
struct f
{
    int he,di,fa=0;
    bool ok=0;
};
int he[100005],di[100005],fa[100005];
bool ok[100005];
vector<int> v1;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ok[1]=1;
    he[2]=1,di[2]=1;
    he[3]=7,di[3]=1;
    he[4]=4,di[4]=1;
    he[5]=3,di[5]=1;
    he[6]=6,di[6]=1;
    he[7]=8,di[7]=1;
    for(int i=8;i<=100000;i++)
    {
        he[i]=-1000,di[i]=1000;
        int x=10000;
        for(int j=9;j>=0;j--)
        {
            if(i-sti[j]>=0&&ok[i-sti[j]]==0)
            {
                if(di[i-sti[j]]+1<=di[i])
                {
                    if(he[i-sti[j]]<x)
                    {
                        di[i]=di[i-sti[j]]+1;
                        he[i]=j;
                        x=he[i-sti[j]];
                        fa[i]=i-sti[j];
                    }
                }
            }
        }
        if(he[i]==1000&&di[i]==1000)ok[i]=1;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(ok[n]==1)
        {
            cout<<-1<<endl;
        }
        else
        {   
            int x=n,cnt=0;
            while(x>0)
            {
                cnt++;
                if(fa[x]==6&&x-fa[x]==6)v1.push_back(6);
                else
                v1.push_back(sti1[x-fa[x]]);
                x=fa[x];
            }
            sort(v1.begin(),v1.end(),greater<int>());
            for(int i=cnt-1;i>=0;i--)
            {
                if(i!=cnt-1&&v1[i]==6)cout<<0;
                else
                cout<<v1[i];
            }
            cout<<endl;
            while(!v1.empty())v1.pop_back();
        }

    }
    return 0;
}