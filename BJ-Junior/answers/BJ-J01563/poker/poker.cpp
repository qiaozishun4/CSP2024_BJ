#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
string s[60];
bool b[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j]){
                b[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=1){
            sum++;
        }
    }
    cout<<52-sum<<endl;



    return 0;
}
