#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

// #define MAX 10
const int MAX = 10;

class HashTable {
    private:
        StudentList hashtable[MAX];
        unsigned int getHashIndex(Student *student); // genera el key
        unsigned int getHashIndex(int id);

    public:
        HashTable();
        void insertStudent(Student *student);
        void printAllStudents();
        void searchStudent();
}

HashTable::HashTable()
{

}

unsigned int HashTable::getHashIndex(Student *student)
{
    int key = student->getStudentId() % MAX;
    return key;
}

unsigned int HashTable::getHashIndex(int id)
{
    int key = id % MAX;
    return key;
}

void HashTable::insertStudent(Student *student)
{
    unsigned int keyIndex = getHashIndex(student);
    hashtable[keyIndex].insertStudent(student);
}

void HashTable::printAllStudents()
{
    for (int i = 0; i < MAX; i++)
    {
        cout<<"["<<i<<"] : ";
        hashtable[i].printAllStudentsIds();
    }
}

void HashTable::searchStudent()
{
    int id;

    cout<<"Introduzca el id del estudiante a buscar: ";
    cin>>id;

    unsigned int index = getHashIndex(id);
    Student *s = hashtable[index].searchStudent(id);

    if (s != NULL)
        s->print();
    else
        cout<<"No se encontro el estudiante.";
}

#endif // HASHTABLE_H_INCLUDED
