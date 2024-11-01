#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6},b[10]={0,0,1,7,4,2,0,8};
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,num=0;
        cin>>n;
        if(n==1)
            cout<<-1<<endl;
        else if(n==2)
            cout<<1<<endl;
        else if(n==3)
            cout<<7<<endl;
        else if(n==4)
            cout<<4<<endl;
        else if(n==5)
            cout<<2<<endl;
        else if(n==6)
            cout<<6<<endl;
        else if(n==7)
            cout<<8<<endl;
        else if(n==8)
            cout<<-1<<endl;
        else if(n==9)
            cout<<18<<endl;
        else if(n==10)
            cout<<78<<endl;
        else if(n==11)
            cout<<48<<endl;
        else if(n==12)
            cout<<28<<endl;
        else if(n==13)
            cout<<68<<endl;
        else if(n==14)
            cout<<88<<endl;
        else if(n==15)
            cout<<108<<endl;
        else if(n==16)
            cout<<188<<endl;
        else if(n==17)
            cout<<788<<endl;
        else if(n==18)
            cout<<208<<endl;
        else if(n==19)
            cout<<288<<endl;
        else if(n==20)
            cout<<388<<endl;
        else if(n%7==1){
            num=10;
            for(int i=1;i<n/7;i++)
                num=num*10+8;
            cout<<num<<endl;
        }else{
            num=b[n%7];
            for(int i=1;i<=n/7;i++)
                num=num*10+8;
            int tmp=num;
            if(tmp/(tmp%100*10)==48)
                num=20*(tmp%10*10)+num%(tmp%10*10);
            else if(tmp/(tmp%100*10)==38)
                num=28*(tmp%10*10)+num%(tmp%10*10);
            else if(tmp/(tmp%100*10)==58)
                num=28*(tmp%10*10)+num%(tmp%10*10);
            else if(tmp/(tmp%100*10)==98)
                num=68*(tmp%10*10)+num%(tmp%10*10);
            else if(tmp/(tmp%100*10)==78)
                num=22*(tmp%10*10)+num%(tmp%10*10);
            cout<<num<<endl;
        }
    }
    return 0;
}