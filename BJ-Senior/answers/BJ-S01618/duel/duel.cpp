#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int dp[MAXN],a[MAXN];
int n,hmi = 100900,xiab = -1,xbiao = -1,hma = -1;
bool flg[MAXN],fag [MAXN];
int MINn = 100900;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    cin >> n;
    dp[1] = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        a[i] = -1;
        flg[i] = true;
        fag[i] = true;
        MINn = min(MINn,a[i]);
    }
    for(int i = 2;i <= n;i++){


            for(int j = 1;j < i;j++){
                if(a[j] > a[i] && flg[j] == true){
                    if(a[j] < hmi){
                        hmi = a[j];
                        xiab = j;
                    }
                }
                if(a[j] < a[i] && fag[j] == true && flg[j] ==false && a[j] != MINn){
                    if(a[j] > hma){
                        hma = a[j];
                        xbiao = j;
                    }
                }

            }
            if(flg[xiab] == true && a[xiab] > a[i]){
				flg[xiab] = false;
				fag[i] = false;
			}
			else{
				if(xbiao != -1) {
					fag[xbiao] = false;
					flg[i] = false;
				}
			}
            
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(fag[i] == true) cnt++;
    }
    cout << cnt;
    return 0;
}
