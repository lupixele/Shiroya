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
| **Unit Answers** | `unit<N>.md` (all lowercase, no space, no hyphen) | `unit1.md`<br>`unit2.md`<br>`unit3.md`<br>`unit4.md`<br>`unit5.md` | ❌ `UNIT-I.md`<br>❌ `Unit 3.md`<br>❌ `unit 3 answers.md`<br>❌ `unit-4.md` |
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

### Core Philosophy: Exam-Ready & High-Retention
- **Simple Enough to Remember:** Write answers optimized for what a student can realistically reproduce by hand on physical examination paper under timed constraints.
- **Zero Academic Bloat:** Eliminate verbose academic introductions, philosophical filler, historical musings, and discursive paragraphs.
- **Hierarchical Markdown Formatting:**
  - Lead with bold definition / summary formula.
  - Use structured comparison tables instead of rambling comparative prose.
  - Use numbered step-by-step algorithms / procedures.
  - Highlight key terms in **bold** to facilitate quick scanning.
  - Use clean bullet points with maximum 2–3 lines per point.

### Markdown Unit Notes Template (`unit<N>.md`)
```markdown
# <Subject Name> — Unit <N>: <Unit Title>

> **Course Code:** `<CODE>` | **Exam Scope:** <Mid-1 / Mid-2 / Sem-End>  
> **Source Materials:** [`raw/<filename>.pdf`](raw/<filename>.pdf) | [`raw/<slides>.pptx`](raw/<slides>.pptx)  
> **Master Questions Index:** [`questions.md`](questions.md#unit-<roman>)

---

## 8M-Q1: <Full Question Statement>
> **Marks:** 8M (or 4M) | **Frequency:** Mid-2 (2024, 2025), Model Paper | **Source:** [`raw/<deck>.pptx`](raw/<deck>.pptx)

### 1. Core Definition / Principle
- **<Core Term>:** Single concise sentence explaining the concept.

### 2. Key Characteristics / Architecture
| Parameter | Feature A | Feature B |
| :--- | :--- | :--- |
| **Basis** | Concise description | Concise description |

### 3. Step-by-Step Mechanism / Working
1. **Step 1 (<Name>):** Action description.
2. **Step 2 (<Name>):** Action description.

### 4. Code / Example (Minimal & Self-Contained)
```<lang>
// Minimal, runnable code snippet without redundant boilerplate
```

### 5. Exam Tip / Key Takeaway
> **Paper Writing Tip:** Draw the accompanying diagram in §2; examiners award 3 marks for the schematic.

---
```

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
- [ ] Rename `UNIT-I.md`, `UNIT-II.md`, etc., or `Unit 3.md`, `unit 3 answers.md` → `unit1.md`, `unit2.md`, `unit3.md`, `unit4.md`, `unit5.md`.
- [ ] Rename all variants of `IMP-QUESTIONS.md`, `question.md`, `Important Questions.md` → `questions.md`.
- [ ] Ensure all raw PDFs/PPTs in subject roots are moved into their respective `raw/` subdirectories.
- [ ] Update `questions.md` to ensure no question text is wrapped in full blue hyperlink blocks.
