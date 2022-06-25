include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <stdio.h>
using namespace std;
int const max_students = 50;
int const max_accounts = 10;
struct Student
{
    string surname,name, patronymic;
    int gruppa, offset[5], exz[5];
    double gpa;
}study;

struct Account
{
    string login, password;
    int role;
};

void menu_adm_start();
void menu_adm_student();
void menu_adm_account();
void menu_user();
void read_file_account(Account* account_arr, int&account_num);
void write_file_account(Account* account_arr, int&account_num);
void add_account(Account*account_arr, int&account_num);
void dell_account(Account*account_arr, int&account_num);
void edit_account(Account*account_arr, int&account_num);
void show_account(Account*account_arr, int&account_num);
void read_file_student(Student*student_arr, int&student_num);
void write_file_student(Student*student_arr, int&student_num);
void add_student(Student*student_arr, int&student_num);
void dell_student(Student*student_arr, int&student_num);
void edit_student(Student*student_arr, int&student_num);
void show_student(Student* student_arr, int&student_num);
void iz_student(Student* student_arr, int&student_num);
void sort_group(Student* student_arr, int& student_num);
void sort_gpa(Student* student_arr, int& student_num);
void sort_name(Student* student_arr, int& student_num);
void search_group(Student*student_arr, int&student_num);
void search_name(Student*student_arr, int&student_num);
void search_gpa(Student*student_arr, int&student_num);
void table_header();
void enter_student(Student*student_arr, int&student_num, int&id);
void cout_student(Student*student_arr, int&student_num, int&id);
int check_login(Account* account_arr, int&account_num, string&login);
int ReadInteger();

int main(){
    SetConsoleOutputCP(CP_UTF8);
    Account account_arr[10];
    int account_num = 0;
    string login, password;
    read_file_account(account_arr, account_num);
    cout << "\n\tАвторизация\n" << endl;
    while (true){
        cout << "Введите логин: ";
        cin >> login;
        cout << "Введите пароль: ";
        cin >> password;
        if (login == "admin"&&password == "admin"){
            cout << "Вы авторизированы как администратор!" << endl;
            menu_adm_start();
            break;
        }
        for (int i = 0; i < account_num; i++){
            if (login == account_arr[i].login && password == account_arr[i].password && account_arr[i].role == 0){
                cout << "Вы авторизированы как администратор!" << endl;
                menu_adm_start();
                break;
            }
            else if (login == account_arr[i].login&&password == account_arr[i].password&&account_arr[i].role == 1){
                cout << "Вы авторизированы как пользователь!" << endl;
                menu_user();
                break;
            }
        }
        cout << "Неверный логин или пароль! Попробуйте снова!"<< endl;
    }
}

void menu_adm_start()
{
    cout << "\n\tСтартовое меню администратора\n" << endl;
    cout <<
         "1. Работа с пользователями\n"
         "2. Работа с данными\n"
         "3. Назад к авторизации\n"
         "0. Выход из программы\n";
    while (true){
        cout << "Введите число: ";
        int k;
        k = ReadInteger();
        switch (k){
            case 1: menu_adm_account();
                break;
            case 2: menu_adm_student();
                break;
            case 3: main();
                break;
            case 0: exit(0);
                break;
            default:cout << "Неверное число!!! Попробуйте снова" << endl;
                continue;
        }
    }
}
void menu_adm_student() {
    Student student_arr[max_students];
    int student_num = 0;
    cout << "\n\tМеню работы с данными\n" << endl;
    cout <<
         "1. Список студентов\n"
         "2. Добавить запись\n"
         "3. Редактировать запись\n"
         "4. Удалить запись\n"
         "5. Индивидуальное задание\n"
         "6. Сортировка записей студентов по группе\n"
         "7. Сортировка записей студентов по среднему баллу\n"
         "8. Сортировка записей студентов по ФИО\n"
         "9. Поиск по группе\n"
         "10. Поиск по ФИО\n"
         "11. Поиск по среднему баллу\n"
         "12. Назад\n"
         "0. Выход из программы\n" << endl;
    int k;
    while (true){
        cout << "Введите число: ";
        k = ReadInteger();
        switch (k)
        {
            case 1:
                read_file_student(student_arr, student_num);
                show_student(student_arr, student_num);
                break;
            case 2: add_student(student_arr, student_num);
                break;
            case 3: edit_student(student_arr, student_num);
                break;
            case 4: dell_student(student_arr, student_num);
                break;
            case 5: iz_student(student_arr, student_num);
                break;
            case 6: sort_group(student_arr, student_num);
                break;
            case 7: sort_gpa(student_arr, student_num);
                break;
            case 8: sort_name(student_arr, student_num);
                break;
            case 9: search_group(student_arr, student_num);
                break;
            case 10: search_name(student_arr, student_num);
                break;
            case 11: search_gpa(student_arr, student_num);
                break;
            case 12: menu_adm_start();
                break;
            case 0: exit(0);
                break;
            default:cout << "\nНеверное число! Попробуйте снова!" << endl;
                break;
        }
    }
}

