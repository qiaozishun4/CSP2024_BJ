#include<bits/stdc++.h>
using namespace std;
string s[100];
int n,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=1;j<i;j++){
            if(s[j]==s[i]){
                ans--;
                break;
            }
        }
        ans++;
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
