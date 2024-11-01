#include<bits/stdc++.h>
using namespace std;
string dp[10005];
string a[7] = {"1","7","4","2","0","8"};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    //memset(dp,"",sizeof(dp));
    dp[1] = "-1",dp[2] = "1",dp[3] = "7",dp[4] = "4",dp[5] = "2",dp[6] = "6",dp[7] = "8";
    for(int i = 8;i <= 10001;i++){
        for(int j = i - 7;j <= i - 2;j++){
            if(j == 1)continue;
            string s = dp[j] + a[i-j-2];
            //cout << i << " " << " " << dp[i] << " " << j << " " << s << endl;
            if(dp[i] == "")dp[i] = s;
            else if(dp[i] > s and dp[i].length() >= s.length())dp[i] = s;
        }
        //cout << dp[i] << endl;
    }
    //if("123123123" > "9999999999")cout << "yes\n";
    //for(int i = 1;i <= 10000;i++)cout << i << " " << dp[i] << endl;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}