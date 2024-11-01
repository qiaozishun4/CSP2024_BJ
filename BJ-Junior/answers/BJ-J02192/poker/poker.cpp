#include<bits/stdc++.h>
using namespace std;
char a[150];
string t;
long long n,flag;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        t="";
        cin>>t;
        for(int j=0;j<flag;j+=2){
            if(a[j]==t[0]&&a[j+1]==t[1])  {
                a[flag]=0;
                a[flag+1]=0;
                flag-=2;
                break;
            }
            a[flag]=t[0];
            a[flag+1]=t[1];
        }
        if(i==0){
            a[flag]=t[0];
            a[flag+1]=t[1];
        }
        flag+=2;
    }
    cout<<52-flag/2;
    return 0;
}
