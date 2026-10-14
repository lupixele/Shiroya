# Unit 5 — Answers

[⬅ Back to Questions](questions.md#unit-5)

---

### 1. Analyze the importance of refactoring and Continuous Integration in maintaining Agile software quality

Both keep the code healthy while it changes often.

- **Refactoring improves design:** clean code is easier to read and change.
- **Refactoring cuts technical debt:** small fixes stop messy code from piling up.
- **CI finds bugs early:** every commit is built and tested automatically.
- **CI avoids integration problems:** frequent merging stops "big bang" conflicts.
- **Together they give safe change:** automated tests confirm that refactoring did not break anything.
- **Faster delivery:** a stable codebase is always ready to release.

[⬆ Back to top](#unit-5--answers)

---

### 2. Identify any four common refactoring techniques

1. **Extract Method:** move a code block into its own named method.
2. **Rename Method/Variable:** use clear, meaningful names.
3. **Move Method:** shift a method to the class where it belongs.
4. **Replace Magic Number with Constant:** give numbers meaningful names.

(Others: Remove Duplicate Code, Extract Class, Inline Method.)

[⬆ Back to top](#unit-5--answers)

---

### 3. Describe the Open-Closed Principle (OCP) with a suitable example

**OCP:** software entities (classes, modules) should be **open for extension but closed for modification**. We add new behaviour without changing existing, tested code.

**Example:** A `Shape` class has an `area()` method.
- **Bad:** one `AreaCalculator` with `if circle... if square...`. Every new shape forces us to edit it.
- **Good:** `Shape` is an interface. `Circle` and `Square` implement `area()`. A new `Triangle` is just a new class. Nothing existing changes.

**Why it matters:** fewer bugs, and new requirements are added safely.

[⬆ Back to top](#unit-5--answers)

---

### 4. Explain the role of Git in Agile software development

**Git** is a distributed **version control system** that tracks code changes.

- **History tracking:** every change is recorded; any version can be restored.
- **Branching and merging:** features are built on separate **branches** and merged later.
- **Supports CI:** each push triggers automatic builds and tests.
- **Parallel work:** many developers work together without overwriting each other.
- **Code review:** **pull requests** let the team review before merging.
- **Small, frequent commits** match Agile's short iterations.

[⬆ Back to top](#unit-5--answers)

---

### 5. Why are design principles important when requirements change frequently?

- **Easier change:** good design lets us add features without rewriting everything (e.g. **OCP**).
- **Low coupling, high cohesion:** a change in one part does not break others.
- **Less rework:** a clean design cuts cost and time for each change.
- **Fewer bugs:** modular code is easier to test and fix.
- **Readable code:** new team members understand and extend it faster.
- **Supports refactoring:** principles like **SOLID** and **DRY** guide safe improvement.

[⬆ Back to top](#unit-5--answers)

---

### 6. What is Continuous Integration (CI)? Mention its major benefits

**CI** is the practice of **merging code into a shared repository many times a day**. Each merge triggers an **automatic build and test run**.

**Benefits:**
- **Early bug detection:** problems show up within minutes.
- **Fewer merge conflicts:** small, frequent merges.
- **Faster feedback** to developers.
- **Always-working build,** ready to release.
- **Better quality** through automated tests.
- **Less risk and lower cost** of integration.

Common tools: Jenkins, GitHub Actions, GitLab CI.

[⬆ Back to top](#unit-5--answers)

---

### 7. What is the role of Git in Agile software development?

Same as Q4. Extra angle: Git's **tags and releases** mark each sprint's increment, so a working version of every iteration can be retrieved at any time.

[⬆ Back to top](#unit-5--answers)

---

### 8. How does version control support team collaboration in Agile projects?

**Version control** (e.g. Git) is a shared record of all code changes.

- **Single source of truth:** everyone works from the same central repository.
- **Parallel development:** **branches** let many people work at once.
- **Conflict handling:** merge tools show and resolve overlapping changes.
- **Traceability:** each commit shows **who changed what and why**.
- **Code reviews:** pull requests give feedback before merging.
- **Rollback:** a bad change can be undone quickly.
- **CI link:** commits trigger automatic builds and tests.

[⬆ Back to top](#unit-5--answers)

---

## Last-minute revision: Unit 5
- **Refactoring** improves structure without changing behaviour; **CI** merges and tests often.
- **Four refactorings:** Extract Method, Rename, Move Method, Replace Magic Number.
- **OCP:** open for extension, closed for modification (e.g. new `Shape` subclasses).
- **Git** gives history, branching, pull requests and CI triggers.
- **Design principles** (SOLID, DRY) make frequent change cheap and safe.
