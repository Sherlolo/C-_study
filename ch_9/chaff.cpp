#include <iostream>
#include <cstring>
#include <new>

const int Buf = 512;


struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    using namespace std;
    char buffer[Buf];
    char *pc = new char[Buf];

    chaff * pc1 = new (buffer) chaff[2];
    chaff * pc2 = new (pc) chaff[2];
    char dross[20] = {0};
    int slag = 0;

   for (int i = 0; i < 2; i++)
    {
        cout << "Enter dross of #" << i+1 << " chaff:\n";
        cin.getline(dross, 20);
        cout << "Enter slag of #" << i+1 << " chaff:\n";
        cin >> slag;
        cin.ignore();
        strcpy_s(pc1[i].dross, dross);
        strcpy_s(pc2[i].dross, dross);
        pc1[i].slag = pc2[i].slag = slag;
    }
    for(int i = 0; i < 2; i++)
    {
        cout << "pc1.dross: " << pc1[i].dross << ", pc1.slag: " << pc1[i].slag << endl;
        cout << "pc2.dross: " << pc2[i].dross << ", pc2.slag: " << pc2[i].slag << endl;
    }
    delete[] pc;
    system("pause");
    return 0;
}