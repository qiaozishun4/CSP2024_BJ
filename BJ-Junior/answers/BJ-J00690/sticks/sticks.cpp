#include<bits/stdc++.h>
using namespace std;
int a[15]={6,2,5,5,4,5,6,3,7,6};
int b[15]={0,1,2,3,4,5,6,7,8,9};
int c[1001]={0};
void f(int n){
    for(int i=1;i<=n;i++){
        int x=i/100,y=i%100/10,z=i%10;
        if(x==0){
            if(y!=0){
                for(int j=0;j<=10;j++){
                    if(b[j]==y||b[j]==z){
                        c[i]+=a[j];
                    }
                }
            }else{
                for(int j=0;j<=10;j++){
                    if(b[j]==z&&z!=0){
                        c[i]+=a[j];
                    }
                }
            }
        }else{
            for(int j=0;j<=10;j++){
                if(b[j]==x||b[j]==y||b[j]==z){
                    c[i]+=a[j];
                }
            }
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    f(999);
    int t;
    long long n[51];
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
    }
    for(int i=1;i<=t;i++){
        if(n[i]==1){
            cout<<-1<<endl;
            continue;
        }
        for(int j=1;j<=999;j++){
            if(c[j]==n[i]){
                cout<<j<<endl;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}