#include <bits/stdc++.h>
using namespace std;
const int maxn=55;
int n;
string a[maxn];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                ans++;
                break;
            }
        }
    }
    n-=ans;
    cout<<52-n<<endl;
    return 0;
}
