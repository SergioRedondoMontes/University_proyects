//
//  Nodo.hpp
//  act_7_2
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#pragma once

// Nodo del árbol binario de búsqueda
struct Nodo {
    int contenido; // Contenido del nodo
    Nodo *padre; // Apunta al padre, o NULL si no tiene
    Nodo *hijoIzquierdo; // Apunta al hijo izquierdo, o NULL si no tiene hijo izquierdo
    Nodo *hijoDerecho; // Apunta al hijo derecho, o NULL si no tiene hijo derecho
};
