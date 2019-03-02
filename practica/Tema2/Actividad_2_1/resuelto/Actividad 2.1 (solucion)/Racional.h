// Clase que representa un n�mero racional mediante una fracci�n
class Racional
{
private:

	int numerador; // Numerador
	int denominador; // Denominador. Precondici�n: no puede ser 0

	// Calcula el m�ximo com�n divisor de dos operandos naturales, usando el algoritmo de Euclides
	// Par�metros:
	// - operando1: primer operando
	// - operando2: segundo operando
	// Retorno: m�ximo com�n divisor de los dos operandos pasados como argumento
	// Precondiciones: operando1 >= 0 && operando2 >= 0
	int calcularMaximoComunDivisor(int operando1, int operando2);

public:

	/* Constructor que construye un numero racional a partir de su numerador y denominador
	Par�metros:
	- Numerador: el numerador de la fracci�n
	- Denominador: el denominador de la fracci�n
	Precondici�n: denominador != 0 */
	Racional(int numerador, int denominador);

	/* Suma "sumando" y el objeto actual. Crea un nuevo racional con el resultado y devuelve su copia
	Par�metro: el racional que es el segundo sumando
	Retorno: un nuevo racional, fruto de sumar "sumando" con el objeto actual */
	Racional sumar(Racional sumando);

	/* Multiplica "multiplicador" y el objeto actual. Crea un nuevo racional con el resultado y devuelve su copia
	Par�metro: el racional que es el multiplicador
	Retorno: un nuevo racional, fruto de multiplicar "multiplicador" con el objeto actual */
	Racional multiplicar(Racional multiplicador);

	/* Obtiene el numerador del objeto racional actual
	Retorno: numerador de la fracci�n del objeto actual */
	int getNumerador();

	/* Obtiene el denominador del objeto racional actual
	Retorno: numerador de la fracci�n del objeto actual */
	int getDenominador();

	/* Simplifica al maximo la fracci�n que representa al numero racional actual */
	void simplificar();

	/* Imprime por pantalla la fracci�n que representa al numero racional actual. Formato n/d.
	Si el numerador es 0 � el denominador es 1 s�lo se escribe el numerador.
	OJO: Este es un m�todo de vista que est� en una clase de modelo => MAL */
	void escribir();



};

