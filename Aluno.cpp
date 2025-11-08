#include "Aluno.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

Aluno::Aluno() : matricula(0), coeficiente(0.0f) {
    memset(nome, 0, sizeof(nome));
    memset(curso, 0, sizeof(curso));
}

Aluno::Aluno(int mat, const string& nom, const string& cur, float coef) 
    : matricula(mat), coeficiente(coef) {
    memset(nome, 0, sizeof(nome));
    memset(curso, 0, sizeof(curso));
    strncpy(nome, nom.c_str(), sizeof(nome) - 1);
    strncpy(curso, cur.c_str(), sizeof(curso) - 1);
}

int Aluno::getMatricula() const { return matricula; }
string Aluno::getNome() const { return string(nome); }
string Aluno::getCurso() const { return string(curso); }
float Aluno::getCoeficiente() const { return coeficiente; }

void Aluno::setMatricula(int mat) { matricula = mat; }
void Aluno::setNome(const string& nom) {
    memset(nome, 0, sizeof(nome));
    strncpy(nome, nom.c_str(), sizeof(nome) - 1);
}
void Aluno::setCurso(const string& cur) {
    memset(curso, 0, sizeof(curso));
    strncpy(curso, cur.c_str(), sizeof(curso) - 1);
}
void Aluno::setCoeficiente(float coef) { coeficiente = coef; }

void Aluno::serializar(ostream& out) const {
    out.write(reinterpret_cast<const char*>(&matricula), sizeof(matricula));
    out.write(nome, sizeof(nome));
    out.write(curso, sizeof(curso));
    out.write(reinterpret_cast<const char*>(&coeficiente), sizeof(coeficiente));
}

void Aluno::desserializar(istream& in) {
    in.read(reinterpret_cast<char*>(&matricula), sizeof(matricula));
    in.read(nome, sizeof(nome));
    in.read(curso, sizeof(curso));
    in.read(reinterpret_cast<char*>(&coeficiente), sizeof(coeficiente));
}

size_t Aluno::tamanhoRegistro() {
    return sizeof(int) + 100 + 50 + sizeof(float);
}

void Aluno::exibir() const {
    cout << "Matrícula: " << matricula << endl;
    cout << "Nome: " << nome << endl;
    cout << "Curso: " << curso << endl;
    cout << "Coeficiente: " << fixed << setprecision(2) 
         << coeficiente << endl;
}
