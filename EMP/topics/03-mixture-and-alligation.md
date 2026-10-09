# 03. Mixture and Alligation

A comprehensive guide to Mixture and Alligation principles, formulas, derivation methods, and solved exam problems.

---

## 1. Comprehensive Theory and Formulas

### 1.1 Fundamental Concepts

- **Mixture:** A combination of two or more ingredients in varying proportions.
- **Alligation:** An arithmetic method that enables us to find the ratio in which two or more ingredients at given prices (or concentrations, rates, percentages) must be mixed to produce a mixture of a desired mean price (or concentration).
- **Mean Price / Weighted Mean:** The cost price per unit quantity of the mixture produced by combining two or more ingredients.

---

### 1.2 The Weighted Average Principle

When quantity $q_1$ of an ingredient with value $v_1$ is combined with quantity $q_2$ of an ingredient with value $v_2$, the average value $M$ of the mixture is given by:

$$M = \frac{q_1 v_1 + q_2 v_2}{q_1 + q_2}$$

Rearranging this equation:

$$M(q_1 + q_2) = q_1 v_1 + q_2 v_2$$
$$q_1(M - v_1) = q_2(v_2 - M)$$
$$\frac{q_1}{q_2} = \frac{v_2 - M}{M - v_1}$$

This direct algebraic derivation forms the core foundation of the **Rule of Alligation**.

---

### 1.3 The Rule of Alligation (Cross Rule)

Let:
- $c$ = Price / Value / Concentration of the Cheaper / Lower ingredient
- $d$ = Price / Value / Concentration of the Dearer / Higher ingredient
- $m$ = Mean Price / Desired average value of the mixture ($c < m < d$)

The ratio of quantities is:

$$\frac{\text{Quantity of Cheaper } (q_c)}{\text{Quantity of Dearer } (q_d)} = \frac{d - m}{m - c}$$

#### Cross-Diagram Representation

```
      Cheaper Value (c)             Dearer Value (d)
              \                           /
               \                         /
                Mean Value / Price (m)
               /                         \
              /                           \
        (d - m)             :           (m - c)
   [Quantity of Cheaper]             [Quantity of Dearer]
```

$$\frac{q_c}{q_d} = \frac{d - m}{m - c}$$

---

### 1.4 Crucial Rules for Applying Alligation

1. **Units Consistency:**
   All values ($c$, $d$, $m$) must be expressed in the exact same physical units and reference framework:
   - If using Cost Price, all three must be Cost Prices (never mix Cost Price with Selling Price).
   - If using concentration of milk, all three values must represent the concentration of milk (not milk for one and water for another).
2. **The "Rate Base" Rule (Denominator Principle):**
   The alligation ratio always gives the ratio of the quantities in the **denominator** of the rate:
   - Price per kg (₹/kg) $\rightarrow$ ratio of **weights** (in kg).
   - Speed in km/h $\rightarrow$ ratio of **time** (in hours).
   - Marks per student $\rightarrow$ ratio of **number of students**.
   - Profit % (Profit/CP $\times 100$) $\rightarrow$ ratio of **Cost Prices**.
   - Percentage concentration (Solute/Total Volume) $\rightarrow$ ratio of **Volumes/Total quantities**.
3. **Selling Price with Profit/Loss:**
   When selling price ($SP$) and profit percentage ($P\%$) or loss percentage ($L\%$) of the mixture are given:
   $$\text{Mean Cost Price } (CP_m) = \frac{SP}{1 + \frac{P}{100}} \quad \text{or} \quad CP_m = \frac{SP}{1 - \frac{L}{100}}$$
   *Always calculate $CP_m$ before applying the Alligation cross diagram.*
4. **Adding Pure Substances or Solvents:**
   - Adding pure water (as a diluent to wine/milk): Cost price of water = ₹0/L; concentration of solute = 0%.
   - Adding pure solute/chemical: Concentration = 100%.

---

### 1.5 Repeated Dilution / Replacement Formula

If a container initially holds $C$ units of pure liquid, and $x$ units of liquid are drawn out and replaced with water, and this operation is repeated for a total of $n$ times:

1. **Remaining quantity of pure liquid:**
   $$\text{Remaining Liquid} = C \left(1 - \frac{x}{C}\right)^n$$

2. **Fraction of pure liquid left in the vessel:**
   $$\frac{\text{Remaining Pure Liquid}}{\text{Total Capacity } C} = \left(1 - \frac{x}{C}\right)^n$$

3. **Ratio of Pure Liquid to Added Liquid (Water):**
   $$\frac{\text{Liquid}}{\text{Water}} = \frac{\left(1 - \frac{x}{C}\right)^n}{1 - \left(1 - \frac{x}{C}\right)^n}$$

---

### 1.6 Invariant / Constant Component Method

When an ingredient (water, solvent, or dry matter) is added or evaporated:
$$\text{Initial Total} \times \text{Initial } \% \text{ of constant component} = \text{Final Total} \times \text{Final } \% \text{ of constant component}$$
- For fresh vs. dry fruit: The **pulp (dry matter)** remains constant while water evaporates.
- For dilution: The **pure solute** remains constant while water is added.

---

## 2. Solved Problems

### Q1
**Question:**
The average weight of 30 students of a class is 45 kg. The average weight of girls is 37 kg, and that of boys is 49 kg. Find the number of boys in the class.

- a) 10
- b) 15
- c) 20
- d) 22

**Correct Option:** **c) 20**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Let the number of boys be $b$, and the number of girls be $g = 30 - b$.
- Total weight of all 30 students $= 30 \times 45 = 1350\text{ kg}$.
- Total weight of girls $= 37g = 37(30 - b) = 1110 - 37b$.
- Total weight of boys $= 49b$.
- Equating total weights:
  $$1110 - 37b + 49b = 1350$$
  $$12b = 1350 - 1110 = 240$$
  $$b = \frac{240}{12} = 20$$
- Therefore, the number of boys in the class is **20**.

##### Method 2: Alligation Cross Rule
- Mean average weight $= 45\text{ kg}$
- Average weight of girls ($c$) $= 37\text{ kg}$
- Average weight of boys ($d$) $= 49\text{ kg}$

$$\begin{array}{ccc}
\text{Girls (37)} & & \text{Boys (49)} \\
& \searrow \swarrow & \\
& \text{Mean (45)} & \\
\swarrow & & \searrow \\
(49 - 45) = 4 & : & (45 - 37) = 8
\end{array}$$

- Ratio of Girls : Boys $= 4 : 8 = 1 : 2$.
- Total parts $= 1 + 2 = 3$ parts.
- Number of boys $= \frac{2}{3} \times 30 = 20$.

##### Shortcut / Quick Exam Trick
$$\text{Ratio of Boys} = \frac{\text{Mean} - \text{Girls}}{\text{Boys} - \text{Girls}} = \frac{45 - 37}{49 - 37} = \frac{8}{12} = \frac{2}{3}$$
$$\text{Number of boys} = 30 \times \frac{2}{3} = 20$$

### Q2
**Question:**
How many kilograms of sugar costing ₹ 9 per kg must be mixed with 27 kg of sugar costing ₹ 7 per kg so that there may be a gain of 10% by selling the mixture at ₹ 9.24 per kg?

- a) 60 kg
- b) 63 kg
- c) 58 kg
- d) 56 kg

**Correct Option:** **b) 63 kg**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Selling Price of mixture ($SP_m$) $= ₹ 9.24\text{ per kg}$ with a profit of $10\%$.
- Cost Price of mixture ($CP_m$):
  $$CP_m = \frac{SP_m}{1 + \frac{\text{Profit}\%}{100}} = \frac{9.24}{1.10} = ₹ 8.40\text{ per kg}$$
- Let $x$ kg of sugar costing ₹ 9/kg be mixed with 27 kg of sugar costing ₹ 7/kg.
- Total cost $= 9x + 7(27) = 9x + 189$.
- Total weight $= x + 27$.
- Average cost price:
  $$\frac{9x + 189}{x + 27} = 8.40$$
  $$9x + 189 = 8.40x + 226.8$$
  $$0.60x = 37.8$$
  $$x = \frac{37.8}{0.60} = 63\text{ kg}$$

##### Method 2: Alligation Cross Rule
- Cheaper sugar price ($c$) $= ₹ 7\text{/kg}$
- Dearer sugar price ($d$) $= ₹ 9\text{/kg}$
- Mean price ($m$) $= ₹ 8.40\text{/kg}$

