#include <iostream>
#include <random>
using namespace std;

class Matriz {
    public:
        Matriz(const int linhas, const int colunas);
        ~Matriz();

        int get_linhas() const;
        int get_colunas() const;
        int** get_matriz() const;

        void set_manual() const;
        void set_auto() const;

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

int Matriz::get_linhas() const {
    return m_linhas;
}

int Matriz::get_colunas() const {
    return m_colunas;
}

int** Matriz::get_matriz() const {
    return m_matriz;
}

void Matriz::set_manual() const {
    cout << endl;
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> m_matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Matriz::set_auto() const {
    // Crie um mecanismo de geração de números aleatórios (RNG)
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister, um algoritmo popular de geração de números aleatórios

    // Crie uma distribuição de números aleatórios (por exemplo, de 1 a 100)
    std::uniform_int_distribution<> dist(1, 99);

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            int random_number = dist(gen);
            m_matriz[i][j] = random_number;
        }
    }
}