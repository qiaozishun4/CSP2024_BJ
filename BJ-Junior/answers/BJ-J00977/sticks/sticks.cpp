#include<bits/stdc++.h>
using namespace std;
long long t,n,a=1,minn=100,flag=0,m=0;
void chai(int n,int last){
    if(n<2&&m==0){
        flag=1;
        return;
    }
    if(n<2&&m==1) return;
    else{
        if(last==2){
            if(a==1) a=1;
            a=a*10+1;
        }else if(last==3){
            if(a==1) a=7;
            a=a*10+7;
        }else if(last==4){
            if(a==1) a=4;
            a=a*10+4;
        }else if(last==5){
            if(a==1) a=2;
            a=a*10+2;
        }else if(last==6){
            if(a==1) a=6;
            else a=a*10*10;
        }else if(last==7){
            if(a==1) a=7;
            a=a*10+8;
        }
        chai(n-2,2);
        chai(n-3,3);
        chai(n-4,4);
        chai(n-5,5);
        chai(n-6,6);
        chai(n-7,7);
    }
    if(n==0){
        minn=min(minn,a);
        flag=0;m=1;
        return;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1) cout<<"-1"<<endl;
        else if(n/2==1) cout<<2<<endl;
        else if(n/3==1) cout<<3<<endl;
        else if(n/4==1) cout<<4<<endl;
        else if(n/5==1) cout<<5<<endl;
        else if(n/6==1) cout<<6<<endl;
        else if(n/7==1) cout<<7<<endl;
        else{
            chai(n,0);
            if(flag==1) cout<<"-1"<<endl;
            else cout<<minn<<endl;
        }

    }
    return 0;
}

//0 1 2 3 4 5 6 7 8 9
//6 2 5 5 4 5 6 3 7 6
