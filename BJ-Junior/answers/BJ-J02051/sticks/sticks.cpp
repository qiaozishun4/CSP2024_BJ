#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans[105]={0,-1,1,7,4,2,6,8};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
        }
        else if(n<=7)
        {
            cout<<ans[n]<<endl;
        }
        else if(n%7==0)
        {
            while(n>0)
            {
                n-=7;
                printf("8");
            }
            printf("\n");
        }
        else if(n%7==1)
        {
            printf("10");
            while(n>8)
            {
                n-=7;
                printf("8");
            }
            printf("\n");
        }
        else if(n%7==2)
        {
            printf("1");
            while(n>2)
            {
                n-=7;
                printf("8");
            }
            printf("\n");
        }
        else if(n%7==3)//
        {
            if(n==10) printf("22");
            else
            {
                printf("200");
                while(n>17)
                {
                    n-=7;
                    printf("8");
                }
            }
            printf("\n");
        }
        else if(n%7==4)
        {
            printf("20");
            while(n>11)
            {
                n-=7;
                printf("8");
            }
            printf("\n");
        }
        else if(n%7==5)
        {
            printf("2");
            while(n>5)
            {
                n-=7;
                printf("8");
            }
            printf("\n");
        }
        else if(n%7==6)
        {
            printf("6");
            while(n>6)
            {
                n-=7;
                printf("8");
            }
            printf("\n");
        }
    }
    return 0;
}
