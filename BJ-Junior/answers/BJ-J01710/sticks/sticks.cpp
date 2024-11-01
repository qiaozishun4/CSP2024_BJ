#include<bits/stdc++.h>
using namespace std;

int t,n,ways=0;

int a[1003];

long long mn=1e18;

void dfs(int x,int step){
    if(x==0){
        long long temp=0,base=1;
        for(int i=step-1;i>0;i--){
            temp+=a[i]*base;
            base*=10;
        }
        mn=min(mn,temp);
        //cout<<mn<<endl;
        //cout<<"temp:"<<temp<<endl;
        return;
    }
    if(x<2) return;
    a[step]=1;
    dfs(x-2,step+1);
    a[step]=0;

    a[step]=7;
    dfs(x-3,step+1);
    a[step]=0;

    a[step]=4;
    dfs(x-4,step+1);
    a[step]=0;

    a[step]=2;
    dfs(x-5,step+1);
    a[step]=0;

    if(step==1){
        a[step]=6;
        dfs(x-6,step+1);
        a[step]=0;
    }
    else{
        a[step]=0;
        dfs(x-6,step+1);
        a[step]=0;
    }

    a[step]=8;
    dfs(x-7,step+1);
    a[step]=0;
}


int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int f=1;f<=t;f++){
        mn=1e18;
        cin>>n;
        //cout<<f<<":"<<endl;
        if(n%7==0){
            int te=n/7;
            for(int i=1;i<=te;i++) cout<<"8";
            cout<<endl;
            continue;
        }
        dfs(n,1);
        if(mn==1e18) mn=-1;
        cout<<mn<<endl;
    }
    return 0;
}
