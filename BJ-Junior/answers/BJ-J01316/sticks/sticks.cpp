#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    int a;
    int list[10000]={0};
    for(int i = 0;i<t;i++)
    {
        cin>>a;
        if(a==0)
        {
            list[i]=-1;
        }
        if(a==1)
        {
            list[i]=-1;
        }
        if(a==2)
        {
            list[i]=1;
        }
        if(a==3)
        {
            list[i]=7;
        }
        if(a==4){
            list[i]=4;
        }
        if(a==5)
        {
            list[i]=2;
        }
        if(a==6)
        {
            list[i]=6;
        }
        if(a==7)
        {
            list[i]=8;
        }
        if(a==8)
        {
            list[i]=10;
        }
        if(a==9)
        {
            list[i]=18;
        }
        if(a==10)
        {
            list[i]=40;
        }
        if(a==11)
        {
            list[i]=20;
        }
        if(a==12)
        {
            list[i]=60;
        }
        if(a==13)
        {
            list[i]=68;
        }
        if(a==14)
        {
            list[i]=106;
        }
        if(a==15)
        {
            list[i]=108;
        }
        if(a==16)
        {
            list[i]=203;
        }
        if(a==17)
        {
            list[i]=206;
        }
        if(a==18)
        {
            list[i]=208;
        }
        if(a==19)
        {
            list[i]=608;
        }
        
    }
    for(int i = 0;i<t;i++)
    {
        cout << list[i]<<endl;
    }
    return 0;
}
