int adicionar_valor_em_tabela_isolada(sqlite3 *db, char *v1, char *v2, int v3, double v4) {
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
    return id;
   
    return id;
}


