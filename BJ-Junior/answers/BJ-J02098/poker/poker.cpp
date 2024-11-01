#include <bits/stdc++.h>
using namespace std;
int n;
bool st[60];
string a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st[i] = false;
    }
    int ans=52;
    for(int i=1;i<=n;i++){
        if(st[i] == false){
            for(int j=i+1;j<=n;j++){
                if(a[j] != a[i] && st[j] == false){
                    ans--;
                    st[j] = true;
                }
                else
                    continue;
            }

        }
    }

    cout<<ans-1<<endl;
    return 0;
}
