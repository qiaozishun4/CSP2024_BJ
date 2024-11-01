#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum=0;
string s,a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        a[i]=s[0];
        b[i]=s[1];

        for(int j=0;j<a.size();j++){
            if(a[i]==s[0]){
                    if(b[i]==s[1]){
                        sum=sum-1;
                    }
            }
        }
        sum++;
    }
    cout<<52-sum;
    return 0;
}
