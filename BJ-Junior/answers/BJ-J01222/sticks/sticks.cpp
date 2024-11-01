#include<bits/stdc++.h>
using namespace std;
//int nu[]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==0||n==1)cout<<-1;
        else if(n==2)cout<<1;
        else if(n==3)cout<<7;
        else if(n==4)cout<<4;
        else if(n==5)cout<<2;
        else if(n==6)cout<<6;
        else if(n==7)cout<<8;
        else if(n==8)cout<<18;
        else if(n==9)cout<<24;
        else if(n==10)cout<<22;
        else if(n==11)cout<<20;
        else if(n==12)cout<<28;
        else if(n==13)cout<<80;
        else if(n==14)cout<<88;
        else if(n==15)cout<<108;
        else if(n==16)cout<<188;
        else if(n==17)cout<<200;
        else if(n==18)cout<<208;
        else if(n==19)cout<<288;
        else if(n==20)cout<<688;
        else{
            if(n%7==0){
                int s=n/7;
                while(s--)cout<<8;
            }
        }
        cout<<"\n";
        #if 0
        else{
            int i;
                //int nums[100002];
            for(int i=10;1;i++){

            }

        }


            int c0=n/7,m0=n%7;
            if(n%7==0){
                while((c0--)>0)cout<<8;
            }
            if(m0==1){
                cout<<7;
                while((c0--)>0)cout<<0;
                //cout<<7;
            }
            if(m0==2){
                c0-=2;
                while((c0--)>0)cout<<8;
            }
            if(m0==3){
                while((c0--)>0)cout<<8;
            }
            if(m0==4){

            }

        }
        cout<<'\n';
        #endif

    }
    }

