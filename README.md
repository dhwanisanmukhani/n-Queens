# n-Queens Puzzle

This puzzles involves placing n chess queens on an nxn chess board. There is at least one solution for n>=4. I have solved this puzzle as a part of an AI project.

# Solution

## Modeling it as 'search' problem (good for n<=12)

A very naive state space can be modelled as placing each queen on any square i.e (nxn)^n states. This can be improved if we place single queen per row - n^n states. Now, the goal state is such that no two queens attach each other.

We can solve this problem with:
- uninformed search algorithms like DFS, BFS, Best first search
- informed search algorithms with simple heuristics

## Modeling it as 'optimization' problem (good for larger n)

Optimization function = number of pair of Queens attacking each other.
Our goal is to minimize the optimization function over the state space.

I have solved this using 'Hill Climbing search with Random Restarts'. We randomly initialize the initial state. At each step, we calculate function over all neighbouring states and choose the state with minimum value. This stops at local minima, but if we run this algorithm with randomly initialized states, we would converge to global minima at some point.