void menu_adm_account() {
    Account account_arr[max_accounts];
    int account_num = 0;
    cout << "\n\tМеню работы с пользователями\n" << endl;
    cout <<
         "1. Список пользователей\n"
         "2. Добавить запись\n"
         "3. Редактировать запись\n"
         "4. Удалить запись\n"
         "5. Назад\n"
         "0. Выход из программы\n" << endl;
    int k;
    while (true){
        cout << "Введите число: ";
        k = ReadInteger();
        switch (k){
            case 1:
                read_file_account(account_arr, account_num);
                show_account(account_arr, account_num);
                break;
            case 2: add_account(account_arr, account_num);
                break;
            case 3: edit_account(account_arr, account_num);
                break;
            case 4: dell_account(account_arr, account_num);
                break;
            case 5: menu_adm_start();
                break;
            case 0: exit(0);
                break;
            default: cout << "\nНеверное число! Попробуйте снова!" << endl;
                break;
        }
    }
}

void menu_user()
{
    Student student_arr[max_students];
    int student_num = 0, k;
    cout << "\n\tМеню пользователя\n" << endl;
    cout <<
         "1. Список студентов\n"
         "2. Индивидуальное задание\n"
         "3. Сортировка записей студентов по группе\n"
         "4. Сортировка записей студентов по среднему баллу\n"
         "5. Сортировка записей студентов по фамилии\n"
         "6. Поиск студента по группе\n"
         "7. Поиск студента по фамилии\n"
         "8. Поиск студента по среднему баллу\n"
         "9. Назад к авторизации\n"
         "0. Выход\n";
    while (true){
        cout << "Введите число: ";
        k = ReadInteger();
        switch (k){
            case 1: read_file_student(student_arr, student_num);
                show_student(student_arr, student_num);
                break;
            case 2: iz_student(student_arr, student_num);
                break;
            case 3: sort_group(student_arr, student_num);
                break;
            case 4: sort_gpa(student_arr, student_num);
                break;
            case 5: sort_name(student_arr, student_num);
                break;
            case 6: search_group(student_arr, student_num);
                break;
            case 7: search_name(student_arr, student_num);
                break;
            case 8: search_gpa(student_arr, student_num);
                break;
            case 9: main();
                break;
            case 0: exit(0);
                break;
            default: cout << "\n Неверное число! Попробуйте снова!" << endl;
                break;
        }
    }
}

void read_file_account(Account* account_arr, int&account_num) {
    ifstream fin;
    fin.open("C:\\Users\\Vladislav Korkutz\\Desktop\\TRPO\\account.txt");
    if (!fin.is_open())
        cout << "Файл не найден!" << endl;
    else{
        int i = 0;
        while (!fin.eof()){
            fin
                >> account_arr[i].login
                >> account_arr[i].password
                >> account_arr[i].role;
            i++;
        }
        account_num = i;
    }
    fin.close();
}

void write_file_account(Account* account_arr, int&account_num) {
    ofstream fout;
    fout.open("C:\\Users\\Vladislav Korkutz\\Desktop\\TRPO\\account.txt");
    for (int i = 0; i < account_num; i++) {
        if (fout.eof())
            break;
        fout
            << account_arr[i].login << "\t"
            << account_arr[i].password << "\t"
            << account_arr[i].role;
        if (i < account_num - 1)
            fout << endl;
    }
    fout.close();
}

