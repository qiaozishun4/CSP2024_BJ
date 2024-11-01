#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt;
        cin>>n;
        cnt=n/7;
        if(n%7==0)
        {
            while(cnt--)printf("8");
            printf("\n");
        }
        else if(n%7==1)
        {
            if(cnt>=1)
            {
                cnt--;
                printf("10");
                while(cnt--)printf("8");
                printf("\n");
            }
            else printf("-1\n");
        }
        else if(n%7==2)
        {
            printf("1");
            while(cnt--)printf("8");
            printf("\n");
        }
        else if(n%7==3)
        {
            if(cnt>=1)
            {
                printf("22");
                cnt--;
                while(cnt--)printf("8");
                printf("\n");
            }
            else printf("7\n");;
        }
        else if(n%7==4)
        {
            if(cnt>=1)
            {
                cnt--;
                printf("20");
                while(cnt--)printf("8");
                printf("\n");
            }
            else printf("4\n");
        }
        else if(n%7==5)
        {
            printf("2");
            while(cnt--)printf("8");
            printf("\n");
        }
        else
        {
            printf("6");
            while(cnt--)printf("8");
            printf("\n");
        }
    }
    return 0;
}
