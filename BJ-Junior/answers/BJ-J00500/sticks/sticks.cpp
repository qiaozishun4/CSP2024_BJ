#include<iostream>
#include<cstdio>
using namespace std;
long long su[10]={6,2,5,99999,4,99999,6,3,7,99999},T,n,mi;
void pl(long long d,long long nu){
    if(n==0&&nu<mi){
        mi=nu;
        return;
    }else{
        if(d==0){
            for(int i=1;i<9;i++){
                if(su[i]<=n){
                    n=n-su[i];
                    pl(d+1,nu*10+i);
                    n=n+su[i];
                }
            }
        }else{
            for(int i=0;i<9;i++){
                if(su[i]<=n){
                    n=n-su[i];
                    pl(d+1,nu*10+i);
                    n=n+su[i];
                }
            }
        }
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        mi=9999999;
        pl(0,0);
        if(mi==9999999) mi=-1;
        cout<<mi<<endl;
    }
    return 0;
}