void add_account(Account* account_arr, int&account_num)
{
    read_file_account(account_arr, account_num);
    cout << "\n\tДобавление нового пользователя!\n" << endl;
    account_num++;
    int id = account_num-1, k;
    cout << "Логин: ";
    do{
        cin >> account_arr[id].login;
    }while(check_login(account_arr, account_num, account_arr[id].login));
    cout << "Пароль: ";
    cin >> account_arr[id].password;
    while (true)
    {
        cout << "Роль (0 - админ, 1 - пользователь): ";
        k = ReadInteger();
        if (k == 1 || k == 0){
            account_arr[id].role = k;
            break;
        }
        else{
            cout << "Неверный ввод!" << endl;
            continue;
        }
    }
    cout << "Пользователь " << account_arr[id].login << " добавлен.\n" << endl;
    write_file_account(account_arr, account_num);
}

int check_login(Account* account_arr, int&account_num, string&login) {
    for (int i = 0; i < account_num-1; i++) {
        if (login == account_arr[i].login) {
            cout << "Пользователь с таким именем существует, пожалуйста введите другое имя" << endl;
            return 1;
        }
    }
    return 0;
}

void edit_account(Account*account_arr, int&account_num) {
    int id = 0, k;
    cout << "\n\tРедактирование пользователя\n" << endl;
    read_file_account(account_arr, account_num);
    show_account(account_arr, account_num);
    cout << "Введите # пользователя: ";
    id = ReadInteger();
    id--;
    if (id < 0 || id >= account_num)
        cout << "Такого пользователя не существует!\n" << endl;
    else
    {
        cout << "Логин: ";
        do{
            cin >> account_arr[id].login;
        }while(check_login(account_arr, account_num, account_arr[id].login));
        cout << "Пароль: ";
        cin >> account_arr[id].password;
        while (true){
            cout << "Роль (0 - админ, 1 - пользователь): ";
            k = ReadInteger();
            if (k == 1 || k == 0){
                account_arr[id].role = k;
                break;
            }
            else{
                cout << "Неверный ввод!" << endl;
                continue;
            }
        }
        cout << "Пользователь # " << id + 1 << " изменен.\n" << endl;
        write_file_account(account_arr, account_num);
    }
}

void dell_account(Account*account_arr, int&account_num) {
    int id, k;
    cout << "\n\tУдаление пользователя" << endl;
    read_file_account(account_arr, account_num);
    show_account(account_arr, account_num);
    cout << "Введите # пользователя: ";
    id = ReadInteger();
    if(!(id < 0 || id >= account_num)){
        id--;
        cout << "Вы дейсвтительно хотите удалить запись?" << endl;
        while (true) {
            cout << "Введите число (1 - да, 0 - нет): ";
            k = ReadInteger();
            if (k == 1) {
                for (int i = id; i < account_num - 1; i++)
                    account_arr[i] = account_arr[i + 1];
                account_num--;
                cout << "Пользователь удален.\n" << endl;
                write_file_account(account_arr, account_num);
                break;
            } else if (k == 0) {
                menu_adm_account();
                break;
            }
        }
    }
    else
        cout << "Несуществующий номер записи студента" << endl;
}

void show_account(Account* account_arr, int&account_num) {
    cout << "\n\tСписок пользователей" << endl;
    cout << "____________________________________________________________________" << endl;
    cout << "| # | "
         << setw(17) << left << "Логин" << "| "
         << setw(16) << left << "Пароль" << "| "
         << setw(6) << left << "Роль" << "|" << endl;
    cout << "____________________________________________________________________" << endl;
    for (int i = 0; i < account_num; i++) {
        cout << "| "
             << setw(2) << left << i + 1 << "| "
             << setw(17) << left << account_arr[i].login << "| "
             << setw(16) << left << account_arr[i].password << "| "
             << setw(6) << left << account_arr[i].role << "|" << endl;
    }
    cout << "____________________________________________________________________\n" << endl;
}

