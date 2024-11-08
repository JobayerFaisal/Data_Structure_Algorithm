#include <bits/stdc++.h>
using namespace std;

// Structure for the dynamic array
struct Dynamic_Array
{
    vector<vector<int>> data;
    vector<string> Headings;
};

// Function to insert a column (column_name) into the dynamic 2D array
void insertHeading(Dynamic_Array &dynArr, const string &column_name)
{
    dynArr.Headings.push_back(column_name);
    for (vector<int> &row : dynArr.data)
    {
        row.push_back(0); // Initialize new column with zeros
    }
}

// Function to insert data into the dynamic 2D array
void insertData(Dynamic_Array &dynArr, int row, int col, int value)
{
    if (row < 1 || col < 1)
    {
        cout << "Invalid row or column index" << endl;
        return;
    }

    // Ensure that there are enough rows
    if (row > dynArr.data.size())
    {
        // Insert new rows with zeros up to the specified row
        for (int i = dynArr.data.size(); i < row; i++)
        {
            dynArr.data.push_back(vector<int>(dynArr.Headings.size(), 0));
        }
    }

    // Ensure that there are enough columns
    if (col > dynArr.Headings.size())
    {
        cout << "Column index exceeds the number of topics" << endl;
        return;
    }

    dynArr.data[row - 1][col - 1] = value;
}

// Function to enter specific data for one entire row
void enterSpecificDataRow(Dynamic_Array &dynArr, size_t rowIndex)
{
    cout << "\nEnter Data for Row " << rowIndex + 1 << ":" << endl;

    for (size_t i = 0; i < dynArr.Headings.size(); i++)
    {
        int value;
        cout << "Enter data for column_name (" << i + 1 << ") " << dynArr.Headings[i] << ": ";
        cin >> value;
        insertData(dynArr, rowIndex + 1, i + 1, value);
    }
}

// Function to enter specific data for all rows
void enterSpecificData(Dynamic_Array &dynArr)
{
    int numRowsToAdd;
    cout << "Enter the number of rows to add data for: ";
    cin >> numRowsToAdd;

    for (int i = 0; i < numRowsToAdd; i++)
    {
        enterSpecificDataRow(dynArr, dynArr.data.size());
    }
}

// Function to delete a column (column_name) and adjust the dynamic 2D array
void deleteHeading(Dynamic_Array &dynArr, int col)
{
    if (col < 1 || col > dynArr.Headings.size())
    {
        cout << "Invalid column index" << endl;
        return;
    }

    dynArr.Headings.erase(dynArr.Headings.begin() + col - 1);
    for (vector<int> &row : dynArr.data)
    {
        row.erase(row.begin() + col - 1);
    }
}

// Function to delete data at a specific row and column
void deleteData(Dynamic_Array &dynArr, int row, int col)
{
    if (row < 1 || row > dynArr.data.size() || col < 1 || col > dynArr.Headings.size())
    {
        cout << "Invalid row or column index" << endl;
        return;
    }

    dynArr.data[row - 1][col - 1] = -1; // Mark the data as deleted (-1)
}

// Function to delete an entire row and deallocate memory
void deleteRow(Dynamic_Array &dynArr, int row)
{
    if (row < 1 || row > dynArr.data.size())
    {
        cout << "Invalid row index" << endl;
        return;
    }

    // Erase the row from the data vector
    dynArr.data.erase(dynArr.data.begin() + row - 1);
}

// Function to display the table names (topics) with their corresponding keys
void displayHeadings(const Dynamic_Array &dynArr)
{
    cout << "Table Names and Keys:" << endl;
    cout << "|";
    for (size_t i = 0; i < dynArr.Headings.size(); i++)
    {
        cout << "(" << i + 1 << ")"
             << " " << dynArr.Headings[i] << " |";
    }
    cout << endl;
}

