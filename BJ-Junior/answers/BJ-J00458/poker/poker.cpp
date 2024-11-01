#include<iostream>
using namespace std;
int n;
string a[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                cnt--;
            }
        }
    }
    int ans=52-cnt;
    cout<<ans;
    return 0;
}