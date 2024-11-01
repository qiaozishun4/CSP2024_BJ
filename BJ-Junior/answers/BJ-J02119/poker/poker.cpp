#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,a[58]={0};
    string p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        int m=0;
        if(p0]=='D')m=0;
        else if(p[0]=='C')m=13;
        else if(p[0]=='H')m=26;
        else if(p[0]=='S')m=39;
        if(p[1]=='A')m++;
        else if(p[1]=='T')m+=10;
        else if(p[1]=='J')m+=11
        else if(p[1]=='Q')m+=12;
        else if(p[1]=='K')m+=13;
        else m+=p[1]-48;
        a[m]++;
    }
    int ans=0;
    for(int i=1;i<=52;i++)
    {
        if(a[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}