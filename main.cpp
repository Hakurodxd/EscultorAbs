#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CutBox.h"
#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutVoxel.h"
#include "FigGeometrica.h"
#include "PutBox.h"
#include "PutEllipsoid.h"
#include "PutSphere.h"
#include "PutVoxel.h"

int main() {

  Sculptor* blackhole;
  blackhole = new Sculptor(100, 100, 100);
  
  std::vector<FigGeometrica *> figs;
  std::ifstream fin;

  fin.open("teste.txt");
  if (!fin.is_open()) {
    return 0;
  }
  while (fin.good()) {
    std::string s;
    fin >> s;

    if (s.compare("putVoxel") == 0) {
      
      int x_, y_, z_;
      float r_, g_, b_, a_;
      fin >> x_ >> y_ >> z_ >> r_ >> g_ >> b_ >> a_;
      figs.push_back(new putVoxel(x_, y_, z_, r_, g_, b_, a_));
      
    } else if (s.compare("cutVoxel") == 0) {
      
      int x_, y_, z_;
      fin >> x_ >> y_ >> z_;
      figs.push_back(new cutVoxel(x_, y_, z_));
      
    } else if (s.compare("putBox") == 0) {
      
      int x0_, x1_, y0_, y1_, z0_, z1_;
      float r_, g_, b_, a_;
      fin >> x0_ >> x1_ >> y0_ >> y1_ >> z0_ >> z1_ >> r_ >> g_ >> b_ >> a_;
      figs.push_back(new putBox(x0_, x1_, y0_, y1_, z0_, z1_, r_, g_, b_, a_));
      
    } else if (s.compare("cutBox") == 0) {
      
      int x0_, x1_, y0_, y1_, z0_, z1_;
      fin >> x0_ >> x1_ >> y0_ >> y1_ >> z0_ >> z1_;
      figs.push_back(new cutBox(x0_, x1_, y0_, y1_, z0_, z1_));
      
    } else if (s.compare("putSphere") == 0) {
      
      int xcenter_, ycenter_, zcenter_, radius_;
      float r_, g_, b_, a_;
      fin >> xcenter_ >> ycenter_ >> zcenter_ >> radius_ >> r_ >> g_ >> b_ >> a_;
      figs.push_back(new putSphere(xcenter_, ycenter_, zcenter_, radius_, r_, g_, b_, a_));
      
    } else if (s.compare("cutSphere") == 0) {
      
      int xcenter_, ycenter_, zcenter_, radius_;
      fin >> xcenter_ >> ycenter_ >> zcenter_ >> radius_;
      figs.push_back(new cutSphere(xcenter_, ycenter_, zcenter_, radius_));
      
    } else if (s.compare("putEllipsoid") == 0) {
      
      int xcenter_, ycenter_, zcenter_, rx_, ry_, rz_;
      float r_, g_, b_, a_;
      fin >> xcenter_ >> ycenter_ >> zcenter_>> rx_ >> ry_ >> rz_ >> r_ >> g_ >> b_ >> a_;
      figs.push_back(new putEllipsoid(xcenter_, ycenter_, zcenter_, rx_, ry_, rz_, r_, g_, b_, a_));
      
    } else if (s.compare("cutEllipsoid") == 0) {
      
      int xcenter_, ycenter_, zcenter_, rx_, ry_, rz_;
      fin >> xcenter_ >> ycenter_ >> zcenter_>> rx_ >> ry_ >> rz_;
      figs.push_back(new cutEllipsoid(xcenter_, ycenter_, zcenter_, rx_, ry_, rz_));
    }
  }

  for (size_t x=0; x<figs.size(); x++){
      figs[x] -> draw(*blackhole);
  }
  
  blackhole -> writeOFF("blackhole.off"); 

  for(size_t x=0; x<figs.size(); x++){
    delete figs[x];
  }

}