$$\begin{array}{ccc}
\text{Dearer Sugar (₹9)} & & \text{Cheaper Sugar (₹7)} \\
& \searrow \swarrow & \\
& \text{Mean (₹8.40)} & \\
\swarrow & & \searrow \\
(8.40 - 7) = 1.40 & : & (9 - 8.40) = 0.60
\end{array}$$

- Ratio of Dearer ($q_1$) : Cheaper ($q_2$) $= 1.40 : 0.60 = 7 : 3$.
- Given $q_2 = 27\text{ kg}$ (corresponds to 3 parts).
- $1\text{ part} = \frac{27}{3} = 9\text{ kg}$.
- Quantity of dearer sugar ($q_1$) $= 7 \times 9 = 63\text{ kg}$.

##### Shortcut / Quick Exam Trick
- Find $CP_m = 9.24 / 1.1 = 8.40$.
- Difference with ₹7 is $1.4$, difference with ₹9 is $0.6$.
- Ratio $= 14 : 6 = 7 : 3$. Since 3 parts $= 27\text{ kg}$, 7 parts $= 7 \times 9 = 63\text{ kg}$.

### Q3
**Question:**
A merchant sells 50 kg of a commodity—partly at 10% profit and the rest at 15% profit. If profit in the deal is 13%, then the quantity sold at 10% profit is :

- a) 20 kg
- b) 25 kg
- c) 30 kg
- d) 40 kg

**Correct Option:** **a) 20 kg**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Let the quantity sold at $10\%$ profit be $x$ kg.
- Quantity sold at $15\%$ profit $= 50 - x$ kg.
- Overall profit percentage is $13\%$ on 50 kg:
  $$10(x) + 15(50 - x) = 13(50)$$
  $$10x + 750 - 15x = 650$$
  $$5x = 100 \implies x = 20\text{ kg}$$

##### Method 2: Alligation Cross Rule
- Profit 1 $= 10\%$
- Profit 2 $= 15\%$
- Mean Profit $= 13\%$

$$\begin{array}{ccc}
\text{Part 1 (10\%)} & & \text{Part 2 (15\%)} \\
& \searrow \swarrow & \\
& \text{Mean (13\%)} & \\
\swarrow & & \searrow \\
(15 - 13) = 2 & : & (13 - 10) = 3
\end{array}$$

- Ratio of quantity at $10\%$ profit to quantity at $15\%$ profit $= 2 : 3$.
- Total parts $= 2 + 3 = 5$.
- Quantity sold at $10\%$ profit $= \frac{2}{5} \times 50 = 20\text{ kg}$.

##### Shortcut / Quick Exam Trick
- Cross differences: $|13 - 15| = 2$ parts; $|13 - 10| = 3$ parts.
- Fraction at $10\% = \frac{2}{2+3} = \frac{2}{5}$.
- $50 \times \frac{2}{5} = 20\text{ kg}$.

### Q4
**Question:**
A merchant mixes two varieties of wine containing 25% and 13% alcohol. The resultant mixture contains 17% alcohol. Find the quantity of second mixture, if 8 litre of first mixture is taken.

- a) 4 litres
- b) 16 litres
- c) 24 litres
- d) 32 litres

**Correct Option:** **b) 16 litres**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- First mixture: volume $= 8\text{ litres}$, alcohol concentration $= 25\%$.
- Alcohol from first mixture $= 8 \times 0.25 = 2\text{ litres}$.
- Let the volume of the second mixture be $y$ litres (alcohol concentration $= 13\%$).
- Alcohol from second mixture $= 0.13y\text{ litres}$.
- Total volume $= 8 + y$.
- Concentration of resultant mixture is $17\%$:
  $$\frac{2 + 0.13y}{8 + y} = 0.17$$
  $$2 + 0.13y = 0.17(8 + y) = 1.36 + 0.17y$$
  $$0.04y = 0.64 \implies y = \frac{0.64}{0.04} = 16\text{ litres}$$

##### Method 2: Alligation Cross Rule
- Variety 1 alcohol $= 25\%$
- Variety 2 alcohol $= 13\%$
- Mean alcohol $= 17\%$

$$\begin{array}{ccc}
\text{Variety 1 (25\%)} & & \text{Variety 2 (13\%)} \\
& \searrow \swarrow & \\
& \text{Mean (17\%)} & \\
\swarrow & & \searrow \\
(17 - 13) = 4 & : & (25 - 17) = 8
\end{array}$$

- Ratio of Variety 1 : Variety 2 $= 4 : 8 = 1 : 2$.
- Quantity of Variety 1 $= 8\text{ litres}$ (corresponds to 1 part).
- Quantity of Variety 2 $= 8 \times 2 = 16\text{ litres}$.

##### Shortcut / Quick Exam Trick
- Ratio $= (17 - 13) : (25 - 17) = 4 : 8 = 1 : 2$.
- Volume 2 is double Volume 1: $2 \times 8 = 16\text{ litres}$.

### Q5
**Question:**
A 20-litre mixture contains 30% alcohol and 70% water. If 5 litres of water is added to the mixture, what will be the percentage of alcohol in the new mixture?

- a) 22%
- b) 23%
- c) 24%
- d) 25%

**Correct Option:** **c) 24%**

---

#### Detailed Mathematical Explanation

##### Method 1: Constant Solute Method
- Initial volume of mixture $= 20\text{ litres}$.
- Initial alcohol content $= 30\% \text{ of } 20 = 20 \times 0.30 = 6\text{ litres}$.
- Pure water added $= 5\text{ litres}$.
- New total volume $= 20 + 5 = 25\text{ litres}$.
- Since only water is added, the absolute quantity of alcohol remains unchanged at $6\text{ litres}$.
- New alcohol percentage:
  $$\text{New } \% = \frac{\text{Quantity of Alcohol}}{\text{New Total Volume}} \times 100 = \frac{6}{25} \times 100 = 24\%$$

##### Method 2: Inverse Proportionality / Dilution Formula
- Since solute is constant:
  $$C_1 V_1 = C_2 V_2$$
  $$30\% \times 20 = C_2 \times 25$$
  $$C_2 = \frac{30 \times 20}{25} = \frac{600}{25} = 24\%$$

##### Method 3: Alligation Cross Rule
- Existing mixture alcohol $= 30\%$, volume $= 20\text{ L}$.
- Pure water alcohol $= 0\%$, volume $= 5\text{ L}$.
- Let mean alcohol be $m\%$.
- Ratio of volumes $= 20 : 5 = 4 : 1$.
- By alligation: $\frac{m - 0}{30 - m} = \frac{4}{1} \implies m = 4(30 - m) \implies 5m = 120 \implies m = 24\%$.

##### Shortcut / Quick Exam Trick
- Volume increases in ratio $20 : 25 = 4 : 5$.
- Concentration decreases in inverse ratio $5 : 4$.
- New concentration $= 30\% \times \frac{4}{5} = 24\%$.

### Q6
**Question:**
The wheat sold by a grocer contained 10% low quality wheat. What quantity of good quality wheat should be added to 150 kgs of wheat so that the percentage of low-quality wheat becomes 5%?

- a) 150 kgs
- b) 135 kgs
- c) 50 kgs
- d) 85 kgs

**Correct Option:** **a) 150 kgs**

---

#### Detailed Mathematical Explanation

##### Method 1: Constant Low-Quality Component Method
- Initial quantity of wheat $= 150\text{ kg}$.
- Low-quality wheat content $= 10\% \text{ of } 150 = 15\text{ kg}$.
- Let the quantity of good quality wheat added be $x$ kg.
- Good wheat contains $0\%$ low-quality wheat, so the mass of low-quality wheat remains $15\text{ kg}$.
- New total quantity $= 150 + x\text{ kg}$.
- Low-quality wheat must now constitute $5\%$ of total:
  $$\frac{15}{150 + x} = \frac{5}{100} = \frac{1}{20}$$
  $$150 + x = 15 \times 20 = 300$$
  $$x = 300 - 150 = 150\text{ kg}$$

##### Method 2: Alligation Cross Rule (on Low-Quality Wheat %)
- Initial wheat: $10\%$ low-quality wheat, quantity $= 150\text{ kg}$.
- Added wheat: $0\%$ low-quality wheat (pure good quality), quantity $= x\text{ kg}$.
- Desired mean: $5\%$ low-quality wheat.

$$\begin{array}{ccc}
\text{Initial Wheat (10\%)} & & \text{Good Wheat Added (0\%)} \\
& \searrow \swarrow & \\
& \text{Mean (5\%)} & \\
\swarrow & & \searrow \\
(5 - 0) = 5 & : & (10 - 5) = 5
\end{array}$$

