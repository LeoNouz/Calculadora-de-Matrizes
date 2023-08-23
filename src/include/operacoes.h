#include <iostream>
using namespace std;

bool Matriz::verificar_indice(const Matriz& matriz) const {
    if (m_linhas == matriz.get_linhas() && m_colunas == matriz.get_colunas())
        return true;
    else
        return false;
}

Matriz Matriz::somar_real(const float numero) const {
    Matriz nova_matriz(m_linhas, m_colunas);

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            nova_matriz.get_matriz()[i][j] = m_matriz[i][j] + numero;
        }
    }
    return nova_matriz;
}

Matriz Matriz::subtrair_real(const float numero) const {
    Matriz nova_matriz(m_linhas, m_colunas);

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            nova_matriz.get_matriz()[i][j] = m_matriz[i][j] - numero;
        }
    }
    return nova_matriz;
}

Matriz Matriz::multiplicar_real(const float numero) const {
    Matriz nova_matriz(m_linhas, m_colunas);

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            nova_matriz.get_matriz()[i][j] = m_matriz[i][j] * numero;
        }
    }
    return nova_matriz;
}

Matriz Matriz::dividir_real(const float numero) const {
    Matriz nova_matriz(m_linhas, m_colunas);

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            nova_matriz.get_matriz()[i][j] = m_matriz[i][j] / numero;
        }
    }
    return nova_matriz;
}