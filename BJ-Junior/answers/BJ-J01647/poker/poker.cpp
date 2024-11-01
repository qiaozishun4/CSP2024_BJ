#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int box[101];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        string s;
        cin>>s;
        if(s[0]=='D')sum+=0;
        else if(s[0]=='C')sum+=13;
        else if(s[0]=='H')sum+=26;
        else sum+=39;
        if(s[1]=='A')sum+=1;
        else if(s[1]=='T')sum+=10;
        else if(s[1]=='J')sum+=11;
        else if(s[1]=='Q')sum+=12;
        else if(s[1]=='K')sum+=13;
        else sum+=(s[1]-'0');
        box[sum]++;
    }
    for(int i=1;i<=52;i++)
    {
        if(box[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}