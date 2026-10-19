# CHAINED INHERITANCE (ACADEMIC PERFORMANCE)

Chained (Multilevel) Inheritance is an Object-Oriented Programming mechanism where a class is derived from another derived class, forming a multi-step hierarchy (`Base -> Intermediate -> Derived`). In [chainedInheritance1.cpp](./chainedInheritance1.cpp), this is modeled using a student's academic performance progression from student identity (`Student`), to continuous assessment (`Coursework`), to final exam grading (`FinalResult`).

**OOP Concepts Used**
• **Multilevel (Chained) Inheritance:** `FinalResult` inherits from `Coursework`, which inherits from `Student`. This allows `FinalResult` to combine `catMarks` (inherited from `Coursework`) with its own `examMarks` to compute the final score.
• **Protected Access (`protected`):** Members like `studentName`, `regNumber`, `courseName`, and `catMarks` are declared `protected` so they remain hidden from outside code while being directly accessible to derived classes (`calculateTotal()` directly accesses `catMarks`).
• **Constructor Chaining:** The `FinalResult` constructor passes arguments up to `Coursework`, which forwards the student details up to `Student`.
• **Const Member Functions:** Functions (`showStudent()`, `showCoursework()`, `showExam()`, `calculateTotal()`) are marked `const` so they do not alter the object's state.

**Algorithm**
1. **Base Class (`Student`):** Store `studentName` and `regNumber`, and implement `showStudent()`.
2. **Intermediate Class (`Coursework`):** Inherit publicly from `Student`, add `courseName` and `catMarks` (out of 30), and implement `showCoursework()`.
3. **Derived Class (`FinalResult`):** Inherit publicly from `Coursework`, add `examMarks` (out of 70), and implement `showExam()` and `calculateTotal()` (`catMarks + examMarks`).
4. **Execution in `main()`:**
   a. Instantiate `FinalResult result1{"Joseph", 2026, "C++ Programming", 26.0, 58.0}`.
   b. Call `result1.showStudent()` (inherited from `Student`).
   c. Call `result1.showCoursework()` (inherited from `Coursework`).
   d. Call `result1.showExam()` and `result1.calculateTotal()` (defined locally in `FinalResult`).

**Possible Error Points**
• **Module & Format Support:** Uses C++23 (`import std;` and `format()`). Compiling with an older compiler standard will cause errors.
• **Lack of Input Validation:** Does not validate that `catMarks` is within `0–30` or `examMarks` is within `0–70`.
