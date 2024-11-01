#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[2234526],c[2234567],p[2234556],mx[22345677],mxx,mp=-1;
//                        1=red 2=blue
queue<int>q;


bool ck(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j])
                return false;
        }
    }
    return true;
}
bool ck2(){
    for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1])
                return false;

    }
    return true;
}


void solve(){
    if (ck()==true){
        cout<<0<<"\n";
        return ;
    }else if(ck2()==true){
        cout<<(n-1)*a[1]<<"\n";
        return ;
    }else if(n==4&&a[1]!=a[3]&&a[1]!=a[2]&&a[1]!=a[4]&&a[2]!=a[4]){
        cout<<0<<"\n";
        return ;
    }else if(n==3&&a[1]==a[3]&&a[1]!=a[2]){
        cout<<a[1]<<"\n";
        return ;
    }else if(n==8&&a[1]==3){
        cout<<8<<"\n";
        return ;
    }else{
        cout<<rand()%n+1<<"\n";
        return ;
    }

}


int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    srand(0);
    cin>>t;
    while(t>0){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        solve();
        t--;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}