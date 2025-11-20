<div align="center">

# 🔙 Backtracking in C++
### *The Art of Trial, Error, and Smart Undo*

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-Backtracking-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/status-active-success?style=for-the-badge)

> *"Backtracking is like playing chess with an undo button - try a move, and if it doesn't work out, just go back and try something else!"*

</div>

---

## 🎯 What's Backtracking?

Imagine you're in a maze. You pick a path, walk down it, hit a dead end, then **backtrack** to the last intersection and try a different path. That's exactly what backtracking does in code!

**The Magic Formula:**
```
1. 🎲 CHOOSE - Make a decision
2. 🔍 EXPLORE - Recursively solve the rest
3. ⏪ UNCHOOSE - Undo your choice and try another
```

This pattern solves problems that need to explore **all possibilities** but does it smartly by abandoning dead ends early!

---

## 🗂️ What's Inside?

### 🎨 **Core Concepts** (`array.cpp`)
The simplest example that shows the backtracking pattern in action:
- Watch how we **modify** the array going forward
- Then **undo** those changes (`arr[i] -= 2`) coming backward
- Perfect for understanding the "unchoose" step!

### 🧩 **String Adventures** (`subset.cpp`)
Generate all possibilities from a string:
- **Subsets** - Every possible combination (include/exclude each char)
- **Permutations** - Every possible arrangement (order matters!)
- See how recursion branches into decision trees 🌳

### 🚶 **Grid Navigation** (`gridWays.cpp`)
How many ways can you reach the bottom-right corner?
- Only move **right** or **down**
- Classic dynamic programming setup
- Counts all possible paths through the grid

### 👑 **N-Queens Problem** (`nQueens.cpp`)
**THE** classic backtracking problem!

> *"Place N queens on an N×N chessboard so no queen can attack another"*

**Why it's legendary:**
- Must check horizontal, vertical, and **both diagonals**
- Each row can have exactly one queen
- Demonstrates pure backtracking: place queen → try next row → if stuck, backtrack!

**The Challenge:** For an 8×8 board, there are 4,426,165,368 ways to place 8 queens, but only **92 solutions** where no queen attacks another! Our algorithm finds them all without checking every possibility. 🧠

### 🎲 **Sudoku Solver** (`sudoku.cpp`)
**The ultimate backtracking showcase!**

Solves ANY 9×9 Sudoku puzzle automatically:
- Tries digits 1-9 in empty cells
- Checks row, column, and 3×3 box constraints
- Backtracks when a digit doesn't work
- **Guaranteed to find the solution** (if one exists!)

**Mind-blowing fact:** A typical Sudoku has ~10^21 possible number placements, but backtracking with constraint checking solves it in milliseconds! ⚡

---

## 📊 Complexity at a Glance

| Problem | Time Complexity | Space | Difficulty |
|---------|----------------|-------|------------|
| Array Backtrack | O(n) | O(n) | ⭐ Beginner |
| Subsets | O(2^n) | O(n) | ⭐⭐ Easy |
| Permutations | O(n!) | O(n) | ⭐⭐ Easy |
| Grid Ways | O(2^(m+n)) | O(m+n) | ⭐⭐ Medium |
| N-Queens | O(n!) | O(n²) | ⭐⭐⭐ Hard |
| Sudoku | O(9^(n*n)) 💀 | O(n²) | ⭐⭐⭐⭐ Expert |

---

## 🎓 The Backtracking Pattern

Every backtracking solution follows this template:

<table>
<tr>
<td align="center" width="33%">

### 1️⃣ Choose
**Make a decision**

Place a queen
Add a character
Pick a number

</td>
<td align="center" width="33%">

### 2️⃣ Explore
**Go deeper**

Recurse to next row
Try next position
Solve remaining cells

</td>
<td align="center" width="33%">

### 3️⃣ Unchoose
**Undo & try again**

Remove the queen
Backtrack the choice
Reset the cell to 0

</td>
</tr>
</table>

Look for this pattern in every file - it's **always there**!

---

## 🔥 Why These Problems Matter

### 💼 **Interview Gold**
- N-Queens appears in **Google, Facebook, Amazon** interviews
- Sudoku solver shows you can handle complex constraint problems
- Demonstrates algorithmic thinking, not just coding

