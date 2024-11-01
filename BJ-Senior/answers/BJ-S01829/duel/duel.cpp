#include <bits/stdc++.h>

using namespace std;
bool kn(int n,bool b[100000]){
    for(int i=0;i<n;i++){
        if(b[i]!=false){
            return 0;
            break;
        }
    }
    return true;
}
bool knw(int n,int r[1000]){
    bool c;
    sort(r,r+n);
    for(int i=0;i<n;i++){
        if(r[i]==r[i+1]){
            continue;
        }
        if(r[i]!=r[i+1]){
            return false;
        }
    }
    return 1;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,c,w;
    cin>>n;
    int cnt=0;
    if(n==1){
        cout<<1;
        return 0;
    }
    int r[n];
    bool b[n],l,q;
    for(int i=0;i<n;i++){
        cin>>r[i];
        b[i]=true;
    }
    sort(r,r+n);
    for(int j=1;j<=n;j++){
        if(r[j-1]!=-1&&r[j]>r[j-1]&&b[j]==true){
            b[j]=b[j-1]=false;
            r[j-1]=-1;
            c=r[1];
            l=b[1];
            w=r[2];
            q=b[2];
            r[1]=r[j-1];
            b[1]=b[j-1];
            r[2]=r[j];
            b[2]=b[j];
            r[j-1]=c;
            b[j-1]=l;
            r[j]=w;
            b[j]=q;
            j=0;
            continue;
        }else continue;
        if(kn(n,b)==1){
            for(int ij=0;ij<n;ij++){
                if(r[ij]!=-1){
                    ++cnt;
                }
            }
            cout<<cnt;
            break;
            return 0;

        }else continue;
        if(knw(n,r)==1){
            for(int il=0;il<n;il++){
                if(r[il]!=-1){
                    ++cnt;
                }
            }
            cout<<cnt;
            break;
            return 0;

        }else continue;

    }
    for(int y=0;y<n;y++){
        if(r[y]!=-1){
            cnt++;
        }
    }

    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
