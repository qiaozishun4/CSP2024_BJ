#include <bits/stdc++.h>
using namespace std ;
int a[]={6,2,5,5,4,5,6,3,7,6} ;
int dp[100000010] ;
int main(){
    freopen("sticks.in","r",stdin) ;
    freopen("sticks.out","w",stdout) ;
    int n ;
    cin >> n ;
    while (n--){
        memset(dp,0,sizeof(dp)) ;
        int x,q=0 ;
        cin >> x ;
        for (int i=1 ; i<=100000000 ; i++){
            string s=to_string(i) ;
            for (int j=0 ; j<s.size() ; j++){
                dp[i]+=a[s[j]-'0'] ;
            }
            if (dp[i]==x){
                cout << i <<endl ;
                q=1 ;
                break ;
            }
        }
        if (!q){
            cout << -1 << endl ;
        }
    }
    return 0 ;
}
