#include <iostream>
using namespace std;

class Matriz {
    public:
        Matriz(const int linhas, const int colunas);
        ~Matriz();

        void mostra_matriz() const;
    private:
        int m_linhas, m_colunas;
        int** m_matriz;
};

Matriz::Matriz(const int linhas, const int colunas)
    : m_linhas(linhas), m_colunas(colunas), m_matriz(new int*[m_linhas])
{
    for (int i = 0; i < m_linhas; i++) {
        m_matriz[i] = new int[colunas];
        for (int j = 0; j < m_colunas; j++) {
            m_matriz[i][j] = 0;
        }
    }
}

Matriz::~Matriz() {
    for (int i = 0; i < m_linhas; i++)
        delete[] m_matriz[i];
    delete[] m_matriz;
}

void Matriz::mostra_matriz() const {
    cout << endl;
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            cout << m_matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}