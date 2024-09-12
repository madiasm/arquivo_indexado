#include <iostream>

using namespace std;

struct paises{
    int codigo;
    string nome;
};

struct indicePaises{
    int codigo;
    int ender;
};

struct cidades{
    int codigo;
    string nome;
    char uf[2];
    int codigoPais;
};

struct indiceCidades{
    int codigo;
    int ender;
};

struct Guias{
    int codigo
    string nome
    endereco
    telefone
    codigoCidade;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
