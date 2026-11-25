# Lab Assignment 2

All the programs are in C++17. Each file can be run separately.

## How to run

For example:

```bash
g++ -std=c++17 01-avl-tree-check.cpp -o avl
./avl
```

For the other questions, use the respective file name.

## Questions and outputs

### Check AVL tree

File: [01-avl-tree-check.cpp](01-avl-tree-check.cpp)

Checks BST ordering and the height difference at each node.

Time: O(n). Space: O(h).

Output:

```text
Is AVL: true
After adding 2: false
```

### Kth smallest element

File: [02-avl-kth-smallest.cpp](02-avl-kth-smallest.cpp)

Uses the size of the left subtree to find the kth element.

Time: O(log n). Space: O(1) for search.

Output:

```text
k = 4, kth smallest = 25
```

### Fibonacci (memoization)

File: [03-fibonacci-memoization.cpp](03-fibonacci-memoization.cpp)

Stores Fibonacci values so they do not need to be calculated again.

Time: O(n). Space: O(n).

Input: 10

Output:

```text
Enter n (0-93): 0 1 1 2 3 5 8 13 21 34 55
F(10) = 55
```

### Fibonacci (tabulation)

File: [03-fibonacci-tabulation.cpp](03-fibonacci-tabulation.cpp)

Starts from 0 and 1 and fills the array in order.

Time: O(n). Space: O(n).

Input: 10

Output:

```text
Enter n (0-93): 0 1 1 2 3 5 8 13 21 34 55
F(10) = 55
```

### Red-black tree

File: [04-red-black-tree.cpp](04-red-black-tree.cpp)

Insert, delete, search, inorder and tree display with node colors. In C++, delete is a keyword, so the function is called deleteKey.

Time: O(log n) for insert/delete/search. Space: O(n) tree storage.

Output:

```text
Inorder after insertion: 1 5 10 15 20 25 30 
Root: 20 (BLACK)
    L: 10 (RED)
        L: 5 (BLACK)
            L: 1 (RED)
        R: 15 (BLACK)
    R: 30 (BLACK)
        L: 25 (RED)
Search 15: true
Inorder after deleting 30 and 10: 1 5 15 20 25 
Root: 20 (BLACK)
    L: 5 (RED)
        L: 1 (BLACK)
        R: 15 (BLACK)
    R: 25 (BLACK)
Search 10: false
```

### Matrix chain multiplication

File: [05-matrix-chain-multiplication.cpp](05-matrix-chain-multiplication.cpp)

Fills the m and s tables and uses s to print the best order of multiplication.

Time: O(n³). Space: O(n²).

Dimensions: 30, 35, 15, 5, 10, 20, 25.

Output:

```text
m table (cost):
       0   15750    7875    9375   11875   15125
       -       0    2625    4375    7125   10500
       -       -       0     750    2500    5375
       -       -       -       0    1000    3500
       -       -       -       -       0    5000
       -       -       -       -       -       0
s table (split):
       -       1       1       3       3       3
       -       -       2       3       3       3
       -       -       -       3       3       3
       -       -       -       -       4       5
       -       -       -       -       -       5
       -       -       -       -       -       -
Minimum cost: 15125
Optimal parenthesization: ((A1 x (A2 x A3)) x ((A4 x A5) x A6))
```

### Longest common subsequence

File: [06-longest-common-subsequence.cpp](06-longest-common-subsequence.cpp)

Fills a DP table and backtracks to get the subsequence.

Time: O(mn). Space: O(mn).

Input: ABCBDAB and BDCABA (on separate lines).

Output:

```text
Enter X: Enter Y: LCS length: 4
LCS: BCBA
```

## Development notes

- Added AVL tree validation implementation.
- Added an unbalanced-tree check to the AVL example.
- Added kth-smallest lookup using augmented AVL nodes.
- Added top-down Fibonacci dynamic programming with memoization.
- Added bottom-up Fibonacci tabulation for comparison.
- Added a red-black tree with balanced insertion, deletion, and lookup.
- Documented the colored tree display used by the red-black tree example.
- Added matrix-chain multiplication with cost and split tables.
- Added LCS table construction and subsequence reconstruction.

