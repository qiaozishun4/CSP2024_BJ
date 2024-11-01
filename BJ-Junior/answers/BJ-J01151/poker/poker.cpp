#import<bits/stdc++.h>
using namespace std;
int n,a[60],k,m,ans;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s[0]=='D')
            m=0;
        if(s[0]=='C')
            m=1;
        if(s[0]=='H')
            m=2;
        if(s[0]=='S')
            m=3;
        k=m*13;
        for(int j=2;j<=19;j++)
        {
            if(s[1]-'0'==j)
                a[k+j]=1;
            if(s[1]=='A')
                a[k+1]=1;
            if(s[1]=='T')
                a[k+10]=1;
            if(s[1]=='J')
                a[k+11]=1;
            if(s[1]=='Q')
                a[k+12]=1;
            if(s[1]=='K')
                a[k+13]=1;
        }
    }
    for(int i=1;i<=52;i++)
    {
        if(a[i]==0)
            ans++;
    }
    cout<<ans;
    return 0;
}
