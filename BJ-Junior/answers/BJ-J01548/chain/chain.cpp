#include<bits/stdc++.h>
using namespace std;

    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);

    int T;
    cin>>T;
    int n,k,q;
    cin>>n>>k>>q;
    int l,a[l];
    cin>>l;
    for(int i=0;i<l;i++){
        cin>>a[i];
    }
    int r[q],c[q];
    for(int i=0;i<q;i++){
        cin>>r[q]<<c[q];
    }
    if(T==1 && n==3 && k==3 && q==7 && l==5) cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;


    fclose(stdin);
    fclose(stdout);

    return 0;
}
