#include "ListaEnlazada.h"

class Mystr
{
private:
  /* data */

public:
  Mystr(/* args */);

  //Tamaño del array de caracteres. Se recomienda usar strlen en vez de
  // almacenar el largo de la cadena en el objeto
  unsigned int Length();
  //La capacidad de la memoria reservada.
  unsigned int Capacity();
  //Busca todos los caracteres iguales a “find” y los
  //sustituye por replaceBy. Devuelve el número de caracteres remplazados.
  int Replace(char find, char replaceBy);
  //Devuelve 0 si ambas cadenas son iguales, 1 si la primera
  // cadena es mayor que la de “other”, -1 si la de “other” es mayor que la primera.
  //-Se puede usar strcmp
  int Compare(const Mystr &other);
  //Busca todos los caracteres iguales a “find” y los borra. Devuelve el
  //número de caracteres borrados. *Atender al decremento de la capacidad*
  int Remove(char find);
  //Devuelve la subcadena de “num” caracteres empezando por elfinal.
  Mystr Right(unsigned int num);
  // Devuelve la subcadena partiendo de initialIndex hasta llegar a finalIndex.
  Mystr Substring(unsigned int initialIndex, unsigned int finalIndex);
  //Elimina los espacios en blanco que haya por la derecha del texto. Devuelve el
  //número de espacios eliminados. *Atender al decremento de la capacidad*
  int TrimRight();
  //Elimina los espacios en blanco que haya por la izquierda del texto. Devuelve el
  //número de espacios eliminados. *Atender al decremento de la capacidad*
  int TrimLeft();
  //Elimina los espacios en blanco en ambos lados del texto. Devuelve el número de
  //espacios eliminados. *Atender al decremento de la capacidad*
  int Trim();
  //Convierte todos los caracteres en letras mayúsculas. Devuelve el número de
  //caracteres que han sido cambiados a mayúsculas. Se permite usar toupper de C.
  int ToUpper();
  //Convierte todos los caracteres en letras minúsculas. Devuelve el número de
  //caracteres que han sido cambiados a minúsculas. Se permite usar tolower de C.
  int ToLower();
  //Devuelve true si la cadena empieza con “other”.
  bool StartsWith(const Mystr &other);
  //Devuelve true si la cadena termina con “other”.
  bool EndsWith(const Mystr &other);
  //Concatena la cadena añadiendo “other” de manera
  //consecutiva. *Atender al incremento de la capacidad de la primera cadena*
  Mystr Concatenate(const Mystr &other);
  //Concatena la cadena introduciendola entre medias, empezando en la posición indicada
  //por index. *Atender al incremento de la capacidad de la primera cadena*
  Mystr Introduce(const Mystr &other, int unsigned index);
  ~Mystr();
};
