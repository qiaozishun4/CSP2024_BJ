#include<bits/stdc++.h>
using namespace std;
int a[5][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string w;
        cin>>w;
        int g,h;
        if(w[0]=='D')
        {
            g=0;
        }
        else if(w[0]=='C')
        {
            g=1;
        }
        else if(w[0]=='H')
        {
            g=2;
        }
        else if(w[0]=='S')
        {
            g=3;
        }
       if(w[1]=='T')
        {
            h=9;
        }
        else if(w[1]=='J')
        {
            h=10;
        }
        else if(w[1]=='Q')
        {
            h=11;
        }
        else if(w[1]=='K')
        {
            h=12;
        }
        else if(w[1]=='A')
        {
            h=0;
        }
        else
        {
            h=w[1]-'0'-1;
        }
        a[g][h]=1;
        //cout<<w<<" "<<g<<" "<<h<<endl;
    }
    int ans=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(a[i][j]==0)
            {
                ans++;
                //cout<<i<<" "<<j<<endl;
            }

        }
    }
    cout<<ans;
    return 0;
}
