#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
using namespace std;
bool isValidID(const string &id)
{
    if (id.size() != 4)
        return false;

    for (char c : id)
    {
        if (!isdigit(c))
            return false;
    }

    return true;
}
string getPini(int length, string id)
{
    if (length < 7)
    {
        cout << "Password length invalid, minimum length of 7 is required.\n";
        exit(1);
    }

    string passs = "";
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string symbols = "@&*#";
    srand(time(0));

    passs += lowercase[rand() % lowercase.size()];
    passs += uppercase[rand() % uppercase.size()];
    passs += numbers[rand() % numbers.size()];
    passs += symbols[rand() % symbols.size()];

    for (int i = 4; i < length; i++)
    {
        passs += characters[rand() % characters.size()];
    }

    for (int i = 0; i < passs.size(); i++)
    {
        swap(passs[i], passs[rand() % passs.size()]);
    }
    id += passs;
    passs = id;

    return passs;
}

string getPine(int length, string id)
{
    if (length < 7)
    {
        cout << "Password length invalid, minimum length of 7 is required.\n";
        exit(1);
    }

    string passs = "";
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string symbols = "@&*#";
    srand(time(0));

    passs += lowercase[rand() % lowercase.size()];
    passs += uppercase[rand() % uppercase.size()];
    passs += numbers[rand() % numbers.size()];
    passs += symbols[rand() % symbols.size()];

    for (int i = 4; i < length; i++)
    {
        passs += characters[rand() % characters.size()];
    }

    for (int i = 0; i < passs.size(); i++)
    {
        swap(passs[i], passs[rand() % passs.size()]);
    }
    passs += id;

    return passs;
}

string getPinr(int length, string id)
{
    if (length < 7)
    {
        cout << "Password length invalid, minimum length of 7 is required.\n";
        exit(1);
    }

    string passs = "";
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string symbols = "@&*#";
    srand(time(0));

    passs += lowercase[rand() % lowercase.size()];
    passs += uppercase[rand() % uppercase.size()];
    passs += numbers[rand() % numbers.size()];
    passs += symbols[rand() % symbols.size()];

    for (int i = 4; i < length; i++)
    {
        passs += characters[rand() % characters.size()];
    }
    passs += id;
    for (int i = 0; i < passs.size(); i++)
    {
        swap(passs[i], passs[rand() % passs.size()]);
    }

    return passs;
}

int main()
{
    int length;
    string id;
    string key;
    string passs; // Declare passs here to ensure it is accessible later

    cout << "Enter the length of the password :: ";
    cin >> length;
    cout << endl
         << endl;
    cout << "Enter the last 4 digits of your BITS ID (except the campus code: P, G, or H): ";
    cin >> id;
    if (!isValidID(id))
    {
        cout << "Invalid ID format! The ID must be exactly 4 digits.\n";
        return 1;
    }
    cout << endl
         << endl;
    cout << "ENTER KEY! Where would you like your ID number placed in the password\n"
         << " - If initially, press 'i'\n"
         << " - If in the end, press 'e'\n"
         << " - If you want it to be mixed randomly, press 'r'\n";
    cin >> key;
    cout << endl
         << endl;

    if (key == "i" || key == "I")
    {
        passs = getPini(length, id);
    }
    else if (key == "e" || key == "E")
    {
        passs = getPine(length, id);
    }
    else if (key == "r" || key == "R")
    {
        passs = getPinr(length, id);
    }
    else
    {
        cout << "Invalid key type! Try again.\n";
        exit(1);
    }

    cout << "Generated password :: " << passs << endl;
    cout << endl
         << endl;
    cout << "Here is your secure password with at least 1 uppercase, 1 lowercase, 1 number, 1 symbol, "
         << "and customized with your BITS ID.\n";
    cout << endl
         << endl;

    return 0;
}
