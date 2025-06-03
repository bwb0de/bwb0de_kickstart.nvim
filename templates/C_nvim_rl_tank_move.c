void mover_protagonista(game_status_t *g, void *p) {
    //TIPO_T protagonista = (TIPO_T)p;

    if (IsKeyDown(KEY_RIGHT)) {
        protagonista->direcao += 2;
        if (protagonista->direcao > 359) {protagonista->direcao = 0;}
        zerar_steps(g);
    }
    else if (IsKeyDown(KEY_LEFT)) {
        protagonista->direcao -= 2;
        if (protagonista->direcao < 0) {protagonista->direcao = 359;}
        zerar_steps(g);
    }

    if (IsKeyDown(KEY_UP)) {
        protagonista->corpo.x += cosf(protagonista->direcao*DEG2RAD) * protagonista->v_mov;
        protagonista->corpo.y += sinf(protagonista->direcao*DEG2RAD) * protagonista->v_mov;
    }
    else if (IsKeyDown(KEY_DOWN)) {
        protagonista->corpo.x -= (cosf(protagonista->direcao*DEG2RAD) / 2) * protagonista->v_mov;
        protagonista->corpo.y -= (sinf(protagonista->direcao*DEG2RAD) / 2) * protagonista->v_mov;
    }

    protagonista->origem.x = protagonista->corpo.width / 2;
    protagonista->origem.y = protagonista->corpo.height / 2;
}
