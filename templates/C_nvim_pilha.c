#define TAMANHO_PILHA 30

typedef struct PilhaIndices {
    int array_idx[TAMANHO_PILHA];
    int numero_elementos;
} pilha_in_stack_t;


void inserir_na_pilha(pilha_in_stack_t *p, uint8_t idx) {
    if (p->numero_elementos < TAMANHO_PILHA) {
        int i = p->numero_elementos;
        p->array_idx[i] = idx;
        p->numero_elementos++;
    }
}

int retirar_da_pilha(pilha_in_stack_t *p) {
    if (p->numero_elementos == 0) {
        return -1;
    }
    int elemento = p->array_idx[p->numero_elementos];
    p->numero_elementos--;
    return elemento;
}
