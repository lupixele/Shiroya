# Link Format Demonstration (Obsidian vs Standard Markdown vs Hybrid)

This demonstration file illustrates the three linking strategies in Markdown vaults like Shiroya.

---

## 1. Pure Obsidian Wikilinks (What we currently have in `questions.md`)

### Syntax:
```markdown
[[unit-1#Question 1 — Evolution of C++ & Paradigm Shift|Evolution & Paradigm Shift]]
```

### How it renders:
[[unit-1#Question 1 — Evolution of C++ & Paradigm Shift|Evolution & Paradigm Shift]]

### Behavior:
- **Inside Obsidian:** ⭐️⭐️⭐️⭐️⭐️ (Flawless). Auto-completes headings as you type, updates automatically if you rename notes or move headings, shows backlink graphs, and supports block references.
- **On GitHub / Web:** ❌ (Broken). GitHub renders this as raw brackets or unlinked text because standard CommonMark does not support wikilinks.
- **Best for:** Private personal vaults viewed exclusively inside the Obsidian desktop/mobile app.

---

## 2. Standard Markdown Relative Links

### Syntax:
```markdown
[Evolution & Paradigm Shift](unit-1.md#question-1--evolution-of-c--paradigm-shift)
```

### How it renders:
[Evolution & Paradigm Shift](unit-1.md#question-1--evolution-of-c--paradigm-shift)

### Behavior:
- **Inside Obsidian:** ⭐️⭐️⭐️⭐️ (Works). Clicking opens `unit-1.md` and jumps straight to the anchor header.
- **On GitHub / Web:** ⭐️⭐️⭐️⭐️⭐️ (Flawless). GitHub natively turns this into a clickable hyperlink that loads the file and scrolls to the `#question-1--evolution-of-c--paradigm-shift` header.
- **Gotchas:** Requires GitHub-compatible anchor slugs (lowercase, punctuation stripped, spaces replaced with hyphens).
- **Best for:** Repositories hosted on GitHub and browsed by friends/collaborators on GitHub.com.

---

## 3. Clean Table Format (Shiroya FDS / P&S Gold Standard)

In subjects like `FDS/questions.md`, Shiroya uses a clean markdown table combining standard links with terminal anchors:

| Q# | Topic | Worked Answer Link |
| :---: | :--- | :--- |
| **Q1** | Evolution & Paradigm Shift | [→ `unit-1.md#Q1`](unit-1.md#question-1--evolution-of-c--paradigm-shift) |
| **Q2** | C vs C++ Comparison | [→ `unit-1.md#Q2`](unit-1.md#question-2--c-vs-c-comparison) |
| **Q3** | OOP Principles & Advantages | [→ `unit-1.md#Q3`](unit-1.md#question-3--oop-principles--advantages) |

### Behavior:
- **Inside Obsidian:** Clean, readable, jumps directly to the question.
- **On GitHub:** Fully interactive, neat layout, looks like an official syllabus index.

---

## Conclusion & Recommendation
If you read your notes inside **Obsidian only**, keep **Format 1 (Wikilinks)**.  
If you or your friends browse Shiroya directly on **GitHub**, **Format 2 or 3** is strictly better because nobody gets broken text.
