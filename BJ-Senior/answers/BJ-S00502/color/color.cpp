#include<bits/stdc++.h>
using namespace std;
struct asd{
    int d;
    bool s=false;
};
int n,x=1;
asd r[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>r[i].d;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
            if((r[i].s==false||r[i+1].s==false)&&r[i+1].d-r[i].d==1){
                r[i].s=true;
                r[i+1].s=true;
            }
        }
    }
    for(int i=0;i<x;i++) cout<<r[i]<<" ";
    return 0;
}
