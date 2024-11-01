#include<bits/stdc++.h>
using namespace std;
int ans=51;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char ch[60][5];
    cin>>n;
    for(int i=0 ;i<n; i++)
    {
            cin>>ch[i][0];
            cin>>ch[i][1];
    }
    char x=ch[0][0];
    char y=ch[0][1];
    for(int i=1 ;i<n; i++)
    {
        if(x==ch[i][0])
        {
            if(y!=ch[i][1])
            {
                ans--;
            }
        }else
        {
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
