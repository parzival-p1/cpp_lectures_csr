#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student {
    private:
        string name;
        string lastName;
        int studentId;
        float gpa;
        Student *next;

    public:
        Student() {
            name = lastName = "";
            studentId = 0;
            gpa = 0.0;
            next = NULL;
        }

        Student(string name, string lastName, int studentId, float gpa)
        {
            this->name = name;
            this->lastName = lastName;
            this->studentId = studentId;
            this->gpa = gpa;
            next = NULL;
        }

        void print() {
            cout<<studentId<<" - "<<name<<" "<<lastName<<" GPA: "<<gpa<<endl;
        }

        void printId()
        {
            cout<<studentId;
        }

        void setName(string name) { this->name = name; }
        string getName() { return name; }
        void setLastName(string lastName) { this->lastName = lastName; }
        string getLastName() { return lastName; }
        void setStudentId(int studentId) { this->studentId = studentId; }
        int getStudentId() { return studentId; }
        void setGpa(float gpa) { this->gpa = gpa; }
        float getGpa() { return gpa; }
        void setNext(Student *s) { this->next = s; }
        Student *getNext() { return this->next; }
};

#endif // STUDENT_H_INCLUDED
