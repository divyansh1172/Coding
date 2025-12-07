#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int b[n-1];
        if(a[0]==-1 && a[n-1] == -1){a[0]=a[n-1]=0;}
        else if(a[0]==-1)a[0]=a[n-1];
        else if(a[n-1]==-1)a[n-1]=a[0];
        for(int i=0;i<n;i++){
            if(a[i]== -1) a[i]=0;
        }
        for(int i=0; i< n-1; i++) b[i]= a[i+1]-a[i];

        int v= (a[n-1] > a[0])? a[n-1]-a[0] : a[0]-a[n-1];
        printf("%d\n",v);
        for(int i=0; i<n; i++)    printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}