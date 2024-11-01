#include <bits/stdc++.h>
using namespace std;
long long t,n;
int ans(int a){
    if(a==1) return -1;
    else if(a==2) return 1;
    else if(a==3) return 7;
    else if(a==4) return 4;
    else if(a==5) return 2;
    else if(a==6) return 6;
    else if(a==7) return 8;
    else if(a==8) return 10;
    else if(a==9) return 18;
    else if(a==10) return 22;
    else if(a==11) return 26;
    else if(a==12) return 28;
    else if(a==13) return 68;
    else if(a==14) return 88;
    else if(a==15) return 108;
    else if(a==16) return 188;
    else if(a==17) return 200;
    else if(a==18) return 208;
    else if(a==19) return 288;
    else if(a==20) return 688;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(long long i=0;i<t;i++){
        cin>>n;
        if(n<=20){
            cout<<ans(n)<<endl;
            continue;
        }else if(n%7==0){
            for(long long j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }else if(n%7==1){
            cout<<10;
            for(long long q=1;q<int(n/7);q++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}