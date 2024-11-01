#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,a[10001],r[10001],b[10001];
        bool f[10001]={};
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            for(int j=0;j<i;j++){
                if(a[j]==a[i]){
                    f[i]=1;
                    f[j]=1;
                }
            }
        }
        int a1=0,a2=0,q=0;
        for(int i=1;i<n;i++){
            if(f[i]==1){
                q=1;
                break;
            }
        }
        if(q!=1){
            cout<<"0"<<endl;
            continue;
        }
        r[0]=a[0];
        if(a[1]==r[0]){
            r[1]=a[1];
            b[0]=a[2];
            a1=2,a2=1;
            for(int i=3;i<n;i++){
                if(r[a1]==a[i]){
                    r[++a1]=a[i];
                }else if(b[a2]==a[i]){
                    b[++a2]=a[i];
                }else{
                    if(r[a1]>=b[a2]){
                        r[++a1]=a[i];
                    }else{
                        b[++a2]=a[i];
                    }
                }
            }
        }else{
            b[0]=a[1];
            a1=1,a2=1;
            for(int i=2;i<n;i++){
                if(r[a1]==a[i]){
                    r[++a1]=a[i];
                }else if(b[a2]==a[i]){
                    b[++a2]=a[i];
                }else{
                    if(r[a1]>=b[a2]){
                        r[++a1]=a[i];
                    }else{
                        b[++a2]=a[i];
                    }
                }
            }
        }
        int sum=0;
        for(int i=1;i<=a1;i++){
            if(r[i]==r[i-1]){
                sum+=r[i];
            }
        }
        for(int i=1;i<=a2;i++){
            if(b[i]==b[i-1]){
                sum+=b[i];
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
