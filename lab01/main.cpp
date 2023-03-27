#include <iostream>
#include <vector>
using namespace std;

struct Student{ //Описание структуры, содержащей поля типа string, int, char, double
string name{};
string surname{};
char english_grade{};
int student_ID{};
int russian_grade{};
double points{};
Student *next{};
};

void add_to_start(Student *& Head,string name, string surname, int student_ID, double points,
                  int russian_grade, char english_grade){ //Добавление элемента в начало списка
    Student *newstudent = new Student;
    newstudent->name = name;
    newstudent->surname = surname;
    newstudent->student_ID = student_ID;
    newstudent->points = points;
    newstudent->russian_grade = russian_grade;
    newstudent->english_grade = english_grade;
    newstudent->next = Head;
    Head = newstudent;
    return;
}

void add_to_end(Student *& Head,string name, string surname, int student_ID, double points,
                int russian_grade, char english_grade){ //Добавление элемента в конец списка;
    Student *tmp = Head;
    if (Head == NULL){
        add_to_start(Head, name, surname, student_ID, points, russian_grade, english_grade);
        return;
    }
    while (tmp->next) tmp = tmp->next;
    Student *newstudent = new Student;
    newstudent->name = name;
    newstudent->surname = surname;
    newstudent->student_ID = student_ID;
    newstudent->points = points;
    newstudent->russian_grade = russian_grade;
    newstudent->english_grade = english_grade;
    newstudent->next = NULL;
    tmp->next = newstudent;
    return;
}

int insert_after(Student *& Head, string name, string surname, int student_ID, double points,
                 int russian_grade, char english_grade, int student_ID_After){ //Добавление элемента в список
    // после заданного элемента
    if (Head == NULL) return 1;
    Student *tmp = Head;
    while (tmp != NULL && tmp -> student_ID != student_ID_After)
        tmp = tmp->next;
    if (tmp == NULL) return 1;
    Student *newstudent = new Student;
    newstudent->name = name;
    newstudent->surname = surname;
    newstudent->student_ID = student_ID;
    newstudent->points = points;
    newstudent->russian_grade = russian_grade;
    newstudent->english_grade = english_grade;
    newstudent->next = tmp->next;
    tmp->next = newstudent;
    return 0;
}


int insert_before(Student *& Head, string name, string surname, int student_ID, double points,
                 int russian_grade, char english_grade, int student_ID_Before){ //Добавление элемента в список
    // перед заданным элементом;
    if (Head == NULL) return 1;
    if (Head->student_ID == student_ID_Before){
        add_to_start(Head, name, surname, student_ID, points, russian_grade, english_grade);
        return 0;
    }
    Student *prev = Head, *tmp=Head->next;
    while (tmp != NULL && tmp -> student_ID != student_ID_Before){
        prev = prev->next;
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp->student_ID!=student_ID_Before) return 1;
    Student *newstudent = new Student;
    newstudent->name = name;
    newstudent->surname = surname;
    newstudent->student_ID = student_ID;
    newstudent->points = points;
    newstudent->russian_grade = russian_grade;
    newstudent->english_grade = english_grade;
    newstudent->next = tmp->next;
    tmp->next = newstudent;
    return 0;
}

int remove_from_list(Student *& Head, int student_ID){ //Удаление из списка элемента с заданным именем
    if (Head == NULL) return 1;
    Student *tmp = Head;
    if (Head->student_ID == student_ID){
        Head = Head->next;
        delete tmp;
        return 0;
    }
    if (Head->next == NULL) return 1;
    Student *prev = Head;
    tmp = Head->next;
    while (tmp->next != NULL && tmp->student_ID != student_ID){
        prev = prev->next;
        tmp = tmp->next;
    }
    if (tmp->next==NULL && tmp->student_ID != student_ID)
        return 1;
    prev -> next = tmp -> next;
    delete tmp;
    return 0;
}

