#include<bits/stdc++.h>
using namespace std;
int n,ans;
char str[100086];
char x[10];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        str+=x;
    }
    for(int i=0;i<str.size();i+=2){
        for(int j=i+1;j<=str.size();j+=2){
            if(str[i]==str[j]&&str[i+1]==str[j+1]){
                continue;
            }
            else{
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}