#include<bits/stdc++.h>
using namespace std;
char a[110],b[110];
bool flag=true;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        for(int j=i;j>=0;j--){
            if(a[i]!=a[i-j]||b[i]!=b[i-j]){
                ans++;
                break;
            }
        }
        if(i!=0){
            if(a[i]==a[0]&&b[i]==b[0]){
                ans--;
                flag=false;
            }
        }
    }
    if(flag==true&&n!=0) ans++;
    cout<<52-ans<<endl;
    return 0;
}
