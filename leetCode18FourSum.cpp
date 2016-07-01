/*
http://blog.csdn.net/jiyanfeng1/article/details/8075309
we can not call threeSum derectly in foursum
add a for loop is ok
it is same with k-sum
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                int left = j+1;
                int right= len-1;
                while(left<right){
                //cout<<nums[i]<<nums[j]<<nums[left]<<nums[right]<<endl;
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum == target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        vector<vector<int> >::iterator result = find(res.begin(),res.end(),tmp);
                        if(result == res.end()){
                            res.push_back(tmp);
                        }

                        left++;
                        right--;
                    }
                    if(sum < target){
                        left++;
                    }
                    if(sum>target){
                        right--;
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    vector<int> nums(6);
    nums[0] = 1;
    nums[1] = 0;
    nums[2] = -1;
    nums[3] = 0;
    nums[4] = -2;
    nums[5] = 2;
    Solution s ;
    vector<vector<int> > res = s.fourSum(nums,0);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res.size();++j){
        cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
