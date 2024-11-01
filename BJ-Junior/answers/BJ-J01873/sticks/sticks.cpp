#include <bits/stdc++.h>
using namespace std;
int d[10];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;if(n==1){cout<<-1<<endl;continue;}
        int di=n/7+1;memset(d,0,sizeof(d));
        if(di!=1){d[8]=di-2;n-=(7*(di-2));}
        if(n==12&&di==2){d[2]++;d[8]++;}
        else if(n==6&&di==1)d[6]++;
        else if(n==1){
            d[8]--;n+=7;
        }else {
            switch(n){
                case 2:d[1]++;break;
                case 3:d[7]++;break;
                case 4:d[4]++;break;
                case 5:d[2]++;break;
                case 6:d[0]++;break;
                case 7:d[8]++;break;
                case 8:d[1]++,d[0]++;break;
                case 9:d[1]++,d[8]++;break;
                case 10:d[2]+=2;break;
                case 11:d[2]++,d[0]++;break;
                case 12:d[0]+=2;break;
                case 13:d[8]++,d[0]++;break;
                case 14:d[8]+=2;break;
            }
        }int not0;
        for(int i=1;i<=9;i++)if(d[i]){not0=i;d[i]--;break;}
        cout<<not0;
        for(int i=0;i<=9;i++){
            for(int j=0;j<d[i];j++)cout<<i;
        }cout<<endl;
    }
}
