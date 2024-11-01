#include<bits/stdc++.h>
using namespace std;
int main()
{
    string t;
    int n,d[13]={0},c[13]={0},h[13]={0},s[13]={0},ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t[0]=='D')
        {
            if(t[1]=='A')d[0]=1;
            else if(t[1]=='J')d[10]=1;
            else if(t[1]=='Q')d[11]=1;
            else if(t[1]=='K')d[12]=1;
            else d[int(t[1]-48)]=1;
        }
        if(t[0]=='C')
        {
            if(t[1]=='A')c[0]=1;
            else if(t[1]=='J')c[10]=1;
            else if(t[1]=='Q')c[11]=1;
            else if(t[1]=='K')c[12]=1;
            else c[int(t[1]-48)]=1;
        }
        if(t[0]=='H')
        {
            if(t[1]=='A')h[0]=1;
            else if(t[1]=='J')h[10]=1;
            else if(t[1]=='Q')h[11]=1;
            else if(t[1]=='K')h[12]=1;
            else h[int(t[1]-48)]=1;
        }
        else
        {
            if(t[1]=='A')s[0]=1;
            else if(t[1]=='J')s[10]=1;
            else if(t[1]=='Q')s[11]=1;
            else if(t[1]=='K')s[12]=1;
            else s[int(t[1]-48)]=1;
        }

    }
    for(int i=0;i<13;i++)if(d[i]==0)ans++;
    for(int i=0;i<13;i++)if(c[i]==0)ans++;
    for(int i=0;i<13;i++)if(h[i]==0)ans++;
    for(int i=0;i<13;i++)if(s[i]==0)ans++;
    cout<<ans;
}
