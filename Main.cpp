#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

// TASK CLASS

class Task{
    public:
        void addTask(){              // ADDING TASK 
            ofstream file;

            file.open("task.csv", ios:: app);

            if (!file.is_open()) {
                cerr << "Failed to open file!" << endl;
            }

            string task, due, status;

            cout << "Enter Task: ";
            getline(cin, task);

            cout << "Enter Due Date: ";
            getline(cin, due);

            cout << "Pending? (y / n): ";
            getline(cin, status);

            cout << endl;

            file << task << "," << due << "," << ((status == "y") ? "Pending" : "Completed") << "\n";
            cout << "Task Added Sucessfully\n\n";
            
            file.close();
        }

        void showPendingTask(){           // SHOWING PENDING TASKS
            ifstream file("task.csv");
            string line;

            cout << "---------- Showing Pending Tasks ----------\n\n";

            while(getline(file, line)){
                stringstream ss(line);
                string task, due, status;

                getline(ss, task, ',');
                getline(ss, due, ',');
                getline(ss, status, ',');

                if(status == "Pending"){
                    cout << "Task: " << task << endl;
                    cout << "Due Date: " << due << "\n\n";
                }
            }

            file.close();
        }
        void showingCompletedTask(){       // SHOWING COMPLETED TASKS
            ifstream file("task.csv");
            string line;
            cout << "---------- Showing Completed Tasks ----------\n\n";
            
            while(getline(file, line)){
                stringstream ss(line);
                string task, due, status;

                getline(ss, task, ',');
                getline(ss, due, ',');
                getline(ss, status, ',');

                if(status == "Completed"){
                    cout << "Task: " << task << endl;
                    cout << "Due Date: " << due << "\n\n";
                }
            }

            file.close();
        }

        void markAsComplete(){               // MARKING TASK AS COMPLETE

            ifstream file("task.csv");
            if (!file.is_open()) {
                cerr << "Could not open file!\n";
                return;
            }

            string line, mark;
            string task, due, status;
            bool found = false;

            vector<vector<string>> tasks;

            cout << "Enter Task: ";
            getline(cin, mark);
            cout << endl;

            while(getline(file, line)){
                stringstream ss(line);

                getline(ss, task, ',');
                getline(ss, due, ',');
                getline(ss, status, ',');

                if(mark == task){
                    found = true;
                    if (status == "Pending") {
                        status = "Completed";
                        cout << "Task marked as completed.\n\n";
                    } else {
                        cout << "Task was already completed.\n\n";
                    }
                }

                vector<string>  row = {task, due, status};
                tasks.push_back(row);
            }

            file.close();

            if(!found){
                cout << "Task Not Found\n\n";
                return;
            }

            ofstream outFile("task.csv");

            for (const auto& t : tasks) {
                outFile << t[0] << "," << t[1] << "," << t[2] << "\n";
            }
            outFile.close();
        }
};

void mainMenu(){
    cout << "-------------- TO - DO LIST --------------\n";
    cout << "1. Add Tasks\n";
    cout << "2. Show Pending Tasks\n";
    cout << "3. Show Completed Tasks\n";
    cout << "4. Mark Task As Complete\n\n";
    cout << "Choose option: ";

}

int main(){

    while(true){
        int choice;
        mainMenu();
        cin >> choice;
        cin.ignore();

        Task t;

        if(choice == 1){
            t.addTask();
        }
        else if(choice == 2){
            t.showPendingTask();
        }
        else if(choice == 3){
            t.showingCompletedTask();
        }
        else if(choice == 4){
            t.markAsComplete();
        }
        else if(choice == 5){
            cout << "Exiting.....";
            return 0;
        }
        else{
            cout << "Invalid Choice\n";
        }
    }
}
