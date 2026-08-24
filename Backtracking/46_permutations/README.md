# Permutations

## Problem

Given an array `nums` containing distinct integers, return **all possible permutations**.

A permutation is an arrangement of all elements in a different order.

### Example

Input:

```text
[1, 2, 3]
```

Output:

```text
[
 [1, 2, 3],
 [1, 3, 2],
 [2, 1, 3],
 [2, 3, 1],
 [3, 1, 2],
 [3, 2, 1]
]
```

For `n` distinct elements, there are:

```text
n!
```

possible permutations.

---

## Approach

This problem can be solved using **Backtracking**.

The idea is:

1. Pick one element from the remaining array.
2. Add it to the current permutation.
3. Remove that element from the remaining elements.
4. Recursively generate permutations of the remaining elements.
5. Remove the selected element from the current permutation.
6. Try another element.

### Backtracking Pattern

```text
Choose
  ↓
Explore
  ↓
Undo
```

For this problem:

```text
Choose an element
      ↓
Add it to curr
      ↓
Remove it from remaining elements
      ↓
Recursively generate permutation
      ↓
Remove it from curr
```

---

## Example Walkthrough

For:

```text
[1, 2, 3]
```

We first choose `1`.

```text
curr = [1]
remaining = [2, 3]
```

Then choose `2`.

```text
curr = [1, 2]
remaining = [3]
```

Then choose `3`.

```text
curr = [1, 2, 3]
remaining = []
```

Since no elements remain, we have found one complete permutation:

```text
[1, 2, 3]
```

Then we backtrack and try another choice:

```text
[1, 3, 2]
```

Similarly, we generate all other permutations.

---

## Correct C++ Implementation

```cpp
class Solution {
    void solve(
        vector<int>& nums,
        vector<int>& curr,
        vector<vector<int>>& ans
    ) {
        // Base case
        if (nums.empty()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Choose nums[i]
            curr.push_back(nums[i]);

            // Create remaining elements
            vector<int> temp;

            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    temp.push_back(nums[j]);
                }
            }

            // Explore
            solve(temp, curr, ans);

            // Undo
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(nums, curr, ans);

        return ans;
    }
};
```

---

## Why Backtracking Works

Suppose:

```text
nums = [1, 2, 3]
```

At the first level, we have three choices:

```text
        []
      / | \
     1  2  3
```

After choosing `1`:

```text
       [1]
       / \
      2   3
```

After choosing `2`:

```text
     [1,2]
       |
       3
```

We get:

```text
[1,2,3]
```

Then we backtrack:

```text
[1,2]
   ↓
remove 2
   ↓
[1]
```

Now choose `3`:

```text
[1,3,2]
```

The same process is repeated for `2` and `3` as the first choice.

---

## Important Difference: Subsets vs Permutations

### Subsets

For subsets, an element can generally be:

```text
Take
or
Skip
```

Example:

```text
[1,2,3]

[]
[1]
[2]
[3]
[1,2]
[1,3]
[2,3]
[1,2,3]
```

### Permutations

For permutations, we must use **every element exactly once**, but the order changes.

```text
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
```

This is why permutation problems require tracking which elements have already been selected.

---

## Complexity

There are:

```text
N!
```

possible permutations.

For every permutation, we construct/store `N` elements.

Therefore, the output itself requires:

```text
O(N × N!)
```

space.

The recursive solution above also creates temporary arrays while generating permutations, so the practical time/space overhead is higher than an optimized `used[]` implementation.

### Output Complexity

```text
Time  → O(N × N!)
Space → O(N × N!)
```

where the space includes the answer array.

---

## Optimized Approach Using `used[]`

A more common backtracking implementation keeps the original array unchanged and uses a `used` array.

```cpp
class Solution {
    void solve(
        vector<int>& nums,
        vector<bool>& used,
        vector<int>& curr,
        vector<vector<int>>& ans
    ) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) {
                continue;
            }

            // Choose
            used[i] = true;
            curr.push_back(nums[i]);

            // Explore
            solve(nums, used, curr, ans);

            // Undo
            curr.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        solve(nums, used, curr, ans);

        return ans;
    }
};
```

### Why `used[]` is better

Instead of creating a new `temp` vector at every recursive call, we simply remember whether an element has already been selected:

```text
used[i] = true
```

After backtracking:

```text
used[i] = false
```

This is the **standard backtracking pattern** for permutations.

---

## Backtracking Template

```cpp
for (each choice) {

    if (choice is already used)
        continue;

    // Choose
    mark choice;

    // Explore
    backtrack();

    // Undo
    unmark choice;
}
```

### Permutation Mapping

```text
Choice  → Select an unused element
Check   → Is the element already used?
Explore → Build the next position
Undo    → Mark the element as unused
```

---

## Key Concepts Learned

* Backtracking
* Recursion
* Permutations
* State management
* `used[]` array
* Choose → Explore → Undo
* Base case
* Recursive tree
* Time complexity of `N!`

---

## Problem Source

**LeetCode 46 — Permutations**

https://leetcode.com/problems/permutations/

---

## Difficulty

**Medium**

## Topic

**Backtracking + Recursion**
