#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3][200011][2];
bool buc[1000011];
int vton[1000011];
int ntov[1000011];
int T;
int n;
int a[200011];
int cnt;
void inline ori(){
    memset(buc,false,sizeof(buc));
    memset(vton,0,sizeof(vton));
    memset(ntov,0,sizeof(ntov));
    memset(dp,-1,sizeof(dp));
    cnt=0;
}
ll inline f(ll a,ll b){//a,b is all v
    if(a==b) return a;
    return 0;
}
void inline solve(){
    dp[1%2][0][0]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=cnt;j++){
            for(int k=0;k<=1;k++){
                if(dp[i%2][j][k]==-1) continue;

                //same color
                dp[(i+1)%2][j][k]=max(dp[(i+1)%2][j][k],dp[i%2][j][k]+f(a[i],a[i+1]));

                //diff color
                dp[(i+1)%2][vton[a[i]]][1-k]=max(dp[(i+1)%2][vton[a[i]]][1-k],dp[i%2][j][k]+f(a[i+1],ntov[j]));

            }
        }
    }

    ll ans=0;
    for(int j=0;j<=cnt;j++){
        for(int k=0;k<=1;k++){
            ans=max(ans,dp[n%2][j][k]);
            //cout << j << ' ' << k << ' ' << dp[n][j][k] << endl;
        }
    }
    cout << ans << endl;

    /*
    cout << endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=cnt;j++){
            for(int k=0;k<=1;k++){
                cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
            }
        }
    }
    */
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    cin >> T;
    for(int i=1;i<=T;i++){
        ori();
        cin >> n;
        for(int j=1;j<=n;j++){
            scanf("%d",&a[j]);
            buc[a[j]]=true;
        }
        for(int j=1;j<=1000000;j++){
            if(buc[j]){
                cnt++;
                vton[j]=cnt;
                ntov[cnt]=j;
            }
        }
        /*
        for(int q=1;q<=cnt;q++){
            cout << ntov[q] << ' ';
        }
        */
        solve();
    }
	return 0;
}
