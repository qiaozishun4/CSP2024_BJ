#include<bits/stdc++.h>
using namespace std;
char ch[60][3];
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int x=52-n;
    for(int i=1;i<=n;i++)
    {
        cin>>ch[i][1]>>ch[i][2];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(ch[i][1]==ch[j][1]&&i!=j&&ch[i][2]==ch[j][2])
            {
                x++;
                ch[j][1]=i;
                ch[j][2]=j;
            }
        }
    }
    cout<<x;
}
