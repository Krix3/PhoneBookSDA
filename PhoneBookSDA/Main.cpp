#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

class Contact {
private:
    char* name;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

public:
    // Конструктор с параметрами
    Contact(const char* name, const string& homePhone, const string& workPhone,
        const string& mobilePhone, const string& additionalInfo)
        : homePhone(homePhone), workPhone(workPhone), mobilePhone(mobilePhone), additionalInfo(additionalInfo)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Конструктор копирования
    Contact(const Contact& other)
        : homePhone(other.homePhone), workPhone(other.workPhone),
        mobilePhone(other.mobilePhone), additionalInfo(other.additionalInfo)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // Оператор присваивания
    Contact& operator=(const Contact& other)
    {
        if (this != &other)
        {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            homePhone = other.homePhone;
            workPhone = other.workPhone;
            mobilePhone = other.mobilePhone;
            additionalInfo = other.additionalInfo;
        }
        return *this;
    }

    // Деструктор
    ~Contact()
    {
        delete[] name;
    }

    // Inline-функции для получения значений
    inline const char* getName() const { return name; }
    inline const string& getHomePhone() const { return homePhone; }
    inline const string& getWorkPhone() const { return workPhone; }
    inline const string& getMobilePhone() const { return mobilePhone; }
    inline const string& getAdditionalInfo() const { return additionalInfo; }

    // Функция для вывода информации о контакте
    void print() const
    {
        cout << "Имя: " << name << "\n"
            << "Домашний телефон: " << homePhone << "\n"
            << "Рабочий телефон: " << workPhone << "\n"
            << "Мобильный телефон: " << mobilePhone << "\n"
            << "Дополнительная информация: " << additionalInfo << "\n";
    }

    // Функция для установки ФИО
    void setName(const char* newName)
    {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    // Функция для установки домашнего телефона
    void setHomePhone(const string& newHomePhone)
    {
        homePhone = newHomePhone;
    }

    // Функция для установки рабочего телефона
    void setWorkPhone(const string& newWorkPhone)
    {
        workPhone = newWorkPhone;
    }

    // Функция для установки мобильного телефона
    void setMobilePhone(const string& newMobilePhone)
    {
        mobilePhone = newMobilePhone;
    }

    // Функция для установки дополнительной информации
    void setAdditionalInfo(const string& newAdditionalInfo)
    {
        additionalInfo = newAdditionalInfo;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создание контакта
    Contact contact("Иван Иванов", "123-45-67", "234-56-78", "345-67-89", "Друг детства");

    // Вывод информации о контакте
    contact.print();

    // Изменение информации о контакте
    contact.setName("Петр Петров");
    contact.setHomePhone("987-65-43");
    contact.setWorkPhone("876-54-32");
    contact.setMobilePhone("765-43-21");
    contact.setAdditionalInfo("Коллега");

    // Вывод измененной информации о контакте
    contact.print();

    return 0;
}