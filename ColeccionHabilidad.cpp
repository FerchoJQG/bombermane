/*#include "ColeccionHabilidad.h"
#include <thread>
#include <chrono>
#include <algorithm>
#include <iostream>

using namespace std;

vector<CHabilidad*> CColeccionHabilidad::getHabilidades() {
    return habilidades;
}

void CColeccionHabilidad::crearHabilidad() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Reducido para mejor rendimiento
    CHabilidad* habilidad = new CHabilidad();
    cout << "Habilidad creada en la posición: (" << habilidad->getFila() << ", " << habilidad->getColumna() << ")" << endl;
    habilidades.push_back(habilidad);
}

void CColeccionHabilidad::revelarHabilidadEnPosicion(int fila, int columna) {
    cout << "Intentando revelar habilidad en posición: (" << fila << ", " << columna << ")" << endl;

    bool habilidadEncontrada = false;
    for (auto habilidad : habilidades) {
        // Usar el método estaEnPosicion para verificar la coincidencia exacta
        if (habilidad->estaEnPosicion(fila, columna)) {
            cout << "Habilidad encontrada y revelada en posición: (" << fila << ", " << columna << ")" << endl;
            habilidad->mostrarHabilidad();
            habilidadEncontrada = true;
            break; // Solo revelar una habilidad por posición
        }
    }

    if (!habilidadEncontrada) {
        cout << "No se encontró habilidad en la posición: (" << fila << ", " << columna << ")" << endl;
    }
}

void CColeccionHabilidad::limpiarHabilidadesExpiradas() {
    auto it = std::remove_if(habilidades.begin(), habilidades.end(),
        [](CHabilidad* habilidad) {
            if (habilidad->debeDesaparecer()) {
                delete habilidad;
                return true;
            }
            return false;
        });

    habilidades.erase(it, habilidades.end());
}

void CColeccionHabilidad::dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha) {
    // Limpiar habilidades expiradas antes de dibujar
    limpiarHabilidadesExpiradas();

    for (int i = 0; i < habilidades.size(); i++) {
        habilidades.at(i)->dibujar(g, bmpHabilidad, cancha);
        habilidades.at(i)->animar();
    }
}*/

#include "ColeccionHabilidad.h"

CColeccionHabilidad::~CColeccionHabilidad() {
    for (auto h : habilidades) delete h;
    habilidades.clear();
}

vector<CHabilidad*>& CColeccionHabilidad::getHabilidades() {
    return habilidades;
}
/*
void CColeccionHabilidad::crearHabilidad(int fila, int columna) {
    CHabilidad* habilidad = new CHabilidad();
    habilidad->setPosicion(fila, columna);
    habilidad->mostrarHabilidad();
    habilidades.push_back(habilidad);
}*/

void CColeccionHabilidad::limpiarHabilidadesExpiradas() {
    auto it = remove_if(habilidades.begin(), habilidades.end(),
        [](CHabilidad* h) {
            if (h->debeDesaparecer()) {
                delete h;
                return true;
            }
            return false;
        });
    habilidades.erase(it, habilidades.end());
}

void CColeccionHabilidad::dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha) {
    limpiarHabilidadesExpiradas();
    for (auto h : habilidades) {
        h->dibujar(g, bmpHabilidad, cancha);
        h->animar();
    }
}

void CColeccionHabilidad::revelarHabilidadEnPosicion(int fila, int columna) {
    for (auto& habilidad : habilidades) {
        if (habilidad->getFila() == fila && habilidad->getColumna() == columna) {
            habilidad->mostrarHabilidad();
            break;
        }
    }
}
