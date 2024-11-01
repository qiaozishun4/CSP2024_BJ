#include <iostream>
#include <algorithm>
using namespace std;
int a[80000],zero=0;
int j;
long long sum=0;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x<=20){
            if(x==1)
                cout<<-1;
            else if(x==2)
                cout<<1;
            else if(x==3)
                cout<<7;
            else if(x==4)
                cout<<4;
            else if(x==5)
                cout<<2;
            else if(x==6)
                cout<<6;
            else if(x==7)
                cout<<8;
            else if(x==8)
                cout<<10;
            else if (x==11)
                cout<<20;
            else if(x==10)
                cout<<22;
            else if(x==12)
                cout<<28;
            else if (x==13){
                cout<<80;
            }
            else if(x==14)
                cout<<88;
            else if(x==15){
                cout<<108;
            }
            else if(x==16)
                cout<<202;
            else if(x==17){
                cout<<200;
            }
            else if(x==18)
                cout<<208;
            else if(x==19)
                cout<<608;
            else if(x==20)
                cout<<808;
            else if(x==21)
                cout<<1008;
            else if(x==22)
                cout<<1808;
            else if(x==23)
                cout<<1008;
            else if(x==24)
                cout<<2008;
            else if(x==25)
                cout<<2808;
            else if(x==26)
                cout<<6808;
            else if(x==27)
                cout<<8808;
            else if(x==28)
                cout<<10808;
            else if(x==29)
                cout<<18808;
            else if(x==30)
                cout<<20008;
            else if(x==31)
                cout<<20808;
            else if(x==32)
                cout<<28808;
            else if(x==33)
                cout<<68808;
            else if(x==34)
                cout<<88808;
        }
        else{
            j=0;
            if(x%7>=2){
                j=x/7;
                x-=j*7;
            }
            for(int l=1;l<=j;l++){
                a[l]=8;
            }
            while(x>=8||x==6){
                x-=6;
                j++;
            }
            while(x>=9){
                x-=7;
                a[++j]=8;
            }
            while(x>=7||x==5){
                x-=5;
                a[++j]=2;
            }
            while(x>=6||x==4){
                x-=4;
                a[++j]=4;
            }
            while(x>=5||x==3){
                x-=3;
                a[++j]=7;
            }
            while(x>=2){
                x-=2;
                a[++j]=1;
            }
        }
        sort(a+1,a+1+j);
        for(int k=1;k<=j;k++){
            if(k==2){
                for(int l=1;l<=zero;l++){
                    cout<<0;
                }
            }
            cout<<a[k];
        }
        if(j==1){
            for(int l=1;l<=zero;l++){
                    cout<<0;
                }
        }
        cout<<endl;
    }
    return 0;
}
