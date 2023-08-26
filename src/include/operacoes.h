#include <iostream>
using namespace std;

bool Matriz::verificar_indice(const Matriz& matriz) const {
    if (m_linhas == matriz.get_linhas() && m_colunas == matriz.get_colunas())
        return true;
    else
        return false;
}

void Matriz::somar_real(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] += numero;
        }
    }
}

void Matriz::subtrair_real(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] -= numero;
        }
    }
}

void Matriz::multiplicar_real(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] *= numero;
        }
    }
}

void Matriz::dividir_real(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] /= numero;
        }
    }
}