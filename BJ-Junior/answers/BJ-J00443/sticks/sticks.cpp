#include<bits/stdc++.h>
using namespace std;
int a[100005];
int num(int a){
    if(a==2) return 1;
    else if(a==3) return 7;
    else if(a==4) return 4;
    else if(a==5) return 2;
    else if(a==6) return 0;
    else if(a==7) return 8;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==2){
            cout<<1<<endl;
        }else if(a[i]==3){
            cout<<7<<endl;
        }else if(a[i]==4){
            cout<<4<<endl;
        }else if(a[i]==5){
            cout<<2<<endl;
        }else if(a[i]==6){
            cout<<6<<endl;
        }else if(a[i]==7){
            cout<<8<<endl;
        }
        int ans;
        if(a[i]<=1) cout<<-1<<endl;
        int minn=1e9;
        int x,y,z,w;

        if(a[i]>=8&&a[i]<=14){
            for(int j=2;j<=7;j++){
            for(int k=2;k<=7;k++){
                    if((j+k)==a[i]) {
                        x=num(j);
                        y=num(k);
                        if(j==6) x=6;
                        minn=min(minn,x*10+y);
                    }
            }
        }
        cout<<minn<<endl;
        }

        if(a[i]>14&&a[i]<=21){
            for(int j=2;j<=7;j++){
                for(int k=2;k<=7;k++){
                    for(int l=2;l<=7;l++){
                        if(j+k+l==a[i]){
                            x=num(j);
                            y=num(k);
                            z=num(l);
                            if(j==6) x=6;
                            minn=min(minn,x*100+y*10+z);
                        }
                    }
                }
            }
            cout<<minn<<endl;
        }else if(a[i]>=21&&a[i]<=29){
            for(int j=2;j<=7;j++){
                for(int k=2;k<=7;k++){
                    for(int l=2;l<=7;l++){
                        for(int m=2;m<=7;m++){
                            if(j+k+l+m==a[i]){
                                x=num(j);
                                y=num(k);
                                z=num(l);
                                w=num(m);
                                if(j==6) x=6;
                                minn=min(minn,x*1000+y*100+z*10+w);
                            }
                        }
                    }
                }
            }
            cout<<minn<<endl;
        }

    }

}