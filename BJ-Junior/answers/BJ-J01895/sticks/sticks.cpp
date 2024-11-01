#include <bits/stdc++.h>
using namespace std;
int T,f[114514];
int stnum1[15]={6,2,5,5,4,5,6,3,7,6};
//int stnum2[]={8,4,7,7,6,7,8,4,9,8,
              //11,7,10,10,9,10,11,8,12,11,
              //11,7,10,10,9,10,11,8,12,11,
              //10,6,9,9,8,9,10,7,11,10,
              //11,7,10,10,9,10,11,8,12,11,
              //12,8,11,11,10,11,12,9,13,12,
              //9,5,8,8,7,8,9,5,10,9,
              //13,9,12,12,11,12,13,10,14,13,
              //12,8,11,11,10,11,12,9,13,12};
int ans10[14]={-1,-1,1,7,4,2,6,8,10,18,22};
int ans20[24]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=1;i<=21;i++) f[i]=ans20[i];
    cin>>T;
    while(T--){
        int n;
        //char nn;
        //cin>>nn;
        //n=nn-'0';
        cin>>n;
        //cout<<nn<<' '<<n<<'\n';
        if(n<=20) cout<<ans20[n]<<'\n';
        else if(n%7==0){
            int cnt=(n/7);
            for(int i=1;i<=cnt;i++) cout<<8;
            cout<<'\n';
        }
        else{
            for(int i=21;i<=114514;i++){
                if((i+1)%7==0){
                    cout<<6;
                    int ccnt=(n-6)/7;
                    for(int i=1;i<=ccnt;i++) cout<<8;
                    cout<<'\n';
                }
                else if((n-1)%7==0||(n-2)%7==0){
                    cout<<1;
                    if((n-2)%7==0){
                        int cnnt=(n-2)/7;
                        for(int i=1;i<=cnnt;i++) cout<<8;
                        cout<<'\n';
                    }
                }
            }
        }
    }
    return 0;
}
