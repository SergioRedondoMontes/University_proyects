class Racional
{
  private:
    int numerador;
    int denominador;
    int calcularMCD(int a, int b);

  public:
    Racional(int a, int b);
    int getNumerador();
    int getDenominador();
    Racional suma(Racional a);
    Racional multiplicacion(Racional a);
    Racional simplificar();
};