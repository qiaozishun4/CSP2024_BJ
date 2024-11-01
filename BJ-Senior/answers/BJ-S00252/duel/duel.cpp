#include <iostream>
#include <cstdio>
using namespace std;
int n,l[100005],flag=0,ans[100005]={},backx=0,minx,sdf;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        ans[l[i]]++;
    }
    sdf=n;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=100000;i++){
        if(ans[i]!=0){
            backx=ans[i];
            minx=i;
            if(backx==n){
                cout<<n;
                return 0;
            }
            break;
        }
    }
    for(int i=minx+1;i<=100000;i++){
        if(ans[i]!=0){
            if(ans[i]>=backx){
                sdf-=backx;
                backx=ans[i];
            }else{
                sdf-=ans[i];
            }
        }
    }
    cout<<sdf;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