- Ratio of Initial : Added $= 5 : 5 = 1 : 1$.
- Since Initial wheat is $150\text{ kg}$, Added good wheat must be $150\text{ kg}$.

##### Shortcut / Quick Exam Trick
- Low-quality wheat is halved (from $10\%$ to $5\%$).
- Halving the concentration requires doubling the total mixture mass ($150\text{ kg} \rightarrow 300\text{ kg}$).
- Wheat to be added $= 300 - 150 = 150\text{ kg}$.

### Q7
**Question:**
In a mixture of one kind, pure milk is 70%. In another pure milk is 60%. If they are mixed in the ratio 3 : 2, how much is the percentage of pure milk in the new mixture?

- a) 65%
- b) 74%
- c) 66%
- d) 67%

**Correct Option:** **c) 66%**

---

#### Detailed Mathematical Explanation

##### Method 1: Weighted Average Formula
- First mixture: milk concentration $c_1 = 70\%$, ratio weight $q_1 = 3$.
- Second mixture: milk concentration $c_2 = 60\%$, ratio weight $q_2 = 2$.
- Resultant milk concentration:
  $$M = \frac{q_1 c_1 + q_2 c_2}{q_1 + q_2} = \frac{3(70) + 2(60)}{3 + 2} = \frac{210 + 120}{5} = \frac{330}{5} = 66\%$$

##### Method 2: Alligation Cross Diagram
- Let the mean percentage be $m\%$.
- Ingredients: $70\%$ and $60\%$.
- Ratio of quantities $= 3 : 2$.

$$\begin{array}{ccc}
\text{Mixture 1 (70\%)} & & \text{Mixture 2 (60\%)} \\
& \searrow \swarrow & \\
& \text{Mean } m & \\
\swarrow & & \searrow \\
(m - 60) & : & (70 - m)
\end{array}$$

- Equating to given ratio:
  $$\frac{m - 60}{70 - m} = \frac{3}{2}$$
  $$2(m - 60) = 3(70 - m)$$
  $$2m - 120 = 210 - 3m$$
  $$5m = 330 \implies m = 66\%$$

##### Shortcut / Quick Exam Trick
- Total distance between percentages $= 70 - 60 = 10\%$.
- Divide the distance of $10\%$ in the inverse ratio of quantities ($2 : 3$, total 5 parts).
- $1\text{ part} = \frac{10}{5} = 2\%$.
- Shift from $60\%$ toward $70\%$: $60\% + 3 \times 2\% = 66\%$ (or $70\% - 2 \times 2\% = 66\%$).

### Q8
**Question:**
A mixture of 70 litres of wine and water contains 10% water. How much more water should be added to the mixture to make 37% water in the resulting mixture?

- a) 37 litres
- b) 30 litres
- c) 27 litres
- d) 18.9 litres

**Correct Option:** **b) 30 litres**

---

#### Detailed Mathematical Explanation

##### Method 1: Constant Wine (Solute) Method
- Initial total volume $= 70\text{ litres}$.
- Initial water content $= 10\% \implies$ Initial wine content $= 90\%$.
- Volume of wine $= 70 \times 0.90 = 63\text{ litres}$.
- When pure water is added, the volume of wine remains constant at $63\text{ litres}$.
- In the resulting mixture, water is $37\% \implies$ Wine is $100\% - 37\% = 63\%$.
- Let new total volume be $V$.
  $$63\% \text{ of } V = 63\text{ litres}$$
  $$\frac{63}{100} \times V = 63 \implies V = 100\text{ litres}$$
- Water to be added $= \text{New Total} - \text{Initial Total} = 100 - 70 = 30\text{ litres}$.

##### Method 2: Alligation Cross Rule (on Water %)
- Initial mixture: $10\%$ water, volume $= 70\text{ litres}$.
- Added component: Pure water $= 100\%$ water, volume $= x\text{ litres}$.
- Mean target: $37\%$ water.

$$\begin{array}{ccc}
\text{Initial Mixture (10\%)} & & \text{Pure Water Added (100\%)} \\
& \searrow \swarrow & \\
& \text{Mean (37\%)} & \\
\swarrow & & \searrow \\
(100 - 37) = 63 & : & (37 - 10) = 27
\end{array}$$

- Ratio $= 63 : 27 = 7 : 3$.
- 7 parts corresponds to $70\text{ litres}$ (initial mixture).
- 1 part $= 10\text{ litres}$.
- Pure water added (3 parts) $= 3 \times 10 = 30\text{ litres}$.

##### Shortcut / Quick Exam Trick
- Wine is $90\%$ of $70 = 63\text{ L}$.
- Final wine percentage is $100 - 37 = 63\%$.
- If $63\% = 63\text{ L}$, then $100\% = 100\text{ L}$.
- Water added $= 100 - 70 = 30\text{ litres}$.

### Q9
**Question:**
In a town, the population was 8000. In one-year, male population increased by 10% and female population increased by 8%, but the total population increased by 9%. The number of males in the town was:

- a) 4000
- b) 4500
- c) 5000
- d) 6000

**Correct Option:** **a) 4000**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Let the initial number of males be $M$, and females be $F = 8000 - M$.
- Increase in males $= 10\% \text{ of } M = 0.10M$.
- Increase in females $= 8\% \text{ of } (8000 - M) = 0.08(8000 - M) = 640 - 0.08M$.
- Total increase $= 9\% \text{ of } 8000 = 720$.
- Setting up the equation:
  $$0.10M + 640 - 0.08M = 720$$
  $$0.02M = 720 - 640 = 80$$
  $$M = \frac{80}{0.02} = 4000$$

##### Method 2: Alligation Cross Rule
- Rate of male increase $= 10\%$
- Rate of female increase $= 8\%$
- Overall average rate of increase $= 9\%$

$$\begin{array}{ccc}
\text{Males (10\%)} & & \text{Females (8\%)} \\
& \searrow \swarrow & \\
& \text{Mean (9\%)} & \\
\swarrow & & \searrow \\
(9 - 8) = 1 & : & (10 - 9) = 1
\end{array}$$

- Ratio of Males : Females $= 1 : 1$.
- Total population $= 8000$.
- Initial number of males $= \frac{1}{1 + 1} \times 8000 = 4000$.

##### Shortcut / Quick Exam Trick
- Since $9\%$ is the exact midpoint between $8\%$ and $10\%$, males and females must be in equal numbers ($1:1$).
- Number of males $= \frac{8000}{2} = 4000$.

### Q10
**Question:**
In what ratio must tea worth ₹ 60 per kg be mixed with tea worth ₹ 65 a kg such that by selling the mixture at ₹ 68.20 a kg, there can be a gain of 10%?

- a) 3 : 2
- b) 2 : 3
- c) 4 : 3
- d) 3 : 4

**Correct Option:** **a) 3 : 2**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Cost Price & Equation Method
- Selling price of mixture ($SP_m$) $= ₹ 68.20\text{/kg}$ with $10\%$ profit.
- Mean Cost Price ($CP_m$):
  $$CP_m = \frac{SP_m}{1 + \frac{\text{Profit}\%}{100}} = \frac{68.20}{1.10} = ₹ 62\text{/kg}$$
- Let ratio of ₹ 60 tea to ₹ 65 tea be $x : y$.
- Average cost price:
  $$\frac{60x + 65y}{x + y} = 62$$
  $$60x + 65y = 62x + 62y$$
  $$65y - 62y = 62x - 60x$$
  $$3y = 2x \implies \frac{x}{y} = \frac{3}{2}$$

##### Method 2: Alligation Cross Rule
- Price of cheaper tea ($c$) $= ₹ 60$
- Price of dearer tea ($d$) $= ₹ 65$
- Mean cost price ($m$) $= ₹ 62$

$$\begin{array}{ccc}
\text{Cheaper (₹60)} & & \text{Dearer (₹65)} \\
& \searrow \swarrow & \\
& \text{Mean (₹62)} & \\
\swarrow & & \searrow \\
(65 - 62) = 3 & : & (62 - 60) = 2
\end{array}$$

- Ratio of Cheaper : Dearer $= 3 : 2$.

##### Shortcut / Quick Exam Trick
- Find $CP_m = 68.2 / 1.1 = 62$.
- Cross subtraction: $(65 - 62) : (62 - 60) = 3 : 2$.

### Q11
**Question:**
The average of the test scores of a class of $m$ students is 70 and that of $n$ students is 91. When the score of both the classes is combined, the average is 80. What is $n/m$?

