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
    game_status_t g = {
        .vidas=3, 
        .vitalidade_maxima=100, 
        .vitalidade=100, 
        .cor_fundo=BACKGROUND_COLOR
    };

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITULO);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        if (fim_de_jogo(&g)) {break;}
        //Lógica do jogo


        BeginDrawing();
            ClearBackground(g.cor_fundo);

        EndDrawing();

    }
    CloseWindow();
    return 0;
}