void read_file_student(Student* student_arr, int& student_num)
{
    ifstream in_file;
    in_file.open("C:\\Users\\Vladislav Korkutz\\Desktop\\TRPO\\student.txt");
    if (!in_file.is_open())
        cout << "Указанный файл не существует!\n" << endl;
    else
    {
        int i = 0;
        while(!in_file.eof()){
            in_file
                 >> student_arr[i].surname
                 >> student_arr[i].name
                 >> student_arr[i].patronymic
                 >> student_arr[i].gruppa
                 >> student_arr[i].gpa;
            for(int k = 0; k < 5; k++)
                in_file >> student_arr[i].offset[k];
            for(int j = 0; j < 5; j++)
                in_file >> student_arr[i].exz[j];
            i++;
        }
        student_num = i;
    }
    in_file.close();
}

void write_file_student(Student*student_arr, int&student_num) {
    ofstream out_file;
    out_file.open("C:\\Users\\Vladislav Korkutz\\Desktop\\TRPO\\student.txt");
    for ( int i = 0; i < student_num; i++){
        if (out_file.eof())
            break;
        out_file
                << student_arr[i].surname << "\t"
                << student_arr[i].name << "\t"
                << student_arr[i].patronymic << "\t"
                << student_arr[i].gruppa << "\t"
                << student_arr[i].gpa << "\t";
        for(int k = 0; k < 5; k++)
            out_file << student_arr[i].offset[k] << " ";
        for(int j = 0; j < 5; j++)
            out_file << student_arr[i].exz[j] << " ";
        if (i < student_num - 1)  //
            out_file << endl;
    }
    out_file.close();
}
void enter_student(Student*student_arr, int&student_num, int&id){
    int sum = 0;
    cout << "фамилия студента: ";
    cin >> student_arr[id].surname;
    cout << "имя студента: ";
    cin >> student_arr[id].name;
    cout << "отчество студента: ";
    cin >> student_arr[id].patronymic;
    cout << "группа(6-ти значное число): ";
    do{
        student_arr[id].gruppa = ReadInteger();
    }while(!(student_arr[id].gruppa > 99999 && student_arr[id].gruppa < 1000000));
    cout << "зачет(1- сдал/0-не сдал)";
    for (int k = 0;k <= 4; k++ ){
        do{
            student_arr[id].offset[k] = ReadInteger();
        }while(!(student_arr[id].offset[k] == 0 || student_arr[id].offset[k] == 1));
    }
    cout << "Отметки по экзаменам: ";
    for (int k = 0;k <= 4; k++ ){
        do{
            student_arr[id].exz[k] = ReadInteger();
        }while(!(student_arr[id].exz[k] > -1 && student_arr[id].exz[k] < 11));
        sum += student_arr[id].exz[k];
    }
    student_arr[id].gpa = sum / 5.0;
}

void add_student(Student*student_arr, int&student_num) {
    cout << "\n\tДобавление записи\n" << endl;
    read_file_student(student_arr, student_num);
    int id = student_num - 1;
    enter_student(student_arr, student_num, id);
    cout << "Новая запись добавлена.\n" << endl;
    write_file_student(student_arr, student_num);
}

void edit_student(Student* student_arr, int&student_num) {
    int id = 0;
    cout << "\n\tРедактирование записи\n" << endl;
    read_file_student(student_arr, student_num);
    show_student(student_arr, student_num);
    cout << "Введите # записи: ";
    id = ReadInteger();
    id--;
    if (id < 0 || id >= student_num)
        cout << "Введен некорректный # записи!\n" << endl;
    else
    {
        enter_student(student_arr, student_num, id);
        cout << "Запись отредактирована.\n" << endl;
        write_file_student(student_arr, student_num);
    }
}

void dell_student(Student* student_arr, int&student_num) {
    int id = 0;
    int k;
    cout << "\n\tУдаление записи" << endl;
    read_file_student(student_arr, student_num);
    show_student(student_arr, student_num);
    cout << "Введите # записи: ";
    cin >> id;
    id--;
    if (id >= 0 && id < student_num)
    {
        cout << "Вы дейсвтительно хотите удалить запись?" << endl;
        while (true)
        {
            cout << "Введите число (1 - да, 0 - нет): ";
            cin >> k;
            if (k == 1)
            {
                for (int i = id; i < student_num - 1; i++)
                    student_arr[i] = student_arr[i + 1];
                student_num--;
                cout << "Пользователь удален.\n" << endl;
                write_file_student(student_arr, student_num);
                break;
            }
            else if (k == 0)
            {
                menu_adm_student();
                break;
            }
        }
    }
    else
        cout << "Неверный ввод!" << endl;
}