- a) 10/13
- b) 10/11
- c) 11/10
- d) 13/10

**Correct Option:** **b) 10/11**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Average Formula
- Total score of $m$ students $= 70m$.
- Total score of $n$ students $= 91n$.
- Combined total score $= 70m + 91n$.
- Combined number of students $= m + n$.
- Given combined average $= 80$:
  $$\frac{70m + 91n}{m + n} = 80$$
  $$70m + 91n = 80(m + n) = 80m + 80n$$
  $$91n - 80n = 80m - 70m$$
  $$11n = 10m \implies \frac{n}{m} = \frac{10}{11}$$

##### Method 2: Alligation Cross Rule
- Score of class $m$ $= 70$
- Score of class $n$ $= 91$
- Combined average $= 80$

$$\begin{array}{ccc}
\text{Class } m \text{ (70)} & & \text{Class } n \text{ (91)} \\
& \searrow \swarrow & \\
& \text{Mean (80)} & \\
\swarrow & & \searrow \\
(91 - 80) = 11 & : & (80 - 70) = 10
\end{array}$$

- Ratio of $m : n = 11 : 10$.
- Inverting to find $\frac{n}{m}$:
  $$\frac{n}{m} = \frac{10}{11}$$

##### Shortcut / Quick Exam Trick
- $\frac{n}{m} = \frac{\text{Mean} - \text{Score}_m}{\text{Score}_n - \text{Mean}} = \frac{80 - 70}{91 - 80} = \frac{10}{11}$.

### Q12
**Question:**
The average of marks scored by the students of a class is 68. The average of marks of the girls in the class is 80 and that of boys is 60. What is the percentage of boys in the class?

- a) 40%
- b) 60%
- c) 65%
- d) 70%

**Correct Option:** **b) 60%**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Average Formula
- Let number of girls be $G$ and number of boys be $B$.
- Total marks $= 68(G + B)$.
- Total marks of girls $= 80G$; total marks of boys $= 60B$.
  $$80G + 60B = 68G + 68B$$
  $$80G - 68G = 68B - 60B$$
  $$12G = 8B \implies \frac{B}{G} = \frac{12}{8} = \frac{3}{2}$$
- Total students $= B + G = 3 + 2 = 5$ parts.
- Percentage of boys:
  $$\% \text{ Boys} = \frac{B}{B + G} \times 100 = \frac{3}{5} \times 100 = 60\%$$

##### Method 2: Alligation Cross Rule
- Girls average $= 80$
- Boys average $= 60$
- Class mean $= 68$

$$\begin{array}{ccc}
\text{Girls (80)} & & \text{Boys (60)} \\
& \searrow \swarrow & \\
& \text{Mean (68)} & \\
\swarrow & & \searrow \\
(68 - 60) = 8 & : & (80 - 68) = 12
\end{array}$$

- Ratio of Girls : Boys $= 8 : 12 = 2 : 3$.
- Proportion of boys $= \frac{3}{2 + 3} = \frac{3}{5}$.
- Percentage of boys $= \frac{3}{5} \times 100 = 60\%$.

##### Shortcut / Quick Exam Trick
- Distance of boys from class average $= |68 - 60| = 8$.
- Distance of girls from class average $= |80 - 68| = 12$.
- Ratio $G : B = 8 : 12 = 2 : 3$.
- Boys fraction $= \frac{3}{5} = 60\%$.

### Q13
**Question:**
A class of 60 students contributed ₹4800 for a charity. If each boy has contributed ₹94 and each girl contributed ₹73. Find the number of boys in the class.

- a) 20
- b) 30
- c) 40
- d) 45

**Correct Option:** **a) 20**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Linear System
- Let the number of boys be $B$ and girls be $G$.
- $B + G = 60 \implies G = 60 - B$.
- Total contribution:
  $$94B + 73G = 4800$$
  $$94B + 73(60 - B) = 4800$$
  $$94B + 4380 - 73B = 4800$$
  $$21B = 4800 - 4380 = 420$$
  $$B = \frac{420}{21} = 20$$

##### Method 2: Alligation Cross Rule (on Average Contribution per Student)
- Overall average contribution per student $= \frac{₹4800}{60} = ₹80$.
- Boys contribution $= ₹94$
- Girls contribution $= ₹73$
- Mean contribution $= ₹80$

$$\begin{array}{ccc}
\text{Boys (₹94)} & & \text{Girls (₹73)} \\
& \searrow \swarrow & \\
& \text{Mean (₹80)} & \\
\swarrow & & \searrow \\
(80 - 73) = 7 & : & (94 - 80) = 14
\end{array}$$

- Ratio of Boys : Girls $= 7 : 14 = 1 : 2$.
- Total parts $= 1 + 2 = 3$.
- Number of boys $= \frac{1}{3} \times 60 = 20$.

##### Shortcut / Quick Exam Trick
- Assume all 60 are girls: Contribution $= 60 \times 73 = 4380$.
- Shortfall $= 4800 - 4380 = 420$.
- Difference per boy $= 94 - 73 = 21$.
- Number of boys $= \frac{420}{21} = 20$.

### Q14
**Question:**
In a mixture of 60 litres, the ratio of acid to base is 2 : 1. If this ratio is to be 1 : 2, then the quantity of base (in litres) to be further added is :

- a) 20
- b) 30
- c) 40
- d) 60

**Correct Option:** **d) 60**

---

#### Detailed Mathematical Explanation

##### Method 1: Component Breakdown Method
- Total mixture $= 60\text{ litres}$, ratio of Acid : Base $= 2 : 1$.
- Acid $= \frac{2}{3} \times 60 = 40\text{ litres}$.
- Base $= \frac{1}{3} \times 60 = 20\text{ litres}$.
- Let $x$ litres of base be added. The acid remains constant at $40\text{ litres}$.
- New ratio of Acid : Base $= 1 : 2$:
  $$\frac{40}{20 + x} = \frac{1}{2}$$
  $$20 + x = 40 \times 2 = 80$$
  $$x = 80 - 20 = 60\text{ litres}$$

##### Method 2: Ratio Equating Method
- Initial: Acid : Base $= 2 : 1$.
- Final: Acid : Base $= 1 : 2$.
- Since only base is added, acid amount must remain constant. Multiply final ratio by 2:
  - Final: Acid : Base $= 2 : 4$.
- Acid is constant (2 parts). Base increases from 1 part to 4 parts $\rightarrow$ Increase $= 3$ parts.
- Initial total mixture $= 2 + 1 = 3\text{ parts} = 60\text{ litres}$.
- Therefore, $1\text{ part} = 20\text{ litres}$.
- Added base $= 3\text{ parts} = 3 \times 20 = 60\text{ litres}$.

##### Method 3: Alligation Cross Rule (on % of Base)
- Initial base $\% = \frac{1}{3} \times 100 = 33.33\%$.
- Added pure base $\% = 100\%$.
- Desired base $\% = \frac{2}{3} \times 100 = 66.67\%$.
- Ratio $= (100 - 66.67) : (66.67 - 33.33) = 33.33 : 33.33 = 1 : 1$.
- Since Initial $= 60\text{ L}$, Added base $= 60\text{ L}$.

##### Shortcut / Quick Exam Trick
- Since acid stays at 40 L and must become 1 part in a 1:2 ratio, base must become $40 \times 2 = 80\text{ L}$.
- Base added $= 80 - 20 = 60\text{ litres}$.

### Q15
**Question:**
A man had 100 kgs of sugar, part of which he sold at 7% profit and rest at 17% profit. He gained 10% on the whole. How much did he sell at 7% profit?

- a) 65 kg
- b) 35 kg
- c) 30 kg
- d) 70 kg

**Correct Option:** **d) 70 kg**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Let quantity sold at $7\%$ profit be $x$ kg.
- Quantity sold at $17\%$ profit $= 100 - x$ kg.
- Overall profit percentage is $10\%$ on 100 kg:
  $$7x + 17(100 - x) = 10(100)$$
  $$7x + 1700 - 17x = 1000$$
  $$-10x = 1000 - 1700 = -700$$
  $$x = 70\text{ kg}$$

##### Method 2: Alligation Cross Rule
- Profit rate 1 $= 7\%$
- Profit rate 2 $= 17\%$
- Mean profit rate $= 10\%$

$$\begin{array}{ccc}
\text{Part 1 (7\%)} & & \text{Part 2 (17\%)} \\
& \searrow \swarrow & \\
& \text{Mean (10\%)} & \\
\swarrow & & \searrow \\
(17 - 10) = 7 & : & (10 - 7) = 3
\end{array}$$

