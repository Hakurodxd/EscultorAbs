#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

class Sculptor {
private:
  Voxel ***v; // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  Sculptor(int _nx, int _ny, int _nz); // Construtor
  ~Sculptor(); // Destrutor
  void setColor(float r, float g, float b, float a); // Define a cor
  void putVoxel(int x, int y, int z); // Cria um voxel 
  void cutVoxel(int x, int y, int z); // Corta um voxel
  void writeOFF(const char* filename); // Escreve o modelo em formato OFF
};
#endif