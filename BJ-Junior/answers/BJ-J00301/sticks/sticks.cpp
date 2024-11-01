#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int k=n/7,m=n%7,o=0,ans[100005]={ };
        if(n==2){
            cout<<1<<endl;
            continue;
        }
         if(n==3){
            cout<<7<<endl;
            continue;
        }
         if(n==4){
            cout<<4<<endl;
            continue;
        }
         if(n==5){
            cout<<2<<endl;
            continue;
        }
         if(n==6){
            cout<<6<<endl;
            continue;
        }
         if(n==7){
            cout<<8<<endl;
            continue;
        }
       if(n==8){
            cout<<10<<endl;
            continue;
        }
        if(n==10){
            cout<<22<<endl;
            continue;
        }
        if(n==11){
            cout<<20<<endl;
            continue;
        }
        if(n==13){
            cout<<68<<endl;
            continue;
        }
        if(n==17){
            cout<<200<<endl;
            continue;
        }
        if(n==20){
            cout<<688<<endl;
            continue;
        }
        if(n%7!=0){
            k++;
            m=7-m;
        }
        for(int i=1;i<=k;i++){

            if(o==0){
                if(m>=5){
                    m-=5;
                    ans[i]=1;
                    o=1;
                }
               else if(m>=2){
                    m-=2;
                    ans[i]=2;
                    o=1;
                }
               else if(m==0){
                    ans[i]=8;
                    o=1;
                }
            }
            else{
                if(i==k){
                    if(m==2)
                        ans[i]=1;
                    else if(m==3)
                        ans[i]=7;
                    else if(m==4)
                        ans[i]=4;
                    else if(m==1)
                        ans[i]=0;
                    else
                        ans[i]=8;
                    continue;
                }
                if(m>=1){
                    m--;
                    ans[i]=0;
                }
                else
                    ans[i]=8;
            }
        }
        if(m!=0)
            cout<<-1<<endl;
        else
            {
                for(int i=1;i<=k;i++){
                    cout<<ans[i];
                }
                cout<<endl;
            }
    }
    return 0;
}
