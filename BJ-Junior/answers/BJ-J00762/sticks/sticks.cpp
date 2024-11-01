#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int T,n;
unsigned long long cnt;
int table[8]={-1,-1,1,7,4,2,0,8};

void dfs(long long num,unsigned long long ans,bool zero, long long last){

    if(num==0){
        cnt=min(cnt,ans);
        return ;
    }

    for(int i=last;i<=7;i++){
        if(num-i>=0){
            if(zero&&i==6){
                dfs(num-i,ans*10+6,false,i);
            }
            else dfs(num-i,ans*10+table[i],false,i);
        }
    }
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n>=60){
            int k=n/7;
            for(int i=0;i<k-1;i++){
                cout<<8;
            }
            if(n%7==1) cout<<10;

            else cout<<8;

            cout<<endl;
        }

        else{
            if(n==1||n==0){

            cout<<-1<<endl;
            continue;
            }
        cnt=INT_MAX;
        dfs(n,0,true,2);
        cout<<cnt<<endl;
        }
    }


    return 0;
}