- Ratio of Part 1 ($7\%$) : Part 2 ($17\%$) $= 7 : 3$.
- Total weight $= 100\text{ kg}$, total parts $= 7 + 3 = 10$.
- Quantity sold at $7\%$ profit $= \frac{7}{10} \times 100 = 70\text{ kg}$.

##### Shortcut / Quick Exam Trick
- Ratio $= (17 - 10) : (10 - 7) = 7 : 3$.
- Weight at $7\% = \frac{7}{10} \times 100 = 70\text{ kg}$.

### Q16
**Question:**
A merchant sold 80 dozen oranges. He sold some at 4% loss and rest at the cost price and thus losing 3% on the whole. What is the quantity sold at loss?

- a) 20 dozen
- b) 40 dozen
- c) 50 dozen
- d) 60 dozen

**Correct Option:** **d) 60 dozen**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Selling at Cost Price represents $0\%$ profit/loss.
- Let quantity sold at $4\%$ loss (i.e. $-4\%$) be $x$ dozen.
- Quantity sold at cost price ($0\%$) $= 80 - x$ dozen.
- Overall loss is $3\%$ (i.e. $-3\%$):
  $$-4(x) + 0(80 - x) = -3(80)$$
  $$-4x = -240 \implies x = 60\text{ dozen}$$

##### Method 2: Alligation Cross Rule
- Loss part: $-4\%$
- Cost price part: $0\%$
- Overall mean: $-3\%$

$$\begin{array}{ccc}
\text{At Loss (-4\%)} & & \text{At Cost Price (0\%)} \\
& \searrow \swarrow & \\
& \text{Mean (-3\%)} & \\
\swarrow & & \searrow \\
0 - (-3) = 3 & : & -3 - (-4) = 1
\end{array}$$

- Ratio of Quantity at Loss : Quantity at CP $= 3 : 1$.
- Total parts $= 3 + 1 = 4$.
- Quantity sold at loss $= \frac{3}{4} \times 80 = 60\text{ dozen}$.

##### Shortcut / Quick Exam Trick
- Loss is $-3$, which is $\frac{3}{4}$ of the way from $0$ to $-4$.
- Quantity at loss $= \frac{3}{4} \times 80 = 60\text{ dozen}$.

### Q17
**Question:**
40 litres of a mixture of milk and water contains 10% of water. How much water should be added to make the water content 20% in the new mixture?

- a) 6 litres
- b) 6.5 litres
- c) 5.5 litres
- d) 5 litres

**Correct Option:** **d) 5 litres**

---

#### Detailed Mathematical Explanation

##### Method 1: Constant Milk Component Method
- Initial total volume $= 40\text{ litres}$.
- Initial water $= 10\% \implies$ Initial milk $= 90\%$.
- Volume of milk $= 40 \times 0.90 = 36\text{ litres}$.
- Let added water be $w$ litres.
- Milk remains constant at $36\text{ litres}$.
- In the new mixture, water is $20\% \implies$ Milk is $80\%$.
  $$80\% \text{ of } (40 + w) = 36$$
  $$0.80(40 + w) = 36$$
  $$40 + w = \frac{36}{0.80} = 45$$
  $$w = 45 - 40 = 5\text{ litres}$$

##### Method 2: Alligation Cross Rule (on Water %)
- Initial mixture water $= 10\%$
- Pure water added $= 100\%$
- Target water $= 20\%$

$$\begin{array}{ccc}
\text{Initial Mixture (10\%)} & & \text{Added Water (100\%)} \\
& \searrow \swarrow & \\
& \text{Mean (20\%)} & \\
\swarrow & & \searrow \\
(100 - 20) = 80 & : & (20 - 10) = 10
\end{array}$$

- Ratio of Initial Mixture : Added Water $= 80 : 10 = 8 : 1$.
- Given Initial Mixture $= 40\text{ litres}$ (corresponds to 8 parts).
- Added water (1 part) $= \frac{40}{8} = 5\text{ litres}$.

##### Shortcut / Quick Exam Trick
$$\text{Added Water} = \text{Initial Total} \times \frac{\%\text{Change in Water}}{100 - \text{New }\%\text{ Water}} = 40 \times \frac{20 - 10}{100 - 20} = 40 \times \frac{10}{80} = 5\text{ litres}$$

### Q18
**Question:**
The mean weight of a class of 65 students is 59 kg. If the mean weight of boys is 63 kg and that of girls is 50 kg, find the number of boys and girls in the class.

- a) 45, 25
- b) 45, 20
- c) 40, 20
- d) 50, 20

**Correct Option:** **b) 45, 20**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Total number of students $= 65$.
- Let the number of boys be $B$ and girls be $G = 65 - B$.
- Total weight of class $= 65 \times 59 = 3835\text{ kg}$.
- Total weight from boys and girls:
  $$63B + 50(65 - B) = 3835$$
  $$63B + 3250 - 50B = 3835$$
  $$13B = 3835 - 3250 = 585$$
  $$B = \frac{585}{13} = 45$$
- Number of girls $G = 65 - 45 = 20$.

##### Method 2: Alligation Cross Rule
- Boys mean weight $= 63\text{ kg}$
- Girls mean weight $= 50\text{ kg}$
- Class mean weight $= 59\text{ kg}$

$$\begin{array}{ccc}
\text{Boys (63)} & & \text{Girls (50)} \\
& \searrow \swarrow & \\
& \text{Mean (59)} & \\
\swarrow & & \searrow \\
(59 - 50) = 9 & : & (63 - 59) = 4
\end{array}$$

- Ratio of Boys : Girls $= 9 : 4$.
- Total parts $= 9 + 4 = 13$.
- Value of 1 part $= \frac{65}{13} = 5$.
- Number of boys $= 9 \times 5 = 45$.
- Number of girls $= 4 \times 5 = 20$.

##### Shortcut / Quick Exam Trick
- Cross differences: $(59 - 50) : (63 - 59) = 9 : 4$.
- Since $9 + 4 = 13$ and total students $= 65$ ($5 \times 13$), multiply each part by 5:
  - Boys $= 9 \times 5 = 45$, Girls $= 4 \times 5 = 20$.

### Q19
**Question:**
A man purchased a horse and a cow for ₹5000. He sells the horse at 20% profit and the cow at 10% loss. If he gains 2% on the whole transaction, the cost price of the horse is :

- a) ₹2000
- b) ₹2500
- c) ₹2800
- d) ₹3000

**Correct Option:** **a) ₹2000**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Let the cost price of the horse be $H$, and cost price of the cow be $C = 5000 - H$.
- Gain on horse $= +20\% \implies +0.20H$.
- Loss on cow $= -10\% \implies -0.10(5000 - H) = -500 + 0.10H$.
- Overall transaction gain $= +2\% \text{ of } 5000 = +100$.
- Setting up the equation:
  $$0.20H - 500 + 0.10H = 100$$
  $$0.30H = 600$$
  $$H = \frac{600}{0.30} = ₹2000$$

##### Method 2: Alligation Cross Rule
- Horse profit $= +20\%$
- Cow loss $= -10\%$
- Overall net profit $= +2\%$

$$\begin{array}{ccc}
\text{Horse (+20\%)} & & \text{Cow (-10\%)} \\
& \searrow \swarrow & \\
& \text{Mean (+2\%)} & \\
\swarrow & & \searrow \\
2 - (-10) = 12 & : & 20 - 2 = 18
\end{array}$$

- Ratio of CP of Horse : CP of Cow $= 12 : 18 = 2 : 3$.
- Total parts $= 2 + 3 = 5$.
- Cost price of horse $= \frac{2}{5} \times 5000 = ₹2000$.

##### Shortcut / Quick Exam Trick
- Net difference: $|2 - (-10)| = 12$; $|20 - 2| = 18$.
- Ratio $= 2 : 3$.
- Cost price of horse $= \frac{2}{5} \times 5000 = ₹2000$.

### Q20
**Question:**
In a family of 8 adults and some minors, the average consumption of rice per head per month is 10.8 kg. The average consumption for adults is 15 kg and for minors is 6 kg. The number of minors is:

- a) 8
- b) 6
- c) 7
- d) 9

**Correct Option:** **c) 7**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Weighted Average Formula
- Number of adults $A = 8$; let number of minors be $M$.
- Adult consumption $= 15\text{ kg/head}$.
- Minor consumption $= 6\text{ kg/head}$.
- Overall mean consumption $= 10.8\text{ kg/head}$.
- Total rice consumed:
  $$8(15) + 6(M) = 10.8(8 + M)$$
  $$120 + 6M = 86.4 + 10.8M$$
  $$10.8M - 6M = 120 - 86.4$$
  $$4.8M = 33.6$$
  $$M = \frac{33.6}{4.8} = 7$$

