#include "racional.h"

class ShortableRacionalArray
{
private:
  Racional *_arrRacionals;
  unsigned int _size;

public:
  ShortableRacionalArray(int size);
  void addRandomRacionalToArrRacionals();
  void orderArrRacionals();
  void writeOnConsole();
  ~ShortableRacionalArray();
};