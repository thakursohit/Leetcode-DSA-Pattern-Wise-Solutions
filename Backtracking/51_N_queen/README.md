# N-Queens

## Problem

The **N-Queens** problem is a classic **Backtracking** problem.

Given an integer `n`, place `n` queens on an `n × n` chessboard such that:

* No two queens are in the same row.
* No two queens are in the same column.
* No two queens are on the same diagonal.

The goal is to find **all possible valid arrangements**.

---

## Approach

We solve the problem using **Backtracking**.

### Step 1: Place queens row by row

We start from `row = 0` and try placing a queen in every column of that row.

### Step 2: Check whether a position is safe

Before placing a queen at `(row, col)`, we check:

1. **Upper-left diagonal**
2. **Same column**
3. **Upper-right diagonal**

We only need to check upward because queens are placed from top to bottom. There cannot be any queen in the current row yet.

### Step 3: Backtrack

If the position is safe:

```cpp
grid[row][col] = 'Q';
```

Then recursively solve the next row:

```cpp
solve(row + 1, n, ans, grid);
```

After returning from recursion, remove the queen:

```cpp
grid[row][col] = '.';
```

This allows us to try another possible position.

---

## Backtracking Pattern

The main idea is:

```text
Choose
   ↓
Check
   ↓
Explore
   ↓
Undo
```

For N-Queens:

```text
Choose a column
      ↓
Check whether safe
      ↓
Place Queen
      ↓
Solve next row
      ↓
Remove Queen
```

---

## Important Observation

Since we place **exactly one queen in each row**, we don't need to check the current row.

We only check:

```text
       ↑
   upper column

↖ upper-left    upper-right ↗
```

All previously placed queens are above the current row.

---

## Code

```cpp
class Solution {
    bool check(int r, int c, vector<vector<char>> &grid) {
        int row = r;
        int col = c;

        // Check upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (grid[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }

        // Check upper column
        row = r;
        col = c;

        while (row >= 0) {
            if (grid[row][col] == 'Q') {
                return false;
            }
            row--;
        }

        // Check upper-right diagonal
        row = r;
        col = c;

        int n = grid.size();

        while (row >= 0 && col < n) {
            if (grid[row][col] == 'Q') {
                return false;
            }
            row--;
            col++;
        }

        return true;
    }

public:
    void solve(
        int row,
        int &n,
        vector<vector<string>> &ans,
        vector<vector<char>> &grid
    ) {
        // Base case
        if (row == n) {
            vector<string> curr;

            for (int i = 0; i < n; i++) {
                string s = "";

                for (int j = 0; j < n; j++) {
                    s.push_back(grid[i][j]);
                }

                curr.push_back(s);
            }

            ans.push_back(curr);
            return;
        }

        // Try every column in the current row
        for (int c = 0; c < n; c++) {

            if (check(row, c, grid)) {

                // Choose
                grid[row][c] = 'Q';

                // Explore
                solve(row + 1, n, ans, grid);

                // Undo
                grid[row][c] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<vector<char>> grid(
            n,
            vector<char>(n, '.')
        );

        solve(0, n, ans, grid);

        return ans;
    }
};
```

---

## Example

### Input

```text
n = 4
```

### Output

```text
[
 [".Q..",
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]
]
```

There are **2 valid solutions** for `n = 4`.

---

## Time Complexity

The worst-case time complexity is approximately:

```text
O(N!)
```

because we try different arrangements of queens using backtracking.

Additionally, each position check takes up to `O(N)` time because we scan the column and diagonals.

---

## Space Complexity

The chessboard requires:

```text
O(N²)
```

space.

The recursion stack requires:

```text
O(N)
```

space.

So the main auxiliary space is:

```text
O(N²)
```

excluding the space required to store all answers.

---

## Key Concepts Learned

* Backtracking
* Recursion
* Chessboard traversal
* Diagonal checking
* State selection and undo
* Base case
* Recursive exploration
* Constraint checking

---

## Backtracking Template

This problem follows the general backtracking structure:

```cpp
for (each choice) {

    if (choice is valid) {

        // Choose
        make_choice();

        // Explore
        backtrack();

        // Undo
        undo_choice();
    }
}
```

### N-Queens Mapping

```text
Choice  → Select a column
Check   → Is the position safe?
Explore → Move to the next row
Undo    → Remove the queen
```

---

## Problem Source

**LeetCode 51 — N-Queens**

https://leetcode.com/problems/n-queens/

---

## Difficulty

**Hard**

## Topic

**Backtracking + Recursion**
