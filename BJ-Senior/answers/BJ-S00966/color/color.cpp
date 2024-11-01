#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,v,b[20],a[20],Ans1;
void work1(){
    int f1=0,f0=0;
    for(int i=1;i<=min(n,v+2);i++){
        if(b[i]==1){
            if(f1==0){
                f1=i;
            }
            else{
                if(a[f1]==a[i]){
                    Ans1+=a[i];
                }
                f1=i;
            }
        }
        else{
            if(f0==0){
                f0=i;
            }
            else{
                if(a[f0]==a[i]){
                    Ans1+=a[i];
                }
                f0=i;
            }
        }
    }
}
void work(int x){
    memset(b,0,sizeof(b));
    v=0;
    while(x>0){
        b[++v]=x%2;
        x/=2;
    }
    work1();
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
            Ans1=0;
    int Max1=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int t=1;
        for(int i=1;i<=n;i++){
            t*=2;
        }
        for(int i=0;i<=t/2;i++){
                Ans1=0;
            work(i);
            Max1=max(Max1,Ans1);
        }
        cout<<Max1<<endl;
    }
    return 0;
}
