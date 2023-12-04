# Conecta4
Para tener un analasis mas claro de como es mas eficiente la ia (dependiendo de su nivel de programacion) primero se programode manera sencilla con numeros aleatorios.
int ai_choice()
{
    return rand() % 7 + 1; // Random column between 1 and 7
}

int p_choice()
{
    player = 1;
    while(fin!=true)
    {
        if (player == 1)
        {
            cout << "PLAYER " << player << ": ";
            cin >> eleccion;
        }
        else
        {
            eleccion = ai_choice();
            cout << "AI chooses column " << eleccion << endl;
        }

        if (eleccion>0 && eleccion<8)
        {
            check(eleccion);
            draw();
            if (player == 1)
            {
                player++;
            }
            else
            {
                player--;
            }
        }
        else
        {
            cout << "Eleccion equivocada!" << endl;
        }
        win_check();
    }
}
Usando este algoritmo teniendo la respuesta en tiempo record ya que no nesecitaba prosesos complejos,
sin embargo debido a la complejidad del minmax este se relentizo de manera muy notable debido a la toma de eleccciones que debia hacer la ia.
Despues se intento implentar el minmax medido por puntos para detectar(la idea era hacer una base con una ia ramdomizada para medir de mejor forma el cambio , "tambien para comprender de forma sencilla el juego") pero por falta de dos clases y la modificacion del main no se logro de cualquier forma se puede llegar a la misma conclusion sabiedno el numero de procesos nesesarios para poder llegar al resultado final ("las pruebas que hice "imperfectas " demostraron esto ) el primero fue con poda que funcionaba pero a medias y con parametros especificos y el poda tenia demasiados errores al momento de compilar .
finalmente se opto por este codigo por que contiene lo mejor de todas las clases que se probaron y tiene un codigo funcional y divertido.