// This is Boyer–Moore Voting Algorithm - vote cancellation type of thing
// Consider a group of candidates A,B,C. They are in a election some people are voting for them.
// what we do is cancel one vote of majority with a one vote of non-majority.
// after the full traversal, the one ith majority remains.
#include<stdio.h>
int majority(int a[], int n){
    int can=0, count=0;   // count measures the votes of majority element. and can is the candidate for the maj elem
    for(int i=0;i<n;i++){
        if(count==0) can=a[i]; // new candidate
        if (a[i]==can) count++; // new vote for candidate
        else count--; // vote for non majority candidate.
    } 
    return can;
}