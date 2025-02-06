#include<iostream>
#include<iomanip> 
#include<map>
#include<string>
using namespace std;


double calculateCGPA(double totalGradePoints, int totalCredits) {
    if(totalCredits==0) {
        return 0.0;
    }
    return totalGradePoints/totalCredits;
}

int main() {
  system("cls");
    cout<<"------------------------------------------------------------\n";
    cout<<"                     CGPA CALCULATOR                        \n";
    cout<<"------------------------------------------------------------\n";

    map<string,double> gradeToPoints = {
        {"O",10.0},{"A+",9.0},{"A",8.0},{"B+",7.0},{"B",6.0},{"C",5.5},
        {"W",0.0},{"F",0.0},{"Ab",0.0},{"I",0.0},{"*",0.0}};
    
    int numSubjects;
    cout<<"Enter the number of Subjects: ";
    cin>>numSubjects;
    cout<<endl;
    double totalGradePoints = 0.0;
    int totalCredits = 0;
    
    for(int i=1;i<=numSubjects;++i) {
        int credits;
        string grade;
        
        cout<<"Enter Credits for Subject "<<i<<": ";
        cin>>credits;
        
        cout<<"Enter Grade (O, A+, A, B+, B, C, W, F, Ab, I, *) for Subject "<<i<<": ";
        cin>>grade;
        
        if(gradeToPoints.find(grade)==gradeToPoints.end()) {
            cout<<"Invalid grade entered. Please try again.\n";
            --i;
            continue;
        }
        
        totalGradePoints += credits*gradeToPoints[grade];
        totalCredits += credits;
        cout<<endl;
    }
    
    double cgpa = calculateCGPA(totalGradePoints, totalCredits);
    
    cout<<"|----------------------RESULT----------------------|\n";
    cout<<"| Total Grade Points: "<<totalGradePoints<<"                            |"<<endl;
    cout<<"| Total Credits: "<<totalCredits<<"                                 |"<<endl;
    cout<<"|----------------------YOUR CGPA-------------------|\n";
    cout<<fixed<<setprecision(3);
    cout<<"| Your CGPA is: "<<cgpa<<"                              |"<<endl;
    cout<<"|--------------------------------------------------|\n";
    return 0;
}