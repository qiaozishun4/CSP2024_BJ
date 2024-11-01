#include<bits/stdc++.h>//DCHS TAJQK
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a[10][20];
    int ans=0;
    int n;
    string s;
    cin>>n;
    int front;
    int back;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        //cout<<s[0]<<" "<<s[1]<<endl;
        if(s[0]=='D')
        {
            front=1;
        }
        else if(s[0]=='C')
        {
            front=2;
        }
        else if(s[0]=='H')
        {
            front=3;
        }
        else
        {
            front=4;
        }
        if(s[1]=='T')
        {
            back=10;
        }
        else if(s[1]=='A')
        {
            back=1;
        }
        else if(s[1]=='J')
        {
            back=11;
        }
        else if(s[1]=='Q')
        {
            back=12;
        }
        else if(s[1]=='K')
        {
            back=13;
        }
        else back=s[1]-'0';
        a[front][back]+=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            //cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
            if(a[i][j]<1)
            {
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}
