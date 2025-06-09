/*#pragma once
#include <ctime>
#include <stdlib.h>
#include "Items.h"
#include "Cancha.h"

using namespace System::Drawing;

enum EEstadoHabilidad {
    Oculta = 0,     // Habilidad oculta en bloque rompible
    Visible,        // Habilidad visible despu�s de romper bloque
    Desaparecida    // Habilidad que ya no debe mostrarse
};

class CHabilidad {
    int i;
    int j;
    int indiceX;
    int indiceY;
    bool posicionFinalizada; // Nueva variable para controlar si la posici�n ya est� fija
    int tipoHabilidad;
    bool ubicado;
    EEstadoHabilidad estado;

    // Control de tiempo para desaparici�n
    clock_t tiempoVisible;
    static const int DURACION_SEGUNDOS = 10;

public:
    CHabilidad();
    ~CHabilidad();

    void dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha);
    void animar();
    // A�adir estas declaraciones:
    int getTipoHabilidad() { return tipoHabilidad; }
    void consumir() { estado = EEstadoHabilidad::Desaparecida; }

    void mostrarHabilidad(); // Hacer visible la habilidad
    bool debeDesaparecer();  // Verificar si debe desaparecer
    EEstadoHabilidad getEstado();
    int getFila() { return i; }
    int getColumna() { return j; }
    bool estaPosicionFinalizada() { return posicionFinalizada; }
    void finalizarPosicion() { posicionFinalizada = true; }
    // M�todo para verificar si la habilidad est� en una posici�n espec�fica
    bool estaEnPosicion(int fila, int columna) { return (i == fila && j == columna); }
};*/
#pragma once
#include <ctime>
#include "Cancha.h"
using namespace System::Drawing;

enum EEstadoHabilidad {
    Oculta = 0,
    Visible,
    Desaparecida
};

class CHabilidad {
private:
    int i, j; // fila y columna en la cancha
    int indiceX, indiceY; // para animaci�n
    bool ubicado;
    int tipoHabilidad; // 1:BombaAdicional, 2:MoverBomba, 3:Calavera, 4:Patines, 5:VidaExtra
    EEstadoHabilidad estado;
    clock_t tiempoVisible;
    static const int DURACION_SEGUNDOS;

public:
    CHabilidad();
    ~CHabilidad();

    void mostrarHabilidad();
    bool debeDesaparecer();
    EEstadoHabilidad getEstado();
    int getTipoHabilidad();
    int getFila();
    int getColumna();
    bool estaEnPosicion(int fila, int columna);
    void setPosicion(int fila, int columna);
    void consumir();

    void dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha);
    void animar();
};
