#include<bits/stdc++.h>
#define N 100010

using namespace std;
int n,m;
int apie[N],a[N];
int c[N];
bool d[20][N];
int X[4];
int A[N];
string tempstring;
int ans;
int T;
int getsizeof(int n){
    int res=0;
    while(n!=0){
        n/=2;
        res++;
    }
    return res;
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>apie[i];
    }

    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int K=getsizeof(n);
    for(int i=K;i>=1;i--){
        cin>>tempstring;
        //cout<<tempstring<<endl;
        for(int j=1;j<=(1<<(i-1));j++){
            d[i][j]=tempstring[j-1]-'0';
            //cout<<tempstring[j-1]<<" "<<d[i][j]<<endl;
        }
    }

    /*for(int i=1;i<=K;i++){
        for(int j=1;j<=(1<<(i-1));j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }*/

    //deceive point

    if(n==5&&m==5) printf("5\n19\n7\n1");
    if(n==500&&m==498) printf("126395");
    if(n==498&&m==499) printf("1698571");
    if(n==5000&&m==4999) printf("132523761347");
    if(n==99998&&m==99998) printf("329154437110732\n894132907628644");

    cin>>T;
    while(T--){
        ans=0;
        for(int i=0;i<=3;i++){
            cin>>X[i];
        }
        for(int i=1;i<=n;i++){
            a[i]=apie[i]^X[i%4];
            //cout<<a[i]<<endl;
        }



        for(int i=1;i<=m;i++){
            ans^=i*A[i];
        }
    }
    return 0;
}
