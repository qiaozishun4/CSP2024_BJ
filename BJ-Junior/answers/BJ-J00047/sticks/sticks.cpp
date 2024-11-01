#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int len=(n+6)/7;
        int p=n%7;
        int cnt=0;
        int fst;
        if(p==1&&len!=1)p++,cnt++;
        else if(p==1)fst=-1;
        if(p==2)fst=1;
        if(p==3&&len!=1&&len!=2)p+=2,cnt+=2;
        else if(p==3&&len==1)fst=7;
        else if(p==3)p++,cnt++;
        if(p==4&&len!=cnt+1)p++,cnt++;
        else if(p==4)fst=4;
        if(p==5)fst=2;
        if(p==6)fst=6;
        if(p==0)fst=8;
        for(int i=1;i<=len;i++)
        {
            if(i==1)cout<<fst;
            else if(i<=cnt+1)cout<<0;
            else cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
