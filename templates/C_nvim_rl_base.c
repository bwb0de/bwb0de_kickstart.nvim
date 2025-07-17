#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include "geometria.h"
#include "gamming.h"

#define TITULO " "
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define FPS 60
#define BACKGROUND_COLOR BLACK


int main() {
    srand(time(NULL));

    game_status_t g = {
        .player_lives=3, 
        .player_helth_max=100, 
        .player_helth=100, 
        .background=BACKGROUND_COLOR
    };

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITULO);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        if (g.game_over) {break;}
        //Lógica do jogo


        BeginDrawing();
            ClearBackground(g.background);

        EndDrawing();

    }
    CloseWindow();

    cleanup:
        free();

    return 0;
}