void show_student(Student* student_arr, int& student_num) {
    table_header();
    for (int i = 0; i < student_num - 1; i++)
        cout_student(student_arr, student_num, i);
    cout << "__________________________________________________________________________\n" << endl;
}

void iz_student(Student* student_arr, int&student_num) {
    cout << "\n\tИндивидуальное задание\n"
         << "Индивидуальное задание: вывести всех студентов в порядке"
            " убывания количества задолженностей (количество задолженностей"
            " по каждому студенту необходимо указать); средний балл, полученный"
            " каждым студентом группы х (вводится с клавиатуры), и всей группой в целом.\n" << endl;
    int group, counter = 0, counter_group = 0;
    double gpa_group = 0.0 , i1= 0.0;
    int k = 0;
    read_file_student(student_arr, student_num);
    cout << "Введите группу: ";
    do{
        group = ReadInteger();
    }while(!(group > 99999 && group < 1000000));
    cout << "__________________________________________________________________________" << endl;
    cout << "|#| "
    << setw(7) << left << "Фамилия" << "| "
    << setw(7) << left << "Имя" << "| "
    << setw(7) << left << "Отчество" << "| "
    << setw(7) << left << "Группа" << "| "
    << setw(7) << left << "Средний балл" << "| "
    << setw(7) << left << "Задолженности" << "| "
    << setw(13) << left << "Зачеты" << "| "
    << setw(13) << left << "Экзамены" << "| " << endl;
    cout << "__________________________________________________________________________" << endl;
    for (int i = 0; i < student_num; i++)
    {
        if (group == student_arr[i].gruppa)
        {
            for(int j = 0; j < 5; j++){
                if(student_arr[i].offset[j] == 0)counter++;
                if(student_arr[i].exz[j] < 4)counter++;
            }
            counter_group += counter;
            cout << "| "
            << setw(2) << left << i + 1 << "| "
            << setw(7) << left << student_arr[i].surname << "| "
            << setw(7) << left << student_arr[i].name << "| "
            << setw(7) << left << student_arr[i].patronymic << "| "
            << setw(7) << left << student_arr[i].gruppa << "| "
            << setw(7) << left << student_arr[i].gpa << "| "
            << setw(7) << left << counter << "| ";
            for (int q = 0; q < 5; q++)
                cout << student_arr[i].offset[q] << " ";
            cout << "| ";
            for (int w = 0; w < 5; w++)
                cout << student_arr[i].exz[w] << " ";
            cout << "| "  << endl;
            gpa_group += student_arr[i].gpa;
            counter = 0;
            i1++;
            k++;
        }
    }
    cout << "Общее количество задолженностей в группе: " << counter_group << endl;
    cout << "Средний балл по группе: " << gpa_group/i1 << endl;
    cout << "__________________________________________________________________________\n" << endl;
    if (k == 0)
        cout << "Нет подходящих записей для вашего запроса." << endl;

}

