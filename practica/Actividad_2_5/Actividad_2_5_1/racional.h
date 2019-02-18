class Racional
{
private:
  int _numerador;
  int _denominador;

public:
  Racional(int numerador, int denominador);
  ~Racional();

  int getNumerador();
  int getDenominador();
  float getValor();
};
