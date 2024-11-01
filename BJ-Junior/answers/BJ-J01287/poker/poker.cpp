#include<bits/stdc++.h>
using namespace std;
char a[60],b[60];
int d[14],c[14],h[14],s[14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]=='D')
        {
            if(b[i]=='A') d[1]++;
            else if(b[i]=='T') d[10]++;
            else if(b[i]=='J') d[11]++;
            else if(b[i]=='Q') d[12]++;
            else if(b[i]=='K') d[13]++;
            else d[int(b[i])-48]++;
        }
        else if(a[i]=='C')
        {
            if(b[i]=='A') c[1]++;
            else if(b[i]=='T') c[10]++;
            else if(b[i]=='J') c[11]++;
            else if(b[i]=='Q') c[12]++;
            else if(b[i]=='K') c[13]++;
            else c[int(b[i])-48]++;
        }
        else if(a[i]=='H')
        {
            if(b[i]=='A') h[1]++;
            else if(b[i]=='T') h[10]++;
            else if(b[i]=='J') h[11]++;
            else if(b[i]=='Q') h[12]++;
            else if(b[i]=='K') h[13]++;
            else h[int(b[i])-48]++;
        }
        else if(a[i]=='S')
        {
            if(b[i]=='A') s[1]++;
            else if(b[i]=='T') s[10]++;
            else if(b[i]=='J') s[11]++;
            else if(b[i]=='Q') s[12]++;
            else if(b[i]=='K') s[13]++;
            else s[int(b[i])-48]++;
        }
    }
    int cnt=0;
    for(int i=1 ; i<=13 ; i++)
    {
        if(d[i]==0) cnt++;
        if(c[i]==0) cnt++;
        if(h[i]==0) cnt++;
        if(s[i]==0) cnt++;
    }
    cout<<cnt;
    return 0;
}

