#include<bits/stdc++.h>
using namespace std;

int n;
int a[120000];
int cnt[120000];
int ans;
const int inf = 1e9+7;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin >> n;
    int len = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        len = max(len,a[i]);
    }
    
    for(int i = 0; i <= len+1; i++){
		if(cnt[i] <= 0){
			cnt[i] = inf;
		}
	}

    ans = n;
    sort(cnt+1,cnt+len+1);

    for(int i = 1; i <= len; i++){
		if(cnt[i] == inf){
			break;
		}
		
		if(cnt[i+1] != inf){
			if(cnt[i+1] >= cnt[i]){
				ans -= cnt[i];
			}else{
				ans -= cnt[i+1];
			}
		}
    }

    cout << ans << endl;
    return 0;
}