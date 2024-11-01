#include <bits/stdc++.h>
using namespace std;
const int N=14;
int n;
int d[N],c[N],h[N],s[N];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c1,c2;
        cin>>c1>>c2;
        if(c1=='D'){
            if(c2=='A') d[1]++;
            else if(c2=='2') d[2]++;
            else if(c2=='3') d[3]++;
            else if(c2=='4') d[4]++;
            else if(c2=='5') d[5]++;
            else if(c2=='6') d[6]++;
            else if(c2=='7') d[7]++;
            else if(c2=='8') d[8]++;
            else if(c2=='9') d[9]++;
            else if(c2=='T') d[10]++;
            else if(c2=='J') d[11]++;
            else if(c2=='Q') d[12]++;
            else d[13]++;
        }
        if(c1=='C'){
            if(c2=='A') c[1]++;
            else if(c2=='2') c[2]++;
            else if(c2=='3') c[3]++;
            else if(c2=='4') c[4]++;
            else if(c2=='5') c[5]++;
            else if(c2=='6') c[6]++;
            else if(c2=='7') c[7]++;
            else if(c2=='8') c[8]++;
            else if(c2=='9') c[9]++;
            else if(c2=='T') c[10]++;
            else if(c2=='J') c[11]++;
            else if(c2=='Q') c[12]++;
            else c[13]++;
        }
        if(c1=='H'){
            if(c2=='A') h[1]++;
            else if(c2=='2') h[2]++;
            else if(c2=='3') h[3]++;
            else if(c2=='4') h[4]++;
            else if(c2=='5') h[5]++;
            else if(c2=='6') h[6]++;
            else if(c2=='7') h[7]++;
            else if(c2=='8') h[8]++;
            else if(c2=='9') h[9]++;
            else if(c2=='T') h[10]++;
            else if(c2=='J') h[11]++;
            else if(c2=='Q') h[12]++;
            else h[13]++;
        }
        if(c1=='S'){
            if(c2=='A') s[1]++;
            else if(c2=='2') s[2]++;
            else if(c2=='3') s[3]++;
            else if(c2=='4') s[4]++;
            else if(c2=='5') s[5]++;
            else if(c2=='6') s[6]++;
            else if(c2=='7') s[7]++;
            else if(c2=='8') s[8]++;
            else if(c2=='9') s[9]++;
            else if(c2=='T') s[10]++;
            else if(c2=='J') s[11]++;
            else if(c2=='Q') s[12]++;
            else d[13]++;
        }
    }
    int sum=0;
    for(int i=1;i<=13;i++){
        if(d[i]==0){
            sum++;
        }
        if(c[i]==0){
            sum++;
        }
        if(h[i]==0){
            sum++;
        }
        if(s[i]==0) sum++;
    }
    cout<<sum;
    return 0;
}