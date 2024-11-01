#include <bits/stdc++.h>
using namespace std;
const long long N=105;
long long n,as[N],ad[N],ac[N],ah[N],ass,add,acc,ahh,cnt=52,flags=1,flagd=1,flagc=1,flagh=1;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='S'){
            ass++;
            for(int i=1;i<=ass;i++){
                if(as[i]==s[1]){
                    flags=0;
                }
            }
            if(flags==1){
                as[ass]+=s[1];
            }
            else{
                ass--;
            }
            flags=1;
        }
        else if(s[0]=='D'){
            add++;
            for(int i=1;i<=add;i++){
                if(ad[i]==s[1]){
                    flagd=0;
                }
            }
            if(flagd==1){
                ad[add]+=s[1];
            }
            else{
                add--;
            }
            flagd=1;
        }
        else if(s[0]=='C'){
            acc++;
            for(int i=1;i<=acc;i++){
                if(ac[i]==s[1]){
                    flagc=0;
                }
            }
            if(flagc==1){
                ac[acc]+=s[1];
            }
            else{
                acc--;
            }
            flagc=1;
        }
        else if(s[0]=='H'){
            ahh++;
            for(int i=1;i<=ahh;i++){
                if(ah[i]==s[1]){
                    flagh=0;
                }
            }
            if(flagh==1){
                ah[ahh]+=s[1];
            }
            else{
                ahh--;
            }
            flagh=1;
        }
    }
    cout<<cnt-ass-add-acc-ahh;
    return 0;
}
