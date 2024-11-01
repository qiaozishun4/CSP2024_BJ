#include<bits/stdc++.h>
using namespace std;
int s=0,n;
char bb[14]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
map<char,char>d,c,h,s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a[0]=='D'){
            d[a[1]]='1';
        }else if(a[0]=='C'){
            c[a[1]]='1';
        }else if(a[0]=='H'){
            h[a[1]]='1';
        }else{
            s[a[1]]='1';
        }
    }
    for(int i=0;i<13;i++){
        if(d[bb[i]]=='1'){
            s++;
        }
        if(c[bb[i]]=='1'){
            s++;
        }
        if(h[bb[i]]=='1'){
            s++;
        }
        if(s[bb[i]]=='1'){
            s++;
        }
    }
    cout>>52-s;
    return 0;
}
