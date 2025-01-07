#include <iostream>

struct REGISTRO {
    int chave; 
};

struct ELEMENTO {
    REGISTRO reg;
    ELEMENTO *prox;

    ELEMENTO() : prox(NULL) {} 
};

typedef ELEMENTO* PONT;

struct FILA {
    PONT inicio;
    PONT fim;

    FILA() {
        inicio = new ELEMENTO();
        fim = inicio;
    }

    ~FILA() {
        while (inicio != NULL) {
            PONT temp = inicio;
            inicio = inicio->prox;
            delete temp;
        }
    }
};

bool inserirNaFila(FILA *f, REGISTRO reg) {
    PONT novo = new ELEMENTO(); 
    if (!novo) return false;   

    novo->reg = reg;  
    f->fim->prox = novo;
    f->fim = novo;
    return true;
}

bool excluirDaFila(FILA *f, REGISTRO *reg) {
    if (f->inicio->prox == NULL) return false;

    PONT apagar = f->inicio->prox;
    *reg = apagar->reg;
    f->inicio->prox = apagar->prox;

    if (f->inicio->prox == NULL) {
        f->fim = f->inicio;
    }

    delete apagar;
    return true;
}

void exibirFila(FILA *f) {
    PONT atual = f->inicio->prox;
    std::cout << "Fila: ";
    while (atual != NULL) {
        std::cout << atual->reg.chave << " ";
        atual = atual->prox;
    }
    std::cout << "\n";
}

int main() {
    FILA fila;

    REGISTRO r1 = {10};
    REGISTRO r2 = {20};
    REGISTRO r3 = {30};

    inserirNaFila(&fila, r1);
    inserirNaFila(&fila, r2);
    inserirNaFila(&fila, r3);

    std::cout << "Fila após inserções: ";
    exibirFila(&fila);

    REGISTRO removido;
    excluirDaFila(&fila, &removido);
    std::cout << "Elemento removido: " << removido.chave << "\n";
    std::cout << "Fila após exclusão: ";
    exibirFila(&fila);

    excluirDaFila(&fila, &removido);
    std::cout << "Elemento removido: " << removido.chave << "\n";
    std::cout << "Fila após exclusão: ";
    exibirFila(&fila);

    excluirDaFila(&fila, &removido);
    std::cout << "Elemento removido: " << removido.chave << "\n";
    std::cout << "Fila após exclusão: ";
    exibirFila(&fila);

    return 0;
}
