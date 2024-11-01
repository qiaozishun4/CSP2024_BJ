#include<bits/stdc++.h>
using namespace std;
string a[60];
int n,cnt=51;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            if(a[j]==a[i]){
                cnt++;
                break;
            }
        }
        cnt--;
    }
    cout<<cnt;
}
