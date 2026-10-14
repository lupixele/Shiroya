# Unit 5 — Answers

> **Questions File:** [`questions.md` — Unit 5](questions.md#unit-5)

---

### 1. Analyze the importance of refactoring and Continuous Integration in maintaining Agile software quality

In Agile, code changes in every iteration. Two practices keep it clean and stable: **refactoring** and **Continuous Integration (CI)**.

- **Refactoring** = improving the internal structure of code **without changing its behaviour**.
- **CI** = merging code into a shared repository **many times a day**, with an **automatic build and test** after every merge.

**Importance of Refactoring:**
1. **Better design:** removes messy or duplicate code so the structure stays clean.
2. **Easy to understand:** clear names and small methods help new members read the code.
3. **Reduces technical debt:** small regular clean-ups stop "bad code" from piling up.
4. **Easy to change:** clean code lets the team add new features quickly.
5. **Fewer bugs:** simple code hides fewer defects.

**Importance of Continuous Integration:**
1. **Early bug detection:** a broken build or failing test shows within minutes.
2. **No big-bang integration:** small, frequent merges avoid large conflicts.
3. **Fast feedback:** developers know at once if their change caused a problem.
4. **Always-ready build:** the product is stable and can be released at any time.
5. **Consistent quality:** automated tests run every time, not only when someone remembers.

**How they work together:**
- Refactoring is **safe because CI runs the automated tests** after each change. If a refactoring breaks something, CI reports it immediately.
- CI stays healthy because refactoring keeps the code easy to build and test.

```
Developer refactors / adds code → Commit → CI server builds & runs tests
        ↑                                           │
        └──── fix quickly if red ◄──── Pass / Fail ─┘
```

**Conclusion:** Refactoring keeps the code clean and CI keeps it working. Together they maintain high quality even when requirements change often.

---

### 2. Identify any four common refactoring techniques

**Refactoring** means changing the structure of code without changing what it does. Four common techniques:

**1. Extract Method**
- Take a block of code from a long method and move it into a **new, well-named method**.
- Before: one 60-line method doing many things.
- After: small methods like `calculateTotal()` and `printBill()`.
- Benefit: shorter, readable, reusable code.

**2. Rename Method / Variable**
- Change unclear names to **meaningful names**.
- Example: `int d;` → `int daysSinceLastLogin;`
- Benefit: code explains itself.

**3. Move Method (or Move Field)**
- Shift a method to the class that **uses it most**.
- Example: move `calculateInterest()` from `Customer` class to `Account` class.
- Benefit: better responsibility and low coupling.

**4. Replace Magic Number with Named Constant**
- Replace raw numbers with a **named constant**.
- Example: `price * 0.18` → `price * GST_RATE`.
- Benefit: easy to understand and change in one place.

**Other techniques (extra):**
- **Remove Duplicate Code**, **Extract Class**, **Inline Method**, **Replace Conditional with Polymorphism**, **Introduce Parameter Object**.

**Rules while refactoring:**
- Make **small steps**.
- **Run tests** after every step.
- Do not add new features at the same time.

**Conclusion:** These techniques improve readability and design while keeping the behaviour the same.

---

### 3. Describe the Open-Closed Principle (OCP) with a suitable example

**Definition:** The **Open-Closed Principle** is the "O" in **SOLID**. It was made popular by Bertrand Meyer and Robert C. Martin. It states:

> **Software entities (classes, modules, functions) should be open for extension but closed for modification.**

- **Open for extension:** we can add new behaviour.
- **Closed for modification:** we do this **without editing existing, tested code**.

**Example 1: Shapes and area (violating OCP)**
```
class AreaCalculator {
    double area(Object shape) {
        if (shape is Circle)  return pi * r * r;
        if (shape is Square)  return side * side;
        // new shape → must edit this method again
    }
}
```
Problem: every new shape (Triangle, Rectangle) forces us to **modify** `AreaCalculator`, which may introduce bugs.

**Example 2: Following OCP**
```
interface Shape { double area(); }

class Circle    implements Shape { double area() { return pi*r*r; } }
class Square    implements Shape { double area() { return side*side; } }
class Triangle  implements Shape { double area() { return 0.5*b*h; } }   // new, no change elsewhere
```
`AreaCalculator` simply calls `shape.area()`. A new shape is added by **creating a new class only**.

**Real-life example:** A mobile phone charger socket. You can plug in new devices (extension) without changing the socket itself (modification).

**How OCP is achieved:** by using **abstraction, interfaces and inheritance / polymorphism**.

**Benefits:**
- Existing tested code stays **safe**, so fewer bugs.
- New requirements are added **easily and quickly**.
- Code is **flexible and reusable**.
- Supports frequent change, which is essential in Agile.

**Conclusion:** OCP lets a system grow by adding new code instead of changing old code, which makes software stable and easy to maintain.

---

### 4. Explain the role of Git in Agile software development

**Definition:** **Git** is a free, **distributed version control system (VCS)**. It records every change made to the source code and lets many developers work on the same project safely. Every developer has a **full copy** of the repository and its history.

**Role of Git in Agile:**

1. **Tracks history of changes**
   - Every change is saved as a **commit** with the author, date and message.
   - Any old version can be restored.

2. **Branching and merging**
   - Each feature or user story is built on its own **branch**, then merged into the main branch.
   - Supports parallel work in the same Sprint.

3. **Supports team collaboration**
   - Many developers work together without overwriting each other's work.
   - Shared remote repositories (GitHub, GitLab, Bitbucket) act as a central point.

4. **Enables Continuous Integration**
   - A push or pull request triggers an automatic **build and test**.
   - Fits the Agile aim of frequent integration.

5. **Code review with pull requests**
   - Team members review changes before merging, which improves quality and shares knowledge.

6. **Supports frequent, small releases**
   - Small commits match short iterations.
   - **Tags** mark the release of each Sprint.

7. **Safe experimentation and rollback**
   - Developers try new ideas on a branch; a bad change is undone quickly with `revert`.

8. **Works offline and is fast**
   - Commits are done locally, then pushed when ready.

**Basic Git flow:**
```
Working folder → git add → Staging → git commit → Local repo → git push → Remote repo
```

**Conclusion:** Git gives Agile teams a safe, fast and collaborative way to manage code changes.

---

### 5. Why are design principles important when requirements change frequently?

**Design principles** are proven guidelines for writing flexible and maintainable code (for example **SOLID, DRY, KISS, YAGNI**). In Agile, requirements change in nearly every iteration, so good design is essential.

**Reasons they are important:**

1. **Easy to accommodate change:** principles like **OCP** let us add features by extension, not by rewriting.
2. **Low coupling, high cohesion:** each class has one job and few dependencies, so a change in one place does not break others.
3. **Reduced rework and cost:** well-designed code needs fewer edits for each new requirement.
4. **Fewer bugs and regressions:** modular code is easier to test and less likely to fail after a change.
5. **Better readability:** clean, consistent design helps new team members understand and modify the code quickly.
6. **Supports refactoring and TDD:** small, well-structured units are easy to refactor and test.
7. **Prevents technical debt:** following principles from the start keeps the design from decaying.
8. **Supports faster delivery:** teams can keep delivering working software every Sprint.

**Key principles (quick list):**
- **S – Single Responsibility:** one class, one reason to change.
- **O – Open-Closed:** open for extension, closed for modification.
- **L – Liskov Substitution:** subclasses can replace parent classes safely.
- **I – Interface Segregation:** many small interfaces are better than one large one.
- **D – Dependency Inversion:** depend on abstractions, not concrete classes.
- **DRY:** Don't Repeat Yourself. **KISS:** Keep It Simple. **YAGNI:** You Aren't Gonna Need It.

**Conclusion:** Design principles make the code flexible, so frequent requirement changes can be handled quickly, cheaply and safely.

---

### 6. What is Continuous Integration (CI)? Mention its major benefits

**Definition:** **Continuous Integration (CI)** is an Agile/XP practice where developers **merge their code into a shared repository frequently (at least daily)**. Every merge triggers an **automated build and automated tests**, so integration problems are found quickly.

**How CI works:**
1. Developer pulls the latest code and makes a small change.
2. Developer runs local tests and **commits / pushes** to the shared repository.
3. The **CI server** (Jenkins, GitHub Actions, GitLab CI) detects the change.
4. It **builds** the project and **runs automated tests**.
5. The team gets a **report**: pass or fail.
6. If it fails, the team **fixes it immediately**.

```
Developer → Commit/Push → Shared Repository → CI Server → Build → Automated Tests → Report
     ↑                                                                               │
     └──────────────────────── fix quickly if the build fails ◄──────────────────────┘
```

**Major benefits:**
1. **Early detection of bugs:** problems appear within minutes of the change.
2. **Fewer merge conflicts:** small and frequent merges avoid large conflicts.
3. **Faster feedback:** developers learn at once whether their change works.
4. **Always a working build:** the product is ready to demo or release anytime.
5. **Higher quality:** automated tests run on every integration.
6. **Reduced risk and cost:** issues are cheaper to fix when found early.
7. **Less manual work:** build and test are automated.
8. **Better team visibility:** everyone sees the status of the build.

**Good CI practices:** keep the build fast, commit often, never leave the build broken, and write automated tests.

**Conclusion:** CI keeps the code base healthy and supports quick, reliable delivery in Agile.

---

### 7. What is the role of Git in Agile software development?

*(This question is similar to Q4. Write the core points from Q4 and add the workflow angle below to make it complete.)*

**Definition:** **Git** is a distributed version control system that records every change in the source code. It lets an Agile team build features in parallel and merge them safely.

**Key Git concepts:**
- **Repository:** the project folder with its full history.
- **Commit:** a saved snapshot of changes.
- **Branch:** a separate line of work for a feature or fix.
- **Merge:** combining a branch into the main branch.
- **Pull request:** a request for the team to review changes before merging.
- **Tag:** a label for a release, e.g. `sprint-5-release`.

**Common commands:**

| Command | Purpose |
|---|---|
| `git clone` | Copy a remote repository |
| `git branch` / `git checkout -b` | Create a new branch |
| `git add` + `git commit` | Save changes |
| `git push` / `git pull` | Share / fetch changes |
| `git merge` | Combine branches |
| `git revert` | Undo a bad change safely |

**Git in the Agile workflow (feature-branch style):**
1. Product Owner adds a **user story** to the Sprint backlog.
2. A developer creates a **feature branch** for that story.
3. Code is written in small commits (often with TDD).
4. A **pull request** is raised and reviewed by teammates.
5. **CI** runs automated tests on the branch.
6. After approval, the branch is **merged** into the main branch.
7. At the end of the Sprint, the main branch is **tagged** as the release.

**Role summary:**
- Keeps the **history** of every Sprint's work.
- Allows **parallel development** of many stories.
- Supports **code review** and **CI**.
- Makes **rollback** easy if a change fails.

**Conclusion:** Git fits Agile's short iterations, teamwork and frequent releases, which is why it is the most widely used tool in Agile teams.

---

### 8. How does version control support team collaboration in Agile projects?

**Definition:** **Version control** is a system that records changes to files over time so that team members can work on the same project together and recall earlier versions. Examples: **Git, SVN, Mercurial**.

**Types:**
- **Centralised (e.g. SVN):** one central server holds the code.
- **Distributed (e.g. Git):** each developer has a full copy of the repository.

**How version control supports collaboration:**

1. **Single source of truth:** all members work from one shared repository, so nobody is unsure which file is the latest.
2. **Parallel development:** many developers work on different stories at the same time using **branches**.
3. **Conflict detection and merging:** when two people change the same code, the tool shows the conflict and helps merge it.
4. **Traceability:** every commit records **who changed what, when and why**, which supports accountability and easy debugging.
5. **Code review:** pull/merge requests let teammates review and comment before the code is accepted.
6. **Easy rollback:** if a change causes a problem, the team can go back to a stable version.
7. **Supports CI/CD:** commits trigger automated build and test, so integration happens frequently.
8. **Supports distributed teams:** members in different places can contribute through a remote repository.
9. **Knowledge sharing:** history and reviews help new members learn the code.

**Collaboration flow:**
```
Developer A ─┐
Developer B ─┼─► Branches → Pull Request & Review → Merge → Main branch → CI build/test
Developer C ─┘                (shared repository)
```

**Best practices:** commit small and often, write clear commit messages, pull latest changes before pushing, and never break the main branch.

**Conclusion:** Version control keeps the team in sync, protects their work and makes frequent, safe collaboration possible in Agile projects.

---

## Last-minute revision: Unit 5
- **Refactoring** = improve structure, same behaviour; **CI** = merge often, automatic build + tests. Refactoring is safe because CI runs the tests.
- **Four refactorings:** Extract Method, Rename, Move Method, Replace Magic Number with Constant.
- **OCP:** open for extension, closed for modification; use interfaces/polymorphism (Shape → Circle, Square, Triangle).
- **Git:** history, branching/merging, pull requests, CI trigger, tags for Sprint releases, rollback.
- **Design principles** (SOLID, DRY, KISS, YAGNI) keep code flexible so frequent change is cheap and safe.
