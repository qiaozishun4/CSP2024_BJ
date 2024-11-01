#include<bits/stdc++.h>
using namespace std;

int cost[15]={6,2,5,5,4,5,6,3,7,6};
int order[15]={8,0,6,9,2,3,5,4,7,1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        bool flag=0;
        //
        if(n<3){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<10;i++){
            if(n==cost[order[i]]){
                    if(i-1==0)i=7;
                cout<<i-1<<endl;
                flag=1;
                break;
            }
        }
        if(n%7==0 && flag==0){
            for(int i=0;i<(n/7);i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        for(int i=1;i<=10;i++){
                if(flag)break;
            for(int j=0;j<=10;j++){
                if(flag)break;
                for(int k=0;k<=10;k++){
                    if(flag)break;
                    if(cost[order[i]]+cost[order[j]]==n){
                        cout<<order[i]<<order[j]<<endl;
                        flag=1;
                    }if(cost[order[i]]+cost[order[j]]+cost[order[k]]==n){
                        cout<<i<<j<<k<<endl;
                        flag=1;
                    }
                }
            }
        }
    }
    return 0;
}
