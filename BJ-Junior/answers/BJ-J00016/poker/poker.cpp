#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string s[60];
    int n,h=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j])  h++;
        }
    }
    cout<<52-n+h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
