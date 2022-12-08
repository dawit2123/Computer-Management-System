#include <fstream>
#include <conio.h>
#include <iomanip>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int i, j, compQ = 0;
void menu();
inline void attributeMenu();
inline void headerDisplay(); // displays the header (The attributes)
void displaySpec(int);       // displays specific computers, used in search function
void insertNewComp();
void deleteCompRec();
void deleteByAtt();
void delete_Max();
void delete_Min();
void deleteFifth();
void deleteLast();
void searchComp();
void searchByAtt();
void search_Max();
void search_Min();
void updateCompInfo();
void countComp();
void topList();
void display();
void average();
void fileImport();
void fileExport();
void totalComputer();
int dataTypeChecker(int n);
void nullChecker();
int MAC_AddressChecker(char check[]);
void help();
struct computer
{
    char brandName[20];
    char computerName[20];
    char MAC_Address[20];
   	short int generation;
    short int RAM;
    int storage;
    float p_speed; // Processor Speed in GHz
    float price;   // Price of the computer
} myPC[15];
int main()
{
    menu();
    return 0;
}
void menu()
{
    system("cls");
    int choice;
    cout << "\t\t===========================================================================\n";
    cout << "\t\t\t\t           Computer Store Management\n";
    cout << "\t\t===========================================================================\n\n";
    cout << "\t\t---------------------------------------------------------------------------\n";
    cout << "\t\t\t1. Insert new computer \n";
    cout << "\t\t\t2. Import computer data \n";
    cout << "\t\t\t3. Delete computer record \n";
    cout << "\t\t\t4. Search for computer \n";
    cout << "\t\t\t5. Average of different numerical attributes \n";
    cout << "\t\t\t6. Display all current records \n";
    cout << "\t\t\t7. Export computer data \n";
    cout << "\t\t\t8. To see the number of computers currently recorded in the system\n";
    cout << "\t\t\t9. Count computers with a given specification \n";
    cout << "\t\t\t10. Update computer record \n";
    cout << "\t\t\t11. List the top computers \n";
    cout << "\t\t\t12. Exit \n";
    cout << "\t\t\t13. Help \n";
    cout << "\t\t--------------------------------------------------------------------------\n";
    cout << "Choose what you want to do : ";
    cin >> choice;
    while (dataTypeChecker(choice) != 0 || choice < 1 || choice > 13)
    {
        cout << "Invalid choice, Choose what you want to do : ";
        cin >> choice;
    }
    if (choice)
        switch (choice)
        {
        case 1:
            insertNewComp();
            break;
        case 2:
            fileImport();
            break;
        case 3:
        	deleteCompRec();
            break;
        case 4:
            searchComp();
            break;
        case 5:
        	average();
            break;
        case 6:
            display();
            break;
        case 7:
            fileExport();
            break;
        case 8:
            totalComputer();
            break;
        case 9:
            countComp();
            break;
        case 10:
            updateCompInfo();
            break;
        case 11:
            topList();
            break;
        case 12:
            exit(0);
            break;
        case 13:
            help();
            break;
        }
}
inline void attributeMenu()
{
    cout << "1.Brand Name\n";
    cout << "2.Computer Name\n";
    cout << "3.MAC Address\n";
    cout << "4.Generation\n";
    cout << "5.RAM\n";
    cout << "6.Storage\n";
    cout << "7.Processor\n";
    cout << "8.Price\n";
}
inline void headerDisplay()
{
    cout
        << left << setw(5) << "No" << left << setw(20) << "Brand Name" << left << setw(30) << "Computer Name" << left << setw(20) << "MAC Address" << left << setw(15) << "Generation" << left << setw(6) << "RAM" << left << setw(10) << "storage" << left << setw(20) << "Processor Speed" << left << setw(16) << "Price (ETB.)" << endl;
}
void displaySpec(int l)
{
    cout
        << left << setw(5) << l << setw(20) << myPC[l - 1].brandName << left << setw(30) << myPC[l - 1].computerName << left << setw(20) << myPC[l - 1].MAC_Address << left << setw(15) << myPC[l - 1].generation << left << setw(6) << myPC[l - 1].RAM << left << setw(10) << myPC[l - 1].storage << left << setw(20) << myPC[l - 1].p_speed << left << setw(16) << myPC[l - 1].price << endl;
}
void insertNewComp()
{
    int check, quant;
    if (compQ == 0)
    {
        check = 0;
    }
    else
    {
        check = compQ;
    }
    char back;
    cout << "How many computers do you want to insert : ";
check:
    cin >> quant;
    while (dataTypeChecker(quant) != 0 || quant < 1 || quant > 10)
    {
        cout << "Invalid input, How many computers do you want to insert : ";
        cin >> quant;
    }
    for (int i = check; i < quant + check; i++)
    {

        cout << "\nEnter specifications for "
             << "computer " << i + 1 << endl;
        cout << "\n\nBrand name : ";
        cin.getline(myPC[i].brandName, 20);
        cout << "Computer Name : ";
        cin.getline(myPC[i].computerName, 50);
        cout << "MAC Address : ";
        cin.getline(myPC[i].MAC_Address, 20);
        while(MAC_AddressChecker(myPC[i].MAC_Address)!=0)
        {
            cout<<"There is another computer with MAC Address : "<<myPC[i].MAC_Address<<" Please enter again.\n";
            cin.getline(myPC[i].MAC_Address, 20);
        }
        cout << "Generation :";
        cin >> myPC[i].generation;
        while (dataTypeChecker(myPC[i].generation) != 0 || myPC[i].generation < 0)
        {
            cout << "Invalid input, please enter again.\n";
            cin >> myPC[i].generation;
        }
        cout << "RAM : ";
        cin >> myPC[i].RAM;
        while (dataTypeChecker(myPC[i].RAM) != 0 || myPC[i].RAM < 0)
        {
            cout << "Invalid input, please enter again.\n";
            cin >> myPC[i].RAM;
        }
        cout << "Storage : ";
        cin >> myPC[i].storage;
        while (dataTypeChecker(myPC[i].storage) != 0 || myPC[i].storage < 0)
        {
            cout << "Invalid input, please enter again.\n";
            cin >> myPC[i].storage;
        }
        cout << "Processor speed (in GHz): ";
        cin >> myPC[i].p_speed;
        while (dataTypeChecker(myPC[i].p_speed) != 0 || myPC[i].p_speed<0)
        {
            cout << "Invalid input, please enter again.\n";
            cin >> myPC[i].p_speed;
        }
        cout << "Price of the Computer : ";
        cin >> myPC[i].price;
        cin.ignore();
    }
    compQ = quant + check;
    cout << "\n\n ----Your data is successfully recorded !!----\n\nEnter 'M or 'm' in your keyboard to go back to the main menu and 'L' or 'l' to see the list.\n";
back:
    cin >> back;
    if (back == 'M' || back == 'm')
        menu();
    else if (back == 'L' || back == 'l')
        display();
    else
    {
        cout << "Invalid input, please enter again!!\n";
        goto back;
    }
}
void deleteCompRec()
{
    int choice;
    cout << " Choose : \n";
    cout << " 1. Delete computer record by attribute \n";
    cout << " 2. Delete by Minimum \n";
    cout << " 3. Delete by Maximum \n";
    cout << " 4. Delete the fifth computer's record \n";
    cout << " 5. Delete the last computer's record \n";
    cout << " 6. Go to Main Menu \n";
    again:
    cin >> choice;
    while (dataTypeChecker(choice) != 0 || choice<0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        deleteByAtt();
        break;
    case 2:
        delete_Min();
        break;
    case 3:
        delete_Max();
        break;
    case 4:
        deleteFifth();
        break;
        exit(1);
    case 5:
        deleteLast();
        break;
    case 6:
        menu();
        break;
    default:
        cout << " You entered wrong choice, please enter again:: ";
        goto again;
        break;
    }
}
void deleteByAtt()
{
    int choice, pos, att, count = 0;
    char a;
    char *c;
    c = new char[20];
    // char Bname[20], Cname[30], Maddress[15];
    float pSpeed;
deleteAgain:
    cout << " Choose the attribute to delete computers:" << endl;
    cout << "1.Number\n";
    cout << "2.Brand Name\n";
    cout << "3.Computer Name\n";
    cout << "4.MAC Address\n";
    cout << "5.Generation\n";
    cout << "6.RAM\n";
    cout << "7.Storage\n";
    cout << "8.Processor speed\n";
    cout << "9.Price\n";
dele:
    cin >> choice;
    while (dataTypeChecker(choice) != 0 || choice<0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        cout << "Enter the position of the computer you want to delete : ";
        cin >> pos;
        while (dataTypeChecker(pos) != 0 || pos<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> pos;
        }
        if (myPC[pos - 1].RAM == 0)
            cout << "There is no computer recorded in this position.\n";
        else
        {
            memset(myPC[pos - 1].brandName, 0, sizeof(myPC[pos - 1].brandName));
            memset(myPC[pos - 1].computerName, 0, sizeof(myPC[pos - 1].computerName));
            memset(myPC[pos - 1].MAC_Address, 0, sizeof(myPC[pos - 1].MAC_Address));
            myPC[pos - 1].generation = '\0';
            myPC[pos - 1].RAM = '\0';
            myPC[pos - 1].storage = '\0';
            myPC[pos - 1].p_speed = '\0';
            myPC[pos - 1].price = '\0';
            cout << "\n----Computer deleted succeccfully----\n";
        }
        break;
    case 2:
        cout << " Enter the Brand Name of the computer you want to delete : ";
        cin.ignore();
        cin.getline(c, 20);
        for (i = 0; i < compQ; i++)
        {
            if (stricmp(myPC[i].brandName, c) == 0)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
            else
                count++;
        }
        if (count == compQ)
            cout << "There is no computer with brand name " << c << " recorded in this system.";
        else
            cout << "\n----Computer deleted succeccfully----\n";
        break;

    case 3:
        cout << " Enter Computer Name of the computer you want to delete : ";
        cin.ignore();
        cin.getline(c, 20);
        for (i = 0; i < compQ; i++)
        {
            if (stricmp(myPC[i].computerName, c) == 0)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
            else
                count++;
        }
        if (count == compQ)
            cout << "There is no computer with computer name " << c << " recorded in this system.";
        else
            cout << "\n----Computer deleted succeccfully----\n";
        break;

    case 4:
        cout << " Enter the MAC Address of the computer you want to delete : ";
        cin.ignore();
        cin.getline(c, 12);
        for (i = 0; i < compQ; i++)
        {
            if (stricmp(myPC[i].MAC_Address, c) == 0)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
            else
                count++;
        }
        if (count == compQ)
            cout << "There is no computer with MAC Address " << c << " recorded in this system.";
        else
            cout << "\n----Computer deleted succeccfully----\n";
        break;

    case 5:

        cout << " Enter the generation of the computer you want to delete: ";
        cin >> att;
        while (dataTypeChecker(att) != 0 || att<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> att;
        }
        for (i = 0; i < compQ; i++)
        {
            if (myPC[i].generation == att)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
            else
                count++;
        }
        if (count == compQ)
            cout << "There is no computer with generation " << att << " recorded in this system.";
        else
            cout << "\n----Computer deleted succeccfully----\n";
        break;

    case 6:

        cout << " Enter the RAM of the computer you want to delete: ";
        cin >> att;
        while (dataTypeChecker(att) != 0 || att<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> att;
        }
        for (i = 0; i < compQ; i++)
        {
            if (myPC[i].RAM == att)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
            else
                count++;
        }
        if (count == compQ)
            cout << "There is no computer with RAM " << att << " recorded in this system.";
        else
            cout << "\n----Computer deleted succeccfully----\n";
        break;
    case 7:

        cout << " Enter the storage of the computer you want to delete: ";
        cin >> att;
        while (dataTypeChecker(att) != 0 || att<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> att;
        }
        for (i = 0; i < compQ; i++)
        {
            if (myPC[i].storage == att)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
            else
                count++;
        }
        if (count == compQ)
            cout << "There is no computer with storage " << att << " recorded in this system.";
        else
            cout << "\n----Computer deleted succeccfully----\n";
        break;
    case 8:

        cout << " Enter the generation of the computer you want to delete: ";
        cin >> pSpeed;
        while (dataTypeChecker(pSpeed) != 0 || pSpeed<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> pSpeed;
        }
        for (i = 0; i < compQ; i++)
        {
            if (myPC[i].p_speed == pSpeed)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
            else
                count++;
        }
        if (count == compQ)
            cout << "There is no computer with processor speed " << pSpeed << " recorded in this system.";
        else
            cout << "\n----Computer deleted succeccfully----\n";
        break;
    case 9:

        cout << " Enter the price of the computer you want to delete: ";
        cin >> att;
        while (dataTypeChecker(att) != 0 || att<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> att;
        }
        for (i = 0; i < compQ; i++)
        {
            if (myPC[i].price == att)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
            else
                count++;
        }
        if (count == compQ)
            cout << "There is no computer with generation " << att << " recorded in this system.";
        else
            cout << "\n----Computer deleted succeccfully----\n";
        break;
    default:
        cout << " You entered wrong choice, please enter again::";
        goto dele;
    }
question:
    cout << "\n\nIf you want to delete another computer press 'D' or 'd' and to see the updated list press 'L' or 'l'\n";
    cin >> a;
    if (a == 'D' || a == 'd')
        goto deleteAgain;
    else if (a == 'L' || a == 'l')
        display();
    else
        cout << "Invalid input, enter again !!\n\n";
    goto question;
    nullChecker();
}
void delete_Max()
{
    int choice;
    char back;
    float max;
    cout << " Choose, To delete computers with:" << endl;
    cout << " 1.  Maximum RAM :" << endl;
    cout << " 2.  Maximum Internal Storage :" << endl;
    cout << " 3.  Maximum Generation:" << endl;
    cout << " 4.  Maximum price:" << endl;
    cout << " 5.  To go to main menu:" << endl;
    cout << " 6.  To delete by Minimum:" << endl;
    cout << " 7.  Exit. " << endl;
again:
    cin >> choice;
    while (dataTypeChecker(choice) != 0 || choice<0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        max = myPC[0].RAM;
        for (int i = 0; i < compQ; i++)
        {

            if (max < myPC[i].RAM)
                max = myPC[i].RAM;
        }
        for (i = 0; i < compQ; i++)
        {
            if (max == myPC[i].RAM)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
        }
        cout << "Selected data is deleted successfully !  Press 'M' or 'm'to go back to the main menu\n";
    back:
        cin >> back;
        if (back == 'M' || back == 'm')
        {
            menu();
        }
        else
            goto back;
        break;
    case 2:
        max = myPC[0].storage;
        for (int i = 0; i < compQ; i++)
        {

            if (max < myPC[i].storage)
                max = myPC[i].storage;
        }
        for (i = 0; i < compQ; i++)
        {
            if (max == myPC[i].storage)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
        }
        cout << "Selected data is deleted successfully !  Press 'M' or 'm' to go back to the main menu\n";
    again1:
        cin >> back;
        if (back == 'M' || back == 'm')
        {
            menu();
        }
        else
            goto again1;
        break;
    case 3:
        max = myPC[0].generation;
        for (int i = 0; i < compQ; i++)
        {

            if (max < myPC[i].generation)
                max = myPC[i].generation;
        }
        for (i = 0; i < compQ; i++)
        {
            if (max == myPC[i].generation)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
        }
        cout << "Selected data is deleted successfully !  Press 'M' or 'm' to go back to the main menu\n";
    again2:
        cin >> back;
        if (back == 'M' || back == 'm')
        {
            menu();
        }
        else
            goto again2;
        break;
    case 4:
        max = myPC[0].price;
        for (int i = 0; i < compQ; i++)
        {

            if (max < myPC[i].price)
                max = myPC[i].price;
        }
        for (i = 0; i < compQ; i++)
        {
            if (max == myPC[i].price)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
        }

        cout << "Selected data is deleted successfully !  Press 'M' or 'm' to go back to the main menu\n";
    again3:
        cin >> back;
        if (back == 'M' || back == 'm')
        {
            menu();
        }
        else
            goto again3;
        break;
    case 5:
        menu();
        break;
    case 6:
        delete_Min();
        break;
    case 7:
        exit(1);
        break;
    default:
        cout << " You entered wrong choice, please enter again:: ";
        goto again;
        break;
    }
    nullChecker();
}
void delete_Min()
{
    float min;
    int choice;
    char back;
    cout << " Choose, To delete computers with:\n";
    cout << " 1.  Minimum RAM :" << endl;
    cout << " 2.  Minimum Internal Storage :" << endl;
    cout << " 3.  Minimum Generation:" << endl;
    cout << " 4.  Minimum price:" << endl;
    cout << " 5.  To go to main menu:" << endl;
    cout << " 6.  To delete by Maximum:" << endl;
    cout << " 7.  Exit. " << endl;
    again:
    cin >> choice;
    while (dataTypeChecker(choice) != 0 || choice<0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        min = myPC[0].RAM;
        for (i = 0; i < compQ; i++)
        {

            if (min > myPC[i].RAM)
                min = myPC[i].RAM;
        }
        for (i = 0; i < compQ; i++)
        {
            if (min == myPC[i].RAM)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
        }
        cout << "Selected data is deleted successfully !  Press 'M' or 'm' to go back to the main menu\n";
    back:
        cin >> back;
        if (back == 'M' || back == 'm')
        {
            menu();
        }
        else
            goto back;
        break;
    case 2:
        min = myPC[0].storage;
        for (int i = 0; i < compQ; i++)
        {

            if (min > myPC[i].storage)
                min = myPC[i].storage;
        }
        for (i = 0; i < compQ; i++)
        {
            if (min == myPC[i].storage)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
        }
        cout << "Selected data is deleted successfully !  Press 'M' or 'm' to go back to the main menu\n";
    again4:
        cin >> back;
        if (back == 'M' || back == 'm')
        {
            menu();
        }
        else
            goto again4;
        break;
    case 3:
        min = myPC[0].generation;
        for (int i = 0; i < compQ; i++)
        {

            if (min > myPC[i].generation)
                min = myPC[i].generation;
        }
        for (i = 0; i < compQ; i++)
        {
            if (min == myPC[i].generation)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
        }
        cout << "Selected data is deleted successfully !  Press 'M' or 'm' to go back to the main menu\n";
    again5:
        cin >> back;
        if (back == 'M' || back == 'm')
        {
            menu();
        }
        else
            goto again5;
        break;
    case 4:
        min = myPC[0].price;
        for (int i = 0; i < compQ; i++)
        {

            if (min > myPC[i].price)
                min = myPC[i].price;
        }
        for (i = 0; i < compQ; i++)
        {
            if (min == myPC[i].price)
            {
                memset(myPC[i].brandName, 0, sizeof(myPC[i].brandName));
                memset(myPC[i].computerName, 0, sizeof(myPC[i].computerName));
                memset(myPC[i].MAC_Address, 0, sizeof(myPC[i].MAC_Address));
                myPC[i].generation = '\0';
                myPC[i].RAM = '\0';
                myPC[i].storage = '\0';
                myPC[i].p_speed = '\0';
                myPC[i].price = '\0';
            }
        }
        cout << "Selected data is deleted successfully !  Press 'M' or 'm' to go back to the main menu\n";
    again6:
        cin >> back;
        if (back == 'M' || back == 'm')
        {
            menu();
        }
        else
            goto again6;
        break;
    case 5:
        menu();
    case 6:
        delete_Max();
        break;
    case 7:
        exit(1);
    default:
        cout << " You entered wrong choice, please enter again:: ";
        goto again;
        break;
    }
    nullChecker();
}
void deleteFifth()
{
    char back;
    if (compQ>=5)
    {
        memset(myPC[5].brandName, 0, sizeof(myPC[5].brandName));
        memset(myPC[5].computerName, 0, sizeof(myPC[5].computerName));
        memset(myPC[5].MAC_Address, 0, sizeof(myPC[5].MAC_Address));
        myPC[5].generation = '\0';
        myPC[5].RAM = '\0';
        myPC[5].storage = '\0';
        myPC[5].p_speed = '\0';
        myPC[5].price = '\0';

        cout << "\n----Computer deleted succeccfully----\n";
    }
    else
        cout << "The number of computers currently in the system is less than 5.\n";
    cout << "\nIf you want to delete other computers press 'D' or 'd' and Press 'M' or 'm' to go back to the main menu.\n";
    back:
    cin >> back;
    if (back == 'M' || back == 'm')
        menu();
    else if(back == 'D' || back == 'd')
        deleteCompRec();
    else
    {
        cout << "Invalid input, please enter again!!\n";
        goto back;
    }
}
void deleteLast()
{
    char back;
    if(compQ!=0)
    {
        char back;
        memset(myPC[compQ-1].brandName, 0, sizeof(myPC[compQ-1].brandName));
        memset(myPC[compQ-1].computerName, 0, sizeof(myPC[compQ-1].computerName));
        memset(myPC[compQ-1].MAC_Address, 0, sizeof(myPC[compQ-1].MAC_Address));
        myPC[compQ-1].generation = '\0';
        myPC[compQ-1].RAM = '\0';
        myPC[compQ-1].storage = '\0';
        myPC[compQ-1].p_speed = '\0';
        myPC[compQ-1].price = '\0';
        cout << "\n----Computer deleted succeccfully----\n";
    }
    else
        cout << "There is no computer currently in the system .\n";
    cout << "\nIf you want to delete other computers press 'D' or 'd' and Press 'M' or 'm' to go back to the main menu.\n";
    back:
    cin >> back;
    if (back == 'M' || back == 'm')
        menu();
    else if(back == 'D' || back == 'd')
        deleteCompRec();
    else
    {
        cout << "Invalid input, please enter again!!\n";
        goto back;
    }
}
void display()
{
    nullChecker();
    char back;
    system("cls");
    cout << "These are the computers available right now.\n\n";
    headerDisplay();

    for (int i = 0; i < compQ; i++)
    {
        cout
            << left << setw(5) << i + 1 << setw(20) << myPC[i].brandName << left << setw(30) << myPC[i].computerName << left << setw(20) << myPC[i].MAC_Address << left << setw(15) << myPC[i].generation << left << setw(6) << myPC[i].RAM << left << setw(10) << myPC[i].storage << left << setw(20) << myPC[i].p_speed << left << setw(16) << myPC[i].price << endl;
    }
    cout << "\n\nPress 'M' or 'm' on your keyboard to go back to the main menu.\n";
back:
    cin >> back;
    if (back == 'M' || back == 'm')
    {
        menu();
    }
    else
    {
        cout << "Invalid input, please enter again!!\n";
        goto back;
    }
}
void searchComp()
{
    int choice;
    cout << " Choose : \n";
    cout << " 1. Search computer record by attribute \n";
    cout << " 2. Serach Minimum \n";
    cout << " 3. Serach Maximum \n";
    cout << " 4. Go to Main Menu \n";
    again:
    cin >> choice;
    while (dataTypeChecker(choice) != 0 )
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        searchByAtt();
        break;
    case 2:
        search_Min();
        break;
    case 3:
        search_Max();
        break;
    case 4:
        menu();
        break;
    default:
        cout << " You entered wrong choice, please enter again:: ";
        goto again;
        break;
    }
}
void searchByAtt()
{
    char *c;
    c = new char[20];
    int choice, find;
    char back;
    int count = 0;
searchAgain:
    cout << "By what attribute do you want to search : \n\n";
    cout << "1.Number\n";
    cout << "2.Brand Name\n";
    cout << "3.Computer Name\n";
    cout << "4.MAC Address\n";
    cout << "5.Generation\n";
    cout << "6.RAM\n";
    cout << "7.Storage\n";
    cout << "8.Processor speed\n";
    cout << "9.Price\n";
    cin >> choice;
    while (dataTypeChecker(choice) != 0 )
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        int n;
        cout << "Enter the Computer position: ";
        cin >> n;
        while (dataTypeChecker(n) != 0 || n<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> n;
        }
        if (myPC[n - 1].RAM == 0)
            cout << "There is no computer recorded in this position.\n";
        else
        {
            headerDisplay();
            displaySpec(n);
        }
        break;
    case 2:
        cout << "Enter your searching word (Brand Name): ";
        cin.ignore(20, '\n');
        cin.getline(c, 20);
        cout << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            int res = stricmp(myPC[i].brandName, c);
            if (res == 0)
                displaySpec(i + 1);
            else
                count++;
        }
        if (count == compQ)
            cout << "\n\nThere is no computer with brand name " << c;
        break;
    case 3:
        cout << "Enter your searching word (Computer Name): ";
        cin.ignore(20, '\n');
        cin.getline(c, 20);
        cout << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            int res = stricmp(myPC[i].computerName, c);
            if (res == 0)
                displaySpec(i + 1);
            else
                count++;
        }
        if (count == compQ)
            cout << "\n\nThere is no computer with computer name " << c;
        break;
    case 4:
        cout << "Enter your searching word (MAC Address): ";
        cin.ignore(12, '\n');
        cin.getline(c, 12);
        cout << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            int res = stricmp(myPC[i].MAC_Address, c);
            if (res == 0)
                displaySpec(i + 1);
            else
                count++;
        }
        if (count == compQ)
            cout << "\n\nThere is no computer with MAC Address " << c;
        break;
    case 5:
        cout << "Enter the generation you want to search ";
        cin >> find;
        while (dataTypeChecker(find) != 0 || find<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> find;
        }
        cout << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (myPC[i].generation == find)
                displaySpec(i + 1);
            else
                count++;
        }
        if (count == compQ)
            cout << "\n\nThere is no computer with generation " << find;
        break;
    case 6:
        cout << "Enter the RAM you want to search ";
        cin >> find;
        while (dataTypeChecker(find) != 0 || find<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> find;
        }
        cout << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (myPC[i].RAM == find)
                displaySpec(i + 1);
            else
                count++;
        }
        if (count == compQ)
            cout << "\n\nThere is no computer with RAM " << find;
        break;
    case 7:
        cout << "Enter the storage you want to search ";
        cin >> find;
        while (dataTypeChecker(find) != 0 || find<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> find;
        }
        cout << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (myPC[i].storage == find)
                displaySpec(i + 1);
            else
                count++;
        }
        if (count == compQ)
            cout << "\n\nThere is no computer with storage " << find;
        break;
    case 8:
        cout << "Enter the processor speed you want to search ";
        cin >> find;
        while (dataTypeChecker(find) != 0 || find<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> find;
        }
        cout << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (myPC[i].p_speed == find)
                displaySpec(i + 1);
            else
                count++;
        }
        if (count == compQ)
            cout << "\n\nThere is no computer with processor speed " << find;
        break;
    case 9:
        cout << "Enter the price you want to search ";
        cin >> find;
        while (dataTypeChecker(find) != 0 || find<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> find;
        }
        cout << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (myPC[i].price == find)
                displaySpec(i + 1);
            else
                count++;
        }
        if (count == compQ)
            cout << "\n\nThere is no computer with price " << find;
        break;
    default:
        cout << "Invalid input, please enter again \n";
    }
    cout << "\n\nIf you want to search another computer press 'S' or 's' and to go back to the main menu press 'M' or 'm'\n";
    cin >> back;
    if (back == 'S' || back == 's')
        goto searchAgain;
    else if (back = 'M' || back == 'm')
        menu();
    else
        cout << "Invalid input, enter again !!\n\n";
}
void search_Max()
{
    float max;
    int choice;
    char back;
again:
    cout << "Enter your choice\n";
    cout << "1. Maximum Price.\n";
    cout << "2. Maximum RAM.\n";
    cout << "3. Maximum Storage.\n";
    cout << "4. Maximum Generation.\n";
    cout << "5. Maximum Processor Speed.\n";
    cin >> choice;
    while (dataTypeChecker(choice) != 0 )
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {

    case 1:

        max = myPC[0].price;
        for (int i = 0; i < compQ; i++)
        {

            if (max > myPC[i].price)
                max = myPC[i].price;
        }
        cout << "The computer with maximum price from the list is " << max << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (max == myPC[i].price)
                displaySpec(i+1);
        }
        break;
    case 2:
        max = myPC[0].RAM;
        for (int i = 0; i < compQ; i++)
        {

            if (max > myPC[i].RAM)
                max = myPC[i].RAM;
        }
        cout << "The computer witn maximum size of RAM from the list is " << max << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (max == myPC[i].RAM)
                displaySpec(i+1);
        }
        break;
    case 3:
        max = myPC[0].storage;
        for (int i = 0; i < compQ; i++)
        {

            if (max > myPC[i].storage)
                max = myPC[i].storage;
        }
        cout << "The computer with maximum storage size from the list is " << max << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (max == myPC[i].storage)
                displaySpec(i+1);
        }
        break;
    case 4:
        max = myPC[0].generation;
        for (int i = 0; i < compQ; i++)
        {

            if (max > myPC[i].generation)
                max = myPC[i].generation;
        }
        cout << "The computer with the oldest generation from the list is " << max << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (max == myPC[i].generation)
                displaySpec(i+1);
        }
        break;

    case 5:

        max = myPC[0].p_speed;
        for (int i = 0; i < compQ; i++)
        {

            if (max > myPC[i].p_speed)
                max = myPC[i].p_speed;
        }
        cout << "The computer with maximum processor speed from the list is " << max << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (max == myPC[i].p_speed)
                displaySpec(i+1);
        }
        break;

    default:
        cout << "invalid in put ,pls enter again\n";
        goto again;
    }
    cout << "\nIf you want to search other computers press 'S' or 's' and Press 'M' or 'm' to go back to the main menu.\n";
    back:
    cin >> back;
    if (back == 'M' || back == 'm')
        menu();
    else if(back == 'S' || back == 's')
        searchComp();
    else
    {
        cout << "Invalid input, please enter again!!\n";
        goto back;
    }
}
void search_Min()
{
    float min;
    int choice;
    char back;
again:
    cout << "Enter your choice\n";
    cout << "1. Minimum Price.\n";
    cout << "2. Minimum RAM.\n";
    cout << "3. Minimum Storage.\n";
    cout << "4. Minimum Generation.\n";
    cout << "5. Minimum Processor Speed.\n";
    cin >> choice;
    while (dataTypeChecker(choice) != 0 )
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {

    case 1:

        min = myPC[0].price;
        for (int i = 0; i < compQ; i++)
        {

            if (min > myPC[i].price)
                min = myPC[i].price;
        }
        cout << "The computer with minimum price from the list is " << min << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (min == myPC[i].price)
                displaySpec(i+1);
        }
        break;
    case 2:
        min = myPC[0].RAM;
        for (int i = 0; i < compQ; i++)
        {

            if (min > myPC[i].RAM)
                min = myPC[i].RAM;
        }
        cout << "The computer witn minimum size of RAM from the list is " << min << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (min == myPC[i].RAM)
                displaySpec(i+1);
        }
        break;
    case 3:
        min = myPC[0].storage;
        for (int i = 0; i < compQ; i++)
        {

            if (min > myPC[i].storage)
                min = myPC[i].storage;
        }
        cout << "The computer with minimum storage size from the list is " << min << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (min == myPC[i].storage)
                displaySpec(i+1);
        }
        break;
    case 4:
        min = myPC[0].generation;
        for (int i = 0; i < compQ; i++)
        {

            if (min > myPC[i].generation)
                min = myPC[i].generation;
        }
        cout << "The computer with the oldest generation from the list is " << min << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (min == myPC[i].generation)
                displaySpec(i+1);
        }
        break;

    case 5:

        min = myPC[0].p_speed;
        for (int i = 0; i < compQ; i++)
        {

            if (min > myPC[i].p_speed)
                min = myPC[i].p_speed;
        }
        cout << "The computer with minimum processor speed from the list is " << min << endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {

            if (min == myPC[i].p_speed)
                displaySpec(i+1);
        }
        break;

    default:
        cout << "invalid in put ,pls enter again\n";
        goto again;
    }
    cout << "\nIf you want to search other computers press 'S' or 's' and Press 'M' or 'm' to go back to the main menu.\n";
    back:
    cin >> back;
    if (back == 'M' || back == 'm')
        menu();
    else if(back == 'S' || back == 's')
        searchComp();
    else
    {
        cout << "Invalid input, please enter again!!\n";
        goto back;
    }
}
void updateCompInfo()
{
    int input, att_input, x;
    char a;
    char *c;
    c = new char[20];
updateAgain:
    cout << "Choose the computer number you want to update: \n";
    if (compQ == 0)
    {
        cout << "Please insert computers !!\n";
        menu();
    }
    cin >> input;
    while (dataTypeChecker(input) != 0 || input <0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> input;
    }
    while (input > compQ)
    {
        cout << "There is no computer recorded in this position, please enter again\n";
        cin >> input;
        while (dataTypeChecker(input) != 0 || input <0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> input;
        }
    }
    cout << endl;
    headerDisplay();
    displaySpec(input);
    cout << "\nWhat attribute do you want to update : \n";
    attributeMenu();
    cin >> att_input;
    while (dataTypeChecker(att_input) != 0 || att_input<0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> att_input;
    }
    switch (att_input)
    {
    case 1:
        cout << "Enter the new brand name : ";
        cin.getline(c, 20);
        strcpy(myPC[input - 1].brandName, c);
        delete[] c;
        break;
    case 2:
        cout << "Enter new computer name : ";
        cin.getline(c, 20);
        strcpy(myPC[input - 1].computerName, c);
        delete[] c;
        break;
    case 3:
        cout << "Enter new MAC Address : ";
        cin.getline(c, 20);
        while(MAC_AddressChecker(c)!=0)
        {
            cout<<"There is another computer with MAC Address : "<<c<<" Please enter again.\n";
            cin.getline(c, 20);
        }
        strcpy(myPC[input - 1].MAC_Address, c);
        delete[] c;
        break;
    case 4:
        cout << "Enter new generation : ";
        cin >> x;
        while (dataTypeChecker(x) != 0 || x<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> x;
        }
        myPC[input - 1].generation = x;
        break;
    case 5:
        cout << "Enter new RAM : ";
        cin >> x;
        while (dataTypeChecker(x) != 0 || x<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> x;
        }
        myPC[input - 1].RAM = x;
        break;
    case 6:
        cout << "Enter new storage : ";
        cin >> x;
        while (dataTypeChecker(x) != 0 || x<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> x;
        }
        myPC[input - 1].storage = x;
        break;
    case 7:
        cout << "Enter new processor speed : ";
        cin >> x;
        while (dataTypeChecker(x) != 0 || x<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> x;
        }
        myPC[input - 1].p_speed = x;
        break;
    case 8:
        cout << "Enter new price : ";
        cin >> x;
        while (dataTypeChecker(x) != 0 || x<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> x;
        }
        myPC[input - 1].price = x;
        break;
    }
    cout << "\n----Your data is successfully updated----\n";
    cout << "\n\nIf you want to update another computer's attribute press 'U' or 'u' and to see the updated list press 'L' or 'l'\n";
    cin >> a;
    if (a == 'U' || a == 'u')
        goto updateAgain;
    else if (a == 'L' || a == 'l')
        display();
    else
        cout << "Invalid input, enter again !!\n\n";
}
void countComp()
{
    int choice, att_input;
    char a;
    char *c;
    c = new char[20];
countAgain:
    cout << "What attribute do you want to count ?\n";
    cout << "1.Brand Name\n";
    cout << "2.Computer Name\n";
    cout << "3.Generation\n";
    cout << "4.RAM\n";
    cout << "5.Storage\n";
    cout << "6.Processor\n";
    cout << "7.Price\n";
    int count = 0;
    cin >> choice;
    while (dataTypeChecker(choice) != 0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        cout << "Enter the Brand name you want to count : \n";
        cin.ignore();
        cin.getline(c, 20);
        cout<<endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (stricmp(myPC[i].brandName, c) == 0)
            {
                displaySpec(i+1);
                count++;
            }
        }
        cout<<endl;
        if (count > 1)
            cout << "There are " << count << " " << c << "  computers in the system\n";
        else if (count == 1)
            cout << "There is only " << count << c << "  computer in the system\n";
        else
            cout << "\nThere is no " << c << " computer in the system";
        delete[] c;
        break;
    case 2:
        cout << "\nter the Computer name you want to count : \n";
        cin.ignore();
        cin.getline(c, 20);
        cout<<endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (stricmp(myPC[i].MAC_Address, c) == 0)
            {
                displaySpec(i+1);
                count++;
            }
        }
        cout<<endl;
        if (count > 1)
            cout << "There are " << count << " " << c << " computers in the system\n";
        else if (count == 1)
            cout << "There is only " << count << c << " computer in the system\n";
        else
            cout << "\nThere is no " << c << " computer in the system";
        delete[] c;
        break;
    case 3:
        cout << "Enter the generation you to want count" << endl;
        cin >> att_input;
        while (dataTypeChecker(att_input) != 0 || att_input<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> att_input;
        }
        cout<<endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (att_input == myPC[i].generation)
            {
                displaySpec(i+1);
                count++;
            }
        }
        cout<<endl;
        if (count > 1)
            cout << "There are " << count << " computers "
                 << "with generation " << att_input << " in the system\n";
        else if (count == 1)
            cout << "There is only " << count << " computer "
                 << "with generation " << att_input << " in the system\n";
        else
            cout << "\nThere is no computer with generation " << att_input << " in the system\n";
        break;
    case 4:
        cout << "Enter the RAM size you want to count : \n";
        cin >> att_input;
         while (dataTypeChecker(att_input) != 0 || att_input<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> att_input;
        }
        cout<<endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (att_input == myPC[i].RAM)
            {
                displaySpec(i+1);
                count++;
            }
        }
        cout<<endl;
        if (count > 1)
            cout << "There are " << count << " computers "
                 << "with RAM size " << att_input << " in the system\n";
        else if (count == 1)
            cout << "There is only " << count << " computer "
                 << "with RAM size " << att_input << " in the system\n";
        else
            cout << "\nThere is no computer with RAM size " << att_input << " in the system\n";
        break;
    case 5:
        cout << "Enter the storage size you want to count : \n";
        cin >> att_input;
        while (dataTypeChecker(att_input) != 0 || att_input<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> att_input;
        }
        cout<<endl;
        for (int i = 0; i < compQ; i++)
        {
            if (att_input == myPC[i].storage)
            {
                displaySpec(i+1);
                count++;
            }
        }
        cout<<endl;
        if (count > 1)
            cout << "There are " << count << " computers "
                 << "with storage size " << att_input << " in the system\n";
        else if (count == 1)
            cout << "There is only " << count << " computer "
                 << "with storage size " << att_input << " in the system\n";
        else
            cout << "\nThere is no computer with storage size " << att_input << " in the system\n";
        break;

    case 6:
        float pSpeed;
        cout << "Enter the processor speed you want to count : \n";
        cin >> pSpeed;
         while (dataTypeChecker(pSpeed) != 0 || pSpeed<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> pSpeed;
        }
        cout<<endl;
        for (int i = 0; i < compQ; i++)
        {
            if (pSpeed == myPC[i].p_speed)
            {
                displaySpec(i+1);
                count++;
            }
        }
        cout<<endl;
        if (count > 1)
            cout << "There are " << count << " computers "
                 << "with processor speed " << pSpeed << " in the system\n";
        else if (count == 1)
            cout << "There is only " << count << " computer "
                 << "with processor speed " << pSpeed << " in the system\n";
        else
            cout << "\nThere is no computer with processor speed " << pSpeed << " in the system\n";
        break;
    case 7:
        cout << "Enter the maximum amount of money you can spend ?\n";
        cin >> att_input;
        while (dataTypeChecker(att_input) != 0 || att_input<0)
        {
            cout << "Invalid input, please enter again:\n";
            cin >> att_input;
        }
        cout<<endl;
        headerDisplay();
        for (int i = 0; i < compQ; i++)
        {
            if (att_input >= myPC[i].price)
            {
                displaySpec(i + 1);
                count++;
            }
        }
        cout<<endl;
        if (count > 1)
            cout << "There are " << count << " computers "
                 << "with price less than or equal to " << att_input << " in the system\n";
        else if (count == 1)
            cout << "There is only " << count << " computer "
                 << "with price less than or equal to " << att_input << " in the system\n";
        else
            cout << "\nThere is no computer with price less than or equal to " << att_input << " in the system\n";
        break;
    default:
        cout << "Invalid input, please enter your choice again !!\n";
        goto countAgain;
    }
