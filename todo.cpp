//TODO CLI Application challenge

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// Prints the CLI usage.
void help()
{
    cout << "Usage :-\n$ ./todo add \"todo item\"  # Add a new todo\n$ ./todo ls               # Show remaining todos\n$ ./todo del NUMBER       # Delete a todo\n$ ./todo done NUMBER      # Complete a todo\n$ ./todo help             # Show usage\n$ ./todo report           # Statistics";
}

//Companion function for printing in reverse order by recursion
void printLines(ifstream &fin, int num)
{
    string line;
    if (getline(fin, line))
    {
        printLines(fin, num + 1);
        cout << "[" << num << "] " << line << endl;
    }
}

//See all the todos that are not yet complete
void list()
{
    ifstream fin("todo.txt");
    if (fin)
    {
        //Check if there are no todos
        string temp;
        if (!getline(fin, temp))
        {
            cout << "There are no pending todos!";
        }
        else
        {
            //Prints todo in latest-first fashion
            fin.clear();
            fin.seekg(0, ios::beg);
            int num = 1;
            printLines(fin, num);
        }
        fin.close();
    }
    else
    { //If 'todo.txt' file doesn't exists
        cout << "There are no pending todos!";
    }
}

// Adds todo to 'todo.txt'
void add(string NewTodo)
{
    ofstream fout("todo.txt", ios::app);
    if (fout)
    {
        if (fout << NewTodo << "\n")
            cout << "Added todo: \"" << NewTodo << "\"";
    }
    fout.close();
}

// Deletes todo based upon number.
void del(int todoNum)
{
    ofstream fout("temp.txt");
    ifstream fin("todo.txt");
    if (fin && fout)
    {
        int i = 1;
        string line;
        bool flag = false;

        while (getline(fin, line))
        {
            if (i == todoNum)
            {
                flag = true;
            }
            else
            {
                fout << line << endl;
            }
            i++;
        }

        fin.close();
        fout.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");

        if (flag)
            cout << "Deleted todo #" << todoNum;
        else
        {
            cout << "Error: todo #" << todoNum << " does not exist. Nothing deleted.";
        }
    }
}

// Marking todos as done (by adding todo from 'todo.txt' to 'done.txt' and deleting the todo)
void markDone(int doneNum)
{
    ofstream fout("done.txt", ios::app);
    ifstream fin("todo.txt");
    if (fin && fout)
    {
        int i = 1;
        string line;
        bool flag = false;

        while (getline(fin, line))
        {
            if (i == doneNum)
            {
                //Getting date
                time_t now = time(0);
                tm *gtm = gmtime(&now);

                fout << "x " << 1900 + gtm->tm_year << "-" << 1 + gtm->tm_mon << "-" << gtm->tm_mday << " " << line << endl;
                flag = true;
            }
            i++;
        }

        fin.close();
        fout.close();

        if (flag)
            cout << "Marked todo #" << doneNum << " as done.";
        else
        {
            cout << "Error: todo #" << doneNum << " does not exist.";
        }
        //Delete the todo from the 'todo.txt' file
        del(doneNum);
    }
}

// Generating report
void GenReport()
{
    ifstream finTodo("todo.txt");
    ifstream finDone("done.txt");
    int pend = 0, comp = 0;
    string tempLine;

    if (finTodo)
    {
        while (getline(finTodo, tempLine))
        {
            pend++;
        }
    }
    if (finDone)
    {
        while (getline(finDone, tempLine))
        {
            comp++;
        }
    }
    //Getting date
    time_t now = time(0);
    tm *gtm = gmtime(&now);

    cout << 1900 + gtm->tm_year << "-" << 1 + gtm->tm_mon << "-" << gtm->tm_mday << " Pending : " << pend << " Completed : " << comp;
}

int main(int argc, char *argv[])
{
    //Get the arguments into vector of string
    vector<string> strvec(argv + 1, argv + argc);

    if (argc == 1 || strvec[0] == "help")
    {
        help();
    }
    else if (strvec[0] == "ls")
    {
        list();
    }

    else if (strvec[0] == "add")
    {
        if (argc == 2)
            cout << "Error: Missing todo string. Nothing added!";
        else
            add(strvec[1]);
    }
    else if (strvec[0] == "del")
    {
        if (argc == 2)
            cout << "Error: Missing NUMBER for deleting todo.";
        else
            del(stoi(strvec[1]));
    }
    else if (strvec[0] == "done")
    {
        if (argc == 2)
            cout << "Error: Missing NUMBER for marking todo as done.";
        else
            markDone(stoi(strvec[1]));
    }
    else if (strvec[0] == "report")
    {
        GenReport();
    }

    return 0;
}
