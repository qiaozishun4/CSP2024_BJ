#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if(n<=14){
            if(n==14) cout<<88;
            else if(n==1) cout<<-1;
            else if(n==2) cout<<1;
            else if(n==3) cout<<7;
            else if(n==4) cout<<4;
            else if(n==5) cout<<2;
            else if(n==6) cout<<6;
            else if(n==7) cout<<8;
            else if(n==8) cout<<10;
            else if(n==9) cout<<18;
            else if(n==10) cout<<22;
            else if(n==11) cout<<20;
            else if(n==12) cout<<28;
            else if(n==13) cout<<68;
        }
        else{
            if(n%7==0) for(long long i=1;i<=n/7;i++) cout<<8;
            else if(n%7==1){
                cout<<10;
                for(long long i=1;i<=n/7-1;i++) cout<<8;
            }
            else if(n%7==2){
                cout<<18;
                for(long long i=1;i<=n/7-1;i++) cout<<8;
            }
            else if(n%7==3){
                cout<<23;
                for(long long i=1;i<=n/7-1;i++) cout<<8;
            }
            else if(n%7==4){
                cout<<20;
                for(long long i=1;i<=n/7-1;i++) cout<<8;
            }
            else if(n%7==5){
                cout<<28;
                for(long long i=1;i<=n/7-1;i++) cout<<8;
            }
            else if(n%7==6){
                cout<<68;
                for(long long i=1;i<=n/7-1;i++) cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}
