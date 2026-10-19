import std;
using namespace std;
//BASE CLASS
class AcademicResult{
public:
virtual void evaluate(double score) const{
cout << format("Student scored {}%\n", score);
}
};
//DERIVED CLASS 1
class Undergraduate : public AcademicResult{
public:
void evaluate(double score) const override{
if (score >= 50.0){
cout << format("Undergraduate ({}%): Pass (Meets 50% requirement).\n", score);
}
else{
cout << format("Undergraduate ({}%): Fail (Below 50% pass mark).\n", score);
}
}
};
//DERIVED CLASS 2
class Postgraduate : public AcademicResult{
public:
void evaluate(double score) const override{
if (score >= 60.0){
cout << format("Postgraduate ({}%): Pass (Meets 60% requirement).\n", score);
}
else{
cout << format("Postgraduate ({}%): Fail (Below 60% pass mark).\n", score);
}
}
};

int main(){

Undergraduate undergradStudent{};
Postgraduate postgradStudent{};

AcademicResult* resultPtr = nullptr;

resultPtr = &undergradStudent;
resultPtr->evaluate(72.0);

resultPtr = &postgradStudent;
resultPtr->evaluate(72.0);

cout << endl;

AcademicResult& ref1 = undergradStudent;
AcademicResult& ref2 = postgradStudent;

ref1.evaluate(55.0);
ref2.evaluate(55.0);

return 0;
}
