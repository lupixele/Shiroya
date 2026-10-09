# 07. Ranking and Sequence

> **Study guide:** theory and formulas follow the supplied slides; worked problems labeled **PPT** are adapted from the deck, while those labeled **additional** are teaching examples. The separate slide-reference file preserves all available on-slide text and inserted images.

## 1. Theory and formulas

### 1.1 Ranking from opposite ends
For the **same person**, with left rank L and right rank R:

**Total people N = L + R − 1**.

**Opposite rank = N − known rank + 1**. In a class, top/bottom works the same way.

### 1.2 Positions of two different people
Person A is Lth from left, person B is Rth from right, total N.

B's left position = **N−R+1**. Then **number strictly between = |(N−R+1)−L|−1**, provided these are different people.

Equivalent PPT cases: if L+R≤N (A before B), **between = N−(L+R)**; if L+R≥N+2 (B before A), **between = L+R−N−2**. If `L+R=N+1`, they occupy the *same* position—contradicting 'different people' unless a condition was misstated.

### 1.3 Maximum and minimum row size
For given ranks of different people and k people between them, **maximum size = L+R+k** (non-overlap) and **minimum size = L+R−k−2** (crossed positions), if positions remain valid.

### 1.4 Sequence and comparisons
Use `>` or `<` consistently: e.g. **D > C > A > B** if D taller than C, C taller than A and A taller than B. Only infer a comparison if a valid chain connects the two people.

### 1.5 Swapping places
After a swap, a person's **new rank is the other person's old rank from the same end**. Write named positions on the line rather than relying on a memorized formula.

## 2. Questions and answers
**Q1 (PPT).** Rohan is 7th from left and 14th from right. Total?
**Answer:** `7+14−1 = 20`.

**Q2 (PPT).** 40 students; Priya 15th from top. From bottom?
**Answer:** `40−15+1=26`.

**Q3 (PPT).** A taller than B but shorter than C, D taller than C. Tallest?
**Answer:** `D>C>A>B`; **D**.

**Q4 (PPT).** 30 people; X 5th from left, Y 10th from right. Between?
**Answer:** Y left=`30−10+1=21`; between=`21−5−1=15`.

**Q5 (PPT).** 21 people; person exactly in middle. Position from either end?
**Answer:** `(21+1)/2=11th`.

## 3. Tricks and tips
1. **Minus one** when the *same person* is counted from both ends.
2. **Convert both ranks to one direction** to avoid wrong overlap formulas.
3. Draw numbered slots when people exchange positions.
4. A tallest/shortest claim needs an inequality chain covering **everyone**.

## 4. Additional exam notes
If total size and ranks imply two people share a position, re-read the statement; do not force a negative answer.
