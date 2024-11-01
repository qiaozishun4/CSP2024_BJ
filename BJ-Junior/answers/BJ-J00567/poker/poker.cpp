#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a[52]={};
    char b[2];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b;
        if(b[0]=='D')
        {
            if(b[1]=='A') a[0]++;
            if(b[1]=='T') a[9]++;
            if(b[1]=='J') a[10]++;
            if(b[1]=='Q') a[11]++;
            if(b[1]=='K') a[12]++;
            else{
                a[b[1]-'0'-1]++;
            }
        }
        if(b[0]=='C')
        {
            if(b[1]=='A') a[13]++;
            if(b[1]=='T') a[22]++;
            if(b[1]=='J') a[23]++;
            if(b[1]=='Q') a[24]++;
            if(b[1]=='K') a[25]++;
            else{
                a[b[1]-'0'+12]++;
            }
        }
        if(b[0]=='H')
        {
            if(b[1]=='A') a[26]++;
            if(b[1]=='T') a[35]++;
            if(b[1]=='J') a[36]++;
            if(b[1]=='Q') a[37]++;
            if(b[1]=='K') a[38]++;
            else{
                a[b[1]-'0'+25]++;
            }
        }
        if(b[0]=='S')
        {
            if(b[1]=='A') a[39]++;
            if(b[1]=='T') a[48]++;
            if(b[1]=='J') a[49]++;
            if(b[1]=='Q') a[50]++;
            if(b[1]=='K') a[51]++;
            else{
                a[b[1]-'0'+38]++;
            }
        }
    }
    int sum=0;
    for(int i=0;i<52;i++)
    {
        if(a[i]==0)
        {
            sum++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
