#include<bits/stdc++.h>
using namespace std;
int n;
char co,oc;
char d[52],c[52],h[52],s[52];
int ans=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>co;
        if(co=='D'){
            cin>>oc;
            if(oc=='A'){
                d[1]++;
            }else if(oc=='T'){
                d[10]++;
            }else if(oc=='J'){
                d[11]++;
            }else if(oc=='Q'){
                d[12]++;
            }else if(oc=='K'){
                d[13]++;
            }else{
                d[oc-'0']++;
            }
        }else if(co=='C'){
            cin>>oc;
            if(oc=='A'){
                c[1]++;
            }else if(oc=='T'){
                c[10]++;
            }else if(oc=='J'){
                c[11]++;
            }else if(oc=='Q'){
                c[12]++;
            }else if(oc=='K'){
                c[13]++;
            }else{
                c[oc-'0']++;
            }
        }else if(co=='H'){
            cin>>oc;
            if(oc=='A'){
                h[1]++;
            }else if(oc=='T'){
                h[10]++;
            }else if(oc=='J'){
                h[11]++;
            }else if(oc=='Q'){
                h[12]++;
            }else if(oc=='K'){
                h[13]++;
            }else{
                h[oc-'0']++;
            }
        }else if(co=='S'){
            cin>>oc;
            if(oc=='A'){
                s[1]++;
            }else if(oc=='T'){
                s[10]++;
            }else if(oc=='J'){
                s[11]++;
            }else if(oc=='Q'){
                s[12]++;
            }else if(oc=='K'){
                s[13]++;
            }else{
                s[oc-'0']++;
            }
        }
    }
    for(int i=1;i<=13;i++){
        if(d[i]==0){
            ans++;
        }if(c[i]==0){
            ans++;
        }if(h[i]==0){
            ans++;
        }if(s[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