##### Method 2: Alligation Cross Rule
- Adults rate $= 15\text{ kg}$
- Minors rate $= 6\text{ kg}$
- Family mean rate $= 10.8\text{ kg}$

$$\begin{array}{ccc}
\text{Adults (15)} & & \text{Minors (6)} \\
& \searrow \swarrow & \\
& \text{Mean (10.8)} & \\
\swarrow & & \searrow \\
(10.8 - 6) = 4.8 & : & (15 - 10.8) = 4.2
\end{array}$$

- Ratio of Adults : Minors $= 4.8 : 4.2 = 48 : 42 = 8 : 7$.
- Since the number of adults is explicitly given as $8$ (matching 8 parts), the number of minors must be **7**.

##### Shortcut / Quick Exam Trick
- Ratio of Adults : Minors $= (10.8 - 6) : (15 - 10.8) = 4.8 : 4.2 = 8 : 7$.
- 8 adults $\implies$ 7 minors directly. No further calculation needed!

### Q21
**Question:**
Fresh fruit contains 70% water and dry fruit contains 40% water. How much dry fruit can be obtained from 100 kg of fresh fruit?

- a) 50 kg
- b) 30 kg
- c) 72 kg
- d) 35 kg

**Correct Option:** **a) 50 kg**

---

#### Detailed Mathematical Explanation

##### Method 1: Constant Pulp (Dry Matter) Method
- In fresh and dry fruit problems, during the drying process only water evaporates; the solid **pulp (dry matter)** remains completely invariant.
- Fresh fruit:
  - Total mass $= 100\text{ kg}$
  - Water content $= 70\% \implies$ Pulp content $= 30\%$
  - Mass of pulp $= 30\% \text{ of } 100\text{ kg} = 30\text{ kg}$
- Dry fruit:
  - Water content $= 40\% \implies$ Pulp content $= 60\%$
  - Let total mass of dry fruit be $D$ kg.
  - Mass of pulp in dry fruit $= 60\% \text{ of } D = 0.60D$
- Since the mass of pulp does not change:
  $$0.60D = 30$$
  $$D = \frac{30}{0.60} = 50\text{ kg}$$

##### Method 2: Ratio of Invariant Components
- Percentage of pulp in fresh fruit $= 100 - 70 = 30\%$.
- Percentage of pulp in dry fruit $= 100 - 40 = 60\%$.
- Since $\text{Mass} \times \%\text{Pulp} = \text{Constant}$:
  $$\frac{\text{Dry Fruit Mass}}{\text{Fresh Fruit Mass}} = \frac{\%\text{Pulp in Fresh}}{\%\text{Pulp in Dry}} = \frac{30}{60} = \frac{1}{2}$$
  $$\text{Dry Fruit Mass} = 100 \times \frac{1}{2} = 50\text{ kg}$$

##### Shortcut / Quick Exam Trick
$$\text{Dry Fruit} = \text{Fresh Fruit} \times \frac{100 - W_{\text{fresh}}}{100 - W_{\text{dry}}} = 100 \times \frac{100 - 70}{100 - 40} = 100 \times \frac{30}{60} = 50\text{ kg}$$

### Q22
**Question:**
The mean weight of 150 students is 60 kg. The mean weight of boys is 70 kg and girls is 55 kg. Find the number of girls.

- a) 105
- b) 100
- c) 95
- d) 60

**Correct Option:** **b) 100**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Total students $= 150$.
- Let number of girls be $G$, and number of boys be $B = 150 - G$.
- Total weight of all students $= 150 \times 60 = 9000\text{ kg}$.
- Total weight from boys and girls:
  $$70(150 - G) + 55G = 9000$$
  $$10500 - 70G + 55G = 9000$$
  $$15G = 10500 - 9000 = 1500$$
  $$G = \frac{1500}{15} = 100$$

##### Method 2: Alligation Cross Rule
- Boys mean weight $= 70\text{ kg}$
- Girls mean weight $= 55\text{ kg}$
- Overall mean weight $= 60\text{ kg}$

$$\begin{array}{ccc}
\text{Boys (70)} & & \text{Girls (55)} \\
& \searrow \swarrow & \\
& \text{Mean (60)} & \\
\swarrow & & \searrow \\
(60 - 55) = 5 & : & (70 - 60) = 10
\end{array}$$

- Ratio of Boys : Girls $= 5 : 10 = 1 : 2$.
- Total parts $= 1 + 2 = 3$.
- Number of girls $= \frac{2}{3} \times 150 = 100$.

##### Shortcut / Quick Exam Trick
- Distance: Boys $= |70 - 60| = 10$; Girls $= |55 - 60| = 5$.
- Ratio $B : G = 5 : 10 = 1 : 2$.
- Girls fraction $= \frac{2}{3} \implies 150 \times \frac{2}{3} = 100$.

### Q23
**Question:**
The average salary per head of all workers is ₹60. The average salary of 12 officers is ₹400 and of the rest is ₹56. The total number of workers is:

- a) 1062
- b) 1060
- c) 1030
- d) 1032

**Correct Option:** **d) 1032**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Weighted Average Formula
- Number of officers $= 12$, with an average salary of ₹400.
- Let the number of remaining workers be $R$, with an average salary of ₹56.
- Total employees $= 12 + R$.
- Overall average salary $= ₹60$.
- Total salary:
  $$12(400) + 56R = 60(12 + R)$$
  $$4800 + 56R = 720 + 60R$$
  $$60R - 56R = 4800 - 720$$
  $$4R = 4080$$
  $$R = \frac{4080}{4} = 1020$$
- Total workforce (officers + rest) $= 12 + 1020 = 1032$.

##### Method 2: Alligation Cross Rule
- Officers average salary $= ₹400$
- Rest of workers average salary $= ₹56$
- Overall mean salary $= ₹60$

$$\begin{array}{ccc}
\text{Officers (₹400)} & & \text{Rest (₹56)} \\
& \searrow \swarrow & \\
& \text{Mean (₹60)} & \\
\swarrow & & \searrow \\
(60 - 56) = 4 & : & (400 - 60) = 340
\end{array}$$

- Ratio of Officers : Rest $= 4 : 340 = 1 : 85$.
- Given number of officers $= 12$ (1 part corresponds to 12).
- Rest of workers $= 85 \times 12 = 1020$.
- Total number of workers $= 12 + 1020 = 1032$.

##### Shortcut / Quick Exam Trick
- Ratio of Officers : Rest $= 4 : 340 = 1 : 85$.
- Total staff parts $= 1 + 85 = 86$.
- Total workforce $= 86 \times 12 = 1032$.

### Q24
**Question:**
The average salary of factory staff is ₹3500. The average salary of workers is ₹2000 and supervisors ₹7000. If there are 900 employees, find the number of supervisors.

- a) 200
- b) 270
- c) 630
- d) 700

**Correct Option:** **b) 270**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Let number of supervisors be $S$.
- Number of workers $= 900 - S$.
- Total salary of 900 employees $= 900 \times 3500 = ₹3,150,000$.
- Sum of individual salaries:
  $$7000S + 2000(900 - S) = 3,150,000$$
  $$7000S + 1,800,000 - 2000S = 3,150,000$$
  $$5000S = 3,150,000 - 1,800,000 = 1,350,000$$
  $$S = \frac{1,350,000}{5000} = 270$$

##### Method 2: Alligation Cross Rule
- Supervisors average salary $= ₹7000$
- Workers average salary $= ₹2000$
- Factory mean salary $= ₹3500$

$$\begin{array}{ccc}
\text{Supervisors (₹7000)} & & \text{Workers (₹2000)} \\
& \searrow \swarrow & \\
& \text{Mean (₹3500)} & \\
\swarrow & & \searrow \\
(3500 - 2000) = 1500 & : & (7000 - 3500) = 3500
\end{array}$$

- Ratio of Supervisors : Workers $= 1500 : 3500 = 3 : 7$.
- Total parts $= 3 + 7 = 10$.
- Total employees $= 900$.
- Value of 1 part $= \frac{900}{10} = 90$.
- Number of supervisors $= 3 \times 90 = 270$.

##### Shortcut / Quick Exam Trick
- Supervisors : Workers $= (3500 - 2000) : (7000 - 3500) = 15 : 35 = 3 : 7$.
- Supervisors $= 900 \times \frac{3}{10} = 270$.

