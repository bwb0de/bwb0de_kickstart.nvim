void mover_protagonista(game_status_t *g, void *p) {
    //TIPO_T protagonista = (TIPO_T)p;
    #define PROTAGONISTA_SPEED 2

    if (IsKeyDown(KEY_RIGHT)) {
        protagonista->pos.x += PROTAGONISTA_SPEED;
    }
    else if (IsKeyDown(KEY_LEFT)) {
        protagonista->pos.x -= PROTAGONISTA_SPEED;
    }

    if (IsKeyDown(KEY_UP)) {
        protagonista->pos.y += PROTAGONISTA_SPEED;
    }
    else if (IsKeyDown(KEY_DOWN)) {
        protagonista->pos.y -= PROTAGONISTA_SPEED;
    }

    protagonista->origem.x = protagonista->corpo.width / 2;
    protagonista->origem.y = protagonista->corpo.height / 2;
}
