/*
    Gui Taglietti - fstream (ofstream and ifstream) CRUD
    Theme: Movies
*/

#include <bits/stdc++.h>
using namespace std;

class RegistroFilme {
private:
    int id;
    string titulo;
    string diretor;
    int anoLancamento;
    float nota;

public:
    RegistroFilme(int id, string titulo, string diretor, int anoLancamento, float nota) :
        id(id), titulo(titulo), diretor(diretor), anoLancamento(anoLancamento), nota(nota) {}

    RegistroFilme(){};

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getTitulo() const {
        return titulo;
    }

    void setTitulo(string titulo) {
        this->titulo = titulo;
    }

    string getDiretor() const {
        return diretor;
    }

    void setDiretor(string diretor) {
        this->diretor = diretor;
    }

    int getAnoLancamento() const {
        return anoLancamento;
    }

    void setAnoLancamento(int anoLancamento) {
        this->anoLancamento = anoLancamento;
    }

    float getNota() const {
        return nota;
    }

    void setNota(float nota) {
        this->nota = nota;
    }

    friend ostream& operator<<(ostream& os, const RegistroFilme& registro) {
        os << "Id: " << registro.id << endl;
        os << "Título: " << registro.titulo << endl;
        os << "Diretor: " << registro.diretor << endl;
        os << "Ano de lançamento: " << registro.anoLancamento << endl;
        os << "Nota: " << registro.nota << endl;
        return os;
    }
};

class ArquivoRegistroFilme{
private:
    string nomeArquivo;

public:
    ArquivoRegistroFilme(string nomeArquivo) : nomeArquivo(nomeArquivo) {}

    void adicionarRegistro(const RegistroFilme& registro) {
        ofstream arquivo(nomeArquivo, ios::binary | ios::app);
        if (arquivo.is_open()) {
            arquivo.write(reinterpret_cast<const char*>(&registro), sizeof(RegistroFilme));
            arquivo.close();
        } else {
            throw runtime_error("Erro ao abrir o arquivo.");
        }
    }

    void alterarRegistro(const RegistroFilme& registro) {
        fstream arquivo(nomeArquivo, ios::binary | ios::in | ios::out);
        if (arquivo.is_open()) {
            RegistroFilme registroAlterado;
            bool encontrado = false;
            while (arquivo.read(reinterpret_cast<char*>(&registroAlterado), sizeof(RegistroFilme))) {
                if (registroAlterado.getId() == registro.getId()) {
                    arquivo.seekp(-static_cast<int>(sizeof(RegistroFilme)), ios::cur);
                    arquivo.write(reinterpret_cast<const char*>(&registro), sizeof(RegistroFilme));
                    encontrado = true;
                    break;
                }
            }
            arquivo.close();
            if (!encontrado) {
                throw runtime_error("Registro não encontrado.");
            }
        } else {
            throw runtime_error("Erro ao abrir o arquivo.");
        }
    }

    void excluirRegistro(int id) {
        fstream arquivo(nomeArquivo, ios::binary | ios::in | ios::out);
        if (arquivo.is_open()) {
            RegistroFilme registro;
            bool encontrado = false;
            while (arquivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroFilme))) {
                if (registro.getId() == id) {
                    encontrado = true;
                    break;
                }
            }
            if (encontrado) {
                arquivo.seekp(-static_cast<int>(sizeof(RegistroFilme)), ios::cur);
                registro.setId(-1);
                arquivo.write(reinterpret_cast<const char*>(&registro), sizeof(RegistroFilme));
            }
            arquivo.close();
            if (!encontrado) {
                throw runtime_error("Registro não encontrado.");
            }
        } else {
            throw runtime_error("Erro ao abrir o arquivo.");
        }
    }

    vector<RegistroFilme> listarRegistros() {
        vector<RegistroFilme> registros;
        ifstream arquivo(nomeArquivo, ios::binary);
        if (arquivo.is_open()) {
            RegistroFilme registro;
            while (arquivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroFilme))) {
                if (registro.getId() != -1) {
                    registros.push_back(registro);
                }
            }
            arquivo.close();
        } else {
            throw runtime_error("Erro ao abrir o arquivo.");
        }
        return registros;
    }

    vector<RegistroFilme> consultarRegistros(function<bool(const RegistroFilme&)> criterio) {
        vector<RegistroFilme> registros;
        ifstream arquivo(nomeArquivo, ios::binary);
        if (arquivo.is_open()) {
            RegistroFilme registro;
            while (arquivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroFilme))) {
                if (registro.getId() != -1 && criterio(registro)) {
                    registros.push_back(registro);
                }
            }
            arquivo.close();
        } else {
            throw runtime_error("Erro ao abrir o arquivo.");
        }
        return registros;
    }
};

void imprimirRegistros(const vector<RegistroFilme>& registros) {
    for (const auto& registro : registros) {
        cout << registro << endl;
    }
}

int main() {
    ArquivoRegistroFilme arquivo("registrosED2.txt");

    // Adiciona alguns registros
    arquivo.adicionarRegistro(RegistroFilme(1, "O Poderoso Chefão", "Francis Ford Coppola", 1972, 9.2));
    arquivo.adicionarRegistro(RegistroFilme(2, "O Senhor dos Anéis: O Retorno do Rei", "Peter Jackson", 2003, 9.0));
    arquivo.adicionarRegistro(RegistroFilme(3, "O Pianista", "Roman Polanski", 2002, 8.5));

    // Lista todos os registros
    vector<RegistroFilme> registros = arquivo.listarRegistros();
    cout << "Todos os registros:" << endl;
    imprimirRegistros(registros);
    cout << endl;

    // Consulta registros de acordo com um critério de pesquisa
    registros = arquivo.consultarRegistros([](const RegistroFilme& registro) {
        return registro.getDiretor() == "Francis Ford Coppola";
    });
        
    // Imprime registros encontrados pela consulta
    cout << "Registros com o diretor Francis Ford Coppola:" << endl;
    imprimirRegistros(registros);
    cout << endl;

    // Altera um registro
    RegistroFilme novoRegistro(1, "O Poderoso Chefão - Parte II", "Francis Ford Coppola", 1974, 9.0);
    arquivo.alterarRegistro(novoRegistro);

    // Exclui um registro
    arquivo.excluirRegistro(3);

    // Lista todos os registros novamente
    registros = arquivo.listarRegistros();
    cout << "Todos os registros após alteração e exclusão:" << endl;
    imprimirRegistros(registros);

    return 0;
}
