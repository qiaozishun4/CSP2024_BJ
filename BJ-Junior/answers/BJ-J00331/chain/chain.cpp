#include<iostream>
int a[100010][200010];
int n,l[100010],q,r,c,t,k;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l[j];
            for(int k=1;k<=l[j];k++){
                cin>>a[j][k];
            }
        }
        for(int j=0;j<q;j++){
            cin>>r>>c;
            rm=r;
            r=(r-1)%n+1;
            for(int k=1;k<=l[r];k++){
                if(a[r][k]==c&&(k!=1||rm==1)){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
}
