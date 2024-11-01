#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100005], s[100005], top, cnt, s2[100005], top2, s3[100005], top3;
bool f[100005];

bool cmp(int x, int y){
    return x > y;
}

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    cnt = n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1, cmp);
    for(int i=1; i<=n; i++){
        if(top && a[s[top]]>a[i] && f[s[top]] == 0){
            f[s[top]] = 1;
            s2[++top2] = i;
            top--;
            cnt--;
        }
        else{
            s[++top] = i;
        }
    }
    for(int i=1; i<=top2; i++){
        if(top3 && a[s3[top3]]>a[s2[i]] && f[s3[top3]] == 0){
            f[s3[top3]] = 1;
            cnt--;
        }
        else{
            s3[++top3] = s2[i];
        }
    }
    cout << cnt;
    return 0;
}
