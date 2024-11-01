#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],x[1000010],m[1000010];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m[i]=1;
        if(a[i]<2){
            x[i]=-1;
        }
        else if(a[i]==2){
            x[i]=1;
        }
        else if(a[i]==3){
            x[i]=7;
        }
        else if(a[i]==4){
            x[i]=4;
        }
        else if(a[i]==5){
            x[i]=3;
        }
        else if(a[i]==6){
            x[i]=6;
        }
        else if(a[i]%7==0){
                m[i]=1;
                while(a[i]>0){
                   x[i]+=8*m[i];
                    m[i]*=10;
                    a[i]-=7;
                }

        }
        else if(a[i]%7==1){
            m[i]=1;
            while(a[i]-8>0){
                x[i]+=8*m[i];
                m[i]*=10;
                a[i]-=7;
            }
            x[i]+=10*m[i];
        }
        else if(a[i]%7==2){
            m[i]=1;
            while(a[i]-7>0){
                x[i]+=8*m[i];
                m[i]*=10;
                a[i]-=7;
            }
            x[i]+=m[i];
        }
        else if(a[i]%6==0){
            m[i]=1;
            while(a[i]>0){
                m[i]*=10;
                a[i]-=6;
            }
            x[i]=6*m[i]/10;
        }
        else{
        m[i]=1;
        while(a[i]>0){

                if(a[i]-7==0||a[i]-7>=2){
                    a[i]-=7;
                    x[i]+=8*m[i];
                }

        else if(a[i]-6==0){
            a[i]-=6;
            x[i]+=6*m[i];
        }
        else if(a[i]-6==0){
            a[i]-=6;
        }
        else if(a[i]-5==0||a[i]-5>=2){
            a[i]-=5;
            x[i]+=3*m[i];
        }
        else if(a[i]-4==0||a[i]-4>=2){
            a[i]-=4;
            x[i]+=4*m[i];
        }
        else if(a[i]-3==0||a[i]-3>=2){
                a[i]-=3;
                x[i]+=7*m[i];
            }
            else if(a[i]-2==0||a[i]-2>=2){
                a[i]-=2;
                x[i]+=m[i];
            }
        m[i]*=10;
    }
        }

    }

    for(int i=1;i<=n;i++){
        cout<<x[i]<<endl;
    }
}
