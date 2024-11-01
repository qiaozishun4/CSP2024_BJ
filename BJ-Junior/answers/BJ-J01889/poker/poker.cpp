#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,a[100];
    string s[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int q=n;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]){
                q-=1;
            }
        }
    }
    cout<<52-q;
    return 0;
}
