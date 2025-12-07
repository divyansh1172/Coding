#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], b[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        int m_xor=b[0], a_xor=a[0];
        for(int i=1; i<n; i++)
        {
            m_xor^=b[i];
            a_xor^=a[i];
        }
        if(m_xor==a_xor) {printf("Tie\n");continue;}
        int div;
        for(int i=n-1; i>=0; i++){
            if(a[i]!=b[i]){
                div=i; break;
            }
        }
        if(div%2==1|| div==0) {printf("Ajisai\n");continue;}
        else printf("Mai\n");
    }
    return 0;
}