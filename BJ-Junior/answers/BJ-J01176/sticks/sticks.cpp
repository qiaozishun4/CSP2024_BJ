#include<iostream>
using namespace std;
long long num[100010];
bool flag=false;
long long T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=1;i<=100000;i++)
    {
        int x=i,d=0;
        while(x>0)
        {
            d=x%10;
            if(d==0) num[i]+=6;
            if(d==1) num[i]+=2;
            if(d==2) num[i]+=5;
            if(d==3) num[i]+=5;
            if(d==4) num[i]+=4;
            if(d==5) num[i]+=5;
            if(d==6) num[i]+=6;
            if(d==7) num[i]+=3;
            if(d==8) num[i]+=7;
            if(d==9) num[i]+=6;
            x/=10;
        }
    }
    while(T--)
    {
        cin>>n;
        flag=false;
        for(int i=1;i<=100000;i++)
        {
            if(num[i]==n)
            {
                flag=true;
                cout<<i<<endl;
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}
