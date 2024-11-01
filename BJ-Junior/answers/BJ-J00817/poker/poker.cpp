#include<iostream>
using namespace std;
int d1[302],d2[302],cnt[102]={0};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i=2;i<=9;i++)
    {
        d2[int(i+'0')]=i;
    }
    d2['A']=1;
    d2['T']=10;
    d2['J']=11;
    d2['Q']=12;
    d2['K']=13;
    d1['D']=0;
    d1['C']=1;
    d1['H']=2;
    d1['S']=3;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char s1,s2;
        cin>>s1>>s2;
        //cout<<d1[s1]*13+d2[s2];
        cnt[d1[s1]*13+d2[s2]]+=1;
    }
    int ans=0;
    for(int i=1;i<=52;i++)
    {
        if(cnt[i]<1)
        {
            //cout<<i;
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}