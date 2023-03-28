#include <iostream>

using namespace std;

class Employee
{
    static int count; // статическая переменная

private: // закрытые методы и поля класса
    string  organization; // Место работы 
    string  position; // Должность
    double  experience; // Стаж
    string  name; // Ф.И.О 
    char    gender; // Пол М или Ж 
    int     age; // возраст
    double  salary; // заработная плата (накопление на счете, сотрудник её не снимает) 

public: // открытые методы и поля класса
    Employee() { // конструктор экземпляра
        string gender_str;
        count++;
        cout << endl << "Место работы: " << endl;
        cin >> organization;
        cout << "Должность: " << endl;
        cin >> position;
        cout << "Стаж: " << endl;
        cin >> experience;
        cout << "Ф.И.О.: " << endl;
        cin >> name;
        cout << "Пол: " << endl;
        cin >> gender_str;
        gender = gender_str[0];
        cout << "Возраст: " << endl;
        cin >> age;
        cout << "Зарплата: " << endl;
        cin >> salary;
    }
    ~Employee() { // деструктор
        count--;
    }
    void show(); // отображение информации о работнике
    void changePosition(string p_position); // обновление должности
    void addSalary(double p_salary); //добавление зарплаты
    void showPrivatFields();

    void static showСount() {
        cout << "Общее количество сотрудников: " << count << endl;
    }

    string operator > (Employee employee) {
        if (salary > employee.salary)
            return ("True");
        else
            return ("False");
    }

    string operator < (Employee employee) {
        if (salary < employee.salary)
            return ("True");
        else
            return ("False");
    }

    string operator == (Employee employee) {
        if (salary == employee.salary)
            return ("True");
        else
            return ("False");
    }

    void operator = (Employee employee) {
        salary = employee.salary;
    }
};

void Employee::show() {
    cout << "Место работы: " << organization << endl;
    cout << "Должность: " << position << endl;
    cout << "Стаж (год): " << experience << endl;
    cout << "Заработная плата: " << salary << endl;
}

void Employee::changePosition(string p_position) {
    position = p_position;
}

void Employee::addSalary(double p_salary) {
    salary += p_salary;
}

void Employee::showPrivatFields() {
    cout << "Ф.И.О: " << name << endl;
    cout << "Пол: " << gender << endl;
}

int Employee::count = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    int    vibor,vibor2, x, i;
    char   var;

    cout << "Введите количество сотрудников (от 2 до 5): ";
    cin >> x;
    cout << "\n";
    Employee *worker[x];
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
        cout << "1) Добавить сотрудников" << endl;
        cout << "2) Удалить сотрудника" << endl;
        cout << "3) Изменить зарплату" << endl;
        //добавить параметры меню: Изменить должность, Вывести всех сотрудников
        cout << "Escape - Выход" << endl;
        
        cin >> var;
        switch (var)
        {
        case '1': 
            for (i = 0; i < x; i++)
                worker[i] = new Employee;
            break;

        case '2': 
            for (i = 0; i < x; i++)
                worker[i]->showPrivatFields();
            cout << "Выберите кого уволить: ";
            cin >> vibor2;
            delete worker[vibor2];
            break;

        case '3':
            for (i = 0; i < x; i++)
                worker[i]->showPrivatFields();
            cout << "Выберите кому начислить зарплату: ";
            cin >> vibor2;
            worker[vibor2]->addSalary(300);
            break;

        case 27 : return 0;
        };
        
    } while (true);
 return 0; 
}