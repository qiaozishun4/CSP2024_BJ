#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,ans=0;
        cin>>n;
        int weishu=n/7;
        if(n%7==0){
            int weizhi=1;
            for(int i=1;i<=weishu;i++){
                ans+=8*weizhi;
                weizhi*=10;
            }
            cout<<ans<<endl;
            continue;
        }
        else if(n%7==1){
            if(n==1){
                cout<<-1<<endl;
                continue;
            }
            else if(n==8){
                cout<<10<<endl;
                continue;
            }
            int weizhi=100;
            for(int i=1;i<=weishu-1;i++){
                ans+=8*weizhi;
                weizhi*=10;
            }
            cout<<ans+1<<endl;
            continue;
        }
        else if(n%7==2){
            if(n==2){
                cout<<1<<endl;
                continue;
            }
            else if(n==9){
                cout<<18<<endl;
                continue;
            }
            int weizhi=1;
            for(int i=1;i<=weishu;i++){
                ans+=8*weizhi;
                weizhi*=10;
            }
            ans+=weizhi;
            cout<<ans<<endl;
        }
        else if(n%7==3){
            if(n==3){
                cout<<7<<endl;
                continue;
            }
            else if(n==10){
                cout<<23<<endl;
                continue;
            }
            else if(n==24){
                cout<<2008<<endl;
                continue;
            }
            int weizhi=1;
            for(int i=1;i<=weishu-1;i++){
                ans+=8*weizhi;
                weizhi*=10;
            }
            ans+=weizhi*2+weizhi*20;
            cout<<ans<<endl;
        }
        else if(n%7==4){
            if(n==4){
                cout<<4<<endl;
                continue;
            }
            else if(n==11){
                cout<<20<<endl;
                continue;
            }
            int weizhi=1;
            for(int i=1;i<=weishu-1;i++){
                ans+=8*weizhi;
                weizhi*=10;
            }
            ans+=weizhi*20;
            cout<<ans<<endl;
        }
        else if(n%7==5){
            if(n==5){
                cout<<5<<endl;
                continue;
            }
            else if(n==12){
                cout<<28<<endl;
                continue;
            }
            else if(n==19){
                cout<<608<<endl;
                continue;
            }
            int weizhi=1;
            for(int i=1;i<=weishu;i++){
                ans+=8*weizhi;
                weizhi*=10;
            }
            ans+=weizhi*2;
            cout<<ans<<endl;
        }
        else if(n%7==6){
            if(n==6){
                cout<<6<<endl;
                continue;
            }
            else if(n==13){
                cout<<80<<endl;
                continue;
            }
            else if(n==20){
                cout<<808<<endl;
                continue;
            }
            int weizhi=1;
            for(int i=1;i<=weishu;i++){
                ans+=8*weizhi;
                weizhi*=10;
            }
            ans+=weizhi*6;
            cout<<ans<<endl;
        }
    }
    return 0;
}
