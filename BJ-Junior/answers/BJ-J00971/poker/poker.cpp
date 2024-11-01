#include <bits/stdc++.h>
using namespace std;
int d[15],c[15],h[15],s[15],n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int sum=52;
    cin>>n;
    for(int i=0;i<n;i++){
        char a[3];
        cin>>a;
        if(a[0]=='D'){
            if(a[1]<='9'&&a[1]>='2'){
                int n=a[1]-'0';
                if(d[n]==0){
                    d[n]=1;
                    sum--;
                }
            }
            if(a[1]=='A'&&d[1]==0){
                d[1]=1;
                sum--;
            }
            if(a[1]=='T'&&d[10]==0){
                d[10]=1;
                sum--;

            }
            if(a[1]=='J'&&d[11]==0){
                d[11]=1;
                sum--;

            }
            if(a[1]=='Q'&&d[12]==0){
                d[12]=1;
                sum--;

            }
            if(a[1]=='K'&&d[13]==0){
                d[13]=1;
                sum--;
            }
        }
        if(a[0]=='C'){
            if(a[1]<='9'&&a[1]>='2'){
                int n=a[1]-'0';
                if(c[n]==0){
                    c[n]=1;
                    sum--;
                }
            }
            if(a[1]=='A'&&c[1]==0){
                c[1]=1;
                sum--;
            }
            if(a[1]=='T'&&c[10]==0){
                c[10]=1;
                sum--;

            }
            if(a[1]=='J'&&c[11]==0){
                c[11]=1;
                sum--;

            }
            if(a[1]=='Q'&&c[12]==0){
                c[12]=1;
                sum--;

            }
            if(a[1]=='K'&&c[13]==0){
                c[13]=1;
                sum--;
            }
        }
        if(a[0]=='H'){
            if(a[1]<='9'&&a[1]>='2'){
                int n=a[1]-'0';
                if(h[n]==0){
                    h[n]=1;
                    sum--;
                }
            }
            if(a[1]=='A'&&h[1]==0){
                h[1]=1;
                sum--;
            }
            if(a[1]=='T'&&h[10]==0){
                h[10]=1;
                sum--;

            }
            if(a[1]=='J'&&h[11]==0){
                h[11]=1;
                sum--;

            }
            if(a[1]=='Q'&&h[12]==0){
                h[12]=1;
                sum--;

            }
            if(a[1]=='K'&&h[13]==0){
                h[13]=1;
                sum--;
            }
        }
        if(a[0]=='S'){
            if(a[1]<='9'&&a[1]>='2'){
                int n=a[1]-'0';
                if(s[n]==0){
                    s[n]=1;
                    sum--;
                }
            }
            if(a[1]=='A'&&s[1]==0){
                s[1]=1;
                sum--;

            }
            if(a[1]=='T'&&s[10]==0){
                s[10]=1;
                sum--;

            }
            if(a[1]=='J'&&s[11]==0){
                s[11]=1;
                sum--;

            }
            if(a[1]=='Q'&&s[12]==0){
                s[12]=1;
                sum--;

            }
            if(a[1]=='K'&&s[13]==0){
                s[13]=1;
                sum--;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
