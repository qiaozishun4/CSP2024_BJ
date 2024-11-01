#include<bits/stdc++.h>
using namespace std;
const int stk[10]={6,2,5,5,4,5,6,3,7,6};
int T,n;
void dfs(int k){
    if(k==0) return;
    else if(k<=7)
        for(int i=0;i<=9;i++){
            if(stk[i]==k){
                cout<<i;
                return ;
            }
        }
    else for(int i=0;i<=9;i++) if(ceil((k-stk[i])/7.0)==ceil((k-7)/7.0)&&k-stk[i]!=1){
        cout<<i;
        k-=stk[i];
        break;
    }
    dfs(k);
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }
        else if(n<=7) for(int j=1;j<=9;j++){
            if(stk[j]==n){
                cout<<j<<endl;
                break;
            }
        }
        else for(int j=1;j<=9;j++) if(ceil((n-stk[j])/7.0)==ceil((n-7)/7.0)&&n-stk[j]!=1){
            cout<<j;
            n-=stk[j];
            dfs(n);
            break;
        }
        cout<<endl;
    }
    return 0;
}