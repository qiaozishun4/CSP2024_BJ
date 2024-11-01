#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    string a[100];
    int s[100];
    string m[100]={"CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<52;j++)
        {
           if(a[i]==m[j])
            {
                s[j]++;
                cout<<a[i]<<" "<<s[j]<<endl;
            }
        }
    }
    for(int i=0;i<52;i++)
    {
        if(s[i]==0)
        {
            cnt++;
            cout<<i<<" ";
            cout<<cnt<<" ";
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
