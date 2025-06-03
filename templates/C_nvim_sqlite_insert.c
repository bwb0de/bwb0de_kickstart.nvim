int obter_id(sqlite3 *db, const char *valor) {
    const char *sql_select = "SELECT id FROM «tabela» WHERE «coluna» = ?";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, NULL) != SQLITE_OK ) {
        printf("Erro ao preparar a consulta em jogadores: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    sqlite3_bind_text(stmt, 1, valor, -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        return id;
    }
    sqlite3_finalize(stmt);
    return -1;
}


int adicionar_valor_em_tabela_isolada(sqlite3 *db, int valor1, const char *valor2) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO emails («coluna1», «coluna2») VALUES (?, ?);";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) return -1;

    sqlite3_bind_int(stmt, 1, jogador_id);
    sqlite3_bind_text(stmt, 2, email, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) return -1;
    sqlite3_finalize(stmt);
    
    int id = sqlite3_last_insert_rowid(db);
    return id;
}



int adicionar_valor_em_tabelas_relacionadas(sqlite3 *db, const char *valor1, const char *valor2, int valor3, int valor4) {
    int id = obter_id(db, nome); //condicional unique entry...
    if (id != -1) {return id;}
 
    char *errmsg = NULL;
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO «tabela» («coluna») VALUES (?);";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) return -1;

    sqlite3_bind_text(stmt, 1, valor1, -1, SQLITE_STATIC);
    
    if (sqlite3_step(stmt) != SQLITE_DONE) return 0;
    sqlite3_finalize(stmt);

    id = sqlite3_last_insert_rowid(db);

    if (email)  { add_email(db, id, valor2); }
    if (numero) { add_phone(db, id, valor3, valor4); }

    return id;
}




