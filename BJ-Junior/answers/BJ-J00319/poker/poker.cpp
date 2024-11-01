#include<iostream>
using namespace std;
int main()
{
    int n,ans=0;
    int cnt[52]={0};
    char a,b;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(a=='C')
        {
            a='1';
        }
        else if(a=='D')
        {
            a='0';
        }
        else if(a=='H')
        {
            a='2';
        }
        else
        {
            a='3';
        }
        if(b>='2'&&b<='9')
        {
            cnt[(a-'0')*13+b-'0'-1]++;
        }
        else if(b=='A')
        {
            cnt[(a-'0')*13+1-1]++;
        }
        else if(b=='T')
        {

            cnt[(a-'0')*13+10-1]++;
        }
        else if(b=='J')
        {
            cnt[(a-'0')*13+11-1]++;
        }
        else if(b=='Q')
        {
            cnt[(a-'0')*13+12-1]++;
        }
        else
        {
            cnt[(a-'0')*13+13-1]++;
        }


    }
    for(int i=0;i<52;i++)
    {
        if(cnt[i]==0)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
