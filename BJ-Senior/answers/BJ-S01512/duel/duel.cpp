#include<bits/stdc++.h>
#define ll long long


using namespace std;

int n;
int a[100010];
int k;
int ans;

int main(){

    scanf("%d", &n);
    ans = n;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for(int i=0;i<n;i++){
        int w = upper_bound(a, a + n, a[i]) - a;
        if(w <= k){
            w ++;
            k ++;
        }else k = w;
        if(w >= n || k >= n)break;
        ans--;
    }
    printf("%d",ans);

    return 0;
}
