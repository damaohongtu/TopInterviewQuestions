## 1.Two Sum
`Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.`
**Examples:**
```
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
**Solutions:**
```c++
//存到一个hash表中，判断target-nums[i]是否在表中。时间和空间复杂度都是O(N),这种解决思路和同python中的字典
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        unordered_map<int,int> m;
        for (int i = 0; i < len; i++){
            if (m.count(target - nums[i])){
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
//将以上的解法拆解：实现建立map，然后进行遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        map<int,int> m;
        for (int i = 0; i < len; i++){
            m[nums[i]] = i;
        }
        for (int i = 0; i < len; i++){
          //需要避免3+3=6的情况，使用map，很好记录了下标
            if (m.count(target - nums[i])&&m[target - nums[i]]!=i){
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
                return res;
            }
        }
        return res;
    }
};

```
