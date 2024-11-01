#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10, INF=0x7fffffff;
using namespace std;
int T;
int n,mn=INF;
int c0;
map<int,int> digit;
map<int,int>stick;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    digit[0]=6;
    digit[1]=2;
    digit[2]=5;
    digit[3]=INF;
    digit[4]=4;
    digit[5]=INF;
    digit[6]=6;
    digit[7]=3;
    digit[8]=7;
    digit[9]=INF;

    stick[1]=INF;
    stick[2]=1;
    stick[3]=7;
    stick[4]=4;
    stick[5]=2;
    stick[6]=0;
    stick[7]=8;
    //stick[8]=1; stick[9]=18; stick[10]=14; stick[11]=12;// stick[12]=INF;
    cin>>T;
    while(T--)
    {
        mn=INF;
        cin>>n;
        if(n<2){cout<<-1<<endl;continue;}
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==1 and n>8)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++)cout<<8;
            cout<<endl;
            continue;
        }
        c0=n/6-1;
        for(int i=1;i<=9;i++)
        {
            int mmn;
            if(digit[i]==INF)continue;

            int tmp=n-6*(c0+1)-digit[i];

            if((tmp==1 or tmp<0) and c0>=0){c0--;tmp+=6;}
            if((tmp==1 or tmp<0) and c0>=0){c0--;tmp+=6;}
            if(tmp==1 or tmp<0)continue;

            if(tmp>=8){c0++;tmp-=6;}

            mmn=i*pow(10,c0+2)+stick[tmp];
            if(tmp==0)mmn/=10;
            //cout<<i<<"+"<<tmp<<"="<<mmn<<endl;
            mn=min(mn,mmn);
        }
        cout<<mn<<endl;
    }
    return 0;
}
