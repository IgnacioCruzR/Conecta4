public:
    int choice() {
        return rand() % 7 + 1; // Random column between 1 and 7
    }
};

// ... (rest of your code)

AI ai;

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
            eleccion = ai.choice();
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