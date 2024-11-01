#include<iostream>
using namespace std;
const int value[10]={6,2,5,5,4,5,6,3,7,6};
const int dbans[50]={-1,-1,1,7,4,2,6,8,10,70,23,48,28,80,88,108,203,238,208,288,808,888/*21xiang*/,1088,1888,2388,2088};
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=22)cout<<dbans[n];
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }
        else if(n%7==1){
            int base=1,ans;
            for(int i=1;i<=n/7;i++){
                ans+=8*base;
                base*=10;
            }
            ans+=2*base;
            cout<<ans;
        }
        else if(n%7==5){
            int base=1,ans;
            for(int i=0;i<=n/7;i++){
                ans+=8*base;
                base*=10;
            }
            ans-=6*base/10;
            cout<<ans;
        }
        else if(n%7==6){
            int base=1,ans;
            for(int i=0;i<=n/7;i++){
                ans+=8*base;
                base*=10;
            }
            ans-=8*base/10/10;
            cout<<ans;
        }
        else if(n%7==3){
            int base=1,ans;
            for(int i=2;i<=n/7;i++){
                ans+=8*base;
                base*=10;
            }
            ans+=23*base;
            cout<<ans;
        }
        else if(n%7==4){
            int base=1,ans;
            for(int i=2;i<=n/7;i++){
                ans+=8*base;
                base*=10;
            }
            ans+=20*base;
            cout<<ans;
        }
        else if(n%7==2){
            int base=1,ans;
            for(int i=2;i<=n/7;i++){
                ans+=8*base;
                base*=10;
            }
            ans+=18*base;
            cout<<ans;
        }
        cout<<endl;
    }
    return 0;
}
