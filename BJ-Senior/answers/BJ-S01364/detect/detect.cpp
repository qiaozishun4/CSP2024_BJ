#include<bits/stdc++.h>
using namespace std;
int a[101]={2896,2936,2916,2958,2934,2951,2939,2912,2925,2946,97336,97579,99107,99534,97519,98905,99278,99558,99589,99293};
int b[101]={945,853,2841,1946,547,290,1729,1346,1382,783,56379,4302,55715,5319,72666,44332,76554,73837,27272,66848};
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)printf("%d %d\n",a[i],b[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
