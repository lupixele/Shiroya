# Shiroya Repository — Academic Preferences & Engineering Standards

> **Repository:** `Shiroya` (`lupixele/Shiroya`)  
> **Scope:** Multi-Semester Academic Exam Notes, Question Banks, & Raw Resource Archive  
> **Institution:** Aditya University | B.Tech CSE (Data Science) & Core Engineering  
> **Author:** Vivek Shiroya (@lupixele)

---

## 1. Core Purpose & Multi-Semester Lifecycle

`Shiroya` is designed as a persistent, standardized, high-yield academic study repository for all engineering semesters. 

### Multi-Semester Branching Workflow
1. **Active Semester (`main`):** The default branch always hosts the current, active semester coursework, study hubs, and timetables.
2. **Semester Archive Branches:** At the conclusion of each semester, a snapshot branch is cut (e.g., `sem-3-archive` or `sem-3`) and tagged (`v3.0-sem3`).
3. **Cross-Semester Permanence:** This document (`preferences.md`) is semester-agnostic. It remains in the repository root across all semesters to enforce identical folder structures, naming rules, raw source handling, and answer formats.

---

## 2. Examination Structure & Academic Blueprint

Aditya University evaluates theory subjects through continuous internal assessment (50 Marks) and a final semester-end examination (50 Marks), scaled to a total of 100 Marks.

```
Total Course Grade (100 Marks)
├── Internal Continuous Assessment (50 Marks)
│   ├── Mid-1 / Internal Exam 1 (16 Marks) ── Units 1 & 2
│   ├── Mid-2 / Internal Exam 2 (24 Marks) ── Units 3, 4 & 5
│   └── Continuous Learning Activities (10 Marks) ── Assignments / Lab / LMS
└── Semester-End Examination / SEE (50 Marks scaled from 100) ── All Units 1–5
```

### Detailed Assessment Breakdown

| Examination | Scope (Units) | Question Paper Architecture | Choice & Answering Rules | Net Marks |
| :--- | :---: | :--- | :--- | :---: |
| **Internal Exam 1 (Mid-1)** | **Units 1 & 2** | • Total 4 questions (2 from Unit 1, 2 from Unit 2)<br>• Each question consists of subparts **(A)** [4M] and **(B)** [4M] | • Internal choice per unit (choose 1 question per unit)<br>• Must answer 2 complete questions (4 subparts total) | **16 Marks** |
| **Internal Exam 2 (Mid-2)** | **Units 3, 4 & 5** | • Total 6 questions (2 from each unit: 3, 4, and 5)<br>• Questions either carry subparts **(A)** [4M] & **(B)** [4M], or a single comprehensive **8M** question | • Internal choice per unit (choose 1 question per unit)<br>• Must answer 3 complete questions (either 3 × 8M or 6 × 4M) | **24 Marks** |
| **Learning Activities** | Ongoing | • Quizzes, lab evaluations, and LMS submissions | • Evaluated continuously by department faculty | **10 Marks** |
| **Internal Total** | — | **Mid-1 (16M) + Mid-2 (24M) + Learning Activities (10M)** | — | **50 Marks** |
| **Semester-End Exam (SEE)** | **Units 1 to 5** | • Total 10 questions (2 questions per unit for all 5 units)<br>• Each question carries **10 Marks** (or 20M scaled) | • Internal choice per unit (answer 1 out of 2 per unit)<br>• Answer exactly 5 questions (one from each unit) | **50 Marks** *(Scaled from 100)* |
| **Total Course Grade** | **All Units** | **Internal Assessment (50 Marks) + Semester-End Exam (50 Marks)** | **Total Final Grade** | **100 Marks** |

---

## 3. Directory Layout & Subject Naming Standards

### Subject Directory Naming
- Subject folders must use the **official uppercase acronym or syllabus course abbreviation**.
- **Approved Examples:** `ADSA`, `DBMS`, `FDS`, `CPP`, `ASE`, `P&S`, `DAE`.
- **Forbidden:** No lowercase names (`fds`), camelCase (`fdsNotes`), kebab-case (`adsa-notes`), or spaces (`Unit 3`).

