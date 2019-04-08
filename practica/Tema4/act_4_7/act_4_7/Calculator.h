//
//  calculator.h
//  act_4_7
//
//  Created by Sergio Redondo on 03/04/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//


#include <stdio.h>
#include <string>

using namespace std;

class Calculator
{
private:
    /*
     Método privado “convertirInfijoAPostfijo()”. A partir del texto recibido (la expresión en
     infijo), convertimos la expresión en postfijo y la metemos sus tokens en orden en un
     string
     */
     string convertirInfijoAPostfijo();
    /*
     Método privado “evaluarPostfijo()”. A partir de string que genera el método anterior (la
     expresión en postfijo), la evalúa y devuelve un int con el resultado.
     */
    int evaluarPostfijo();
public:
    /*
     Método público “evaluar()”: se le pasa por parámetro un texto (objeto de la clase
     “string”) que contiene la expresión infija a evaluar y nos devuelve un int como
     resultado. Este método llamará a los siguientes en el orden adecuado.
     */
    int evaluar();
    
    
};
