#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace simulator {

class Swarm {
public:
  const static int NPARTICLES = 9000;

private:
  Particle* m_pParticles;
  int m_lastTime;

public:
  Swarm();
  virtual ~Swarm();
  void update(int elapsed);

  Particle * getParticles();
};

}

#endif
