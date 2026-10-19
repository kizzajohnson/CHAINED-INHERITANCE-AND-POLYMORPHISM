import std;
using namespace std;
//BASE CLASS
class Student{
protected:
string studentName;
int regNumber;

public:
Student(string name = "Unknown", int reg = 1000)
: studentName{name}, regNumber{reg}
{}
void showStudent() const{
cout << format("Student     : {} (Reg No: {})\n", studentName, regNumber);
}
};
//Intermediate Class
class Coursework : public Student{
protected:
string courseName;
double catMarks;

public:
Coursework(string name = "Unknown", int reg = 1000, string course = "C++", double cat = 0.0)
: Student{name, reg}, courseName{course}, catMarks{cat}
{}
void showCoursework() const{
cout << format("Course      : {} (CAT Marks: {}/30)\n", courseName, catMarks);
}
};
//Derived class
class FinalResult : public Coursework{
private:
double examMarks;

public:
FinalResult(string name, int reg, string course, double cat, double exam)
: Coursework{name, reg, course, cat}, examMarks{exam}
{}
double calculateTotal() const{
return catMarks + examMarks;
}
void showExam() const{
cout << format("Exam Marks  : {}/70\n", examMarks);
}
};

int main(){

FinalResult result1{"Joseph", 2026, "C++ Programming", 26.0, 58.0};

result1.showStudent();
result1.showCoursework();
result1.showExam();
cout << format("Total Score : {}%\n", result1.calculateTotal());

return 0;
}
