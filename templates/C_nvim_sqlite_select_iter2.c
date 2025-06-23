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
    } else {
        sqliter->done = true;
        sqlite3_finalize(sqliter->stmt);
        return (sqlite_response_t){};
    }
}



