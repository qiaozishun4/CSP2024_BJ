#include<bits/stdc++.h>
using namespace std;
int n,bk[100010][2],a[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int cnt = 1;
    bk[1][0]++;
    for(int i = 2;i <= n;i++){
        if(a[i] != a[i - 1]){
            bk[++cnt][0]++;
        }
        else{
            bk[cnt][0]++;
        }
    }
    /*for(int i = 1;i <= cnt;i++){
        cout << bk[i][0] << " ";
    }
    cout << endl;*/
    long long sum,sum1 = 0,sum2 = 0;
    for(int i = 1;i <= cnt;i++){
        if(sum1 + sum2 <= bk[i][0]){
            int tmp = bk[i][0];
            bk[i][0] -= sum1;
            bk[i][0] -= sum2;
            sum1 = 0;
            sum2 = 0;
            bk[i][1] = tmp - bk[i][0];
            sum1 += bk[i][0];
            sum2 += bk[i][1];
        }
        else if(bk[i][0] >= sum1){
            int tmp = bk[i][0];
            bk[i][0] = 0;
            sum2 = sum2 - tmp + sum1;
            sum1 = 0;
            bk[i][1] = tmp;
            sum2 += bk[i][1];
        }
        else{
            int tmp = bk[i][0];
            bk[i][0] = 0;
            sum1 -= tmp;
            bk[i][1] = tmp;
            sum2 += bk[i][1];
        }
    }
    /*for(int i = 1;i <= cnt;i++){
        cout << bk[i][0] << " ";
    }
    cout << endl;
    for(int i = 1;i <= cnt;i++){
        cout << bk[i][1] << " ";
    }
    cout << endl;*/
    sum = sum1 + sum2;
    cout << sum << endl;
    return 0;
}