### Uniform Subject Folder Tree
Every subject in this repository must strictly adhere to this uniform layout:

```
<SUBJECT_CODE>/
├── README.md               # Subject overview, syllabus mapping, exam weightage, navigation index
├── questions.md            # Master question index mapping all 5 units (Mid-1 + Mid-2 + Sem-End)
├── unit1.md                # Unit 1 worked exam answers (Mid-1 scope)
├── unit2.md                # Unit 2 worked exam answers (Mid-1 scope)
├── unit3.md                # Unit 3 worked exam answers (Mid-2 scope)
├── unit4.md                # Unit 4 worked exam answers (Mid-2 scope)
├── unit5.md                # Unit 5 worked exam answers (Mid-2 scope)
├── raw/                    # ALL raw PDFs, PPTs, DOCX, model papers, handwritten notes
└── figures/                # (Optional) Frameless dark-mode SVG/PNG diagrams and charts
```

### Root-Level Directory Layout
```
Shiroya/
├── .gitignore              # Ignores Obsidian volatile state (workspace*.json) & OS files
├── preferences.md          # Permanent repository rules and standards (this file)
├── README.md               # Master semester syllabus, subject index, and academic calendar
├── academic-calendar.md    # Formatted university calendar & holiday schedule
├── ds-syllabus.md          # Complete program curriculum & regulation guide
├── exam-timetable.md       # Mid and Semester-end examination timetables
├── exam-schedule.md        # Subject-wise exam schedule summary
└── raw/                    # Root raw administrative documents (PDFs, PPTs, full regulation syllabus)
```

---

## 4. File Naming Conventions

| Category | Standard Pattern | Examples | Prohibited Variations |
| :--- | :--- | :--- | :--- |
| **Unit Answers** | `unit-<N>.md` or `unit<N>.md` (all lowercase, hyphenated standard) | `unit-1.md`<br>`unit-2.md`<br>`unit-3.md`<br>`unit-4.md`<br>`unit-5.md` | ❌ `UNIT-I.md`<br>❌ `Unit 3.md`<br>❌ `unit 3 answers.md` |
| **Question Index** | `questions.md` | `questions.md` | ❌ `question.md`<br>❌ `IMP-QUESTIONS.md`<br>❌ `Important Questions.md`<br>❌ `QUESTIONS.md` |
| **Subject Index** | `README.md` | `README.md` | ❌ `readme.md`, `index.md` |
| **Raw Folder** | `raw/` | `<SUBJECT>/raw/` | ❌ `Raw/`, `PDFs/`, `sources/` |
| **Figures Folder** | `figures/` | `<SUBJECT>/figures/` | ❌ `images/`, `Figures/`, `assets/` |
| **Raw Files** | Descriptive kebab-case or clean original name | `raw/mid2-imp-questions.pdf`<br>`raw/unit-3-slides.pptx` | ❌ Storing PDFs or PPTs in subject root or repo root |

---

## 5. Raw Source Asset Policy (Zero-Loose-Asset Rule)

1. **Mandatory Storage in `raw/`:**
   - **No PDF, PPT, PPTX, DOC, DOCX, XLS, or XLSX file may ever exist in the root of a subject folder or in the repository root.**
   - All source slide decks, syllabus PDFs, question paper scans, and sample programs must be placed immediately into either:
     - The subject-level `raw/` directory (e.g., `FDS/raw/`), or
     - The global root `raw/` directory for university-wide materials.
2. **Source Provenance Mapping:**
   - When answers or question banks are synthesized, the corresponding raw document(s) must be explicitly listed in `README.md` and cited in the question metadata block.
   - Example: `Source: raw/FDS_UNIT_IV.pptx (Slides 12–19)`

---

## 6. `questions.md` Formatting & Linking Rules

The `questions.md` file serves as the master map for all questions across all 5 units.

