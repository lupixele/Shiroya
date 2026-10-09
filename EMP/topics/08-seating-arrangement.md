# 08. Seating Arrangement

> **Study guide:** theory and formulas follow the supplied slides; worked problems labeled **PPT** are adapted from the deck, while those labeled **additional** are teaching examples. The separate slide-reference file preserves all available on-slide text and inserted images.

## 1. Theory and formulas

### 1.1 Linear arrangement
Represent positions as numbered boxes from **your chosen left to right**. Carefully note which way a person is **facing**. 'Next to' means adjacent; 'to the right' does **not necessarily** mean immediate right.

### 1.2 Double-row arrangements
Draw two rows with arrows for facing direction. If the two rows face each other, **a person's own right** is opposite to the right of a person facing the other direction.

### 1.3 Circular seating
Fix one person to remove rotational duplicates. For people **facing center**:

**Right = anticlockwise; left = clockwise**.

For people **facing away from center**:

**Right = clockwise; left = anticlockwise**.

### 1.4 Rectangular seating
Separate corner seats from side seats, and track whether a person faces the center or outward; their own left/right changes accordingly.

## 2. Questions and answers
**Q1 (PPT).** A, P, R, X, S, Z in a row; S and Z in center; Z not next to X; A and P at ends; R immediately left of A.
**Answer:** One arrangement shown in PPT: `P – X – S – Z – R – A` (left to right). Immediate right of P = **X**. Fourth to left of A = **X**. Extreme right = **A**.

**Q2 (additional).** Five people A,B,C,D,E sit in a row. A at left end; B immediately right of A; E at right end; D immediately left of E; who is in the middle?
**Answer:** `A B C D E`; **C**.

**Q3 (additional).** Six people face the center at a circular table. Starting from A and going clockwise: A,B,C,D,E,F. Who is immediately to A's right?
**Answer:** right while facing center is anticlockwise, so **F**.

**Q4 (PPT type).** If 'B is next to A', can you place B definitely on A's right?
**Answer:** **No**. B may be immediately left or right of A.

## 3. Tricks and tips
1. **Anchor the certain clues** first: ends, center, immediate neighbor, opposite.
2. Make only a few candidate layouts; cross out any breaking a condition.
3. For circles, mark **↻ CW** and **↺ ACW** once, then use the facing rule.
4. Never assume 'right' means 'immediate right'.

## 4. Additional exam notes
For multi-question seating sets, **reuse the solved layout** for all subquestions. If a clue names a person not in the original group (one PPT box puzzle has such a mismatch), treat the question as a possible source typo, not a valid extra person.
