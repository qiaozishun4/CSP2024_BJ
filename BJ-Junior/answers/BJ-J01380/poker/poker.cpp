#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    string a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt++;
        for(int j=1;j<i;j++){
            if(a[i] == a[j] && cnt > 2){
                cnt--;
            }
        }
    }
    if(cnt == 0){
        cnt = 1;
    }
    int res = 52-cnt;
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}