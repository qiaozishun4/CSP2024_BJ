#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
struct poker{
    char fr,sc;
}a[N];
int d[N],c[N],h[N],s[N];
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i].fr>>a[i].sc;
    if(a[i].fr=='D'){
        if(a[i].sc=='A')d[1]++;
        if(a[i].sc=='T')d[10]++;
        else if(a[i].sc=='J')d[11]++;
        else if(a[i].sc=='Q')d[12]++;
        else if(a[i].sc=='K')d[13]++;
        else if(a[i].sc=='2')d[2]++;
        else if(a[i].sc=='3')d[3]++;
        else if(a[i].sc=='4')d[4]++;
        else if(a[i].sc=='5')d[5]++;
        else if(a[i].sc=='6')d[6]++;
        else if(a[i].sc=='7')d[7]++;
        else if(a[i].sc=='8')d[8]++;
        else if(a[i].sc=='9')d[9]++;
    }if(a[i].fr=='C'){
        if(a[i].sc=='A')c[1]++;
        if(a[i].sc=='T')c[10]++;
        else if(a[i].sc=='J')c[11]++;
        else if(a[i].sc=='Q')c[12]++;
        else if(a[i].sc=='K')c[13]++;
        else if(a[i].sc=='2')c[2]++;
        else if(a[i].sc=='3')c[3]++;
        else if(a[i].sc=='4')c[4]++;
        else if(a[i].sc=='5')c[5]++;
        else if(a[i].sc=='6')c[6]++;
        else if(a[i].sc=='7')c[7]++;
        else if(a[i].sc=='8')c[8]++;
        else if(a[i].sc=='9')c[9]++;
    }if(a[i].fr=='H'){

        if(a[i].sc=='A')h[1]++;
        if(a[i].sc=='T')h[10]++;
        else if(a[i].sc=='J')h[11]++;
        else if(a[i].sc=='Q')h[12]++;
        else if(a[i].sc=='K')h[13]++;
        else if(a[i].sc=='2')h[2]++;
        else if(a[i].sc=='3')h[3]++;
        else if(a[i].sc=='4')h[4]++;
        else if(a[i].sc=='5')h[5]++;
        else if(a[i].sc=='6')h[6]++;
        else if(a[i].sc=='7')h[7]++;
        else if(a[i].sc=='8')h[8]++;
        else if(a[i].sc=='9')h[9]++;
    }if(a[i].fr=='S'){
        if(a[i].sc=='A')s[1]++;
        else if(a[i].sc=='T')s[10]++;
        else if(a[i].sc=='J')s[11]++;
        else if(a[i].sc=='Q')s[12]++;
        else if(a[i].sc=='K')s[13]++;
        else if(a[i].sc=='2')s[2]++;
        else if(a[i].sc=='3')s[3]++;
        else if(a[i].sc=='4')s[4]++;
        else if(a[i].sc=='5')s[5]++;
        else if(a[i].sc=='6')s[6]++;
        else if(a[i].sc=='7')s[7]++;
        else if(a[i].sc=='8')s[8]++;
        else if(a[i].sc=='9')s[9]++;
    }
}
int ans=0;
for(int i=1;i<=13;i++){
        if(d[i])ans++;
        if(c[i])ans++;
        if(h[i])ans++;
        if(s[i])ans++;
}
ans=max(52-ans,0);
cout<<ans;
return 0;
}

