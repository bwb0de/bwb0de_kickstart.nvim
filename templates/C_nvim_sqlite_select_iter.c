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


//Uma struct por tipo de consulta...
typedef struct SQLiteResponseVALOR {
    int         v1;
    double      v2;
    char       *v3;
} sqlite_response_t;


sqlite_response_t retornar_proximo_registro_VALOR(sqlite_iter_t *sqliter) {
    if (sqliter->done) {return (sqlite_response_t){};}

    if (sqlite3_step(sqliter->stmt) == SQLITE_ROW) {
        sqlite_response_t resposta = {};

        resposta.v1 = sqlite3_column_int(sqliter->stmt, 0);
        resposta.v2 = sqlite3_column_double(sqliter->stmt, 1);
        v3 = sqlite3_column_text(sqliter->stmt, 2); srtncpy(resposta.v3, v3, sizeof(resposta.v3) - 1);

        return resposta;
    
    } 
    else {
        sqliter->done = true;
        sqlite3_finalize(sqliter->stmt);
        return (sqlite_response_t){};
    }
}



