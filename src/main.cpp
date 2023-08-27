#include <iostream>
#include <thread>
#include <chrono>
#include "include/matriz.h"
#include "include/operacoes.h"
using namespace std;

int main();

int get_linhas() {
    int linhas = 0;
    cout << "\nLinhas: ";
    cin >> linhas;
    return linhas;
}

int get_colunas() {
    int colunas = 0;
    cout << "Colunas: ";
    cin >> colunas;
    return colunas;
}

bool verificar_indices(int linhas1, int colunas1, int linhas2, int colunas2) {
    setlocale(LC_ALL, "pt-BR.UTF8");
    try {
        if ((linhas1 != 0 && linhas1 > 0) && (colunas1 != 0 && colunas1 > 0) && (linhas2 != 0 && linhas2 > 0) && (colunas2 != 0 && colunas2 > 0)) {
            return true;
        } else {
            throw (linhas1);
        }
    }
    catch (...) {
        cout << "\nErro de operação -> Índices não foram definidos!" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        return false;
    }
}

float get_real() {
    float real = 0;
    cout << "\nNº real: ";
    cin >> real;
    return real;
}

bool verificar_real(float real) {
    setlocale(LC_ALL, "pt-BR.UTF8");
    try {
        if (real != 0 && real > 0) {
            return true;
        } else {
            throw (real);
        }
    }
    catch (...) {
        cout << "\nErro de operação -> Nº real não foi definido!" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        return false;
    }
}

void menu_operacoes_reais(int linhas, int colunas) {
    int tecla = 0;
    float real = 0;
    Matriz matriz(linhas, colunas);
    setlocale(LC_ALL, "pt-BR.UTF8");
    while (tecla != 6) {
        cout << "\n====== Operações com reais ======";
        cout << "\n[1] : Definir número real";
        cout << "\n[2] : Somar";
        cout << "\n[3] : Subtrair";
        cout << "\n[4] : Multiplicar";
        cout << "\n[5] : Dividir";
        cout << "\n[6] : Voltar";
        cout << "\n================================";
        cout << "\nEscolha: ";
        cin >> tecla;
        switch (tecla) {
            case 1:
                real = get_real();
                break;
            case 2:
                if (verificar_real(real)) {
                    matriz.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz.somar(real);
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << real << " + Matriz A: " << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 3:
                if (verificar_real(real)) {
                    matriz.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz.subtrair(real);
                    cout << real << " - Matriz A: " << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 4:
                if (verificar_real(real)) {
                    matriz.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz.multiplicar(real);
                    cout << real << " * Matriz A: " << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 5:
                if (verificar_real(real)) {
                    matriz.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz.dividir(real);
                    cout << real << " / Matriz A: " << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 6:
                main();
                break;
            default:
                cout << "\nErro de operação -> Opção inválida" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                break;
        }
    }
}

void menu_operacoes_matrizes(int linhas1, int colunas1, int linhas2, int colunas2) {
    int tecla = 0;
    Matriz matriz1(linhas1, colunas1);
    Matriz matriz2(linhas2, colunas2);
    setlocale(LC_ALL, "pt-BR.UTF8");
    while (tecla != 5) {
        cout << "\n====== Operações entre matrizes ======";
        cout << "\n[1] : Somar";
        cout << "\n[2] : Subtrair";
        cout << "\n[3] : Multiplicar";
        cout << "\n[4] : Dividir";
        cout << "\n[5] : Voltar";
        cout << "\n======================================";
        cout << "\nEscolha: ";
        cin >> tecla;
        switch (tecla) {
            case 1:
                if (matriz1.verificar_indices(matriz2) == 1) {
                    matriz1.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz2.set_auto();
                    cout << "Matriz B:" << endl;
                    matriz2.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz1.somar(matriz2);
                    cout << "Matriz A + Matriz B: " << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 2:
                if (matriz1.verificar_indices(matriz2) == 1) {
                    matriz1.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz2.set_auto();
                    cout << "Matriz B:" << endl;
                    matriz2.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz1.subtrair(matriz2);
                    cout << "Matriz A - Matriz B: " << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 3:
                if (matriz1.verificar_indices(matriz2, 1) == 1) {
                    matriz1.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz2.set_auto();
                    cout << "Matriz B:" << endl;
                    matriz2.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz1.multiplicar(matriz2);
                    cout << "Matriz A * Matriz B: " << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                } else if (matriz1.verificar_indices(matriz2, 1) == 2) {
                    matriz1.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz2.set_auto();
                    cout << "Matriz B:" << endl;
                    matriz2.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    Matriz matriz3 = matriz1.multiplicar(matriz2, 1);
                    cout << "Matriz A * Matriz B: " << endl;
                    matriz3.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 4:
                if (matriz1.verificar_indices(matriz2, 1) == 1) {
                    matriz1.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz2.set_auto();
                    cout << "Matriz B:" << endl;
                    matriz2.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz1.multiplicar(matriz2);
                    cout << "Matriz A * Matriz B: " << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                } else if (matriz1.verificar_indices(matriz2, 1) == 2) {
                    matriz1.set_auto();
                    cout << "\nMatriz A:" << endl;
                    matriz1.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz2.set_auto();
                    cout << "Matriz B:" << endl;
                    matriz2.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    Matriz matriz3 = matriz1.dividir(matriz2, 1);
                    cout << "Matriz A * Matriz B: " << endl;
                    matriz3.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 5:
                main();
                break;
            default:
                cout << "\nErro de operação -> Opção inválida" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                break;
        }
    }
}

int main()
{
    int tecla = 0;
    int aux = 0;
    int linhas1, colunas1, linhas2, colunas2 = 0;
    setlocale(LC_ALL, "pt-BR.UTF8");
    while (tecla != 5) {
        cout << "\n============ Interface ============";
        cout << "\n[1] : Definir índices iguais";
        cout << "\n[2] : Definir índices diferentes";
        cout << "\n[3] : Operações com número reais";
        cout << "\n[4] : Operações entre matrizes";
        cout << "\n[5] : Encerrar";
        cout << "\n================================";
        cout << "\nEscolha: ";
        cin >> tecla;
        switch (tecla) {
            case 1:
                linhas1 = get_linhas();
                colunas1 = get_colunas();
                linhas2, colunas2 = 1;
                aux = 1;
                break;
            case 2:
                linhas1 = get_linhas();
                colunas1 = get_colunas();
                linhas2 = get_linhas();
                colunas2 = get_colunas();
                aux = 2;
                break;
            case 3:
                if (verificar_indices(linhas1, colunas2, linhas2, colunas2)) {
                    menu_operacoes_reais(linhas1, colunas1);
                }
                break;
            case 4:
                if (verificar_indices(linhas1, colunas2, linhas2, colunas2) && aux == 1) {
                    menu_operacoes_matrizes(linhas1, colunas1, linhas1, colunas1);
                } else if (verificar_indices(linhas1, colunas2, linhas2, colunas2) && aux == 2) {
                    menu_operacoes_matrizes(linhas1, colunas1, linhas2, colunas2);
                }
                break;
            case 5:
                exit(0); 
                break;
            default:
                cout << "\nErro de operação -> Opção inválida" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                break;
        }
    }
    return 0;
}