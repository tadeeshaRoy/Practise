//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

//For example:
//Given the array [-2,1,-3,4,-1,2,1,-5,4],the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//For this problem, return the maximum sum.
//The following solution covers for all negative numbers as well.

int Solution::maxSubArray(const vector<int> &A) {
    int curr_sum =0, mx_sum =-1000000000;
    for(int i=0;i<A.size();i++)
    {
        /*meh+=A[i];
        if(meh<0)
            meh=0;
        else if(meh>mes)
            mes=meh;*/
            
        curr_sum+=A[i];
        mx_sum=max(mx_sum,curr_sum);
        if(curr_sum<0)   curr_sum=0;
    }
    return mx_sum;
}


//check here for returning the Max Sum Contiguous Subarray rather than just the sum
//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/#tablist4-tab5
