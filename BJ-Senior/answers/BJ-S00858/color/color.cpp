#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int t, n, a[1000010], ans;
int solvea_rs[1000010];

void dfssolvea(int step){
    if(step == n+1){
        //for(int i=1; i<=n; i++) cout<<solvea_rs[i]<<'  ';
        //cout<<endl;

        int tans = 0;
        for(int i=1; i<=n; i++){
            int prev = -1;
            for(int j=i-1; j>0; j--) if(solvea_rs[i] == solvea_rs[j]){
                prev = j;
                break;
            }
            if(prev!=-1 && a[i] == a[prev]) tans+=a[i];
        }
        ans = max(ans, tans);
        return ;
    }
    solvea_rs[step] = 0;
    dfssolvea(step+1);
    solvea_rs[step] = 1;
    dfssolvea(step+1);
}

void solvea(){
    dfssolvea(1);
    cout<<ans<<endl;
}

int main(){

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i];
        if(n<=20) solvea();
        else{
            for(int i=1; i<=n; i++){
                ans+=a[i];
            }
            cout<<ans<<endl;
        }
    }


    return 0;
}
