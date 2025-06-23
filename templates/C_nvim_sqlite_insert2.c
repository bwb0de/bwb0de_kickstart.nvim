int adicionar_valor_em_tabelas_relacionadas(sqlite3 *db, const char *v1, const char *v2, int v3, double v4, int v5, int v6) {
    //int id = obter_id(db, nome); //condicional unique entry...
    //if (id != -1) {return id;}
 
    char *errmsg = NULL;
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO «tabela» («coluna1», «coluna2»,...) VALUES (?, ?, ?, ?,...);";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) return -1;

    //time_t agora = time(NULL); sqlite3_bind_int64(stmt, idx, agora);
    sqlite3_bind_text(stmt, 1, v1, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, v2, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, v3);
    sqlite3_bind_double(stmt, 4, v4);
    
    if (sqlite3_step(stmt) != SQLITE_DONE) return -1;
    sqlite3_finalize(stmt);

    id = sqlite3_last_insert_rowid(db);

    //Comandos de adição nas tabelas relacionadas usando o id
    if (email)  { add_email(db, id, v5); } 
    if (numero) { add_phone(db, id, v6); }

    return id;
}




