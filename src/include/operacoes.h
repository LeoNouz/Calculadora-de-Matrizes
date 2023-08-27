#include <iostream>
using namespace std;

bool Matriz::verificar_indices(const Matriz& matriz) const {
    try {
        if (m_linhas == matriz.get_linhas() && m_colunas == matriz.get_colunas())
            return true;
        else
            throw (m_linhas, m_colunas);
    }
    catch (...) {
        cout << "\nErro de operação -> Os índices das matrizes devem ser [" << m_linhas << "]";
        cout << "[" << m_colunas << "]" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        return false;
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
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] *= matriz.get_matriz()[i][j];
        }
    }
}

void Matriz::dividir(const float numero) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] /= numero;
        }
    }
}

void Matriz::dividir(const Matriz& matriz) const {
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] /= matriz.get_matriz()[i][j];
        }
    }
}