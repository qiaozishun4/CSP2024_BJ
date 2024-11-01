#include<bits/stdc++.h>
using namespace std;

long long n;
long long sj;
long long ge[100010];
queue<long long> q;
long long m=-1;

long long work()
{
    for(long long i=1;i<=m;i++)
    {
        for(long long j=1;j<=ge[i];j++) q.push(i);
    }
    for(long long i=1;i<=m;i++)
    {
        if(ge[i]!=0)
        {
            for(long long j=1;j<=ge[i];j++)
            {
                int temp=q.front();
                if(i>temp) q.pop();
                else break;
            }
        }
    }
    return q.size();
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    for(int i=1;i<=100000;i++)
    {
        ge[i]=0;//初始化
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sj;
        ge[sj]++;
        if(sj>m) m=sj;
    }
    m++;
    cout<<work()<<endl;
    return 0;
}
