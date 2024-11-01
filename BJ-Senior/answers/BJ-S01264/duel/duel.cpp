#include<bits/stdc++.h>
using namespace std;
int num[100005];
int shu[100005];
map<int ,int> num_of;
priority_queue<int,vector<int>,less<int> > q;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,m=0;
    cin>>n;m=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        num_of[num[i]]=0;
    }
    for(int i=1;i<=n;i++)
    {
        num_of[num[i]]++;
        if(num_of[num[i]]>1)
        {
            m--;
            continue;
        }
        q.push(num[i]);
    }
    for(int i=1;i<=m;i++)
    {
        shu[i]=q.top();
        q.pop();
    }
    /*for(int i=1;i<=m;i++)
    {
        cout<<shu[i]<<' ';
    }cout<<endl;*/
    for(int i=1;i<=m/2;i++)
    {
        //cout<<shu[i]<<' '<<shu[m-i+1]<<'\n';
        swap(shu[i],shu[m-i+1]);
        //cout<<shu[i]<<' '<<shu[m-i+1]<<'\n';
    }
    /*for(int i=1;i<=m;i++)
    {
        cout<<shu[i]<<' '<<num_of[shu[i]]<<'\n';
    }*/
    int cnt=num_of[shu[1]],ans=0;
    for(int i=2;i<=m;i++)
    {
        if(cnt>num_of[shu[i]])
        {
            ans+=num_of[shu[i]];
        }
        else
        {
            ans+=cnt;
            cnt=num_of[shu[i]];
        }
    }
    cout<<n-ans<<'\n';
    return 0;
}