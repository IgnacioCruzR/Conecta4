class JugadorIa {
public:
    int choice() {
        int bestScore = -10000;
        int move = 0;
        // intenta cada posible movimiento
        for (int i = 1; i <= 7; i++) {
            // Chequea si se puede mover 
            if (tab[i-1][0] == 0) {
                // se mueve
                tab[i-1][0] = 2;
                // llama al minimax
                int score = minimax(tab, 0, false);
                // Undo the move
                tab[i-1][0] = 0;
                // si este movimiento es mejor que el guardado , actualiza el score y lo mueve 
                if (score > bestScore) {
                    bestScore = score;
                    move = i;
                }
            }
        }
        return move;
    }

    int minimax(int board[7][6], int depth, bool isMaximizing) {
        // checkea si el juego termino
        if (gameOver(board) || depth == 6) {
            return evaluate(board);
        }

        if (isMaximizing) {
            int bestScore = -10000;
            for (int i = 1; i <= 7; i++) {
                if (board[i-1][0] == 0) {
                    board[i-1][0] = 2;
                    int score = minimax(board, depth + 1, false);
                    board[i-1][0] = 0;
                    bestScore = max(score, bestScore);
                }
            }
            return bestScore;
        } else {
            int bestScore = 10000;
            for (int i = 1; i <= 7; i++) {
                if (board[i-1][0] == 0) {
                    board[i-1][0] = 1;
                    int score = minimax(board, depth + 1, true);
                    board[i-1][0] = 0;
                    bestScore = min(score, bestScore);
                }
            }
            return bestScore;
        }
    }

    bool gameOver(int board[7][6]) {
        // Check if game is over
        // This function needs to be implemented
        return false;
    }

    int evaluate(int board[7][6]) {
        // Evaluate the game board
        // This function needs to be implemented
        return 0;
    }
};

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