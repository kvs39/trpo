#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    char fio[50];
    int gruppa;
    bool offset[5];
    int exz[5], gpa;
};

struct authorisation {
    string login;
    string password;
    bool operator==(const authorisation &other) const {
        return login == other.login && password == other.password;
    }
};

void Autorization(){
    char r;
    string login, password;
    cout << "Введите логин и пароль: " << endl;
    while (true){
        cin >> login;
        cin >> password;
        if (login == "admin" && password == "admin"){

            break;
        }
        else if (login == "guest" && password == "guest"){

            break;
        }
        else{
            cout << "Такого пользователя не существует!";
            cout << "Вы хотите повторить?(y/n)";
            cin >> r;
            switch (r) {
                case 'y':
                    continue;
                case 'n':
                    break;
           }
       }
   }
}
void Admin(){

}

void Search(student* arr, int n)
    {
    char name[50];
    cout << "Введите ФИО студента, которого хотите найти... ";
    cin >> name;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(reinterpret_cast<const char *>(name), arr[i].fio) == 0)
            {
                cout <<"\t№ \t" << i+1;
                cout <<"\tFIO \t" << arr[i].fio;
                cout <<"\tGroup \t" <<arr[i].gruppa;
                cout <<"\tOffsets \t" << arr[i].offset;
                cout <<"\tExams \t" << arr[i].exz;
                cout <<"\tGPA \t" << arr[i].gpa;
                cout <<"\n\n";
            }
            else cout << "Ничего не найдено..." << endl;
        }
    }
void Add(student* (&arr), int& n)
{

    arr = new student[n];
    n++;
    cout << n + 1 << " студент: ";
    cout << "ФИО студента: ";
    cin >> arr[n].fio;
    cout << "группа(6-ти значное число): ";
    do{
        cin >> arr[n].gruppa;
    }while(!(arr[n].gruppa > 99999 && arr[n].gruppa < 1000000));
    cout << "зачет(1- сдал/0-не сдал)";
    for (int k = 0;k <= 4; k++ ){
        cin >> arr[n].offset[k];
    }
    cout << "Отметки по экзаменам: ";
    for (int k = 0;k <= 4; k++ ){
        do{
            cin >> arr[n].exz[k];
        }while(!(arr[n].exz[k] > -1 && arr[n].exz[k] < 11));
    }
}

void Delete(student* (&arr), int& n)
{
    int position;
    cout << "Введите номер студента в файле, который вы хотите удалить (от 1 до" << n << "): ";
    cin >> position;
    position--;
    if (position >= 0 && position < n)
    {
        student* buf = new student[n];
        for (int i = 0; i < n; i++)
        {
            buf[i] = arr[i];
        }
        --n;
        arr = new student[n];
        int k = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i != position)
            {
                arr[k] = buf[i];
                ++k;
            }
        }
        delete[]buf;
        cout << "Студент удален." << endl;
    }
    else cout << "Номер товара введен неверно!" << endl;
}

void Change(student* (&arr), int n)
{
    int position;
    cout << "Введите номер студента в файле, который вы хотите изменить (от 1 до" << n << "): ";
    cin >> position;
    position--;
    if (position >= 0 && position < n)
    {
        cout << "ФИО студента: ";
        cin >> arr[n].fio;
        cout << "группа(6-ти значное число): ";
        do{
            cin >> arr[n].gruppa;
        }while(!(arr[n].gruppa > 99999 && arr[n].gruppa < 1000000));
        cout << "зачет(1- сдал/0-не сдал)";
        for (int k = 0;k <= 4; k++ ){
            cin >> arr[n].offset[k];
        }
        cout << "Отметки по экзаменам: ";
        for (int k = 0;k <= 4; k++ ){
            do{
                cin >> arr[n].exz[k];
            }while(!(arr[n].exz[k] > -1 && arr[n].exz[k] < 11));
        }
    }
    else cout << "Неверно введена позиция рейса" << endl;
}

void Print(student* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout <<"\t№ \t" << i+1;
        cout <<"\tFIO \t" << arr[i].fio;
        cout <<"\tGroup \t" <<arr[i].gruppa;
        cout <<"\tOffsets \t" << arr[i].offset;
        cout <<"\tExams \t" << arr[i].exz;
        cout <<"\tGPA \t" << arr[i].gpa;
        cout <<"\n\n";
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n;
    string filename;
    return 0;
}
