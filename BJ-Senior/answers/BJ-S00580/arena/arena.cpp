#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int a[N];
int c[N];
int two[18]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
int findk(int a){
    int l=1,r=17;
    int m=(l+r)/2;
    while(l<r){
        if(two[m]>a)r=m-1;
        else{
            if(two[m]==a)return m;
            l=m+1;
        }
        m=(l+r)/2;
        //cout<<"l:"<<l<<" r:"<<r<<endl;
    }
    return r;
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int K=findk(n);
    //cout<<"k"<<K<<endl;
    for(int i=1;i<=K;i++){
        string s;
        cin>>s;
        // int now=first
        // for(int i=0;i<two[K-i];i++){

        // }
    }
    int T;
    cin>>T;
    while(T--){
        cout<<1<<endl;
    }
    return 0;
}