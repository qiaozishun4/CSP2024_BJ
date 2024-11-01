# include <bits/stdc++.h>

using namespace std;
int t,n,k,q,l,x1,r,c,yx;
long long z1=0;
vector <int> a[100005];
int b[200005];
bool jie(int r1,int i2,int kt){
    int z2=a[i2].size();
    if(r1==r){
        for(int i=0;i<z2;i++){
            if(a[i2][i]==kt){
                for(int j=i+1;j<min(z2,j+k);j++){
                    if(a[i2][j]==c){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    else{
        for(int i=0;i<z2;i++){
            if(a[i2][i]==kt){
                for(int j=i+1;j<min(z2,j+k);j++){
                    for(int i9=1;i9<=n;i9++){
                        if(i9==i2){
                            continue;
                        }
                        if(jie(r+1,i9,a[i2][j])==1){
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
}
int main(){
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i1=1;i1<=t;i1++){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=0;j<l;j++){
                cin>>x1;
                b[x1]++;
                z1++;
                a[i].insert(a[i].begin()+j,x1);
            }
        }
        for(int xy1=1;xy1<=q;xy1++){
            yx=0;
            cin>>r>>c;
            for(int i=1;i<=n;i++){
                if(jie(1,i,1)==1){
                    cout<<"1"<<endl;
                    yx=1;
                    break;
                }
            }
            if(yx==0){
                cout<<0<<endl;
            }
        }
    }

    return 0;
}
