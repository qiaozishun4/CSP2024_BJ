#include <bits/stdc++.h>
using namespace std;
int t,n;
int ma;
int ab[12]={0,6,2,5,5,4,5,6,3,7,6};
void dfs(int nm,int cnt){

    int i;
    if(nm==n){
        i=2;
    }else{
        i=1;
    }

    for(;i<=10;i++){
        if(ab[i]==nm){
            cnt=cnt*10+i-1;
            ma=min(ma,cnt);
            cout<<i<<endl;
            return ;
        }
    }
    if(i==11){
        if(nm==n){
            i=2;
        }else{
            i=1;
        }
    }
    for(;i<=10;i++){
        if(ab[i]<nm){
            dfs(nm-ab[i],cnt*10+i-1);
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        ma=1e7;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==2){
            cout<<1<<endl;
            continue;
        }
        if(n==3){
            cout<<7<<endl;
            continue;
        }
        if(n==4){
            cout<<4<<endl;
            continue;
        }
        int t=n;
        dfs(t,0);
        if(ma==1e7){
            cout<<-1<<endl;
            continue;
        }
        cout<<ma<<endl;
    }
    return 0;
}