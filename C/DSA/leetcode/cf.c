#include<stdio.h>
#include<stdlib.h>
// int main(){
//     int t;
//     scanf("%d", &t);
//     while(t--){
//         int x,n,s;
//         scanf("%d %d %d", &n, &s, &x);
//         int a[n];
//         int sum=0;
//         for(int i=0;i<n;i++) {scanf("%d",&a[i]);sum+=a[i];}
//         if(sum>s){printf("no\n");continue;}
//         if((s-sum)%x==0) { printf("yes\n");continue;}
//         else{printf("no\n");continue;}
//     }
//     return 0;
// }
int cmp(const void *a, const void *b) {return (*(int*)a - *(int*)b);}
int BinarySearch(long long int a[], int n, int k){
    int left=0, right=n-1, ans=-1;
    while(left <= right){
        int mid=(left+right)/2;
        if(a[mid]<=k){ans=mid;left=mid+1;}
        else right=mid-1;
    }
    return ans+1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d", &n);
        long long int max=0;
        int a[n], b[n];
        long long int pre[n];
        for(int i=0;i<n;i++){scanf("%d", a+i);}
        for(int i=0;i<n;i++) {scanf("%d", b+i);if(i==0)pre[i]=b[i]; else pre[i]=pre[i-1]+b[i];}

        // MergeSort(a,0,n-1);
        qsort(a,n,sizeof(int), cmp);
        for(int i=0;i<n;i++){
            if (i > 0 && a[i] == a[i - 1]) continue;
            long long m= 1LL * a[i]*(BinarySearch(pre, n, n-i));
            if(m>max) max=m;
        }
        printf("%lld\n", max);
    }
    return 0;
}