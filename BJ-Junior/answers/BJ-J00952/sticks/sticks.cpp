#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int n,x,a[15],ans[N],cnt;
void solve(int now){
        if(now==1){++cnt;ans[cnt]=-1;}
        if(now==2){++cnt;ans[cnt]=1;}
        if(now==3){++cnt;ans[cnt]=7;}
        if(now==4){++cnt;ans[cnt]=4;}
        if(now==5){++cnt;ans[cnt]=2;}
        if(now==6){if(cnt==0){++cnt;ans[cnt]=6;}else{++cnt;ans[cnt]=0;}}
        if(now==7){++cnt;ans[cnt]=8;}
        if(now==8){++cnt;ans[cnt]=0;++cnt;ans[cnt]=1;}
        if(now==9){++cnt;ans[cnt]=8;++cnt;ans[cnt]=1;}
        if(now==10){++cnt;ans[cnt]=3;++cnt;ans[cnt]=2;}
        if(now==11){++cnt;ans[cnt]=0;++cnt;ans[cnt]=2;}
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a[1]=-1;a[2]=1;a[3]=7;a[4]=4;a[5]=2;a[6]=6;a[7]=8;
    a[8]=10;a[9]=18;a[10]=23;a[11]=20;
    while(n--){
        cnt=0;
        memset(ans,0,sizeof(0));
        cin>>x;
        while(x>=12){
            x-=7;
            ++cnt;
            ans[cnt]=8;
        }
        solve(x);
        //cout<<x<<" "<<cnt<<'\n';
        for(int i=cnt;i>=1;i--)cout<<ans[i];
        cout<<'\n';
    }
    return 0;
}
