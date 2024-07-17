#include <iostream>
#include <cstring>
using namespace std;

bool isPasswordValid(char password[])
{
    int length = strlen(password);
    bool hasDigit = false, hasUpperCase = false, hasSpecialChar = false;

    if (length < 6 || length > 10)
        return false;

    for (int i = 0; i < length; i++)
    {
        if (isdigit(password[i])) 
            hasDigit = true;
        else if (isupper(password[i]))
            hasUpperCase = true;
        else if (!isalpha(password[i]) && !isdigit(password[i]))
            hasSpecialChar = true;
    }

    return hasDigit && hasUpperCase && hasSpecialChar;
}

int main()
{
    char password[20];
    cout << "Enter password: ";
    cin >> password;

    if (isPasswordValid(password))
        cout << "Valid password" << endl;
    else
        cout << "Invalid password" << endl;

    return 0;
}