### Q25
**Question:**
How much pure alcohol must be added to 400 ml of a solution containing 15% alcohol to make it 32% alcohol?

- a) 60 ml
- b) 100 ml
- c) 128 ml
- d) 68 ml

**Correct Option:** **b) 100 ml**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Concentration Equation
- Initial solution volume $= 400\text{ ml}$, containing $15\%$ alcohol.
- Alcohol present initially $= 400 \times 0.15 = 60\text{ ml}$.
- Let $x$ ml of pure alcohol ($100\%$ alcohol) be added.
- New total volume $= 400 + x\text{ ml}$.
- New total alcohol $= 60 + x\text{ ml}$.
- Resultant concentration is $32\%$:
  $$\frac{60 + x}{400 + x} = 0.32$$
  $$60 + x = 0.32(400 + x) = 128 + 0.32x$$
  $$x - 0.32x = 128 - 60$$
  $$0.68x = 68$$
  $$x = \frac{68}{0.68} = 100\text{ ml}$$

##### Method 2: Alligation Cross Rule
- Initial solution alcohol $= 15\%$
- Pure alcohol added $= 100\%$
- Target mean concentration $= 32\%$

$$\begin{array}{ccc}
\text{Initial Solution (15\%)} & & \text{Pure Alcohol (100\%)} \\
& \searrow \swarrow & \\
& \text{Mean (32\%)} & \\
\swarrow & & \searrow \\
(100 - 32) = 68 & : & (32 - 15) = 17
\end{array}$$

- Ratio of Initial Solution : Pure Alcohol Added $= 68 : 17 = 4 : 1$.
- Given Initial Solution $= 400\text{ ml}$ (corresponds to 4 parts).
- Pure alcohol to be added (1 part) $= \frac{400}{4} = 100\text{ ml}$.

##### Shortcut / Quick Exam Trick
- Ratio $= (100 - 32) : (32 - 15) = 68 : 17 = 4 : 1$.
- 4 parts $= 400\text{ ml} \implies 1\text{ part} = 100\text{ ml}$.

### Q26
**Question:**
10 gallons are drawn from a container full of alcohol and filled with water again. 10 gallons of mixture are again drawn and the container is filled with water again. If the ratio of alcohol and water left in the container is 49 : 32, then find how much quantity does the container hold?

- a) 35 gallons
- b) 45 gallons
- c) 55 gallons
- d) 60 gallons

**Correct Option:** **b) 45 gallons**

---

#### Detailed Mathematical Explanation

##### Method 1: Repeated Replacement Formula
- Let the total capacity of the container be $C$ gallons.
- Amount drawn out and replaced in each cycle, $x = 10\text{ gallons}$.
- Number of replacement operations performed, $n = 2$.
- The container is initially completely full of pure alcohol.
- The standard replacement formula states:
  $$\frac{\text{Quantity of pure liquid remaining}}{\text{Total capacity } C} = \left(1 - \frac{x}{C}\right)^n$$
- In the final mixture:
  - Ratio of Alcohol : Water $= 49 : 32$.
  - Total mixture parts $= 49 + 32 = 81$.
  - Fraction of alcohol remaining $= \frac{49}{81}$.
- Equating the formula to the remaining fraction:
  $$\left(1 - \frac{10}{C}\right)^2 = \frac{49}{81}$$
- Taking the square root on both sides:
  $$1 - \frac{10}{C} = \sqrt{\frac{49}{81}} = \frac{7}{9}$$
  $$\frac{10}{C} = 1 - \frac{7}{9} = \frac{2}{9}$$
  $$C = 10 \times \frac{9}{2} = 45\text{ gallons}$$

##### Method 2: Reverse Proportionality Verification
- If $C = 45$:
  - First cycle: 10 drawn $\rightarrow 45 - 10 = 35$ alcohol remaining. Alcohol fraction $= \frac{35}{45} = \frac{7}{9}$.
  - Second cycle: 10 of mixture drawn $\rightarrow$ alcohol removed $= 10 \times \frac{7}{9} = \frac{70}{9}$.
  - Remaining alcohol $= 35 - \frac{70}{9} = \frac{315 - 70}{9} = \frac{245}{9}$.
  - Water in vessel $= 45 - \frac{245}{9} = \frac{405 - 245}{9} = \frac{160}{9}$.
  - Ratio of Alcohol : Water $= \frac{245}{9} : \frac{160}{9} = 245 : 160 = 49 : 32$. (Matches perfectly).

##### Shortcut / Quick Exam Trick
$$\sqrt{\frac{\text{Alcohol}}{\text{Total}}} = \sqrt{\frac{49}{49 + 32}} = \sqrt{\frac{49}{81}} = \frac{7}{9}$$
$$\text{Fraction removed in 1 turn} = 1 - \frac{7}{9} = \frac{2}{9}$$
$$\frac{2}{9} \text{ of } C = 10 \implies C = 10 \times \frac{9}{2} = 45\text{ gallons}$$

### Q27
**Question:**
Mira’s expenditure and savings are in the ratio 3 : 2. Her income increases by 10% and expenditure by 12%. By how much percent does her saving increase?

- a) 7%
- b) 10%
- c) 9%
- d) 13%

**Correct Option:** **a) 7%**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Numerical Base Method
- Given ratio of Expenditure : Savings $= 3 : 2$.
- Let Expenditure $E = 300$, and Savings $S = 200$.
- Total Income $I = E + S = 300 + 200 = 500$.
- New Income increases by $10\%$:
  $$\text{New Income} = 500 + (10\% \text{ of } 500) = 500 + 50 = 550$$
- New Expenditure increases by $12\%$:
  $$\text{New Expenditure} = 300 + (12\% \text{ of } 300) = 300 + 36 = 336$$
- New Savings:
  $$\text{New Savings} = \text{New Income} - \text{New Expenditure} = 550 - 336 = 214$$
- Absolute increase in savings:
  $$\Delta S = 214 - 200 = 14$$
- Percentage increase in savings:
  $$\%\text{ Increase in Savings} = \frac{14}{200} \times 100 = 7\%$$

##### Method 2: Alligation Cross Rule (Income as Weighted Mean of Expenditure and Savings)
- Total Income percentage increase ($10\%$) is the weighted average of Expenditure percentage increase ($12\%$) and Savings percentage increase ($x\%$), weighted by their respective initial base values ($3 : 2$).

$$\begin{array}{ccc}
\text{Expenditure Increase (12\%)} & & \text{Savings Increase (}x\%\text{)} \\
& \searrow \swarrow & \\
& \text{Mean Income Increase (10\%)} & \\
\swarrow & & \searrow \\
(10 - x) & : & (12 - 10) = 2
\end{array}$$

- Equating to the ratio of Expenditure : Savings ($3 : 2$):
  $$\frac{10 - x}{2} = \frac{3}{2}$$
  $$10 - x = 3 \implies x = 10 - 3 = 7\%$$

##### Shortcut / Quick Exam Trick
- Deviation equation:
  $$3 \times (+12\%) + 2 \times (x\%) = 5 \times (+10\%)$$
  $$36 + 2x = 50 \implies 2x = 14 \implies x = 7\%$$

### Q28
**Question:**
A sample of 50 litres of glycerine is found to be adulterated to the extent of 20%. How much pure glycerine should be added to it so as to bring down the percentage of impurity to 5%?

- a) 155 litres
- b) 150 litres
- c) 150.4 litres
- d) 149 litres

**Correct Option:** **b) 150 litres**

---

#### Detailed Mathematical Explanation

##### Method 1: Constant Impurity (Solute) Method
- Initial volume of mixture $= 50\text{ litres}$.
- Initial impurity content $= 20\% \text{ of } 50 = 50 \times 0.20 = 10\text{ litres}$.
- Pure glycerine is added; pure glycerine contains $0\%$ impurity.
- Therefore, the absolute quantity of impurity remains unchanged at $10\text{ litres}$.
- In the new mixture, the impurity must be $5\%$ of the new total volume $V$:
  $$\frac{10}{V} = 5\% = \frac{5}{100} = \frac{1}{20}$$
  $$V = 10 \times 20 = 200\text{ litres}$$
- Pure glycerine to be added:
  $$\text{Added Glycerine} = V - 50 = 200 - 50 = 150\text{ litres}$$

##### Method 2: Alligation Cross Rule (on Impurity %)
- Initial mixture impurity $= 20\%$
- Added pure glycerine impurity $= 0\%$
- Desired mean impurity $= 5\%$

