#include <bits/stdc++.h>
using namespace std;
int n;
map<string,int>aa;
string a[20]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
string b[10]={"D","C","H","S"};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        aa[s]=1;
    }
    int ans=0;
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            if(aa[b[j]+a[i]]==0){
                ans++;
            }

        }
    }
    cout<<ans<<endl;

    return 0;
}
