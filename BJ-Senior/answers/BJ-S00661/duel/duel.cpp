#include<bits/stdc++.h>
using namespace std;
long long n,a[114514],t[114514],cnt;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t[a[i]]++;
    }
    for(int i=1;i<=114513;i++)
    {
        if(t[i]!=0)
        {
            if(cnt==0)cnt+=t[i];
            else if(cnt<t[i])
            {
                cnt=t[i];
            }
            else if(cnt>=t[i])
            {
                cnt=cnt;
            }
            //cout<<i<<"  "<<cnt<<"\n";
        }
    }
    cout<<cnt;
    return 0;
}
