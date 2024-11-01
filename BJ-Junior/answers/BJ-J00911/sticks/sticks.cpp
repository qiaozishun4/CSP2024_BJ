#include<bits/stdc++.h>
using namespace std;
//RP++
int num[10]={6,2,5,5,4,5,6,3,7,6};
int number(int n){
    if(n<=1)return -1;

    for(int i=1;i<=10;i++)if(n==num[i])return i;

    for(int i=1;i<=10;i++)
        for(int j=0;j<=10;j++)if(n==num[i]+num[j])return i*10+j;

    for(int i=1;i<=10;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=10;k++)
                if(n==num[i]+num[j]+num[k])return i*100+j*10+k;

    for(int i=1;i<=10;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=10;k++)
                for(int o=0;o<=10;o++)
                    if(n==num[i]+num[j]+num[k]+num[o])return i*1000+j*100+k*10+o;
    
    for(int i=1;i<=10;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=10;k++)
                for(int o=0;o<=10;o++)
                    for(int y=0;y<=10;y++)
                        if(n==num[i]+num[j]+num[k]+num[o]+num[y])return i*10000+j*1000+k*100+o*10+y;

return -1;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        cout <<number(n)<<endl;
    }
    return 0;
}
