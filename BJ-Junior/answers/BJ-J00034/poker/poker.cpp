#include <iostream>
using namespace std;
string poker[1005];
int a[57];
int n,pai;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>poker[i];
        if(poker[i]=="DA"){
            a[1]++;
        }
        if(poker[i]=="D2"){
            a[2]++;
        }
        if(poker[i]=="D3"){
            a[3]++;
        }
        if(poker[i]=="D4"){
            a[4]++;
        }
        if(poker[i]=="D5"){
            a[5]++;
        }
        if(poker[i]=="D6"){
            a[6]++;
        }
        if(poker[i]=="D7"){
            a[7]++;
        }
        if(poker[i]=="D8"){
            a[8]++;
        }
        if(poker[i]=="D9"){
            a[9]++;
        }
        if(poker[i]=="D10"){
            a[10]++;
        }
        if(poker[i]=="DT"){
            a[11]++;
        }
        if(poker[i]=="DJ"){
            a[12]++;
        }
        if(poker[i]=="DQ"){
            a[13]++;
        }
        if(poker[i]=="DK"){
            a[14]++;
        }
        if(poker[i]=="CA"){
            a[15]++;
        }
        if(poker[i]=="C2"){
            a[16]++;
        }
        if(poker[i]=="C3"){
            a[17]++;
        }
        if(poker[i]=="C4"){
            a[18]++;
        }
        if(poker[i]=="C5"){
            a[19]++;
        }
        if(poker[i]=="C6"){
            a[20]++;
        }
        if(poker[i]=="C7"){
            a[21]++;
        }
        if(poker[i]=="C8"){
            a[22]++;
        }
        if(poker[i]=="C9"){
            a[23]++;
        }
        if(poker[i]=="C10"){
            a[24]++;
        }
        if(poker[i]=="CT"){
            a[25]++;
        }
        if(poker[i]=="CJ"){
            a[26]++;
        }
        if(poker[i]=="CQ"){
            a[27]++;
        }
        if(poker[i]=="CK"){
            a[28]++;
        }
        if(poker[i]=="HA"){
            a[29]++;
        }
        if(poker[i]=="H2"){
            a[30]++;
        }
        if(poker[i]=="H3"){
            a[31]++;
        }
        if(poker[i]=="H4"){
            a[32]++;
        }
        if(poker[i]=="H5"){
            a[33]++;
        }
        if(poker[i]=="H5"){
            a[34]++;
        }
        if(poker[i]=="H7"){
            a[35]++;
        }
        if(poker[i]=="H8"){
            a[36]++;
        }
        if(poker[i]=="H9"){
            a[37]++;
        }
        if(poker[i]=="H10"){
            a[38]++;
        }
        if(poker[i]=="HT"){
            a[39]++;
        }
        if(poker[i]=="HJ"){
            a[40]++;
        }
        if(poker[i]=="HQ"){
            a[41]++;
        }
        if(poker[i]=="HK"){
            a[42]++;
        }
        if(poker[i]=="SA"){
            a[43]++;
        }
        if(poker[i]=="S2"){
            a[44]++;
        }
        if(poker[i]=="S3"){
            a[45]++;
        }
        if(poker[i]=="S4"){
            a[46]++;
        }
        if(poker[i]=="S5"){
            a[47]++;
        }
        if(poker[i]=="S6"){
            a[48]++;
        }
        if(poker[i]=="S7"){
            a[49]++;
        }
        if(poker[i]=="S8"){
            a[50]++;
        }
        if(poker[i]=="S9"){
            a[51]++;
        }
        if(poker[i]=="S10"){
            a[52]++;
        }
        if(poker[i]=="ST"){
            a[53]++;
        }
        if(poker[i]=="SJ"){
            a[54]++;
        }
        if(poker[i]=="SQ"){
            a[55]++;
        }
        if(poker[i]=="SK"){
            a[56]++;
        }
    }
    for(int i=1;i<=56;i++){
        if(a[i]!=0){
            pai++;
        }
    }
    cout<<52-pai;
    return 0;
}