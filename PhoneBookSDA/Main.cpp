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
    // ����������� � �����������
    Contact(const char* name, const string& homePhone, const string& workPhone,
        const string& mobilePhone, const string& additionalInfo)
        : homePhone(homePhone), workPhone(workPhone), mobilePhone(mobilePhone), additionalInfo(additionalInfo)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // ����������� �����������
    Contact(const Contact& other)
        : homePhone(other.homePhone), workPhone(other.workPhone),
        mobilePhone(other.mobilePhone), additionalInfo(other.additionalInfo)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // �������� ������������
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

    // ����������
    ~Contact()
    {
        delete[] name;
    }

    // Inline-������� ��� ��������� ��������
    inline const char* getName() const { return name; }
    inline const string& getHomePhone() const { return homePhone; }
    inline const string& getWorkPhone() const { return workPhone; }
    inline const string& getMobilePhone() const { return mobilePhone; }
    inline const string& getAdditionalInfo() const { return additionalInfo; }

    // ������� ��� ������ ���������� � ��������
    void print() const
    {
        cout << "���: " << name << "\n"
            << "�������� �������: " << homePhone << "\n"
            << "������� �������: " << workPhone << "\n"
            << "��������� �������: " << mobilePhone << "\n"
            << "�������������� ����������: " << additionalInfo << "\n";
    }

    // ������� ��� ��������� ���
    void setName(const char* newName)
    {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    // ������� ��� ��������� ��������� ��������
    void setHomePhone(const string& newHomePhone)
    {
        homePhone = newHomePhone;
    }

    // ������� ��� ��������� �������� ��������
    void setWorkPhone(const string& newWorkPhone)
    {
        workPhone = newWorkPhone;
    }

    // ������� ��� ��������� ���������� ��������
    void setMobilePhone(const string& newMobilePhone)
    {
        mobilePhone = newMobilePhone;
    }

    // ������� ��� ��������� �������������� ����������
    void setAdditionalInfo(const string& newAdditionalInfo)
    {
        additionalInfo = newAdditionalInfo;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // �������� ��������
    Contact contact("���� ������", "123-45-67", "234-56-78", "345-67-89", "���� �������");

    // ����� ���������� � ��������
    contact.print();

    // ��������� ���������� � ��������
    contact.setName("���� ������");
    contact.setHomePhone("987-65-43");
    contact.setWorkPhone("876-54-32");
    contact.setMobilePhone("765-43-21");
    contact.setAdditionalInfo("�������");

    // ����� ���������� ���������� � ��������
    contact.print();

    return 0;
}