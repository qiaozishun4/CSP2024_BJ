#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T,n;
long long cnt;
int dic[15]={6,2,5,5,4,5,6,3,7,6};
int a[8000]={};
void zh(int w)
{
    long long ans=0;
    for(int i=w;i>1;i--)
    {
        ans+=pow(10,(w-1))*a[i];
    }
    ans+=a[1];
    cnt=min(cnt,ans);
}
void dfs(int w,int s)
{
    if(s<=0)
    {
        zh(w);
        return ;
    }
    if(s<=1)
    {
        cnt=-1;
        return ;
    }
    for(int i=0;i<=9;i++)
    {
        a[w]=min(a[w],i);
        dfs(w+1,s-dic[i]);
    }
}
int main()
{
        freopen("sticks.in","r",stdin);
        freopen("sticks.out","w",stdout);
        cin >> T;
        while(T)
        {
            cin >> n;
            cnt=0;
            if(n<=1)
            {
                cnt=-1;
            }
            else if(n==2)
            {
                cnt=1;
            }
            else if(n==3)
            {
                cnt=7;
            }
            else if(n==6)
            {
                cnt=6;
            }
            else
            {
                memset(a,0,sizeof(a));
                dfs(1,n);
            }
            cout << cnt << endl;
            T--;
        }
        return 0;
}
