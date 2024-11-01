#include <bits/stdc++.h>
using namespace std;

int T,n,ans[3000],cnt,anslen,firs,c[10] = {6,2,5,5,4,5,6,3,7,6},mi,fang[20];

int ci(int k){
    if(fang[k]){
        return fang[k];
    }
    int an = 1;
    while(k){
        an *= 10;
        k--;
    }
    fang[k] = an;
    return an;
}

void dfs(int k){
    if(k == 1){
        return;
    }
    if(k == 0){
        int s = 0;
        for(int i = anslen;i >= firs + 1;i--){
            s *= 10;
            s += ans[i];
        }
        if(s < mi){
            mi = s;
        }

        return;
    }
    if(k <= 7){
        if(k == 2){
            ans[++anslen] = 1;
        }
        if(k == 3){
            ans[++anslen] = 7;
        }
        if(k == 4){
            ans[++anslen] = 4;
        }
        if(k == 5){
            ans[++anslen] = 2;
        }
        if(k == 6){
            ans[++anslen] = 6;
        }
        if(k == 7){
            ans[++anslen] = 8;
        }
        dfs(0);
        anslen--;
        return;
    }
    if(ci(anslen - firs) > mi){
        return;
   }
    for(int i = 9;i >= 0;i--){
 //       if(anslen == firs && i == 0){
 //           continue;
 //       }
        if(i == 3 || i == 5 || i == 9 || i == 6){
            continue;
        }
        ans[++anslen] = i;
        dfs(k - c[i]);
        anslen--;
    }
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> T;

    while(T--){
        memset(ans,0,sizeof(ans));
        cin >> n;
        if(n == 1){
            cout << -1 << endl;
            continue;
        }
        cnt = n;
        anslen = 0;
        firs = 0;
        while(cnt > 30){
            ans[++anslen] = 8;
            cnt -= 7;
        }
        firs = anslen;
        mi = INT_MAX;
        dfs(cnt);
        cout << mi;
        for(int i = firs;i >= 1;i--){
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
