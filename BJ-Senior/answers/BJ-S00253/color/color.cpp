#include<bits/stdc++.h>
using namespace std;
int a[1000010],c[1000010];
int t,n,l,ans;
int aa(int o){
    for(int i=o+1;i<n;i++){
        if(a[i]==a[o]){
            if(c[i]==1){
                return i;
            }
        }
    }
    return 0;
}

int fin(int x,int y){
    if(x<0||y>n-1||x>n-1||y<0||x>=y){
        return 0;
    }
    int sum=0,l=0,maxl=0,maxi=0;
    for(int i=x;i<=y;i++){
        if(c[i]==0){
            l=aa(i);
            if(l!=0&&c[l]!=1){
                if(a[i]>sum){
                    sum=a[i];
                    maxl = l;
                    maxi = i;
                }
            }
        }

    }
    ans+=sum;
    c[maxl]=1;
    c[maxi]=1;
    if(maxl-maxi>=3){
        fin(maxi+1,maxl-1);
    }
    fin(maxl+1,n-1);
    return 0;
}

int main(){
    freopen("color.out","w",stdout);
    freopen("color.in","r",stdin);
    cin>>t;
    for(int ab=0;ab<t;ab++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        fin(0,n-1);
        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            a[i]=0;
        }
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}