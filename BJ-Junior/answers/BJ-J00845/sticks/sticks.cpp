#include<bits/stdc++.h>
using namespace std;
long long M=1000000000000000005;
int a[15]={6,2,5,5,4,5,6,3,7,6};
long long minn=M;
void dfs(int k,int t,long long ans){
    bool flag=false;
    for(int i=0;i<10;i++){
        if(t>=a[i]){
            flag=true;
        }
    }
    if(flag==false){
        if(t==0){
            minn=min(minn,ans);
        }
        return ;
    }else{
        for(int i=0;i<10;i++){
            if(i==0&&ans==0){
                continue;
            }else{
                if(t>=a[i]){
                    t-=a[i];
                    dfs(k,t,ans*10+i);
                    t+=a[i];
                }
            }
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        long long n;
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(((n-1)%7)==0&&(n-1)>0){
            cout<<1<<6;
            for(int i=1;i<=(n-8)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n<=20){
            minn=M;
            dfs(n,n,0);
            if(minn==M){
                minn=-1;
            }
            cout<<minn<<endl;
        }
    }
    return 0;
}
