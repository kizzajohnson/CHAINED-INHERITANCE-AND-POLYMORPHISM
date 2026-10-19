# POLYMORPHISM (ACADEMIC PERFORMANCE)

**Subject Matter Overview**
Polymorphism ("many forms") allows a single function call through a base-class pointer or reference to execute different behaviors depending on the actual derived object at runtime. In [polymorphism1.cpp](./polymorphism1.cpp), runtime polymorphism is modeled using university grading rules where an `Undergraduate` student passes at `50%`, whereas a `Postgraduate` student requires `60%` to pass.

**Hierarchy Diagram**
```text
               +-----------------------------------+
               |    AcademicResult (Base Class)    |
               |-----------------------------------|
               | + virtual evaluate(score) : void  |
               +-----------------------------------+
                        ^                 ^
                        |                 |
         +--------------+                 +--------------+
         |                                               |
+--------+------------------------+     +----------------+----------------+
|    Undergraduate (Derived 1)    |     |     Postgraduate (Derived 2)    |
|---------------------------------|     |---------------------------------|
| + evaluate(score) override      |     | + evaluate(score) override      |
|   Pass if score >= 50.0%        |     |   Pass if score >= 60.0%        |
+---------------------------------+     +---------------------------------+
```

**OOP Concepts Used**
• **Virtual Functions (`virtual`):** Declaring `virtual void evaluate(double score) const` in `AcademicResult` enables **dynamic dispatch**, ensuring the program selects the appropriate grading rule at runtime.
• **Function Overriding (`override`):** Both `Undergraduate` and `Postgraduate` override `evaluate(double score) const` with their respective pass thresholds (`50.0%` vs. `60.0%`).
• **Base-Class Pointers & References:** A base-class pointer (`AcademicResult* resultPtr`) and base-class references (`AcademicResult& ref1`, `AcademicResult& ref2`) invoke `evaluate()`, showing how the exact same score (`55.0%`) produces a **Pass** for an `Undergraduate` object and a **Fail** for a `Postgraduate` object.

**Algorithm**
1. **Base Class (`AcademicResult`):** Declare the virtual function `evaluate(double score) const`.
2. **Derived Class 1 (`Undergraduate`):** Inherit from `AcademicResult` and override `evaluate()` to pass scores `>= 50.0`.
3. **Derived Class 2 (`Postgraduate`):** Inherit from `AcademicResult` and override `evaluate()` to pass scores `>= 60.0`.
4. **Execution in `main()`:**
   a. Instantiate `Undergraduate undergradStudent{}` and `Postgraduate postgradStudent{}`.
   b. Use base-class pointer `resultPtr` to call `evaluate(72.0)` on both objects.
   c. Bind base-class references `ref1` and `ref2` to both objects and call `evaluate(55.0)` to show different outcomes for the same `55%` score.

**Output**
```text
Undergraduate (72%): Pass (Meets 50% requirement).
Postgraduate (72%): Pass (Meets 60% requirement).

Undergraduate (55%): Pass (Meets 50% requirement).
Postgraduate (55%): Fail (Below 60% pass mark).
```

**Possible Error Points**
• **Module & Format Support:** Uses C++23 (`import std;` and `format()`), requiring a C++23-capable compiler with module support.
• **Omitting `virtual`:** Removing `virtual` from the base class disables runtime polymorphism, causing pointer/reference calls to default to the base `AcademicResult::evaluate()` implementation.
