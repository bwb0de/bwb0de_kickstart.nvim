typedef struct SQLiteIter {
    sqlite3_stmt    *stmt;
    bool             done;
} sqlite_iter_t;


bool sqlite_iter_init(sqlite3 *db, const char *sql, sqlite_iter_t *sqliter) {
    //const char *sql = "SELECT «col1», «col2», «col3» FROM «tabela» WHERE «coluna» = ?;";
    sqliter->done = false;
    if (sqlite3_prepare_v2(db, sql, -1, &sqliter->stmt, NULL) != SQLITE_OK) {
        fprintf(stderr,"Erro ao preparar: %s\n", sqlite3_errmsg(db));
        return false;
    }
    return true;
}


void sqlite_iter_finalize(sqlite_iter_t *sqliter) {
    sqlite3_finalize(sqliter->stmt);
}



