#include <bits/stdc++.h>
using namespace std;
int a[53];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int temp = 0;
    int h = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='D'){
            temp = 0;
        }
        if(s[0]=='C'){
            temp = 13;
        }
        if(s[0]=='H'){
            temp = 26;
        }
        if(s[0]=='S'){
            temp = 39;
        }
        if(s[1]=='A'){
            h = 1;
        }
        else if(s[1]=='T'){
            h = 10;
        }
        else if(s[1]=='J'){
            h = 11;
        }
        else if(s[1]=='Q'){
            h = 12;
        }
        else if(s[1]=='K'){
            h = 13;
        }
        else{
            h = (s[1]-'0');
        }
        a[temp+h] = 1;
    }
    for(int i=1;i<=52;i++){
        if(a[i] == 1){
            ans++;
        }
    }
    cout<<(52-ans);
    return 0;
}