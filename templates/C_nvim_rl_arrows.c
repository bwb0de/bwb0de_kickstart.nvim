void mover_protagonista(game_status_t *g, void *p) {
    #define PROTAGONISTA_SPEED 2

    if (IsKeyDown(KEY_RIGHT)) {
        protagonista->rect.x += PROTAGONISTA_SPEED;
    }
    else if (IsKeyDown(KEY_LEFT)) {
        protagonista->rect.x -= PROTAGONISTA_SPEED;
    }

    if (IsKeyDown(KEY_UP)) {
        protagonista->rect.y -= PROTAGONISTA_SPEED;
    }
    else if (IsKeyDown(KEY_DOWN)) {
        protagonista->rect.y += PROTAGONISTA_SPEED;
    }

    protagonista->origin.x = protagonista->rect.x + (protagonista->rect.width / 2);
    protagonista->origin.y = protagonista->rect.y + (protagonista->rect.height / 2);
}
