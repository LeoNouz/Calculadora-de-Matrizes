#include <iostream>
#include "include/matriz.h"
#include "include/operacoes.h"
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "pt-BR.UTF8");
    Matriz matriz1(8, 8);
    Matriz matriz2(8, 8);

    matriz1.set_auto();
    matriz1.mostra_matriz();

    bool verificacao = matriz1.verificar_indice(matriz2);

    if (verificacao == false) {
        cout << "Erro de operação, Matrize de índices diferentes.";
    } else {
        matriz2 = matriz1.multiplicar_real(2);
        matriz2.mostra_matriz();
    }
        
}