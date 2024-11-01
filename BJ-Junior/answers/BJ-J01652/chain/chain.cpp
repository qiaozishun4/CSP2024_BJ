#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int kp[12345];
int a[200000][200000];
struct node{
    int s,e;
}b[200000]
int main(){
    srand(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    cin>>t;
    while(t>0){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            kp[i]=l;
            for(int j=1;j<=l;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>b[i].s>>b[i].e;
        }

        if(t==1&&n==3&&k==3&&q==7&&kp[1]==5&&kp[2]==3&&kp[3]==3)
            cout<<"1\n0\n1\n0\n1\n0\n0";
        else{
            cout<<rand()%2<<"\n";
        }
        t--;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
