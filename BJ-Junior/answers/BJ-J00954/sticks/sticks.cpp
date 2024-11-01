#include<iostream>
#include<string>
#include<cmath>
using namespace std;
unsigned long long Min=10000000000;
int mymap[10];
int str=0;
int minn(int a,int b)
{
    return a<b;
}
void bai(int n,bool tf)
{
    if(n==0)
    {
        Min=minn(Min,str);
        return;
    }
    if(tf==true)
    {
        for(int i=1;i<=9;i++)
        {
            if(n-mymap[i]>=0)
            {
                str+=i;
                str*=10;
                bai(n-mymap[i],false);
                str/=10;
                str-=i;
            }

        }
        return;
    }
    else
    {
        for(int i=0;i<=9;i++)
        {
            if(n-mymap[i]>=0)
            {
                str+=i;
                str*=10;
                bai(n-mymap[i],false);
                str/=10;
                str-=i;
            }
        }
        return;
    }

}
int main()
{

    mymap[0]=6;
    mymap[1]=2;
    mymap[2]=5;
    mymap[3]=5;
    mymap[4]=4;
    mymap[5]=5;
    mymap[6]=6;
    mymap[7]=3;
    mymap[8]=7;
    mymap[9]=6;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        bai(n,true);
        if(Min==10000000000)
        {
            cout<<-1;
        }
        else
        {
            cout<<Min;
        }
    }
}