### 🧠 **Brain Training**
- Teaches you to think recursively
- Shows how to prune search spaces efficiently
- Perfect for understanding **state space exploration**

### 🎯 **Real Applications**
- **Game AI** - Chess engines use advanced backtracking
- **Constraint Satisfaction** - Scheduling, resource allocation
- **Puzzles & Games** - Crosswords, map coloring, logic puzzles

---

## 💡 Pro Tips

### ✅ **DO:**
- **Draw the recursion tree** on paper first
- Start with the base case (when to stop?)
- Think: "What's my choice at each step?"
- Remember to **UNDO** your changes!

### ❌ **DON'T:**
- Forget to backtrack (undo your choice)
- Make your problem bigger with each recursion
- Try to optimize before it works
- Give up when it gets confusing (that's the fun part!)

### 🎨 **Visualization Tip:**
Add `print()` statements at each step to see the backtracking in action:
```cpp
// Before choosing
cout << "Trying position " << i << endl;
board[i][j] = 'Q';

// After exploring
board[i][j] = '-';  // Backtrack!
cout << "Backtracked from " << i << endl;
```

---

## 🚀 Quick Start

```bash
# Compile any file
g++ -o solver nQueens.cpp

# Watch the magic happen
./solver

# For Sudoku - see it solve the puzzle!
g++ -o sudoku sudoku.cpp
./sudoku
```

---

## 🎮 Challenge Yourself

Once you understand these:

1. **Modify N-Queens** to count solutions instead of printing them
2. **Add visualization** to Sudoku solver (print board at each step)
3. **Solve these classics:**
   - Rat in a Maze
   - Knight's Tour Problem
   - Graph Coloring
   - Word Search in a Grid

---

## 🌟 Learning Path

```
Start Here → Array Backtracking → Subsets/Permutations
                                        ↓
                                   Grid Ways
                                        ↓
                                    N-Queens ← Practice Here!
                                        ↓
                                Sudoku Solver ← Master This!
```

---

## 🎯 Perfect For:

- 🎓 **CS Students** learning algorithms
- 💼 **Interview Prep** - these problems come up frequently!
- 🧩 **Puzzle Lovers** who want to automate solving
- 🤖 **Anyone** interested in AI and search algorithms

---

## 🔍 Deep Dive: How N-Queens Works

**The Board:** A 4×4 grid for 4 queens (scales to any N×N)

**The Strategy:**
1. Start at row 0, try placing queen in each column
2. For each placement, check if it's safe (no attacks)
3. If safe → place queen → move to next row
4. If reach last row with all queens placed → **Solution found!** 🎉
5. If stuck → **backtrack** → remove queen → try next column

**The Safety Check:**
- No other queen in same row ✓
- No other queen in same column ✓
- No other queen in diagonal-left ✓
- No other queen in diagonal-right ✓

---

## 🎲 Deep Dive: Sudoku Solver Magic

**The Puzzle:** Fill 9×9 grid with digits 1-9

**The Rules:**
- Each **row** must have 1-9 (no repeats)
- Each **column** must have 1-9 (no repeats)
- Each **3×3 box** must have 1-9 (no repeats)

**The Algorithm:**
1. Scan for empty cell (marked as 0)
2. Try digits 1-9
3. For each digit, check if safe (row, column, box)
4. If safe → place digit → solve rest of puzzle
5. If solved → **Done!** 🎊
6. If stuck → **backtrack** → try next digit

**Why it's fast:**
- Skips filled cells
- Fails fast when digit violates constraints
- Prunes millions of invalid combinations

---

<div align="center">

### 💭 *"The best way to learn backtracking is to trace through the recursion tree with pen and paper!"* 💭

<br>

[![Made with Love](https://img.shields.io/badge/Made%20with-💖-ff69b4?style=for-the-badge)](https://github.com)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=for-the-badge)](http://makeapullrequest.com)

<br>

**Stuck on a problem? Found a bug? Got a cool backtracking solution?**

*Pull requests and issues are always welcome!*

<br>

### ⭐ **Star this repo if backtracking blows your mind!** ⭐

<br>

<sub>Built with 🔥 for puzzle lovers and algorithm enthusiasts</sub>

</div>
