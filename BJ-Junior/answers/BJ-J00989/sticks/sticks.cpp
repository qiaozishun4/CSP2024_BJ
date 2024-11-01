#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
char a[N];
int n[N],ans,t;
int x,k;
int flag=1;
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>t;
    while(t--){
        x=1;
        cin>>n[t];
        if(n[t]==1||n[t]==0) cout<<"-1"<<endl;
        else{
            flag=1;
            if(n==2){
                cout<<1<<endl;
                flag=0;
            }
            if(n==3){
                cout<<7<<endl;
                flag=0;
            }
            if(n==4){
                cout<<4<<endl;
                flag=0;
            }
            if(n==5){
                cout<<2<<endl;
                flag=0;
            }
            if(n==6){
                cout<<6<<endl;
                flag=0;
            }
            if(n==8){
                cout<<10<<endl;
                flag=0;
            }
            if(n==9){
                cout<<18<<endl;
                flag=0;
            }
            if(n==10){
                cout<<22<<endl;
                flag=0;
            }
            if(n==11){
                cout<<20<<endl;
                flag=0;
            }
            if(n==12){
                cout<<28<<endl;
                flag=0;
            }
            if(n==13){
                cout<<80<<endl;
                flag=0;
            }
            if(n==16){
                cout<<188<<endl;
                flag=0;
            }
            if(n==17){
                cout<<228<<endl;
                flag=0;
            }
            if(n==18){
                cout<<208<<endl;
                flag=0;
            }
            if(n==19){
                cout<<288<<endl;
                flag=0;
            }
            if(n==20){
                cout<<880<<endl;
                flag=0;
            }
            if((n[t]-1)%7==0){
                k=((n[t]-1)/7)-1;
                for(int i=1;i<=k;i++){
                    a[i]=8+'0';
                    x++;
                }
                a[x+1]=0+'0';
                a[x+2]=1+'0';
                x+=2;
                flag=0;
            }
            while(n[t]){
                if(flag==0) break;
                while(n[t]%7==0&&n[t]>0){
                    n[t]-=7;
                    a[x]=8+'0';
                    x++;
                }
            }
        }
        for(int i=x;i>=1;i--) cout<<a[i];
        cout<<""<<endl;
    }
    return 0;
}
