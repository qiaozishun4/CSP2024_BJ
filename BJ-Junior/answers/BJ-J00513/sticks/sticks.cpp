#include<bits/stdc++.h>
using namespace std;
int a[12]={0,0,1,2,4,7,8};
int s[12]={0,6,2,5,4,3,7};
int n,t,ans,sum,minans;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        while(1){
            if(n==1){
                cout << -1 << endl;
                break;
            }
            for(int i=1;i<=6;i++){
                ans=ans*10+a[n%7];
                sum+=s[n%7];
                if(ans<minans) minans=ans;
            }
            if(sum==n){
                cout << minans;
                break;
            }
            if(sum>n){
                cout << -1 << endl;
                break;
            }
        }
    }
    return 0;
}
