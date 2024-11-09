#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ���������� ����� ������� Count
int Count(char* str, int i = 0) {
    // ������� ������� - ����� ����� ��� ������� ����� 3
    if (strlen(str) < 3 || str[i + 2] == 0)
        return 0;

    // ���������� ������� ������� � ������ ����������� ������
    return (strncmp(&str[i], "abc", 3) == 0 ? 1 : 0) + Count(str, i + 1);
}

// ���������� ����� ������� Change
char* Change(char* str, char* tmp = nullptr, char* t = nullptr, size_t i = 0) {
    // ����� ����������� ��� ������� �������
    if (tmp == nullptr) {
        if (strlen(str) < 3)
            return str;
        tmp = new char[strlen(str) * 3 + 1];
        t = tmp;
        tmp[0] = '\0';
        return Change(str, tmp, t, 0);
    }

    // ������� ������� - ����� �����
    if (i >= strlen(str)) {
        strcpy(str, tmp);
        return tmp;
    }

    // ���������� "abc" � ������ ����������� ������
    if (i < strlen(str) - 2 && strncmp(&str[i], "abc", 3) == 0) {
        strcat(t, "**");
        t += 1;
        return Change(str, tmp, t, i + 3);
    }
    else {
        *t = str[i];
        *(t + 1) = '\0';
        return Change(str, tmp, t + 1, i + 1);
    }
}

int main()
{

    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of 'abc'" << endl;
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    delete[] dest;
    return 0;
}