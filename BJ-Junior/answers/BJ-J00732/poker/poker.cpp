#include <bits/stdc++.h>
using namespace std;
bool d[20],c[20],h[20],s[20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c1,c2;
        int ic2;
        cin>>c1>>c2;
        if(c2=='A') ic2=1;
        else if(c2=='T') ic2=10;
        else if(c2=='J') ic2=11;
        else if(c2=='Q') ic2=12;
        else if(c2=='K') ic2=13;
        else ic2=c2-'0';
        if(c1=='D') d[ic2]=true;
        else if(c1=='C') c[ic2]=true;
        else if(c1=='H') h[ic2]=true;
        else if(c1=='S') s[ic2]=true;
    }
    int sum=0;
    for(int i=1;i<=13;i++) if(!d[i]) sum++;
    for(int i=1;i<=13;i++) if(!c[i]) sum++;
    for(int i=1;i<=13;i++) if(!h[i]) sum++;
    for(int i=1;i<=13;i++) if(!s[i]) sum++;
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
