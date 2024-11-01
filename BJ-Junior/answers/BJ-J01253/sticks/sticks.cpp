#include <bits/stdc++.h>
using namespace std;
int sk[10]={6,2,5,5,4,5,6,3,7,6};
void solveA(int n)
{
    for(int i=1;i<=n/7;i++)
    {
        printf("8");
    }
}
void solveB(int n)
{
    printf("10");
    for(int i=1;i<=(n-8)/7;i++)
    {
        printf("8");
    }
}

void solve2(int n)
{
    printf("1");
    for(int i=1;i<=(n-2)/7;i++)
    {
        printf("8");
    }
}
void solve3(int n)
{
    printf("23");
    for(int i=1;i<=(n-10)/7;i++)
    {
        printf("8");
    }
}
void solve4(int n)
{
    printf("20");
    for(int i=1;i<=(n-11)/7;i++)
    {
        printf("8");
    }
}
void solve5(int n)
{
    printf("2");
    for(int i=1;i<=(n-5)/7;i++)
    {
        printf("8");
    }
}
void solve6(int n)
{
    printf("6");
    for(int i=1;i<=(n-6)/7;i++)
    {
        printf("8");
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    int n;
    while(T--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"-1";
        }
        else if(n==2) printf("1");
        else if(n==3) printf("7");
        else if(n==4) printf("4");
        else if(n==5) printf("2");
        else if(n==6) printf("6");
        else if(n%7==0) solveA(n);
        else if(n%7==1) solveB(n);
        else if(n%7==2) solve2(n);
        else if(n%7==3) solve3(n);
        else if(n%7==4) solve4(n);
        else if(n%7==5) solve5(n);
        else if(n%7==6) solve6(n);
        cout<<endl;
    }
    return 0;
}
