int obter_id(sqlite3 *db, const char *valor) {
    const char *sql = "SELECT «id» FROM «tabela» WHERE «coluna» = ?";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK ) {
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



