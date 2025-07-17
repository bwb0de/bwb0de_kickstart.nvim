typedef struct Wall{
    Rectangle rect;
} wall_t;


void create_wall_structure(wall_t *bricks, size_t bricks_num, uint8_t base_matrix[][], const size_t NUM_OF_LINES, const size_t NUM_OF_COLS){
    wall_t bricks[bricks_num];
    size_t wall_idx = 0;

    for (size_t i = 0; i < NUM_OF_LINES; i++) {
        for (size_t j = 0; j < NUM_OF_COLS; j++) {
            if (base_matriz[i][j] == 1) {
                bricks[wall_idx].rect.x = BOX_SIZE * j;
                bricks[wall_idx].rect.y = BOX_SIZE * i;
                bricks[wall_idx].rect.width = BOX_SIZE;
                bricks[wall_idx++].rect.height = BOX_SIZE;
            }
        }
    }
}

