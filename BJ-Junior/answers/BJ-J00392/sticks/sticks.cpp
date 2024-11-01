#include<bits/stdc++.h>
using namespace std;

int T,n;
int need[10]={6,2,5,5,4,5,6,3,7,6};
long long ans[1000006];

void chu(){
    for(int tmp=1;tmp<=1000000;tmp++){
        int tmpi=tmp,cnt=0;
        while(tmpi!=0){
            cnt+=need[tmpi%10];
            tmpi/=10;
        }
        if(!ans[cnt])
            ans[cnt]=tmp;
    }
}

int main(){
    chu();
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        if(ans[n]){
            cout << ans[n] << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
    return 0;
}

