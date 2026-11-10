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
├── 2-marks.md              # Section A 2-Marks Short Answers (All 5 Units)
├── unit-1.md               # Unit 1 worked exam answers (8M questions)
├── unit-2.md               # Unit 2 worked exam answers (8M questions)
├── unit-3.md               # Unit 3 worked exam answers (8M questions)
├── unit-4.md               # Unit 4 worked exam answers (8M questions)
├── unit-5.md               # Unit 5 worked exam answers (8M questions)
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
1. Define <term>. (2M) — [→ Answer](2-marks.md#1-define-term)
2. State the difference between X and Y. (2M) — [→ Answer](2-marks.md#2-state-the-difference-between-x-and-y)

---
```

### 2-Mark Short Questions Rules (`2-marks.md`)
- **No `2M-` or `2m-` Heading Prefixes:** Never prefix individual question headings or anchor slugs with `2M-` or `2m-` (e.g., do not use `### 2M-1. ...` or `#2m-1-...`).
- **Heading Scoping:** The top-level document heading (`# <Subject> — 2-Marks Short Answers`) and the section heading (`### 2-Mark Short Questions`) already establish the 2-mark context. Question headings in `2-marks.md` must simply use standard question numbering: `### 1. <Question Title>` (or `### Q1. <Question Title>`).
- **Dedicated File:** All Section A 2-mark questions are collected into `2-marks.md`, leaving `unit-1.md` through `unit-5.md` dedicated exclusively to Section B 8-mark questions.

---

## 7. Answer Standards (Strict Raw-Material Transcoding)

- **Strictly Raw-Sourced, Zero AI Meta-Bloat:**
  - Unit answers must directly use the exact text, bullet points, explanations, and examples provided in the raw study materials (`raw/`).
  - Prohibit AI-generated filler, artificial coaching sections, and forced generic structures.
  - Preserve the student's authentic notes, simple examples, and memory tricks exactly as provided in the raw files.
- **Headings & Outline Compatibility:**
  - Question headings must use `## <Number>. <Title>` and subheadings must use `###` to support clean outline navigation in GitHub and Obsidian.

---

## 8. Extra Operational Rules & Best Practices

### Git Commit Conventions
Commit messages must be concise, descriptive, and prefixed with the subject scope:
- `docs(<SUBJECT>): <action description>`
- `refactor(<SUBJECT>): standardize files to unit1.md-unit5.md format`
- `chore(repo): archive sem-3 branch and initialize sem-4`

When commits are authored with agent assistance, include the relevant trailer:
- Claude: `Co-authored-by: Claude <claude@anthropic.com>`
- Animus: `Co-authored-by: Animus <animus@lupixele.online>`

### Raw-First Authoring Workflow
Whenever new notes or questions are prepared:
1. **Collect & Archive:** Place all provided PPTs, PDFs, and assignment questions into `<SUBJECT>/raw/`.
2. **Index in `questions.md`:** List all questions with exam weightage (8M/4M/2M) and clean source links.
3. **Direct Transcoding:** Transcode answers directly from the raw files into `unit-<N>.md` and `2-marks.md` without synthesizing external textbook filler.

### Standardization Checklist for Existing Subjects
Existing folders in the repository should be migrated to match this standard:
- [ ] Rename `UNIT-I.md`, `UNIT-II.md`, etc., or `Unit 3.md`, `unit 3 answers.md` → `unit-1.md`–`unit-5.md` (or `unit1.md`–`unit5.md`).
- [ ] Rename all variants of `IMP-QUESTIONS.md`, `question.md`, `Important Questions.md` → `questions.md`.
- [ ] Ensure all raw PDFs/PPTs in subject roots are moved into their respective `raw/` subdirectories.
- [ ] Update `questions.md` to ensure no question text is wrapped in full blue hyperlink blocks.
