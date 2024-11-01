#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","r",stdin);
    string a[52]={"DA","D1","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C1","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H1","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S1","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"}
    int s=52;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string d;
        cin>>d;
        for(int j=0;j<52;j++){
            if(d==a[j]){
                s--;
                a[j]="0";
    	    }
    	}
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
    
}
