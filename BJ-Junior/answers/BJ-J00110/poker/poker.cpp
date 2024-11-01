#include<bits/stdc++.h>
using namespace std;
const long long N=100;
string s[N];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    cin>>n;
    long long d=n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(n==1){
        cout<<51;
        return 0;
    }
    for(int i=1;i<=1;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j]){
                d--;
            }
        }
    }

    long long b=52-d;
    cout<<b;




    return 0;
}
