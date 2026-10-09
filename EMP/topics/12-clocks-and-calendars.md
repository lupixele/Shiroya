# 12. Clocks and Calendars

> **Study guide:** theory and formulas follow the supplied slides; worked problems labeled **PPT** are adapted from the deck, while those labeled **additional** are teaching examples. The separate slide-reference file preserves all available on-slide text and inserted images.

## 1. Theory and formulas

### 1.1 Clock hand speeds
- **Minute hand = 6° per minute**.
- **Hour hand = 0.5° per minute**, or **30° per hour**.
- **Relative speed = 5.5° per minute**.

**Angle at h:m = |30h − 5.5m|** (take h modulo 12). For the smaller angle, **min(angle, 360°−angle)**.

### 1.2 Clock coincidences / right angles
In 12 hours, hands coincide **11 times** and are at right angles **22 times**. In 24 hours, coincidences **22**, right-angle positions **44**, oppositely directed **22**.

### 1.3 Calendar: odd days
An **odd day** is the remainder when number of days is divided by 7.

- Ordinary year 365 days = 52 weeks + **1 odd day**.
- Leap year 366 days = 52 weeks + **2 odd days**.
- **Leap year:** divisible by 4, except century years must be divisible by 400.
- A 100-year block starting at a century boundary and containing 24 leap years has **5 odd days**; 200 years: **3**; 300 years: **1**; 400 years: **0**.

### 1.4 Day-of-week calculation
Count complete days between the reference date and target; reduce the difference **modulo 7**. Move forward by the remainder (backward for earlier dates). Use actual month lengths, especially February 29 in leap years.

## 2. Questions and answers
**Q1 (PPT).** Hour hand rotates from 8 AM to 2 PM through how many degrees?
**Answer:** 6 hours ×30° = **180°**.

**Q2 (PPT).** Smaller angle at 8:40?
**Answer:** `|30×8−5.5×40|=|240−220|=20°`.

**Q3 (PPT).** Angle at 8:30?
**Answer:** `|240−165|=75°`.

**Q4 (PPT).** Angle at 4:20?
**Answer:** `|120−110|=10°`.

**Q5 (PPT).** Angle at 5:15?
**Answer:** `|150−82.5|=67.5°`. **Check slide options:** if this is absent, printed options may contain an error.

**Q6 (PPT).** Number of coincidences in a day?
**Answer:** `11×2=22`.

**Q7 (PPT).** Number of times clock hands at right angles in a day?
**Answer:** `22×2=44`.

**Q8 (additional).** Is 2100 a leap year?
**Answer:** **No**. It is divisible by 100 but not 400.

## 3. Tricks and tips
1. At **h:m**, hour hand moves beyond the hour mark by **m/2 degrees**.
2. Always compare the computed angle to **360°−angle** for the smaller angle.
3. Century leap-year check: **divisible by 400**, not just 4.
4. After day counting, **mod 7** removes full weeks.

## 4. Additional exam notes
A 12-hour clock repeats the hand geometry twice per 24 hours. For calendar problems, use the Gregorian calendar and be consistent about whether you are counting *elapsed* days (exclude the starting date).
