#include<bits/stdc++.h>
using namespace std;
bool flag=1;
int mlen=9999999;
int a[11]={6,2,5,5,4,5,6,3,7,6};
int b[100]={},minn[150]={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
void f(int n,int s){
    if(flag==0)return;
    else{
        for(int i=!(bool(s-1));i<=9;i++){
            if(a[i]==n){
                b[s]=i;
                if(s<mlen){
                    for(int j=1;j<=s;j++)minn[j]=b[j];
                    for(int j=s+1;j<=145;j++){
                        minn[j]=10;
                    }
                    mlen=s;
                }if(s>mlen)return;
                for(int i=1;i<=s;i++){
                    if(b[i]<minn[i]){
                        for(int j=1;j<=s;j++)minn[j]=b[j];
                        for(int j=s+1;j<=145;j++){
                            minn[j]=10;
                        }
                        mlen=s;
                    }if(b[i]>minn[i])break;
                }
                //for(int i=1;i<=s;i++)cout<<minn[i];
                //cout<<endl;
                //flag=0;
            }
        }if(flag){
            for(int i=!(bool(s-1));i<=9;i++){
                if(flag==0)break;
                if(n>a[i]){
                    b[s]=i;
                    f(n-a[i],s+1);
                    b[s]=0;
                }
            }
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++){
        flag=1;
        mlen=9999999;
        cin>>n;
        if(n==1)cout<<-1<<endl;
        else if(n==8)cout<<10<<endl;
        else{
            f(n,1);
            for(int i=1;i<=145;i++){
                if(minn[i]>9)break;
                cout<<minn[i];
            }cout<<endl;
        }
    }
    return 0;
}
