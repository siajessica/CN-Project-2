#include <iostream>
#include <sqlite3.h>
#include <string>
#include "database.h"
#include "login_interface.h"
#include "relationship.h"

using namespace std;

int main(){
    sqlite3 *db = createDB();
    int rc = sqlite3_open("chatroom.db", &db);

    sign_up("Antonio", "123456789");
    sign_up("Jensen", "qwertyuiop");
    sign_up("Lala", "!@#$%^&*()");
    string sql = "SELECT * FROM USERS;";
    rc = sqlite3_exec(db, sql.c_str(), print_select, 0, NULL);
    cout << endl;

    change_password("Lala", "a1b2c3");
    string sql = "SELECT * FROM USERS;";
    rc = sqlite3_exec(db, sql.c_str(), print_select, 0, NULL);
    cout << endl;

    add_friend("Antonio", "Jensen");
    sql = "SELECT * FROM FRIENDS;";
    rc = sqlite3_exec(db, sql.c_str(), print_select, 0, NULL);
    cout << endl;


    add_block("Antonio", "Jensen");
    add_block("Lala", "Jensen");
    add_block("Antonio", "Lulu");
    sql = "SELECT * FROM BLOCKED;";
    rc = sqlite3_exec(db, sql.c_str(), print_select, 0, NULL);
    cout << endl;

    add_friend("Jensen", "Antonio");
    add_friend("Antonio", "Lala");
    add_friend("Lala", "Antonio");
    add_friend("Jensen", "Lulu");
    sql = "SELECT * FROM FRIENDS;";
    rc = sqlite3_exec(db, sql.c_str(), print_select, 0, NULL);
    cout << endl;

    unblock("Lala", "Jensen");
    remove_friend("Lala", "Antonio");
    add_friend("Lala", "Jensen");
    sql = "SELECT * FROM FRIENDS;";
    rc = sqlite3_exec(db, sql.c_str(), print_select, 0, NULL);
    cout << endl;
    sql = "SELECT * FROM BLOCKED;";
    rc = sqlite3_exec(db, sql.c_str(), print_select, 0, NULL);
    cout << endl;
}