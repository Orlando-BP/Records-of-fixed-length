#include "Manejador_De_Archivo.h"

Manejador_De_Archivo::Manejador_De_Archivo()
{
}

void Manejador_De_Archivo::CrearObjetoA()
{
    int key;
    do{
    cout << "Ingresa La Llave del objeto A: " << endl;
    cin>>key;
    } while (VerificarLlave(key)==false);
    obj = Clase_A(key);
}

void Manejador_De_Archivo::insertarFinal()
{
    CrearObjetoA();
    ofstream fout("fichero.bin", ios::binary | ios::app);
    fout.write((char*)&obj, sizeof(Clase_A));
}

void Manejador_De_Archivo::insertarInicio()
{
    ifstream fin("fichero.bin", ios::binary);
    string Archivo;
    fin >> Archivo;
    fin.close();
    CrearObjetoA();
    ofstream fout("fichero.bin", ios::binary);
    fout.write((char*)&obj, sizeof(Clase_A));
    fout << Archivo;
}

void Manejador_De_Archivo::Mostrar()
{
    ifstream fin("fichero.bin", ios::binary);
    fin.read((char*)&obj, sizeof(Clase_A));
    while (!fin.eof()) {
        cout << "_---REGISTRO---_" << endl;
        obj.Mostrar();
        fin.read((char*)&obj, sizeof(Clase_A));
    }
    fin.close();
}

void Manejador_De_Archivo::MostrarUNO()
{
    int key;
    cout << "Ingresa la llave del registro a mostrar:" << endl;
    cin >> key;
    if (Buscar(key) != -1) {
        cout << "_---REGISTRO---_" << endl;
        obj.Mostrar();
    }
    else {
        cout << "No se encontro Registro" << endl;
    }
}

int Manejador_De_Archivo::Buscar(int key)
{
    ifstream fin("fichero.bin", ios::binary);
    int fileIndex = 0;
    fin.read((char*)&obj, sizeof(Clase_A));
    while (!fin.eof()) {
        if (obj.DarLlave() == key) {
            return fileIndex;
        }
        fileIndex += sizeof(Clase_A);
        fileIndex = fin.tellg();
        fin.read((char*)&obj, sizeof(Clase_A));
    }
    fin.close();
    return -1;
}

void Manejador_De_Archivo::LlenarSecundario()
{
    ifstream fin("fichero.bin", ios::binary);
    string Archivo;
    fin >> Archivo;
    fin.close();
    ofstream fout("Secundario.bin", ios::binary);
    fout << Archivo;
}

void Manejador_De_Archivo::Eliminar()
{
    LlenarSecundario();
    int key;
    cout << "Ingresa la llave del registro a eliminar:" << endl;
    cin >> key;
    ifstream fin("Secundario.bin", ios::binary);
    int fileIndex = 0;
    fin.read((char*)&obj, sizeof(Clase_A));
    ofstream fout("fichero.bin", ios::binary);
    while (!fin.eof()) {
        if (obj.DarLlave() != key) {
            fout.write((char*)&obj, sizeof(Clase_A));
        }
        fileIndex += sizeof(Clase_A);
        fileIndex = fin.tellg();
        fin.read((char*)&obj, sizeof(Clase_A));
    }
    fout.close();
    fin.close();
}

void Manejador_De_Archivo::Modificar()
{
    int key;
    int fileindex;
    cout << "Ingresa la llave del registro a modificar:" << endl;
    cin >> key;
    fileindex = Buscar(key);
    if (fileindex == -1) {
        cout << "No se encontro el registro" << endl;
        return;
    }
    MenuModificar();
    ofstream fout("fichero.bin", ios::binary | ios::in);
    fout.seekp(fileindex, ios::beg);
    fout.write((char*)&obj, sizeof(Clase_A));
}

void Manejador_De_Archivo::MenuModificar()
{
    char opcion;
    bool salir = true;
    do {
        cout << "Se encontro el registro a Modificar" << endl;
        cout << "Que deseas modificar? " << endl;
        cout << "1.-Nombre" << endl;
        cout << "2.-Llave" << endl;
        cout << "3.-Agregar objeto B" << endl;
        cout << "Ingresa una opcion:" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case '1': {
            salir = false;
            obj.SetCadena();
            break;
        }
        case '2': {
            salir = false;
            int key;
            do {
                cout << "Ingresa la llave del objeto de clase A (debe ser nueva)" << endl;
                cin >> key;
            } while (VerificarLlave(key) == false);
            obj.SetLlave(key);
            break;
        }
        case '3': {
            salir = false;
            if (obj.DarContadorB() < 5) {
                obj.AumentarContB();
                double Double = 0;
                bool Bool = false;
                cout << "Objeto B# " << obj.DarContadorB() << endl;
                cout << "Ingresa Double: " << endl;
                cin >> Double;
                cout << "Ingresa booleano 1 o 0: " << endl;
                cin >> Bool;
                Clase_B objB(Double, Bool);
                obj.SetObjB(objB);
            }
            break;
        }
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (salir);
}

bool Manejador_De_Archivo::VerificarLlave(int key)
{
    ifstream fin("fichero.bin", ios::binary);
    int fileIndex = 0;
    fin.read((char*)&obj, sizeof(Clase_A));
    while (!fin.eof()) {
        if (obj.DarLlave() == key) {
            return false;
        }
        fileIndex += sizeof(Clase_A);
        fileIndex = fin.tellg();
        fin.read((char*)&obj, sizeof(Clase_A));
    }
    fin.close();
    return true;
}

void Manejador_De_Archivo::Menu()
{
    bool continuar = true;
    char Opcion;
    do {
        cout << "Menu" << endl;
        cout << "1.-Agregar" << endl;
        cout << "2.-Eliminar" << endl;
        cout << "3.-Modificar" << endl;
        cout << "4.-Mostrar Registro" << endl;
        cout << "5.-Mostrar Registros" << endl;
        cout << "6.-Salir" << endl;
        cout << "Ingresa una Opcion: ";
        cin >> Opcion;
        switch (Opcion)
        {
        case '1': {
            system("CLS");
            cout << "Selecciona en que lugar del archivo quieres agregar un registro:" << endl;
            cout << "1.-Inicio" << endl;
            cout << "2.-Final" << endl;
            cout << "Ingresa una opcion: ";
            cin >> Opcion;
            switch (Opcion)
            {
            case '1': {
                system("CLS");
                insertarInicio();
                break;
            }
            case '2': {
                system("CLS");
                insertarFinal();
                break;
            }
            default:
                cout << "Opcion no valida, intenta de nuevo." << endl;
                break;
            }
            break;
        }
        case '2': {
            system("CLS");
            Eliminar();
            break;
        }
        case '3': {
            system("CLS");
            Modificar();
            break;
        }
        case '4': {
            system("CLS");
            MostrarUNO();
            break;
        }
        case '5': {
            system("CLS");
            Mostrar();
            break;
        }
        case '6': {
            cout << "Nos vemos..." << endl;
            continuar = false;
            break;
        }
        default:
            cout << "Opcion no valida, intenta de nuevo." << endl;
            break;
        }
    } while (continuar);
}
