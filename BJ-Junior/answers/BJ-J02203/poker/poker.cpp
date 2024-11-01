#include<bits/stdc++.h>
using namespace std;
int A[128],D[20],C[20],H[20],S[20];
char a[128];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char zi;
    for(int i=0;i<n;i++){
        cin>>zi>>a[i];
        if(a[i]=='A')
            A[i]=1;
        else if(a[i]=='T')
            A[i]=10;
        else if(a[i]=='J')
            A[i]=11;
        else if(a[i]=='Q')
            A[i]=12;
        else if(a[i]=='K')
            A[i]=13;
        else{
            A[i]=a[i]-'0';
        }
        if(zi=='D')
            D[A[i]]=1;
        if(zi=='C')
            C[A[i]]=1;
        if(zi=='H')
            H[A[i]]=1;
        if(zi=='S')
            S[A[i]]=1;
    }
    int k=0;
    for(int i=1;i<14;i++){
        if(D[i]==1)
            k++;
        if(C[i]==1)
            k++;
        if(H[i]==1)
            k++;
        if(S[i]==1)
            k++;
    }
    int ans=52-k;
    cout<<ans;

    return 0;
}