question:
    cout << "\n\nIf you want to count another attribite press 'C' or 'c' and to go back to the main menu press 'M' or 'm' \n";
    cin >> a;
    if (a == 'C' || a == 'c')
        goto countAgain;
    else if (a == 'M' || a == 'm')
        menu();
    else
        cout << "Invalid input, enter again !!\n\n";
    goto question;
}
void topList()
{
    int choice, t, temp;
    char a;
    char *c;
    c = new char[20];
topAgain:
    cout << "Enter number of Tops (The current number of computers recorded is " << compQ << ") : ";
    if (compQ == 0)
    {
        cout << "Please insert computers !!";
        menu();
    }
top:
    cin >> t;
    while (dataTypeChecker(t) != 0 || t<0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> t;
    }
    if (t > compQ || t < 1)
    {
        cout << " Invalid input, please enter again: ";
        goto top;
    }
    cout << "Choose an attribute to print the tops : \n";
    cout << "1.Brand Name\n";
    cout << "2.Computer Name\n";
    cout << "3.Generation\n";
    cout << "4.RAM\n";
    cout << "5.Storage\n";
    cout << "6.Processor\n";
    cout << "7.Price\n";
sort:
    cin >> choice;
    while (dataTypeChecker(choice) != 0 || choice<0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        cout << "The computers with Top " << t << " Brand names are:\n\n";
        for (int i = 0; i < compQ; i++)
        {
            for (int j = i + 1; j < compQ; j++)
            {
                if (strcmp(myPC[i].brandName, myPC[j].brandName) > 0)
                {
                    swap(myPC[i],myPC[j]);
                }
            }
        }
        headerDisplay();
        for (i = 0; i < t; i++)
        {
            displaySpec(i+1);
        }
        break;
    case 2:
        cout << "The computers with Top " << t << " Computer names are:\n\n";
        for (int i = 0; i < compQ; i++)
        {
            for (int j = i; j < compQ; j++)
            {
                if (strcmp(myPC[i].computerName, myPC[j].computerName) > 0)
                {
                    swap(myPC[i],myPC[j]);
                }
            }
        }
        headerDisplay();
        for (i = 0; i < t; i++)
        {
            displaySpec(i+1);
        }
        break;
    case 3:
        cout << "The computers with Top" << t << " Generations are:\n\n";
        for (int i = 0; i < compQ; i++)
        {
            for (int j = i + 1; j < compQ; j++)
            {
                if (myPC[i].generation < myPC[j].generation)
                {
                    swap(myPC[i],myPC[j]);
                }
            }
        }
        headerDisplay();
        for (i = 0; i < t; i++)
        {
            displaySpec(i+1);
        }
        break;
    case 4:
        cout << "The computers with Top " << t << " RAMs are:\n\n";
        for (int i = 0; i < compQ; i++)
        {
            for (int j = i + 1; j < compQ; j++)
            {
                if (myPC[i].RAM < myPC[j].RAM)
                {
                    swap(myPC[i],myPC[j]);
                }
            }
        }
        headerDisplay();
        for (i = 0; i < t; i++)
        {
            displaySpec(i+1);
        }
        break;
    case 5:
        cout << "The computer with Top " << t << " Storage sizes are:\n\n";
        for (int i = 0; i < compQ; i++)
        {
            for (int j = i + 1; j < compQ; j++)
            {
                if (myPC[i].storage < myPC[j].storage)
                {
                    swap(myPC[i],myPC[j]);
                }
            }
        }
        headerDisplay();
        for (i = 0; i < t; i++)
        {
            displaySpec(i+1);
        }
        break;
    case 6:
        cout << "The computes with Top " << t << " Processor speeds are:\n\n";
        for (int i = 0; i < compQ; i++)
        {
            for (int j = i + 1; j < compQ; j++)
            {
                if (myPC[i].p_speed < myPC[j].p_speed)
                {
                    swap(myPC[i],myPC[j]);
                }
            }
        }
        headerDisplay();
        for (i = 0; i < t; i++)
        {
            displaySpec(i+1);
        }
        break;
    case 7:
        cout << "The computers with Top " << t << "  Prices are:\n\n";
        float temp;
        for (i = 0; i < compQ; i++)
        {
            for (j = i + 1; j < compQ; j++)
            {
                if (myPC[i].price < myPC[j].price)
                {
                    swap(myPC[i],myPC[j]);
                }
            }
        }
        headerDisplay();
        for (i = 0; i < t; i++)
        {
            displaySpec(i+1);
        }
        break;
    default:
        cout << " Invalid input, please enter again: ";
        goto sort;
        break;
    }
question:
    cout << "If you want to display Tops in other attribites press 'T' or 't' and to go back to the main menu press 'M' or 'm' \n";
    cin >> a;
    if (a == 'T' || a == 't')
        goto topAgain;
    else if (a == 'M' || a == 'm')
        menu();
    else
        cout << "Invalid input, enter again !!\n\n";
    goto question;
}
void average()
{
    int choice;
    char back;
    float total = 0, avera;
    int tot = 0, ave;
again:
    cout << "Enter your choice\n";
    cout << "1. To calculate average price.\n";
    cout << "2. To calculate average RAM.\n";
    cout << "3. To calculate average Storage.\n";
    cout << "4. To calculate average Generation.\n";
check:
    cin >> choice;
    while (dataTypeChecker(choice) != 0 || choice<0)
    {
        cout << "Invalid input, please enter again:\n";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        for (int i = 0; i < compQ; i++)
        {
            total += myPC[i].price;
        }
        avera = total / compQ;
        cout << "The average price of the computers is " << avera << endl;
        break;
    case 2:
        for (int i = 0; i < compQ; i++)
        {
            tot += myPC[i].RAM;
        }
        ave = tot / compQ;
        cout << "The average RAM of the computers is " << ave << endl;
        break;
    case 3:
        for (int i = 0; i < compQ; i++)
        {
            total += myPC[i].storage;
        }
        avera = total / compQ;
        cout << "The average storage of the computers is " << avera << endl;
        break;
    case 4:
        for (int i = 0; i < compQ; i++)
        {
            tot += myPC[i].generation;
        }
        ave = tot / compQ;
        cout << "The average generation of the computers is " << ave;
        break;
    default:
        cout << "Invalid input, please try again\n";
        goto check;
    }
inv:
    cout << "\nIf you want to check average of other attributes press 'A' or 'a' and to go back to the main menu press 'M' or 'm'\n";
    cin >> back;
    if (back == 'A' || back == 'a')
        goto again;
    else if (back == 'M' || back == 'm')
        menu();
    else
    {
        cout << "Invalid input, please enter again\n";
        goto inv;
    }
}
void fileImport()
{
    char back;
    ifstream fileImport("D:\\fullInfo(to import).txt");
    if (fileImport.fail())
    {
        cout << "\nError opening the notepad file!\n";
    }
    for (int i = compQ; i < 5 + compQ; i++)
    {
        fileImport.getline(myPC[i].brandName, 20);
        fileImport.getline(myPC[i].computerName, 20);
        fileImport.getline(myPC[i].MAC_Address, 20);
        for(j=i;j>=0;j--)
        {
            if(i==j)
                continue;
            else
            {
                if(stricmp(myPC[i].MAC_Address,myPC[j].MAC_Address)==0)
                {
                    cout<<"Please enter different MAC Address for each computer in the notepad file you want to import !\n";
                    exit(0);
                }
            }
            
        }
        fileImport >> myPC[i].generation;
        fileImport >> myPC[i].RAM;
        fileImport >> myPC[i].storage;
        fileImport >> myPC[i].p_speed;
        fileImport >> myPC[i].price;

        fileImport.ignore(256, '\n');
    }

    fileImport.close();

    cout << "Data imported successfully !  Press 'M' or 'm' to go back to the main menu\n";
    compQ += 5;
back:
    cin >> back;
    if (back == 'M' || back == 'm')
    {
        menu();
    }
    else
        goto back;
}
void fileExport()
{
    char back;
    ofstream fileExport("D:\\fullInfo.txt",ios::app);

    if (fileExport.fail())
        cout << "Error opening the notepad file!\n";

    fileExport << "These are the computers currently available:\n\n\n";
    fileExport
        << left << setw(5) << "No" << left << setw(20) << "Brand Name" << left << setw(30) << "Computer Name" << left << setw(20) << "MAC Address" << left << setw(15) << "Generation" << left << setw(6) << "RAM" << left << setw(10) << "storage" << left << setw(20) << "Processor Speed" << left << setw(16) << "Price (ETB.)" << endl;
    for (int i = 0; i < compQ; i++)
    {
        fileExport
            << left << setw(5) << i + 1 << setw(20) << myPC[i].brandName << left << setw(30) << myPC[i].computerName << left << setw(20) << myPC[i].MAC_Address << left << setw(15) << myPC[i].generation << left << setw(6) << myPC[i].RAM << left << setw(10) << myPC[i].storage << left << setw(20) << myPC[i].p_speed << left << setw(16) << myPC[i].price << endl;
    }
    fileExport.close();
    cout << "Data exported successfully !  Press 'M' or 'm' to go back to the main menu\n";
back:
    cin >> back;
    if (back == 'M' || back == 'm')
    {
        menu();
    }
    else
        goto back;
}
void totalComputer()
{
    char back;
    int count_of = 0;
    for (int i = 0; i < compQ; i++)
        count_of++;
    cout << "\nThere are " << count_of << " computers in the system\n";
    cout << "Press 'M' or 'm' to go back to the main menu\n";
back:
    cin >> back;
    if (back == 'M' || back == 'm')
    {
        menu();
    }
    else
        goto back;
}
int dataTypeChecker(int n)
{
    bool cond;
    int x;
    cond = cin.fail();
    x = cond;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return x;
}
void nullChecker()
{
    int count = 0;
    for (i = 0; i < compQ; i++)
    {
        if (myPC[i].RAM == 0)
            count++;
    }
    for (j = 0; j < compQ; j++)
    {
        for (i = 0; i < compQ; i++)
        {
            if (myPC[i + 1].RAM - myPC[i].RAM == myPC[i + 1].RAM)
            {
                myPC[compQ].RAM = myPC[i].RAM;
                myPC[i] = myPC[i + 1];
                myPC[i + 1].RAM = myPC[compQ].RAM;
            }
        }
    }
    compQ -= count;
}
int MAC_AddressChecker(char check[])
{
    bool same=0;
    int x;
    for(i=0;i<compQ;i++)
    {
        if(stricmp(myPC[i].MAC_Address,check)==0)
        {
            same=1;
            break;
        }
    }
    x=same;
    return x;   
}
void help()
{
    cout<<"not done";
}