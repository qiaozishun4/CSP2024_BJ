#include<bits/stdc++.h>
using namespace std;
int n;
char a[100][2];
char s1[5]={'D','C','H','S'};
char s2[14]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int s[4][13];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%c%c\n",&a[i][0],&a[i][1]);
        int j,k;
        for(j=0;j<4;j++)
        {
            if(a[i][0]==s1[j])
                break;
        }
        for(k=0;k<13;k++)
        {
            if(a[i][1]==s2[k])
                break;
        }
        s[j][k]=1;
    }
    /*for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
            cout<<s[i][j]<<' ';
        cout<<endl;
    }*/
    int ans=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(s[i][j]==0)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
