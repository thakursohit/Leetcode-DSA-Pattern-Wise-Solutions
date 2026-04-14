📌 Problem: Fruit Into Baskets (LeetCode 904)
🧠 Concept
At most 2 distinct elements
Find longest contiguous subarray
Pattern: Sliding Window + HashMap
✅ Approach
Use unordered_map<int,int> to store frequency of fruits
Expand window using right
If more than 2 fruit types:
Shrink window from left
Track maximum window size
💻 Code
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < fruits.size(); right++){
            mp[fruits[right]]++;

            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
🔁 Dry Run Example

Input:

[1,2,3,2,2]

Output:

4

Valid subarray:

[2,3,2,2]
⏱ Complexity
Time: O(n)
Space: O(1) (max 2 keys in map)
🔑 Key Points
Window must always have ≤ 2 distinct fruits
Shrink window only when condition breaks

Use:

right - left + 1

to calculate length

⚠️ Common Mistakes
❌ Adding fruit values instead of counting length
❌ Using only indices without tracking last occurrence
❌ Forgetting to erase map entry when count = 0
🚀 Optimization (Interview Bonus)
Can be solved in O(1) space without hashmap
Track:
last fruit
second last fruit
last streak count