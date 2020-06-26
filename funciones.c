void ordenarLista_MIO(tLista *p, int (*compararMovim)(const void *, const void *))
{
    /*DEFINICION DE PUNTEROS

    MENOR = Señala el elemento con el menor valor
    PRI = Señana el elemento desde donde se inicia el recorrido en busca de menores
    R = Es el puntero que recorre en busca de menores

    */
    tNodo *menor, *pri = *p, *r = *p;

    //Mienras exista un elemento siguiente a PRI
    while(pri->sig)
    {
        //PRI Inicia como el MENOR
        menor = pri;
        r = pri->sig;
        //R recorre en busca del Menor entre todos de la derecha
        while(r)
        {
            if(compararMovim && compararMovim((r)->info, menor->info) < 0 )
                menor = r;
            r = r->sig;
        }
        //Al terminar de recorrer toda la derecha, pueden pasar dos cosas:
        //SI "MENOR" NO SE ENCONTRO
        if(menor == pri)
            pri = pri->sig;
        //SI "MENOR" SI FUE HAYADO
        else
        {
            //Invocamos un aux que comienza en PRI
            tNodo *aux = pri;

            //Posicionamos AUX hasta uno antes del MENOR para desvincularlo y reubicarlo antes de PRI
            while(aux->sig != menor) //mientras el siguiente de aux no sea igual a "MENOR"
                aux = aux->sig;      //avanza aux

            aux->sig = menor->sig;   //desvinculamos el menor
            menor->sig = pri;        //lo ponemos antes de pri

            /*Si P es igual a PRI, se trata de la primera insercion, y P
            pasa a apuntarlo*/
            if((*p) == pri)
                *p = menor;
            else
            {
              (*p)->sig = menor;
               p = &(*p)->sig;
            }
        }
    }


}
