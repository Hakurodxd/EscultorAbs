#include "sculptor.h"
#include <iostream>
#include <fstream>

/**Definição do construtor da classe, responsável por receber as dimensões do Sculptor e criar a matriz 3D.
 * @param _nx - Recebe a dimensão x do Sculptor.
 * @param _ny - Recebe a dimensão y do Sculptor.
 * @param _nz - Recebe a dimensão z do Sculptor.
  */
  Sculptor::Sculptor(int _nx, int _ny, int _nz){

    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];

    for (int i = 0; i < nx; ++i) {
        v[i] = new Voxel*[ny];
    }
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            v[i][j] = new Voxel[nz];
        }
    }
  }

/**Definição do destrutor da classe, responsável por liberar a memória alocada para a matriz 3D.
  */
  Sculptor::~Sculptor(){
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
  }

/**Método setColor, responsável por definir a cor que os voxels irão receber na matriz 3D. No entanto, cada método de contrução de voxel é responsável por pintar os voxels que está criando, uma vez que, o método setColor apenas armazena a cor informada para os próximos voxels.
 */
  void Sculptor::setColor(float r, float g, float b, float a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
  }
/**Método putVoxel, com a função de criar um voxel na posição (x,y,z) da matriz 3D. Sendo que para criar um voxel, o v.show deve ser igual a 'true', tornando o mesmo visível.
  */
  void Sculptor::putVoxel(int x, int y, int z){
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
      v[x][y][z].show = true;
      v[x][y][z].r = r;
      v[x][y][z].g = g;
      v[x][y][z].b = b;
      v[x][y][z].a = a;
    }
  }

/**Método cutVoxel, com a função de apagar um voxel na posição (x,y,z) da matriz 3D, mudando v.show para 'false'.
  */
  void Sculptor::cutVoxel(int x, int y, int z){
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
      v[x][y][z].show = false;
    }
  }

/**O writeOFF é o método responsável por escrever o arquivo .off que será lido pelo visualizador 3D, por isso deve obedecer uma sintaxe especifica, utilizando as bibliotecas iostream e fstream.
  */
  void Sculptor::writeOFF(const char* filename){

    //Abertura do arquivo informado.
    std::ofstream fout(filename);

    if (!fout.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        return;
    }

    //Declaração e contagem do número vértices e faces presentes na escultura
    int nVertices = 0;
    int nFaces = 0;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    nVertices += 8;
                    nFaces += 6; 
                }
            }
        }
    }

    //Cabecalho do arquivo .off.
    fout << "OFF\n";
    fout << nVertices << " " << nFaces << " 0\n";

    //Loop responsável por gerar os vértices e informar as cores dos voxels.
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {

                    float x0 = i;
                    float y0 = j;
                    float z0 = k;
                    float x1 = i + 1;
                    float y1 = j + 1;
                    float z1 = k + 1;

                    float red = v[i][j][k].r;
                    float green = v[i][j][k].g;
                    float blue = v[i][j][k].b;
                    float alpha = v[i][j][k].a;

                    fout << x0 << " " << y0 << " " << z0 << " " << red << " " << green << " " << blue << " " << alpha << ".\n";
                    fout << x1 << " " << y0 << " " << z0 << " " << red << " " << green << " " << blue << " " << alpha << ".\n";
                    fout << x1 << " " << y1 << " " << z0 << " " << red << " " << green << " " << blue << " " << alpha << ".\n";
                    fout << x0 << " " << y1 << " " << z0 << " " << red << " " << green << " " << blue << " " << alpha << ".\n";
                    fout << x0 << " " << y0 << " " << z1 << " " << red << " " << green << " " << blue << " " << alpha << ".\n";
                    fout << x1 << " " << y0 << " " << z1 << " " << red << " " << green << " " << blue << " " << alpha << ".\n";
                    fout << x1 << " " << y1 << " " << z1 << " " << red << " " << green << " " << blue << " " << alpha << ".\n";
                    fout << x0 << " " << y1 << " " << z1 << " " << red << " " << green << " " << blue << " " << alpha << ".\n";

                }
            }
        }
    }

    //Ultima parte do arquivo, que define as conexões entre os vértices, gerando as faces.
    int vertice0 = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    fout << "4 " << vertice0 << " " << vertice0 + 1 << " " << vertice0 + 2 << " " << vertice0 + 3 << "\n";
                    fout << "4 " << vertice0 + 4 << " " << vertice0 + 5 << " " << vertice0 + 6 << " " << vertice0 + 7 << "\n";
                    fout << "4 " << vertice0 << " " << vertice0 + 1 << " " << vertice0 + 5 << " " << vertice0 + 4 << "\n";
                    fout << "4 " << vertice0 + 1 << " " << vertice0 + 2 << " " << vertice0 + 6 << " " << vertice0 + 5 << "\n";
                    fout << "4 " << vertice0 + 2 << " " << vertice0 + 3 << " " << vertice0 + 7 << " " << vertice0 + 6 << "\n";
                    fout << "4 " << vertice0 + 3 << " " << vertice0 << " " << vertice0 + 4 << " " << vertice0 + 7 << "\n";
                    vertice0 += 8;
                }
            }
        }
    }
  //Fechamento do arquivo.
    fout.close();
  }