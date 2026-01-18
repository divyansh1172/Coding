// Sliding Window
// Problem: Given an array of integers nums and a positive integer k, find the maximum sum of any contiguous subarray of size k.
//Input: nums = [2, 1, 5, 1, 3, 2], k = 3
// Output: 9

// what we do is add the number which is added to the window right now and substract the removed one 
#include<stdio.h>
#include<limits.h>
int max_k_sum(int a[], int n, int k){
    if(k>n) return -1;
    int winSum = 0;
    for(int i=0;i<k;k++) winSum+=a[i];
    int maxSum=winSum;
    for(int i=k;i<n;k++){
        winSum -= a[i-k];
        winSum+=a[i];
        if(winSum>maxSum) maxSum=winSum;
    }
    return maxSum;
}

// variable size sliding window
// the window size is not constant and keeps changing 
// Problem: Given an array of positive integers nums and a positive integer target, find the minimal length of a contiguous subarray of which the sum is greater than or equal to target. If there isn't one, return 0.
// Input: target = 7, nums = [2, 3, 1, 2, 4, 3]
// Output: 2

int min_len(int a[], int n, int target){
    int min_len=INT_MAX;
    int left=0;
    int currentSum = 0;
    for(int right =0; right<n;right++){
        currentSum+=a[right];
        while(currentSum >= target){
            int currentLen = right - left + 1;
            if (currentLen < min_len) {
                min_len = currentLen;
            }
            // min_len = right-left+1;
            currentSum -=a[left++];
        }
    }
    return (min_len == INT_MIN)? 0: min_len;
}