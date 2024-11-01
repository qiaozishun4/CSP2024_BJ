#include<iostream>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,i,j;
    char s[53][2];
    cin>>n;
     for(i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    int sum=52,cnt=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if((s[i][0]==s[j][0])&&(s[i][1]==s[j][1])&&j!=i)
             {
                cnt++;
            }
        }
    }
    cout<<sum+cnt-n;
}
