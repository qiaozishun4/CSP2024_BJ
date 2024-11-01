#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=n/7;
        if(n%7!=0)
            x++;
        y=n%7;
        if(y==0)
        {
            for(int i=1;i<=x;i++)
                printf("8");
        }
        else if(y==1)
        {
            if(n==1)
                printf("-1");
            else
                printf("10");
            for(int i=1;i<x-1;i++)
                printf("8");
        }
        else if(y==2)
        {
            printf("1");
            for(int i=1;i<x;i++)
                printf("8");
        }
        else if(y==3)
        {
            if(n==3)
                printf("7");
            else if(n==10)
                printf("22");
            else
            {
                printf("200");
                for(int i=1;i<=x-3;i++)
                    printf("8");
            }

        }
        else if(y==4)
        {
            if(n==4)
                printf("4");
            else
            {
                printf("20");
                for(int i=1;i<=x-2;i++)
                    printf("8");
            }

        }
        else if(y==5)
        {
            printf("2");
            for(int i=1;i<=x-2;i++)
                printf("8");

        }
        else
        {
            if(n==6)
                printf("6");
            else
            {
                printf("80");
                for(int i=1;i<=x-2;i++)
                    printf("8");
            }
        }
        printf("\n");
    }
    return 0;
}
