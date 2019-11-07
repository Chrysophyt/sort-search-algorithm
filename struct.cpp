#include <iostream>
#include <string>

struct Course{
    public:
        std::string courseName;
        float       courseGrade;

    //constructor
    Course(std::string CourseName, float CourseGrade){
        courseName = CourseName;
        courseGrade = CourseGrade;
    }
    Course(){

    }
};

struct Student {
    public:
        std::string nim;
        std::string name;

        void insertCourse(Course course){
            courses[currentCourseIndex++] = course;
        }

        float getGPA(){
            float temp = 0;
            for(int i = 0; i < currentCourseIndex; i++){
                temp += courses[i].courseGrade;
            }
            GPA = temp/ currentCourseIndex;
            return GPA;
        }

    Student(std::string Name, std::string NIM) {
        name = Name;
        nim = NIM;
        currentCourseIndex = 0;
    }

    private:
        float GPA;
        int currentCourseIndex;
        Course courses[40];

    
};

//Sequential Search
Student getStudentWithNIM(Student *students, int studentsSize, std::string nim){
    for (int i = 0; i < studentsSize; i++ ){
        if(students[i].nim == nim){
            return students[i];
        }
    }
    return Student("Not Found","-");
}

void printStudents(Student *students){
    for (int i = 0; i < 6; i++){
        std::cout << "\n" << i << "." <<students[i].name <<", GPA : " << students[i].getGPA()<<", NIM : "<<students[i].nim;
    }
}

int main(){
    //-----------Searching Example-----------------
    //Generate Data
    std::cout << "Contoh Searching \n";

    Student students[6] = {
        Student("Anthony", "18/431257/PA/18923"),
        Student("Bella"  , "18/431258/PA/18924"),
        Student("Cony"   , "18/431259/PA/18925"),
        Student("Delphi" , "18/431260/PA/18926"),
        Student("Epsilon", "18/431261/PA/18927"),
        Student("Farhan" , "18/431262/PA/18928")
    };

    for (int i = 0; i < 6; i++){
        students[i].insertCourse(Course("Kalkulus", 10*i+50));
    }

    for (int i = 0; i < 6; i++){
        students[i].insertCourse(Course("Kimia", 8*i+30));
    }

    printStudents(students);

    //ex Sequential Search
    std::cout << "\n Student with NIM 18/431262/PA/18928 are " << getStudentWithNIM(students, 6, "18/431262/PA/18928").name;
}

