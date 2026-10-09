# 05. Permutations and Combinations

> **Study guide:** theory and formulas follow the supplied slides; worked problems labeled **PPT** are adapted from the deck, while those labeled **additional** are teaching examples. The separate slide-reference file preserves all available on-slide text and inserted images.

## 1. Theory and formulas

### 1.1 Factorials
**n! = n×(n−1)×...×1**. Also, **0! = 1**.

### 1.2 Permutations: order matters
- **nPr = n!/(n−r)!** for selecting and arranging r distinct objects from n.
- Arrangements of all n different objects: **n!**.
- With repeated indistinguishable letters: **n!/(a!b!...)**.
- If each of r slots can use n options independently and reuse is allowed: **n^r**.

### 1.3 Combinations: order does not matter
- **nCr = n!/[r!(n−r)!]**.
- **nCr = nC(n−r)**; **nPr = nCr × r!**.
- **nC0 = nCn = 1**, **nC1 = n**.
- **nCr + nC(r−1) = (n+1)Cr** (Pascal identity).
- Selecting r objects from n types with repetitions permitted: **(n+r−1)Cr**.

### 1.4 Together / separate, and circular arrangements
- When specific letters or people must stay together, **treat the group as one block** and multiply by arrangements inside the block.
- Circular distinct-person arrangements: **(n−1)!** when rotations are identical.
- If reflections are also equivalent (e.g. an unmarked necklace), **(n−1)!/2** for n > 2.

## 2. Questions and answers
**Q1 (PPT).** Find 50P2.
**Answer:** `50×49=2450`.

**Q2 (PPT).** Arrange RUBBER.
**Answer:** Six letters; R twice, B twice; `6!/(2!×2!)=180`.

**Q3 (PPT).** Arrange LEADING with vowels always together.
**Answer:** EAI as one block + four consonants = five objects, arranged `5!`; vowels inside block `3!`. **5!×3!=720**.

**Q4 (PPT).** Arrange CYCLE.
**Answer:** Five letters with C repeated twice; `5!/2!=60`.

**Q5 (additional).** Select 3 students from 8 students.
**Answer:** `8C3=8×7×6/(3×2×1)=56`; the order of selected students does not matter.

**Q6 (additional).** Assign president, secretary and treasurer from 8 students.
**Answer:** `8P3=8×7×6=336`; offices differ, so order matters.

**Q7 (PPT style).** 5 people around a circular table?
**Answer:** `(5−1)!=24` arrangements up to rotation.

## 3. Tricks and tips
1. **Selection = combination**; **arranging/assigning roles = permutation**.
2. Cancel factorials before multiplying; e.g. `10P3=10×9×8`.
3. Repeated letters? Divide by each repeated-letter factorial.
4. Together means block; apart often means **total minus together**.

## 4. Additional exam notes
For seat positions in a line, left and right ends are distinct; for a round table, rotations are not distinct. Do not divide circular permutations by 2 unless reversed arrangements are explicitly treated as identical.
