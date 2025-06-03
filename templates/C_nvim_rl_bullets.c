#define TOTAL_ELEMENTOS_PILHA 30


typedef struct PilhaIndices {
    uint8_t array_idx[TOTAL_ELEMENTOS_PILHA];
    uint8_t numero_elementos;
} pilha_in_stack_t;



void inserir_na_pilha(pilha_in_stack_t *p, uint8_t idx) {
    if (p->numero_elementos < TOTAL_ELEMENTOS_PILHA) {
        uint8_t i = p->numero_elementos;
        p->array_idx[i] = idx;
        p->numero_elementos++;
    }
}


int8_t retirar_da_pilha(pilha_in_stack_t *p) {
    if (p->numero_elementos == 0) {
        return -1;
    }
    int8_t elemento = p->array_idx[p->numero_elementos];
    p->numero_elementos--;
    return elemento;

}


typedef struct Projetil {
    Vector2 pos;
    Vector2 v_mov;
    uint8_t raio;
    uint8_t dano;
    Color cor;
} projetil_t;


uint8_t mover_projeteis(uint8_t numero_projeteis_ativos, projetil_t *projeteis_ativos) {
    pilha_in_stack_t p = {};

    for (uint8_t i = 0; i < numero_projeteis_ativos; i++) {
        projeteis_ativos[i].pos.x += projeteis_ativos[i].v_mov.x;
        projeteis_ativos[i].pos.y += projeteis_ativos[i].v_mov.y;
        if (projeteis_ativos[i].pos.x > SCREEN_WIDTH || projeteis_ativos[i].pos.x < 0 || projeteis_ativos[i].pos.y > SCREEN_HEIGHT || projeteis_ativos[i].pos.y < 0) {
            inserir_na_pilha(&p, i);
        }
    }

    int8_t idx_retirado = 0;
    uint8_t decrementar_balas_ativas = 0;

    if (p.numero_elementos) {
        idx_retirado = retirar_da_pilha(&p);
        decrementar_balas_ativas++;
        if (idx_retirado < numero_projeteis_ativos) {
            for (uint8_t i = idx_retirado; i < numero_projeteis_ativos; i++) {
                projeteis_ativos[i] = projeteis_ativos[i+1];
            }
        }
    }

    numero_projeteis_ativos -= decrementar_balas_ativas;

    return numero_projeteis_ativos;
}