void print(Student *Head){ // Вывод содержания списка на экран;
    int i = 1;
    if (Head == NULL){
        cout<<"Список пуст";
        return;
    }
    Student *tmp = Head;
    while (tmp != NULL){
        cout << i << ") " << tmp->name << ' ' << tmp->surname << ' ' << tmp->student_ID << ' ';
        cout << tmp->points << ' ' << tmp->russian_grade << ' ';
        cout << tmp->english_grade << "; " << endl;
        i++;
        tmp = tmp->next;
    }
    return;
}


int main(){
    setlocale(LC_ALL, "Russian");
    typedef Student *students;
    students Head = NULL;
    int n, student_ID, russian_grade, student_ID_before, student_ID_after;
    string name, surname;
    char english_grade;
    double points;
    cout << "Краткое руководство по работе с данной программой: " << endl;
    cout << "Данная программа позволяет хранить список отметок студентов, а также самые базовые их ";
    cout << "данные, такие как имя и фамилия, а также номер студенческого билета";
    cout << "Если вы хотите добавить студента в начало списка - нажмите 1" << endl;
    cout << "Если вы хотите добавить студента в конец списка - нажмите 2" << endl;
    cout << "Если вы хотите добавить студента после какого-то другого студента - нажмите 3" << endl;
    cout << "Если вы хотите добавить студента до какого-то другого студента - нажмите 4" << endl;
    cout << "Если вы хотите удалить студента из списка - нажмите 5" << endl;
    cout << "Если вы хотите отобразить список - нажмите 6" << endl;
    cout << "Если вы хотите закончить работу со списком - нажмите 0" << endl;
    cout << "Для начала работы программы пожалуйста нажмите нужную цифру" << endl;
    cin >> n;
    while (n != 0){
        if (n == 1) {
            cout << "Введите данные студента в формате:" << endl;
            cout << "Имя Фамилия Студенческий билет(int) Баллы(double) Итоговую отметку в русском формате(int) ";
            cout << "Итоговую отметку в английском формате(char)" << endl;
            cin >> name >> surname >> student_ID >> points >> russian_grade >> english_grade;
            add_to_start(Head, name, surname, student_ID, points, russian_grade, english_grade);
        }
        if (n == 2) {
            cout << "Введите данные студента в формате:" << endl;
            cout << "Имя Фамилия Студенческий билет(int) Баллы(double) Итоговую отметку в русском формате(int) ";
            cout << "Итоговую отметку в английском формате(char)" << endl;
            cin >> name >> surname >> student_ID >> points >> russian_grade >> english_grade;
            add_to_end(Head, name, surname, student_ID, points, russian_grade, english_grade);
        }
        if (n == 3) {
            cout << "Введите данные студента в формате:" << endl;
            cout << "Студак того, после кого он должен быть Имя Фамилия Студенческий билет(int) Баллы(double) ";
            cout << "Итоговую отметку в русском формате(int) Итоговую отметку в английском формате(char)" << endl;
            cin >> student_ID_after >> name >> surname >> student_ID >> points >> russian_grade >> english_grade;
            insert_after(Head, name, surname, student_ID, points, russian_grade, english_grade, student_ID_after);
        }
        if (n == 4) {
            cout << "Введите данные студента в формате:" << endl;
            cout << "Студак того, до кого он должен быть Имя Фамилия Студенческий билет(int) Баллы(double) ";
            cout << "Итоговую отметку в русском формате(int) Итоговую отметку в английском формате(char)" << endl;
            cin >> student_ID_before >> name >> surname >> student_ID >> points >> russian_grade >> english_grade;
            insert_before(Head, name, surname, student_ID, points, russian_grade, english_grade, student_ID_before);
        }
        if (n == 5) {
            cout << "Введите номер студенческого билета студента, которого вы хотите удалить из списка" << endl;
            cin >> student_ID;
            remove_from_list(Head, student_ID);
        }
        if (n == 6) {
            print(Head);
        }
        cin >> n;
    }
    return 0;
}