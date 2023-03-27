#include <iostream>

using namespace std;

int i = 0;
string p,o,s;
int x = 1;
int count; // Количество сотрудников

class Employee
{    // закрытые члены класса
    string organization; // Место работы 
    string position; // Должность
    double experience; // Стаж
    string name; // Ф.И.О 
    string lastname;
    string surname;
    string gender; // Пол М или Ж 
    int age; // возраст
    double salary; // заработная плата (накопление на счете, сотрудник её не снимает) 
    int count = 1; // Количество сотрудников

public:
    // открытые члены класса
    void setorganization(); // установка места работы
    void setposition(); // установка должности
    void setexperience(); // установка стажа
    void setname(); // установка Ф.И.О.
    void setgender(); // установка пола
    void setage(); // установка возраста
    void setsalary(); // установка заработной платы
    void set(); // установка всех семи полей
    void setcount(); // установка количества сотрудников
    void show(); // отображение информации о студенте
    void add();
    void del();

};

//ввод места работы
void Employee::setorganization() {
    cout << "введите место работы =";
    cin >> organization;
}

//ввод должности
void Employee::setposition() {
    cout << "\nвведите должность =";
    cin >> position;
}

//ввод стажа
void Employee::setexperience() {
    cout << "\nвведите стаж (год) =";
    cin >> experience;
}

//ввод Ф.И.О 
void Employee::setname() {

    cout << "\nвведите Ф.И.О.";
    cout << "\nФамилия:";
    cin >> lastname;
    
    cout << "Имя:";
   cin >> name;

    cout << "Отчество:";
    cin >> surname;
}

//ввод Пол М или Ж (Лучше сделать через иф)
void Employee::setgender() {
    cout << "\nвведите пол (М или Ж)  =";
    cin >> gender;
}

//ввод возраст
void Employee::setage() {
    cout << "\nвведите возраст =";
    cin >> age;
}

//ввод заработная плата 
void Employee::setsalary() {
    cout << "\nвведите заработная плата =";
    cin >> salary;
    cout << "\n\n";
}

//ввод Количество сотрудников
void Employee::setcount() {
    cout << "введите количество сотрудников =";
    cin >> count;
} 


void Employee::add() {
    
        cout << "Сотрудник № " << count++ << endl;
        setorganization();
        setposition();
        setexperience();
        setname();
        setgender();
        setage();
        setsalary();
    }
 
 
void Employee::del() {
        
        organization = "Уволен";
        position = "";
        experience = 0;
        name = "";
        gender = "";
        age = 0;
        salary = 0;

}

void Employee::show() {
    cout << "\nСотрудник № " << i + 1 << endl;
    cout << "Место работы: " << organization << endl;
    cout << "Должность: " << position << endl;
    cout << "Стаж (год): " << experience << endl;
    cout << "Ф.И.О: " << lastname <<" "<< name <<" "<< surname << endl;
    cout << "Пол: " << gender << endl;
    cout << "Возраст: " << age << endl;
    cout << "Заработная плата: " << salary << endl;
}

int main()
{
setlocale(LC_ALL, "Russian");
 int vibor,vibor2;
 char var;
 
 
 cout << "Введите количество сотрудников (от 2 до 5): ";
    cin >> x;
    cout << "\n";
        Employee worker[x];
   /* for (i = 0; i < x; i++)
    {
        Employee[i].add();

    }
    
    
        for (i = 0; i < x; i++)
    {
        Employee[i].show();
    }
*/

    do
    {
        cout << "Выберите пункт меню" << endl;
        cout << "1) Добавить сотрудника" << endl;
        cout << "2) Удалить сотрудника" << endl;
        cout << "3) Изменить зарплату" << endl;
        cout << "Escape - Выход" << endl;
        
        cin >> var;
        switch (var)
        {
    
    case '1': 
    count+1; 
    worker[count].add();
    break;
            
           
    case '2': 
            for (i = 0; i < x; i++) {worker[count].show();}

            cout << "Выберите кого уволить: ";
            cin >> vibor2;
            worker[vibor2].del();
            break;
            
            
            
    case '3': break;

    case 27 : return 0;
        };
        
    } while (true);
 return 0;
    
}