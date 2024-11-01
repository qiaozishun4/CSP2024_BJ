#include<bits/stdc++.h>
using namespace std;
int mg[10]={6,2,5,5,4,5,6,3,7,6};
//          0 1 2 3 4 5 6 7 8 9
long long sz[100001]={0,0,1,7,4,2,0,8};
long long ws(long long a,long long b){
    int x[10000],sl=0,s0=0;
    if(a==0)s0++;
    if(b==0) s0++;
    while(a>0){
        x[sl]=a%10;
        if(a%10==0)s0++;
        a/=10;
        sl++;
    }
    while(b>0){
        x[sl]=b%10;
        if(b%10==0)s0++;
        b/=10;
        sl++;
    }
    // cout<<s0<<"*"<<sl<<"@";
    sort(x,x+sl);
    long long z=0;
    if(sl==0) z=6*(pow(10,s0-1));
    else if(s0!=0){
        for(int i=0;i<sl;i++) z=z*10+x[i];
        // cout<<'!'<<z<<'!';
        z=(z-x[0]*(pow(10,sl-1))+x[0]*(pow(10,sl-1+s0)));
        
    }
    else for(int i=0;i<sl;i++) z=z*10+x[i];
    return z;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,num=0,q3=0,q2=0;
        cin>>n;
        if(n==1 || n==0) cout<<-1<<endl;
        else if(n%7==0){
            for(int i=0;i<n;i=i+7) cout<<8;
            cout<<endl;
        }
        else if(n==6){
            cout<<6;
        }
        else{
            for(int i=8;i<=n;i++){
                for(int x=2,y=i-1;x<=y;x++,y--){
                    if(x>2)sz[i]=min(sz[i],ws(sz[x],sz[y]));
                    else sz[i]=ws(sz[x],sz[y]);
                    // cout<<"!"<<ws(sz[x],sz[y])<<"!";
                }
            }
            cout<<sz[n]<<endl;
            
        }
    }
    return 0;
}