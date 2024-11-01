#include <bits/stdc++.h>
using namespace std;
int stk[10]={0,0,1,7,4,2,6,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int x=n/7,y=n%7;
        if (y==0){
            for (int i=1; i<=x; i++) cout<<"8";
        }else if (y==1){
            if (x==0) cout<<"-1";
            else{
                cout<<"10";
                for (int i=1; i<x; i++) cout<<"8";
            }
        }else{
            int num=y,mn=stk[y];
            for (int i=y+1; i<=min(y+x*5,7); i++){
                if (stk[i]<mn) mn=stk[i],num=i;
            }cout<<mn;
            int tmp=num-y;
            if (tmp<=x){
                for (int i=1; i<=tmp; i++) cout<<"0";
                for (int i=1; i<=x-tmp; i++) cout<<"8";
            }else{
                int k=tmp-x+1;
                for (int i=1; i<x; i++) cout<<"0";
                cout<<stk[7-k];
            }
        }cout<<"\n";
    }return 0;
}
