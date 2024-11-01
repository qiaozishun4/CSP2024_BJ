#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string st;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>st;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //cout<<i<<" "<<j<<" ";
            if(st[i]==st[j]&&st[j+1]==st[i+1]){
                n--;
                //cout<<n<<endl;
                break;
            }
        }
    }
    cout<<52-n<<endl;
    return 0;
}
