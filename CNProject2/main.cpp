#include <iostream>
#include <sqlite3.h>
#include <string>
#include "database.h"
#include "login_interface.h"
#include "relationship.h"
#include "message.h"

using namespace std;

int main(){
    sqlite3 *db = createDB();
    int rc = sqlite3_open("chatroom.db", &db);

    cout << "Welcome to the client." << endl;
    cout << "1. SIGN IN" << endl;
    cout << "2. SIGN UP" << endl;
    
    int command;
    cin >> command;

    string username, password, target_user;
    if(command == 1){
        cout << "Please enter your username: ";
        cin >> username;
        cout << "Please enter your password: ";
        cin >> password;
        login(username, password);
    }
    else if(command == 2){
        cout << "Please enter your username: ";
        cin >> username;
        cout << "Please enter your password: ";
        cin >> password;
        sign_up(username, password);
    }

    while(1){
        cout << "3. LIST FRIEND" << endl;
        cout << "4. ADD FRIEND" << endl;
        cout << "5. REMOVE FRIEND" << endl;
        cout << "6. CHAT FRIEND" << endl;
        
        if(command == 3){
            list_friends(username);
        }
        else if(command == 4){
            cout << "Please enter friend's username: ";
            cin >> target_user;
            add_friend(username, target_user);
        }
        else if(command == 5){
            cout << "Please enter friend's username: ";
            cin >> target_user;
            remove_friend(username, target_user);
        }
        else if(command == 6){
            cout << "Please enter friend's username: ";
            cin >> target_user;
            message_history(3);
            while(target_user != "exit"){
                cin >> target_user;
                record_message(username, 3, target_user);
                cout << "SENDER: " << username << endl;
                cout << "BODY: " << target_user << endl;
            }
        }
    }

    return 0;
}
