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

bool verificar_indices(int linhas) {
    setlocale(LC_ALL, "pt-BR.UTF8");
    try {
        if (linhas != 0 && linhas > 0) {
            return true;
        } else {
            throw (linhas);
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
                    cout << "Matriz A:" << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz.somar_real(real);
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << real << " + Matriz A: " << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 3:
                if (verificar_real(real)) {
                    matriz.set_auto();
                    cout << "Matriz A:" << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz.subtrair_real(real);
                    cout << real << " - Matriz A: " << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 4:
                if (verificar_real(real)) {
                    matriz.set_auto();
                    cout << "Matriz A:" << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz.multiplicar_real(real);
                    cout << real << " * Matriz A: " << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 5:
                if (verificar_real(real)) {
                    matriz.set_auto();
                    cout << "Matriz A:" << endl;
                    matriz.mostra_matriz();
                    this_thread::sleep_for(chrono::seconds(2));
                    matriz.dividir_real(real);
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

int main()
{
    int tecla = 0;
    int linhas, colunas = 0;
    setlocale(LC_ALL, "pt-BR.UTF8");
    while (tecla != 3) {
        cout << "\n============ Interface ============";
        cout << "\n[1] : Definir índices";
        cout << "\n[2] : Operações com número reais";
        cout << "\n[3] : Encerrar";
        cout << "\n================================";
        cout << "\nEscolha: ";
        cin >> tecla;
        switch (tecla) {
            case 1:
                linhas = get_linhas();
                colunas = get_colunas();
                break;
            case 2:
                if (verificar_indices(linhas)) {
                    menu_operacoes_reais(linhas, colunas);
                }
                break;
            case 3:
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