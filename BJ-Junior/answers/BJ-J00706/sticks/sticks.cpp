#include<bits/stdc++.h>
using namespace std;
char a[7]={0,'1','7','4','2','6'};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.ans","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n==1){putchar('-');putchar('1');}
        else if(n<7)putchar(a[n-1]);
        else if(n%7==0)for(int i=7;i<=n;i+=7)putchar('8');
        else if(n%7==1){putchar('1');putchar('0');for(int i=15;i<=n;i+=7)putchar('8');}
        else if(n%7==2){putchar('1');for(int i=9;i<=n;i+=7)putchar('8');}
        else if(n%7==3){putchar('2');putchar('2');for(int i=17;i<=n;i+=7)putchar('8');}
        else if(n%7==4){putchar('2');putchar('0');for(int i=18;i<=n;i+=7)putchar('8');}
        else if(n%7==5){putchar('2');for(int i=12;i<=n;i+=7)putchar('8');}
        else if(n%7==6){putchar('6');for(int i=13;i<=n;i+=7)putchar('8');}
        puts("");
    }
    return 0;
}