void sort_group(Student* student_arr, int& student_num)// Сортировка массива пузырьком
{
    read_file_student(student_arr, student_num);
    cout << "\n\tСортировка по номеру группы\n" << endl;
    for (int i = 0; i < student_num - 1; i++) {
        for (int j = 1; j < student_num - i - 1 ; j++) {
            if (student_arr[j-1].gruppa > student_arr[j].gruppa) {
                swap(student_arr[j-1], student_arr[j]);
            }
        }
    }
    show_student(student_arr, student_num);
}
void sort_gpa(Student* student_arr, int& student_num)//Сортировка вставками
{
    read_file_student(student_arr, student_num);
    cout << "\n\tСортировка по среднему баллу студента\n" << endl;
    for(int i = 0 ; i < student_num - 1 ; i++)
        for(int j = i ; j > 0 && student_arr[j-1].gpa > student_arr[j].gpa ; j--)
            swap(student_arr[j-1],student_arr[j]);
    show_student(student_arr, student_num);
}
void sort_name(Student* student_arr, int& student_num)//Сортировка выбором
{
    read_file_student(student_arr, student_num);
    cout << "\n\tСортировка по фамилии студента\n" << endl;
    int min = 0;
    for (int i = 0; i < student_num; i++)
    {
        min = i;
        for (int j = i + 1; j < student_num-1; j++) {
            if(student_arr[j].surname < student_arr[min].surname)
                min = j;
        }
        if (i != min)
            swap(student_arr[i], student_arr[min]);
    }
    show_student(student_arr, student_num);
}
void search_group(Student* student_arr, int&student_num) { //Линейный поиск x3
    cout << "\n\tПоиск студентов по номеру группы\n" << endl;
    read_file_student(student_arr, student_num);
    int group;
    int k = 0;
    cout << "Введите номер группы(6-значное число): ";
    do{
        group = ReadInteger();
    }while(!(group > 99999 && group < 1000000));
    table_header();
    for (int i = 0; i < student_num; i++) {
        if (group == student_arr[i].gruppa) {
            cout_student(student_arr, student_num, i);
            k++;
        }
    }
    cout << "__________________________________________________________________________\n" << endl;
    if (k == 0)
        cout << "Нет подходящих записей для вашего запроса." << endl;
}
void search_name(Student* student_arr, int&student_num) {
    cout << "\n\tПоиск студента по фамилии\n" << endl;
    read_file_student(student_arr, student_num);
    string fio;
    int k = 0;
    cout << "Введите ФИО: ";
    cin >> fio;
    table_header();
    for (int i = 0; i < student_num; i++) {
        if (fio == student_arr[i].surname) {
            cout_student(student_arr, student_num, i);
            k++;
        }
    }
    cout << "__________________________________________________________________________\n" << endl;
    if (k == 0)
        cout << "Нет подходящих записей для вашего запроса." << endl;

}
void search_gpa(Student *student_arr, int &student_num) {
    cout << "\n\tПоиск студента по среднему баллу\n" << endl;
    read_file_student(student_arr, student_num);
    double gpa;
    int k = 0;
    cout << "Введите средний балл студента: ";
    cin >> gpa;
    table_header();
    for (int i = 0; i < student_num; i++) {
        if (gpa == student_arr[i].gpa) {
            cout_student(student_arr, student_num, i);
            k++;
        }
    }
    cout << "__________________________________________________________________________\n" << endl;
    if (k == 0)
        cout << "Нет подходящих записей для вашего запроса." << endl;
}
void table_header(){
    cout << "__________________________________________________________________________" << endl;
    cout << "| # |"
         << setw(7) << left << "Фамилия" << "| "
         << setw(7) << left << "Имя" << "| "
         << setw(7) << left << "Отчество" << "| "
         << setw(9) << left << "Группа" << "| "
         << setw(15) << left << "Средний балл" << "| "
         << setw(7) << left << "Зачеты" << "| "
         << setw(7) << left << "Экзамены" << "| " << endl;
    cout << "__________________________________________________________________________" << endl;
}
void cout_student(Student*student_arr, int&student_num, int&id){
    cout << "| "
         << setw(2) << left << id + 1 << "| "
         << setw(7) << left << student_arr[id].surname << "| "
         << setw(7) << left << student_arr[id].name << "| "
         << setw(7) << left << student_arr[id].patronymic << "| "
         << setw(7) << left << student_arr[id].gruppa << "| "
         << setw(7) << left << student_arr[id].gpa << "| ";
    for (int h = 0; h < 5; h++)
        cout << student_arr[id].offset[h] << " ";
    cout << "| ";
    for (int g = 0; g < 5; g++)
        cout << student_arr[id].exz[g] << " ";
    cout << "| "  << endl;
}

int ReadInteger() {
    int number;
    char c;
    while (1) {
        if (!scanf_s("%d", &number) || getchar() != '\n')
            while ((c = getchar()) != '\n' && c != EOF);
        else
            return number;
        printf_s("Ошибка.\n Попробуйте снова: ");
    }
}
