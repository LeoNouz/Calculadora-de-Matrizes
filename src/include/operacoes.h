#include <iostream>
using namespace std;

int Matriz::verificar_indices(const Matriz& matriz, int aux = 0) const {
    try {
        if (m_linhas == matriz.get_linhas() && m_colunas == matriz.get_colunas())
            return 1;
        else if (m_colunas == matriz.get_linhas() && aux == 1)
            return 2;
        else
            throw (m_linhas, m_colunas);
    }
    catch (...) {
        cout << "\nErro de operação -> Os índices das matrizes devem ser [" << m_linhas << "]";
        cout << "[" << m_colunas << "]" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        return 0;
    }
}

void Matriz::somar(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] += numero;
        }
    }
}

void Matriz::somar(const Matriz& matriz) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] += matriz.get_matriz()[i][j];
        }
    }
}

void Matriz::subtrair(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] -= numero;
        }
    }
}

void Matriz::subtrair(const Matriz& matriz) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] -= matriz.get_matriz()[i][j];
        }
    }
}

void Matriz::multiplicar(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] *= numero;
        }
    }
}

void Matriz::multiplicar(const Matriz& matriz) const {
    for (int i = 0; i < m_linhas; ++i) {
        for (int j = 0; j < m_colunas; ++j) {
            m_matriz[i][j] *= matriz.get_matriz()[j][i];
        }
    }
}

Matriz Matriz::multiplicar(const Matriz& matriz, int aux) const {
    Matriz nova_matriz(m_linhas, matriz.get_colunas());
    for (int i = 0; i < m_linhas; ++i) {
        for (int j = 0; j < m_colunas; ++j) {
            nova_matriz.get_matriz()[i][j] = m_matriz[i][j] * matriz.get_matriz()[j][i];
        }
    }
    return nova_matriz;
}

void Matriz::dividir(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] /= numero;
        }
    }
}

void Matriz::dividir(const Matriz& matriz) const {
    for (int i = 0; i < m_linhas; ++i) {
        for (int j = 0; j < m_colunas; ++j) {
            m_matriz[i][j] /= matriz.get_matriz()[j][i];
        }
    }
}

Matriz Matriz::dividir(const Matriz& matriz, int aux) const {
    Matriz nova_matriz(m_linhas, matriz.get_colunas());
    for (int i = 0; i < m_linhas; ++i) {
        for (int j = 0; j < m_colunas; ++j) {
            nova_matriz.get_matriz()[i][j] = m_matriz[i][j] / matriz.get_matriz()[j][i];
        }
    }
    return nova_matriz;
}