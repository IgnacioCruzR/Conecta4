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