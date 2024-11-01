#include<bits/stdc++.h>
using namespace std;
long long s[1001],f[100100];
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    memset(f,-1,sizeof(f));
    f[1]=-1;
    f[2]=1;
    f[3]=7;
    f[4]=4;
    f[5]=2;
    f[6]=6;
    f[7]=8;
    f[8]=10;

    int T;
    cin>>T;
    for(int i=9;i<=100010;i++){
        f[i]=min(f[i-2]*10+f[2],min(f[i-5]*10+f[5],min(f[i-6]*10+0,f[i-7]*10+f[7])));
    }
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
        }else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<"8";
            }
            cout<<endl;
        }else if((n-1)%7==0){
            int num=(n-1)/7-1;
            cout<<"10";
            for(int i=1;i<=num;i++){
                cout<<"8";
            }
            cout<<endl;
        }else{
            cout<<f[n]<<endl;
        }
    }
    return 0;
}
