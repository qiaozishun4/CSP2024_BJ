#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,i,j,g,f,n,m,k,p=1,x0,y0,d;
    cin>>t;
    string s;
    for(i=0;i<t;i++){

        cin>>n>>m>>k;
        cin>>x0>>y0>>d;
        x0--;
        y0--;
        char a[n+1][m+1];
        for(j=0;j<n;j++){
            cin>>s;
            for(g=0;g<s.length();g++){
                a[j][g]=s[g];
            }
        }
        for(f=0;f<k;f++){
            if(d==0){
                if(y0+1<m && a[x0][y0+1]=='.'){
                    p++;
                    y0++;

                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==1){
                if(x0+1<n && a[x0+1][y0]=='.'){
                    p++;
                    x0++;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                if(y0-1>=0 && a[x0][y0-1]=='.'){
                    p++;
                    y0--;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==3){
                if(x0-1>=0 && a[x0-1][y0]=='.'){
                    p++;
                    x0--;
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        cout<<p<<endl;
        p=0;
    }
    return 0;
}
