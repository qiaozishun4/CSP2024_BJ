#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long n;
    cin>>n;
    long p=n;
    string s;
    for(int i=0;i<n*2;i++)cin>>s[i];
    int i=0,j=i+2;
    for(i=0;i<n*2-1;i+=2){
        for(int j=i+2;j<n*2-1;j+=2){
            if(s[i]==s[j]&&s[i+1]==s[j+1]){
                p--;
                break;
            }
        }
    }
    cout<<52-p;
    return 0;
}
