#include<bits/stdc++.h>
using namespace std;
int a[200001],b[200001],j,k;
bool f(int l,int r,int d,int q){
    int i,i1,i2=0;bool s=0,p;
    if(d==1){
        if(q==-1){
            for(i=0;i<j;i++,i2--){
                if(b[i]==1)i2=0;
                if(i2>0&&a[i]==r){return 1;}
                if(a[i]==l){
                    if(i2>0){i2=k-1;i++;}
                    else i2=k;
                }
            }
        }else{
            for(i=0;i<j;i++,i2--){
                if(b[i]==1){
                    if(i==q){
                        for(;b[i]!=1 | i<j;i++);
                    }i2=0;
                }if(i2>0&&a[i]==r){return 1;}
                if(a[i]==l){
                    if(i2>0){i2=k-1;i++;}
                    else i2=k;
                }
            }
        }
    }else{/////////////////////////////////////////////
        if(q==-1){
            for(i=0;i<j;i++,i2--){
                if(b[i]==1){i2=0;}
                if(a[i]==l){
                    if(i2>0){i2=k-1;i++;}
                    else i2=k;if(s==1){break;}
                }if(i2>0)s=s||f(a[i],r,d-1,i);

            }
        }else{
            for(i=0;i<j;i++,i2--){
                if(b[i]==1){
                    if(i==q){
                        for(;b[i]!=1 | i<j;i++);
                    }i2=0;
                }
                if(a[i]==l){
                    if(i2>0){i2=k-1;i++;}
                    else i2=k;if(s==1){break;}
                }if(i2>0)s=s||f(a[i],r,d-1,i);

            }
        }
    }
    return s;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    int op;
    for(op=0;op<t;op++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n,rt,i,i1;j=0;
        cin>>n>>k>>rt;

        for(i=0;i<n;i++){
            int l;
            cin>>l;
            for(i1=0;i1<l;i1++)cin>>a[i1+j];
            j+=l;
            b[j]=1;
        }
        for(i=0;i<rt;i++){
            int r,c,ka=0;
            cin>>r>>c;
            for(i1=0;i1<j;i1++){
                if(a[i1]==c){
                    ka=1;
                    break;
                }
            }
            //cout<<i<<endl;
            if(ka)cout<<f(1,c,r,-1)<<endl;
            else cout<<0<<endl;
        }
    }
}
