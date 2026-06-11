#include<iostream>
#include<fstream>

using namespace std;

string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];
int total = 0;

void saveData()
{
    ofstream file("stud.txt");

    for(int i = 0; i < total; i++)
    {
        file << arr1[i] << " "
             << arr2[i] << " "
             << arr3[i] << " "
             << arr4[i] << " "
             << arr5[i] << endl;
    }

    file.close();
}

void loadData()
{
    ifstream file("stud.txt");

    total = 0;

    while(file >> arr1[total]
               >> arr2[total]
               >> arr3[total]
               >> arr4[total]
               >> arr5[total])
    {
        total++;
    }

    file.close();
}

void enter()
{
    int ch = 0;

    cout << "How many students do u want to enter??" << endl;
    cin >> ch;

    if(total == 0)
    {
        total = ch + total;

        for(int i = 0; i < ch; i++)
        {
            cout << "\nEnter the Data of student " << i + 1 << endl << endl;

            cout << "Enter name ";
            cin >> arr1[i];

            cout << "Enter Roll no ";
            cin >> arr2[i];

            cout << "Enter course ";
            cin >> arr3[i];

            cout << "Enter class ";
            cin >> arr4[i];

            cout << "Enter contact ";
            cin >> arr5[i];
        }
    }
    else
    {
        for(int i = total; i < ch + total; i++)
        {
            cout << "\nEnter the Data of student " << i + 1 << endl << endl;

            cout << "Enter name ";
            cin >> arr1[i];

            cout << "Enter Roll no ";
            cin >> arr2[i];

            cout << "Enter course ";
            cin >> arr3[i];

            cout << "Enter class ";
            cin >> arr4[i];

            cout << "Enter contact ";
            cin >> arr5[i];
        }

        total = ch + total;
    }

    saveData();
}

void show()
{
    if(total == 0)
    {
        cout << "No data is entered" << endl;
    }
    else
    {
        for(int i = 0; i < total; i++)
        {
            cout << "\nData of Student " << i + 1 << endl << endl;

            cout << "Name " << arr1[i] << endl;
            cout << "Roll no " << arr2[i] << endl;
            cout << "Course " << arr3[i] << endl;
            cout << "Class " << arr4[i] << endl;
            cout << "Contact " << arr5[i] << endl;
        }
    }
}

void search()
{
    if(total == 0)
    {
        cout << "No data is entered" << endl;
    }
    else
    {
        string rollno;

        cout << "Enter the roll no of student" << endl;
        cin >> rollno;

        bool found = false;

        for(int i = 0; i < total; i++)
        {
            if(rollno == arr2[i])
            {
                cout << "Name " << arr1[i] << endl;
                cout << "Roll no " << arr2[i] << endl;
                cout << "Course " << arr3[i] << endl;
                cout << "Class " << arr4[i] << endl;
                cout << "Contact " << arr5[i] << endl;

                found = true;
            }
        }

        if(!found)
        {
            cout << "Student not found!" << endl;
        }
    }
}

void update()
{
    if(total == 0)
    {
        cout << "No data is entered" << endl;
    }
    else
    {
        string rollno;

        cout << "Enter the roll no of student which you want to update" << endl;
        cin >> rollno;

        bool found = false;

        for(int i = 0; i < total; i++)
        {
            if(rollno == arr2[i])
            {
                cout << "\nPrevious data" << endl << endl;

                cout << "Name " << arr1[i] << endl;
                cout << "Roll no " << arr2[i] << endl;
                cout << "Course " << arr3[i] << endl;
                cout << "Class " << arr4[i] << endl;
                cout << "Contact " << arr5[i] << endl;

                cout << "\nEnter new data" << endl << endl;

                cout << "Enter name ";
                cin >> arr1[i];

                cout << "Enter Roll no ";
                cin >> arr2[i];

                cout << "Enter course ";
                cin >> arr3[i];

                cout << "Enter class ";
                cin >> arr4[i];

                cout << "Enter contact ";
                cin >> arr5[i];

                saveData();

                cout << "Record Updated Successfully!" << endl;

                found = true;
            }
        }

        if(!found)
        {
            cout << "Student not found!" << endl;
        }
    }
}

void deleterecord()
{
    if(total == 0)
    {
        cout << "No data is entered" << endl;
    }
    else
    {
        int a;

        cout << "Press 1 to delete all record" << endl;
        cout << "Press 2 to delete specific record" << endl;

        cin >> a;

        if(a == 1)
        {
            total = 0;

            saveData();

            cout << "All record is deleted..!!" << endl;
        }
        else if(a == 2)
        {
            string rollno;

            cout << "Enter the roll no of student which you wanted to delete" << endl;
            cin >> rollno;

            bool found = false;

            for(int i = 0; i < total; i++)
            {
                if(rollno == arr2[i])
                {
                    for(int j = i; j < total - 1; j++)
                    {
                        arr1[j] = arr1[j + 1];
                        arr2[j] = arr2[j + 1];
                        arr3[j] = arr3[j + 1];
                        arr4[j] = arr4[j + 1];
                        arr5[j] = arr5[j + 1];
                    }

                    total--;

                    saveData();

                    cout << "Your required record is deleted" << endl;

                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "Student not found!" << endl;
            }
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}

int main()
{
    loadData();

    int value;

    while(true)
    {
        cout << "\nPress 1 to enter data" << endl;
        cout << "Press 2 to show data" << endl;
        cout << "Press 3 to search data" << endl;
        cout << "Press 4 to update data" << endl;
        cout << "Press 5 to delete data" << endl;
        cout << "Press 6 to exit" << endl;

        cin >> value;

        switch(value)
        {
            case 1:
                enter();
                break;

            case 2:
                show();
                break;

            case 3:
                search();
                break;

            case 4:
                update();
                break;

            case 5:
                deleterecord();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid input" << endl;
        }
    }
}