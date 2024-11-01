#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int f(int p){
    int ps[7]={6,2,5,4,6,3,7},pss[7]={0,1,2,4,6,7,8};
    if(p==1)    q=1;
    else    q=0;
    for(;q<=6;q++){
        if(n-ps[q]<=(k-p)*7&&n-ps[q]>=(k-p)*2){
            n-=ps[q];
            return pss[q];
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<2) {cout<<-1<<endl;continue;}
        k=(n-1)/7+1;
        for(int i=1;i<=k;i++){
            cout<<f(i);
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}