$$\begin{array}{ccc}
\text{Initial Mixture (20\%)} & & \text{Pure Glycerine Added (0\%)} \\
& \searrow \swarrow & \\
& \text{Mean (5\%)} & \\
\swarrow & & \searrow \\
(5 - 0) = 5 & : & (20 - 5) = 15
\end{array}$$

- Ratio of Initial Mixture : Added Pure Glycerine $= 5 : 15 = 1 : 3$.
- Initial mixture quantity $= 50\text{ litres}$ (corresponds to 1 part).
- Added pure glycerine (3 parts) $= 3 \times 50 = 150\text{ litres}$.

##### Shortcut / Quick Exam Trick
- Impurity drops from $20\%$ to $5\%$ (a 4-fold reduction).
- Total volume must become 4 times initial: $50 \times 4 = 200\text{ L}$.
- Added glycerine $= 200 - 50 = 150\text{ litres}$.

### Q29
**Question:**
In a class there are 150 students. 60% of boys are passed while 45% of girls are passed. The pass percentage of class is 55%. Find the number of girls in the class.

- a) 50
- b) 100
- c) 115
- d) None of these

**Correct Option:** **a) 50**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Algebraic Equation
- Total students $= 150$.
- Let the number of girls be $G$ and number of boys be $B = 150 - G$.
- Number of boys passed $= 60\% \text{ of } (150 - G) = 0.60(150 - G) = 90 - 0.60G$.
- Number of girls passed $= 45\% \text{ of } G = 0.45G$.
- Total students passed in class $= 55\% \text{ of } 150 = 82.5$.
- Setting up the equation:
  $$90 - 0.60G + 0.45G = 82.5$$
  $$90 - 0.15G = 82.5$$
  $$0.15G = 90 - 82.5 = 7.5$$
  $$G = \frac{7.5}{0.15} = 50$$

##### Method 2: Alligation Cross Rule
- Boys pass percentage $= 60\%$
- Girls pass percentage $= 45\%$
- Overall class pass percentage $= 55\%$

$$\begin{array}{ccc}
\text{Boys (60\%)} & & \text{Girls (45\%)} \\
& \searrow \swarrow & \\
& \text{Mean (55\%)} & \\
\swarrow & & \searrow \\
(55 - 45) = 10 & : & (60 - 55) = 5
\end{array}$$

- Ratio of Boys : Girls $= 10 : 5 = 2 : 1$.
- Total parts $= 2 + 1 = 3$.
- Total students $= 150$.
- Number of girls $= \frac{1}{3} \times 150 = 50$.
- (Number of boys $= \frac{2}{3} \times 150 = 100$).

##### Shortcut / Quick Exam Trick
- Cross differences: $(55 - 45) : (60 - 55) = 10 : 5 = 2 : 1$.
- Girls share $= \frac{1}{3}$.
- Girls $= \frac{1}{3} \times 150 = 50$.

### Q30
**Question:**
In a zoo there are rabbits and pigeons. If their heads are counted, they are 35 while their legs are 120. Find the number of rabbits in the zoo.

- a) 25
- b) 15
- c) 10
- d) None of these

**Correct Option:** **a) 25**

---

#### Detailed Mathematical Explanation

##### Method 1: Standard Simultaneous Equations
- Each animal has 1 head: Rabbits ($R$) have 4 legs each; Pigeons ($P$) have 2 legs each.
- Equation for heads:
  $$R + P = 35 \implies P = 35 - R$$
- Equation for legs:
  $$4R + 2P = 120$$
- Substituting $P$:
  $$4R + 2(35 - R) = 120$$
  $$4R + 70 - 2R = 120$$
  $$2R = 120 - 70 = 50$$
  $$R = \frac{50}{2} = 25$$
- Number of rabbits is **25** (and pigeons $P = 35 - 25 = 10$).

##### Method 2: Alligation Cross Rule (on Legs per Head)
- Pigeons have 2 legs/head.
- Rabbits have 4 legs/head.
- Mean legs per head $= \frac{\text{Total legs}}{\text{Total heads}} = \frac{120}{35} = \frac{24}{7}$.

$$\begin{array}{ccc}
\text{Pigeons (2)} & & \text{Rabbits (4)} \\
& \searrow \swarrow & \\
& \text{Mean } \left(\frac{24}{7}\right) & \\
\swarrow & & \searrow \\
4 - \frac{24}{7} = \frac{4}{7} & : & \frac{24}{7} - 2 = \frac{10}{7}
\end{array}$$

- Ratio of Pigeons : Rabbits $= \frac{4}{7} : \frac{10}{7} = 4 : 10 = 2 : 5$.
- Total parts $= 2 + 5 = 7$.
- Given total animals $= 35$ heads.
- Number of rabbits $= \frac{5}{7} \times 35 = 25$.

##### Shortcut / Quick Exam Trick
- **4-Legged Animals Formula:**
  $$\text{Number of 4-legged animals (Rabbits)} = \frac{\text{Total Legs}}{2} - \text{Total Heads}$$
  $$R = \frac{120}{2} - 35 = 60 - 35 = 25$$
- **2-Legged Animals Formula:**
  $$P = 2 \times (\text{Total Heads}) - \frac{\text{Total Legs}}{2} = 2(35) - 60 = 10$$

---

## 3. Tricks, Tips & Exam Shortcuts

### 3.1 Master Cheat Sheet of Alligation Formats

| Problem Domain | Value 1 ($c$) | Value 2 ($d$) | Mean Value ($m$) | Ratio Output ($q_c : q_d$) |
| :--- | :--- | :--- | :--- | :--- |
| **Price / Grocery** | Price per kg of cheaper | Price per kg of dearer | Mean Cost Price per kg | Ratio of Weights / Quantities (kg) |
| **Profit & Loss** | % Profit/Loss of item 1 | % Profit/Loss of item 2 | Overall % Profit/Loss | Ratio of Cost Prices (CP) |
| **Dilution / Liquids** | % Solute in solution 1 | % Solute in solution 2 (or 100% pure solute, 0% water) | Desired % Solute in mixture | Ratio of Volumes (Litres) |
| **Averages / Classes** | Average marks/weight of group A | Average marks/weight of group B | Overall average of combined class | Ratio of Number of Students |
| **Wages / Salaries** | Average salary of cadre A | Average salary of cadre B | Overall mean salary of all staff | Ratio of Headcount in each cadre |
| **Demographics** | % growth in male population | % growth in female population | % growth in total population | Ratio of Initial Males : Females |
| **Animals / Legs** | Legs per 2-legged animal (2) | Legs per 4-legged animal (4) | Average legs per head (Legs / Heads) | Ratio of 2-legged : 4-legged heads |
| **Income & Savings** | % change in Expenditure | % change in Savings | % change in Total Income | Ratio of Initial Expenditure : Initial Savings |

---

### 3.2 Five Universal Golden Rules for Exam Speed

1. **Always Verify Cost Price Before Alligation:**
   - If selling price of the mixture is given with a profit/loss, **never** put the selling price in the center of the alligation diagram.
   - Convert to Cost Price first: $CP_m = \frac{SP_m}{1 + \frac{P}{100}}$.

2. **The Invariant Quantity Technique:**
   - When only one liquid/component is added or removed, identify which component is **constant**.
   - Formula: $\text{Total}_1 \times (\%\text{ Constant}_1) = \text{Total}_2 \times (\%\text{ Constant}_2)$.
   - Avoids quadratic expressions and solves in a single line.

3. **Repeated Dilution Shortcut:**
   - When $x$ units are removed and replaced with water $n$ times from an initial volume $C$:
     $$\frac{\text{Final Solute}}{\text{Total Capacity}} = \left(1 - \frac{x}{C}\right)^n$$
   - If ratio of Pure Solute to Water is given as $A : B$, then $\frac{\text{Final Solute}}{\text{Total}} = \frac{A}{A + B}$.
   - Take the $n$-th root to immediately find $\left(1 - \frac{x}{C}\right)$ without expanding polynomials.

4. **Legs and Heads Instant Formula:**
   - For mixed 2-legged ($T$) and 4-legged ($F$) creatures with $H$ total heads and $L$ total legs:
     $$F = \frac{L}{2} - H$$
     $$T = 2H - \frac{L}{2}$$

5. **Fresh vs. Dry Fruit Invariant Pulp Formula:**
   $$\text{Mass of Dry Fruit} = \text{Mass of Fresh Fruit} \times \left(\frac{100 - \%\text{Water}_{\text{fresh}}}{100 - \%\text{Water}_{\text{dry}}}\right)$$
