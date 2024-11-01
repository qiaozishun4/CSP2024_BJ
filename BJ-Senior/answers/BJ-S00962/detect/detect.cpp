#include<bits/stdc++.h>
using namespace std;



struct car{
    int st,sp,plsp;
    bool nice;
}a[100005];
int b[100005];

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T;
    cin>>T;
    while(T--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>a[i].st>>a[i].sp>>a[i].plsp;
            a[i].nice=0;
        } 
        for(int i=1;i<=m;i++) cin>>b[i];
        sort(b+1,b+m+1);
        int maxb=b[m],minb=b[1],cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i].plsp){
                if(a[i].sp+a[i].plsp*maxb<=V) cnt++;
            }
            else{
                if(a[i].sp+a[i].plsp*minb<=V) cnt++;
            }
        }
        cout<<cnt<<" "<<m-2<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}