#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int x_total=0, y_total=0, z_total=0,a,b,c;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a, &b,&c );
        x_total+=a;
        y_total+=b;
        z_total+=c;
    }
    if(x_total==0 && y_total==0 && z_total==0) printf("YES");
    else printf("NO");
    return 0;
}