### The "No Long Blue Link" Rule
- **Strictly Prohibited:** Wrapping an entire question sentence in markdown link syntax. Long colored blue link blocks cause visual clutter and degrade scanability.
  - ❌ `* [1. Describe the Divide and Conquer strategy and explain the three fundamental steps with suitable examples. (8M)](unit3.md#1-describe-the-divide-and-conquer-strategy)`
- **Mandatory Standard:** Keep the question statement in clean, neutral text. Append a compact navigation link at the end:
  - ✅ `1. Describe the Divide and Conquer strategy and explain the three fundamental steps with suitable examples. (8M) — [→ Answer](unit3.md#1-divide-and-conquer-strategy)`

### Master Question File Structure
```markdown
# <Subject Full Name> — Master Question Bank & Exam Guide

> **Course Code:** `<CODE>` | **Program:** B.Tech — III Semester | Aditya University  
> **Navigation:** [Unit 1](#unit-i) · [Unit 2](#unit-ii) · [Unit 3](#unit-iii) · [Unit 4](#unit-iv) · [Unit 5](#unit-v)

---

## UNIT I — <Unit Title>
*Exam Scope: Internal Exam 1 (Mid-1) & Semester-End Exam*

### 8-Mark / 4-Mark Questions
1. Question statement text here in clear, plain font. (4M/8M) — [→ Answer](unit1.md#anchor-1)
2. Question statement text here. (8M) — [→ Answer](unit1.md#anchor-2)

### 2-Mark Short Questions
1. Define <term>. (2M) — [→ Answer](unit1.md#2m-q1)
2. State the difference between X and Y. (2M) — [→ Answer](unit1.md#2m-q2)

---
```

---

## 7. Answer Synthesis & Note Formatting Standards

### Core Philosophy: True Preparation Notes (Full-Marks & Zero Complexity)
- **Preparation Notes, Not Corporate Cheat-Sheets:** 
  - ❌ **Anti-Pattern (Corporate Slide Syndrome):** Never compress complex concepts into cryptic 1–2 line robotic bullet points or corporate executive summaries. Stripping away the explanation makes notes harder to understand, unnatural to read, and impossible to reproduce in a university exam for full marks.
  - ✅ **The Standard (Exam-Ready Preparation Guide):** Notes must read like the clearest, most intuitive explanation written by a top-scoring student. The student must understand *why* a concept exists, *how* it works in simple English, and have the exact depth needed to fill 1.5–3 pages on an answer booklet to secure full marks (4M / 8M / 10M).
- **Simple Enough to Understand, Thorough Enough to Score:**
  - Lead with plain-language intuition before dense formalisms.
  - Every technical term must be explained in clear, natural prose before diving into rules.
  - Retain hand-drawable diagrams, relatable database tables, and step-by-step walkthroughs.

---

### The 5-Part Exam Answer Blueprint (Standard Structure for Every Question)

Every question answer in `unit<N>.md` must follow this 5-part blueprint:

