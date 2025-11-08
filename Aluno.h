#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <fstream>

using namespace std;

class Aluno {
private:
    int matricula;
    char nome[100];
    char curso[50];
    float coeficiente;

public:
    Aluno();
    Aluno(int mat, const string& nom, const string& cur, float coef);
    
    // Getters
    int getMatricula() const;
    string getNome() const;
    string getCurso() const;
    float getCoeficiente() const;
    
    // Setters
    void setMatricula(int mat);
    void setNome(const string& nom);
    void setCurso(const string& cur);
    void setCoeficiente(float coef);
    
    // Serialização
    void serializar(ostream& out) const;
    void desserializar(istream& in);
    
    // Tamanho fixo do registro
    static size_t tamanhoRegistro();
    
    // Exibição
    void exibir() const;
};

#endif
