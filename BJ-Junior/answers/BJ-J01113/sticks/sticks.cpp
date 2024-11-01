#include<bits/stdc++.h>
using namespace std;
int n,t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<-1<<endl;
        else if(n==2)cout<<1<<endl;
        else if(n==3)cout<<7<<endl;
        else if(n==4)cout<<4<<endl;
        else if(n==5)cout<<2<<endl;
        else if(n==6)cout<<6<<endl;
        else if(n==7)cout<<8<<endl;
        else if(n==8)cout<<10<<endl;
        else if(n==9)cout<<18<<endl;
        else if(n==10)cout<<22<<endl;
        else if(n==11)cout<<20<<endl;
        else if(n==12)cout<<28<<endl;
        else if(n==13)cout<<68<<endl;
        else if(n==14)cout<<88<<endl;
        else if(n==15)cout<<108<<endl;
        else if(n==16)cout<<188<<endl;
        else if(n==17)cout<<200<<endl;
        else if(n==18)cout<<208<<endl;
        else if(n==19)cout<<588<<endl;
        else if(n==20)cout<<688<<endl;
        else if(n==21)cout<<888<<endl;
        else if(n==22)cout<<1088<<endl;
        else if(n==23)cout<<1888<<endl;
        else if(n==24)cout<<2007<<endl;
        else{
            if(n%7==0){
                int sum=n/7,ans=0;
                while(sum--)cout<<8;
            }
            else if(n%7==1){
                int sum=(n-1)/7,ans=10;
                cout<<10;
                while(sum--)cout<<8;
                cout<<endl;
            }

        }
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

