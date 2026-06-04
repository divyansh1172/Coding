#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void init(int *a, int *s, int n){
    for(int i=0;i<n;i++)
        a[i]=s[i];
}
long long maximumSumOfHeights(int* s, int n) {
    long long max=0;
    int s1[n], s2[n], t1,t2;
    int a[n],f[n];
    for(int i=0;i<n;i++){
        init(a,s,n);
        s1[0]=s2[0]=a[i];
        t1=t2=1;
        long long m=a[i];
        for(int j=i+1; j<n;j++){
            if(a[j]>=s1[t1-1]) {
                // if(a[j]==s[i]) a[j]=s[i]-1;
                // else 
                a[j]=s1[t1-1];
            }
            s1[t1++]=a[j];
            m+=a[j];
        }
        for(int j=i-1; j>=0;j--){
            if(a[j]>=s2[t2-1]) {
                // if(a[j]==s[i]) a[j]=s[i]-1;
                // else 
                a[j]=s2[t2-1];
            }
            s2[t2++]=a[j];
            m+=a[j];
            // t2++;
        }

        if(m>max){
            max=m;
            init(f,a,n);
        }
        // printf("\n");
    }
    for(int i=0;i<n;i++)
        printf("%d->", f[i]);
    printf("\n");
    return max;
}

int main(){
    int s1[5]={5,3,4,1,1};
    int s2[6]={6,5,3,9,2,7};
    int s3[6]={3,2,5,5,2,3};
    printf("%lld\n",maximumSumOfHeights(s1,5));
    printf("%lld\n", maximumSumOfHeights(s2,6));
    printf("%lld\n", maximumSumOfHeights(s3,6));
    return 0;
}