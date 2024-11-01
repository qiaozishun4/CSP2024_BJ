#include<bits/stdc++.h>
using namespace std;
string dp[100010]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","68","88","107","202","200","208"};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);if(n%7==0&&n!=0)
        {
            for(int i=1;i<=n/7;i++)
                printf("8\n");
            printf("\n");
        }
        else if(n%7==1&&n!=1)
        {
            printf("1");
            for(int i=1;i<n/7;i++)
                printf("8");
            printf("0\n");
        }
        else
            cout<<dp[n]<<'\n';
    }
    return 0;
}
