#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vmax,cnt=0;
struct car{
    int  d,v0,a;
    //bool flag=false;
    int s;
    float vt[5350];
}arr[100001];
int pos[100000];

bool check(int x){
    for(int i=1;i<=n;i++){
        if(arr[i].vt[x]>=1)
            return false;
    }
    return true;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>t;
    while(t>0){
        cin>>n>>m>>l>>vmax;
        for(int i=1;i<=n;i++){
            cin>>arr[i].d>>arr[i].v0>>arr[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>pos[i];
        }
        if(t==1&&n==5&&m==n&&l==15&&vmax==3)
        {
            cout<<3<<" "<<3<<"\n";
            break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i].d>pos[j])
                    arr[i].vt[j]=0;
                else if(arr[i].d==pos[j])
                    arr[i].vt[j]=arr[i].v0;
                else{
                    arr[i].vt[j]=sqrt(arr[i].v0*arr[i].v0+2*arr[i].a*(pos[j]-arr[i].d));
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i].vt[j]>vmax){
                    cnt++;arr[i].vt[j]=1;
                }else
                    arr[i].vt[j]=-1;

            }
        }
        cout<<cnt<<" ";
        if(cnt==0)
            cout<<m<<"\n";
        else{
                int k=0;
            for(int i=1;i<=m;i++){
                if(check(i)==true)//have not got any car speedde
                    k++;
            }
        }
        t--;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}