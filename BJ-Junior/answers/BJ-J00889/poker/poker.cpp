#include<bits/stdc++.h>
using namespace std;
int n,g=0;
int a[200][200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        a[s[0]][s[1]]++;
    }
    for(int i='2';i<='9';i++){
        if(a['D'][i]==0){
            g++;
        }
        if(a['C'][i]==0){
            g++;
        }
        if(a['H'][i]==0){
            g++;
        }
        if(a['S'][i]==0){
            g++;
        }
    }
    if(a['S']['T']==0) g++;
    if(a['D']['T']==0) g++;
    if(a['C']['T']==0) g++;
    if(a['H']['T']==0) g++;
    if(a['S']['J']==0) g++;
    if(a['D']['J']==0) g++;
    if(a['C']['J']==0) g++;
    if(a['H']['J']==0) g++;
    if(a['S']['Q']==0) g++;
    if(a['D']['Q']==0) g++;
    if(a['C']['Q']==0) g++;
    if(a['H']['Q']==0) g++;
    if(a['S']['K']==0) g++;
    if(a['D']['K']==0) g++;
    if(a['C']['K']==0) g++;
    if(a['H']['K']==0) g++;
    if(a['S']['A']==0) g++;
    if(a['D']['A']==0) g++;
    if(a['C']['A']==0) g++;
    if(a['H']['A']==0) g++;
    cout<<g;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
