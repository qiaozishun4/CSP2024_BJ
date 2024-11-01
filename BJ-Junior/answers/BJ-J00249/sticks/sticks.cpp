#include<bits/stdc++.h>
using namespace std;
int p[29]={6,2,5,5,4,5,6,3,7,6};
int t,n,aa[59];
int main(){
   freopen("sticks.in","r",stdin);
   freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
    cin>>aa[i];
    }
    for(int i=1;i<=t;i++){
    if(aa[i]%7==0){
    int dd=aa[i]/7;
    for(int j=1;j<=dd;j++){
    cout<<8;}cout<<endl;
    }
    else if(aa[i]==1){
    cout<<-1<<endl;
    }
    else if(aa[i]%7==1){
    cout<<10;
    int oo=(aa[i]-8)/7;
    for(int j=1;j<=oo;j++){
    cout<<8;}
cout<<endl;
    }
else{
    int yu=aa[i]%7;
    if(yu==2)cout<<1;
    if(yu==3)cout<<7;
    if(yu==4)cout<<4;
    if(yu==5)cout<<2;
    if(yu==6)cout<<6;
    int up=(aa[i]-yu)/7;


    for(int o=1;o<=up;o++){cout<<8;}
    cout<<endl;

}

    }
fclose(stdin);
   fclose(stdout);
    return 0;
}
