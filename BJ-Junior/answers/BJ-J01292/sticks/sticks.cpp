#include<bits/stdc++.h>
using namespace std;
int T;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        int n,ans=0;
        cin>>n;
        if(n==7||(n-7)%6==1) n-=7,ans+=8;
        else if(n==6||(n-6)%6==1) n-=6,ans+=6;
        else if(n==5||(n-5)%6==1) n-=5,ans+=2;
        else if(n==4||(n-4)%6==1) n-=4,ans+=4;
        else if(n==3||(n-3)%6==1) n-=3,ans+=7;
        else if(n==2||(n-2)%6==1) n-=2,ans+=1;
        else if(n>=8) n-=2,ans+=1;
        else{
            n=0,cout<<"-1"<<endl;
            goto brk;
        }
        while(n>0){
//            cout<<"start "<<n<<" "<<ans<<endl;
            if(n==7) ans=ans*10+8,n-=7;
            else if(n>=6) ans=ans*10,n-=6;
            else if(n==5) n-=5,ans=ans*10+2;
            else if(n==4) n-=4,ans=ans*10+4;
            else if(n==3) n-=3,ans=ans*10+7;
            else if(n==2) n-=2,ans=ans*10+1;
        }
        cout<<ans<<endl;
        brk:;
    }
    return 0;
}
