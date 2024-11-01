#include<bits/stdc++.h>//T3 10^3 50pts
using namespace std;
int T,n;
int num[10]={6,2,5,100005,4,100005,6,3,7,100005};
int dy[10]={114,514,1,7,4,2,0,8};//paiming
int f[100005];
int f1[100005];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=2;i<=7;++i){
        f[i]=1;
        f1[i]=i;
    }
    f[1]=0x3f3f3f3f;
    for(int i=8;i<=100000;++i){
        f[i]=0x3f3f3f3f;
        for(int j=2;j<=7;++j){
            if(f[i-j]+1<f[i]){
                f1[i]=j;
                f[i]=f[i-j]+1;
            }
            if(f[i-j]+1==f[i]&&dy[f1[i]]>dy[j]){
                f1[i]=j;
            }
        }
    }
    while(T--){
        cin>>n;
        int n1=n;
        if(n<=1){ cout<<-1<<endl; continue;}

        dy[6]=6;
        if(f1[n]==6){
            f[n]=0x3f3f3f3f;
            for(int j=2;j<=7;++j){
                if(f[n-j]+1<f[n]){
                    f1[n]=j;
                    f[n]=f[n-j]+1;
                }
                if(f[n-j]+1==f[n]&&dy[f1[n]]>dy[j]){
                    f1[n]=j;
                }
            }
        }
        dy[6]=0;
        if(f1[n]==6){
            n-=6;
            cout<<6;
        }
        while(n){
            cout<<dy[f1[n]];
            n-=f1[n];
        }
        cout<<'\n';
        f[n]=0x3f3f3f3f;
        for(int j=2;j<=7;++j){
            if(f[n-j]+1<f[n]){
                f1[n]=j;
                f[n]=f[n-j]+1;
            }
            if(f[n-j]+1==f[n]&&dy[f1[n]]>dy[j]){
                f1[n]=j;
            }
        }
    }
    return 0;
}
//easy to now: 3,5,9 is false so 10000000000000000000000