// Function to display the dynamic 2D array as a table
void displayTable(const Dynamic_Array &dynArr)
{
    cout << "\nTable Contents:\n";

    // Display topics (column names)
    cout << "|";
    for (const string &column_name : dynArr.Headings)
    {
        cout << " " << column_name << " |";
    }
    cout << endl;

    // Display data
    for (size_t i = 0; i < dynArr.data.size(); i++)
    {
        cout << "|";
        for (int value : dynArr.data[i])
        {
            if (value == -1)
            {
                cout << " "
                     << "Deleted"
                     << " |"; // Display "Deleted" for deleted data
            }
            else
            {
                cout << " " << value << " |";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to save data to a text file
void saveDataToFile(const Dynamic_Array &dynArr, const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Failed to open the file for saving." << endl;
        return;
    }

    // Save topics
    for (size_t i = 0; i < dynArr.Headings.size(); i++)
    {
        file << dynArr.Headings[i];
        if (i < dynArr.Headings.size() - 1)
        {
            file << " ";
        }
    }
    file << endl;

    // Save data
    for (size_t i = 0; i < dynArr.data.size(); i++)
    {
        for (size_t j = 0; j < dynArr.data[i].size(); j++)
        {
            file << dynArr.data[i][j];
            if (j < dynArr.data[i].size() - 1)
            {
                file << " ";
            }
        }
        file << endl;
    }

    file.close();
    cout << "Data saved to " << filename << endl;
}

// Function to load data from a text file
void loadDataFromFile(Dynamic_Array &dynArr, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Failed to open the file for loading." << endl;
        return;
    }

    // Clear existing data
    dynArr.data.clear();
    dynArr.Headings.clear();

    // Load topics
    string topicLine;
    getline(file, topicLine);
    stringstream topicStream(topicLine);
    string column_name;
    while (topicStream >> column_name)
    {
        dynArr.Headings.push_back(column_name);
    }

    // Load data
    string dataLine;
    while (getline(file, dataLine))
    {
        stringstream dataStream(dataLine);
        vector<int> row;
        int value;
        while (dataStream >> value)
        {
            row.push_back(value);
        }
        dynArr.data.push_back(row);
    }

    file.close();
    cout << "Data loaded from " << filename << endl;
}

int main()
{
    Dynamic_Array dynArr;
    int choice;
    string filename = "D:/New folder/z.CSE207/data.txt";

    // Load data from the file at the start
    loadDataFromFile(dynArr, filename);

    do
    {
        cout << "\n=========================================" << endl;
        cout << "            Dynamic Table Menu" << endl;
        cout << "=========================================" << endl;
        cout << "1. Insert Heading" << endl;
        cout << "2. Insert Data" << endl;
        cout << "3. Delete Heading" << endl;
        cout << "4. Delete Data" << endl;
        cout << "5. Delete Row" << endl;
        cout << "6. Display Table" << endl;
        cout << "7. Display Headings" << endl;
        cout << "8. Enter Specific Data for All Rows" << endl;
        cout << "9. Save Data to File" << endl;
        cout << "10. Load Data from File" << endl;
        cout << "11. Quit" << endl;
        cout << "=========================================" << endl;
        cout << "Please, Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string column_name;
            cout << "Enter the column name: ";
            cin >> column_name;
            insertHeading(dynArr, column_name);
            break;
        }
        case 2:
        {
            int row, col, value;
            displayHeadings(dynArr);
            cout << "Please, Enter row index, column index, and value: ";
            cin >> row >> col >> value;
            insertData(dynArr, row, col, value);
            break;
        }
        case 3:
        {
            int col;
            cout << "Please, Enter the column index to delete: ";
            cin >> col;
            deleteHeading(dynArr, col);
            break;
        }
        case 4:
        {
            int row, col;
            cout << "Please, Enter row index and column index to delete data: ";
            cin >> row >> col;
            deleteData(dynArr, row, col);
            break;
        }
        case 5:
        {
            int row;
            cout << "Please, Enter the row index to delete: ";
            cin >> row;
            deleteRow(dynArr, row);
            break;
        }
        case 6:
            displayTable(dynArr);
            break;
        case 7:
            displayHeadings(dynArr);
            break;
        case 8:
            enterSpecificData(dynArr);
            break;
        case 9:
            saveDataToFile(dynArr, filename);
            break;
        case 10:
            loadDataFromFile(dynArr, filename);
            break;
        case 11:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 11);

    return 0;
}
