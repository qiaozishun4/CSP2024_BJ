#include <bits/stdc++.h>
using namespace std;
long long n,p[60],sum,ans;
string a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<a[i][0]<<" "<<a[i][1];
        if(a[i][0]=='D'){
            if(a[i][1]=='A')p[1]++;
            if(a[i][1]=='2')p[2]++;
            if(a[i][1]=='3')p[3]++;
            if(a[i][1]=='4')p[4]++;
            if(a[i][1]=='5')p[5]++;
            if(a[i][1]=='6')p[6]++;
            if(a[i][1]=='7')p[7]++;
            if(a[i][1]=='8')p[8]++;
            if(a[i][1]=='9')p[9]++;
            if(a[i][1]=='T')p[10]++;
            if(a[i][1]=='J')p[11]++;
            if(a[i][1]=='Q')p[12]++;
            if(a[i][1]=='K')p[13]++;
        }else if(a[i][0]=='C'){
            if(a[i][1]=='A')p[14]++;
            if(a[i][1]=='2')p[15]++;
            if(a[i][1]=='3')p[16]++;
            if(a[i][1]=='4')p[17]++;
            if(a[i][1]=='5')p[18]++;
            if(a[i][1]=='6')p[19]++;
            if(a[i][1]=='7')p[20]++;
            if(a[i][1]=='8')p[21]++;
            if(a[i][1]=='9')p[22]++;
            if(a[i][1]=='T')p[23]++;
            if(a[i][1]=='J')p[24]++;
            if(a[i][1]=='Q')p[25]++;
            if(a[i][1]=='K')p[26]++;
        }else if(a[i][0]=='H'){
            if(a[i][1]=='A')p[27]++;
            if(a[i][1]=='2')p[28]++;
            if(a[i][1]=='3')p[29]++;
            if(a[i][1]=='4')p[30]++;
            if(a[i][1]=='5')p[31]++;
            if(a[i][1]=='6')p[32]++;
            if(a[i][1]=='7')p[33]++;
            if(a[i][1]=='8')p[34]++;
            if(a[i][1]=='9')p[35]++;
            if(a[i][1]=='T')p[36]++;
            if(a[i][1]=='J')p[37]++;
            if(a[i][1]=='Q')p[38]++;
            if(a[i][1]=='K')p[39]++;
        }else if(a[i][0]=='S'){
            if(a[i][1]=='A')p[40]++;
            if(a[i][1]=='2')p[41]++;
            if(a[i][1]=='3')p[42]++;
            if(a[i][1]=='4')p[43]++;
            if(a[i][1]=='5')p[44]++;
            if(a[i][1]=='6')p[45]++;
            if(a[i][1]=='7')p[46]++;
            if(a[i][1]=='8')p[47]++;
            if(a[i][1]=='9')p[48]++;
            if(a[i][1]=='T')p[49]++;
            if(a[i][1]=='J')p[50]++;
            if(a[i][1]=='Q')p[51]++;
            if(a[i][1]=='K')p[52]++;
        }
        //cout<<"p12"<<p[12]<<" "<<"p29"<<p[29]<<" "<<"p10"<<p[10]<<endl;

    }
    for(int i=1;i<=52;i++){
        if(p[i]!=0){
            sum++;
            //cout<<i<<" ";
        }
    }
    ans=52-sum;
    cout<<ans<<endl;
    return 0;
}