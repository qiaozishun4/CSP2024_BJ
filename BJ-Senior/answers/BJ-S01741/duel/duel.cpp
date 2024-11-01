#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[100005],ans;
    cin>> n;
    ans = n;
    for(int i=1;i<=n;i++){
        cin>> a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    while(r <= n){
        if(a[r] == a[l]) r++;
        else{
            l++;
            r++;
            ans--;
        }
    }
    cout<< ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
