#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sqlite3.h>
#include <string.h>
#include <stdbool.h>


int create_db(sqlite3 *db) {
    char *errmsg = NULL;

    const char *queries[] = {
        "CREATE TABLE IF NOT EXISTS tab1 ("
            "col1 INTEGER PRIMARY KEY AUTOINCREMENT, "
            "col2 TEXT NOT NULL, "
            "col3 REAL NOT NULL, "
            "col4 INTEGER NOT NULL, "
            "col5 TEXT, "
            "col6 REAL, "
            "col7 INTEGER"
        ");",

        "CREATE TABLE IF NOT EXISTS tab2 ("
            "col1 INTEGER PRIMARY KEY AUTOINCREMENT, "
            "col2 INTEGER REFERENCES tab1(col1), "
            "col3 TEXT NOT NULL, "
            "col4 REAL NOT NULL, "
            "col5 INTEGER NOT NULL, "
            "col6 TEXT, "
            "col7 REAL, "
            "col8 INTEGER"
        ");"
    };

    int numQueries = sizeof(queries) / sizeof(queries[0]);
    int rc;
    for (int i = 0; i < numQueries; i++) {
        rc = sqlite3_exec(db, queries[i], 0, 0, &errmsg);
        if (rc != SQLITE_OK) {
            sqlite3_free(errmsg);
        }
    }
    return 0;
}