```markdown
## <Q#>. <Question Statement> (Marks: 4M / 8M)

### 1. Intuition & Core Definition
- **Intuitive Explanation (In Plain English):** A 2–3 sentence plain-language explanation of what problem this concept solves and why we care. (e.g., "Without normalization, deleting a course might accidentally wipe out an entire student's record...").
- **Formal Textbook Definition:** The standard, formal academic definition. Highlight **crucial keywords in bold** that evaluators look for when checking answer sheets.

### 2. Hand-Drawable Diagram / Relational Schema
- Provide a clean, hand-drawable diagram, schema box, or dark-mode visual (`figures/<subject>_q<n>_...png` or clean ASCII diagram).
- Include a 2-line explanation of the diagram's components (what each box, arrow, or symbol represents) so the student knows what to draw on paper.

### 3. Core Mechanics & Deep Breakdown (No Telegraphic Bullets)
- Explain the key types, properties, algorithms, or rules in well-developed, clear paragraphs or explanatory bullet points.
- **Rule:** Do NOT truncate explanations into cryptic one-liners. Give complete, easy-to-follow sentences that explain both the *rule* and the *reason* behind it.
- Use comparison tables where contrasting two concepts (e.g., 3NF vs. BCNF, Primary vs. Secondary Index).

### 4. Concrete, Relatable Example (Tables / Query / Step-by-Step Trace)
- Use standard, intuitive schemas that every student knows (`STUDENT`, `COURSE`, `EMPLOYEE`, `ORDERS`).
- When explaining problems/solutions (like Normalization or Anomalies), show:
  1. The **Before Table** (with sample data showing the flaw/anomaly).
  2. The **Reason it fails** (explained simply).
  3. The **After Decomposed Tables** (with sample data showing how it fixes the issue).
- For SQL / Code: Provide valid, syntax-highlighted SQL queries with an explanation of what the query produces.

### 5. Exam Strategy & Marks Breakdown
- **If Asked for 4 Marks:** State precisely what to write (e.g., "Write Definition + Draw Box Diagram + Mention the 3 types with 1 line each").
- **If Asked for 8 Marks:** State how to expand (e.g., "Include the full Before/After table breakdown, write the SQL query, and explain both rules").
- **Key Scoring Points:** Bullet list of the 3–4 exact phrases/diagrams the university examiner awards marks for.
```

---

### Code Snippet Guidelines
- **Minimal Boilerplate:** Strip out excessive header files, unnecessary helper functions (e.g. redundant `printArray` templates), and unrelated error checks unless explicitly asked.
- **Syntactically Correct:** Code must be valid and standard (C++17, Python 3.10+, Java 17+, SQL:2016).
- **Handwriting-Friendly:** If an exam answer requires code, keep the logic concise enough to write comfortably in ~15–20 lines.

### Algorithmic & Mathematical Standards
- Use the **2-Step Paper Method** for manual tracing problems (e.g., Floyd-Warshall, Quick Sort, Knapsack, Dijkstra):
  - **Step 1:** Initial configuration table/matrix with index notation.
  - **Step 2:** Iteration passes showing formula applied, pivot selection, and updated state.
- **LaTeX Math Formatting:**
  - Inline equations: `$O(V \cdot E)$`, `$\sum_{i=1}^n i$`.
  - Display equations: On separate lines wrapped in `$$...$$`.
  - Always escape literal dollar signs (`\$`) in prose to prevent rendering corruption.

### Figures & Visual Assets
- All custom or extracted figures should be saved in `<SUBJECT>/figures/`.
- Figures should be **frameless, dark-mode friendly** (transparent or deep dark background), avoiding harsh white boxed borders.

---

## 8. Extra Operational Rules & Best Practices

### Git Commit Conventions
Commit messages must be concise, descriptive, and prefixed with the subject scope:
- `docs(<SUBJECT>): <action description>`
- `refactor(<SUBJECT>): standardize files to unit1.md-unit5.md format`
- `chore(repo): archive sem-3 branch and initialize sem-4`

### Source-First Authoring Workflow
Whenever new notes or questions are prepared:
1. **Collect & Archive:** First place all provided PPTs, PDFs, and assignment questions into `<SUBJECT>/raw/`.
2. **Index in `questions.md`:** List all questions with exam weightage (8M/4M/2M) and source links.
3. **Synthesize into `unit<N>.md`:** Write answers referencing the exact raw slides/documents first. Only query external references if the faculty materials lack coverage.

### Standardization Checklist for Existing Subjects
Existing folders in the repository should be migrated to match this standard:
- [ ] Rename `UNIT-I.md`, `UNIT-II.md`, etc., or `Unit 3.md`, `unit 3 answers.md` → `unit-1.md`–`unit-5.md` (or `unit1.md`–`unit5.md`).
- [ ] Rename all variants of `IMP-QUESTIONS.md`, `question.md`, `Important Questions.md` → `questions.md`.
- [ ] Ensure all raw PDFs/PPTs in subject roots are moved into their respective `raw/` subdirectories.
- [ ] Update `questions.md` to ensure no question text is wrapped in full blue hyperlink blocks.
