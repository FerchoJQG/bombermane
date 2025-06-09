/*#pragma once
#include <vector>
#include "Habilidad.h"

using namespace std;

class CColeccionHabilidad {
    vector<CHabilidad*> habilidades;

public:
    CColeccionHabilidad() {}
    ~CColeccionHabilidad() {}

    vector<CHabilidad*> getHabilidades();
    void crearHabilidad();
    void dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha);
    void limpiarHabilidadesExpiradas(); // Nueva función
};*/
#pragma once
#include <vector>
#include "Habilidad.h"
using namespace std;

class CColeccionHabilidad {
private:
    vector<CHabilidad*> habilidades;

public:
    ~CColeccionHabilidad();

    vector<CHabilidad*>& getHabilidades();

    void crearHabilidad(int fila, int columna) {};
    void limpiarHabilidadesExpiradas();
    void dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha);

    void revelarHabilidadEnPosicion(int fila, int columna); // Nueva función

};
