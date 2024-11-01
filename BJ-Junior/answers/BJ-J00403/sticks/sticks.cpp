#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int ans[101][11],dy[1000005];
int qpow[8]={1,10,100,1000,10000,100000,1000000,10000000};
int qmin(int a,int b){
    int ya=a,yb=b;
    while(dy[a]<dy[b]){
        a=a*10+8;
    }
    while(dy[b]<dy[a]){
        b=b*10+8;
    }
    while(a&&b){
        if(a/qpow[dy[a]-1]!=b/qpow[dy[b]-1]){
            return a/qpow[dy[a]-1]<b/qpow[dy[b]-1]?ya:yb;
        }
        a%=qpow[dy[a]-1];b%=qpow[dy[b]-1];
    }
    return yb;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    memset(ans,0x3f,sizeof(ans));
    int np=1;
    for(int i=1;i<=999999;i++){
        dy[i]=np;
        if(i==10){
            np=2;
        }
        if(i==100){
            np=3;
        }
        if(i==1000){
            np=4;
        }
        if(i==10000){
            np=5;
        }
        if(i==100000){
            np=6;
        }
        int now=i,cnt=0;
        while(now){
            cnt+=num[now%10];
            now/=10;
        }
        if(ans[cnt][np]==0x3f3f3f3f){
            ans[cnt][np]=i;
        }
    }
    dy[1000000]=7;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        int np=n/7,ys=n%7;
        int an=1000000;
        if(np>5){
            int us=0;
            for(int i=1;i<=6;i++){
                if(ans[ys+(i-1)*7][i]>999999){
                    continue;
                }else if(an==1000000){
                    an=ans[ys+(i-1)*7][i];
                    us=ys+(i-1)*7;
                    continue;
                }
                an=qmin(an,ans[ys+(i-1)*7][i]);
                if(dy[an]==i){
                    us=ys+(i-1)*7;
                }
            }
            if(an!=1000000){
                cout<<an;
                for(int i=us+7;i<=n;i+=7){
                    cout<<8;
                }
                cout<<endl;
            }
        }else{
            cout<<ans[n][(n+6)/7]<<endl;
        }
    }
    return 0;
}
