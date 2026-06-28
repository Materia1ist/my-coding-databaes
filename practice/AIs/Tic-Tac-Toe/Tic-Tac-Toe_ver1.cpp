///use a dfs approach to find the best move for the computer
///use a minimax algorithm to find the best move for the computer
///it can be improved by using alpha-beta pruning
//cost about 4 hours(too long)
#include <bits/stdc++.h>
using namespace std;

struct TicTacToe
{
    int state[3][3];
    int score, player, depth;

    void init()
    {
        memset(state, 0, sizeof(state));
        score = depth = 0;
        player = 1;
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << (state[i][j] == 1 ? "X" : (state[i][j] == -1 ? "O" : " "));
            }
            cout << endl;
        }
    }
    int checkWinner()
    {
        for (int i = 0; i < 3; i++)
        {
            if (state[i][0] != 0 && state[i][0] == state[i][1] && state[i][0] == state[i][2])
                return state[i][0];
            if (state[0][i] != 0 && state[0][i] == state[1][i] && state[0][i] == state[2][i])
                return state[0][i];
        }
        if (state[0][0] != 0 && state[0][0] == state[1][1] && state[0][0] == state[2][2])
            return state[0][0];
        if (state[0][2] != 0 && state[0][2] == state[1][1] && state[0][2] == state[2][0])
            return state[0][2];
        return 0;
    }
    int isDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (state[i][j] == 0)
                    return 0;
            }
        }
        return checkWinner() == 0;
    }
    bool terminal()
    { // answer is the game over?
        return checkWinner() != 0 || isDraw();
    }

    void utility()
    { // answer is the score
        if (checkWinner() == 1)
            score = 1;
        else if (checkWinner() == -1)
            score = -1;
        else
            score = 0;
    }

    void isWin()
    {
        if (checkWinner() == 1)
            cout << "X wins" << endl;
        else if (checkWinner() == -1)
            cout << "O wins" << endl;
        else
            cout << "It's a draw" << endl;
    }

    void action(int x, int y)
    {
        if (state[x][y] == 0)
        {
            state[x][y] = player;
            player = -player;
        }
    }
    int miniMax()
    {
        int winner = checkWinner();
        if (winner == 1)
            return 10 - depth;
        if (winner == -1)
            return -10 + depth;
        if (isDraw())
            return 0;

        if (player == 1)
        {
            int bestScore = INT_MIN;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (state[i][j] == 0)
                    {
                        state[i][j] = 1;
                        depth++;
                        player = -player;
                        bestScore = max(bestScore, miniMax());
                        state[i][j] = 0;
                        player = -player;
                        depth--;
                    }
                }
            }
            return bestScore;
        }
        else
        {
            int bestScore = INT_MAX;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (state[i][j] == 0)
                    {
                        state[i][j] = -1;
                        depth++;
                        player = -player;
                        bestScore = min(bestScore, miniMax());
                        state[i][j] = 0;
                        player = -player;
                        depth--;
                    }
                }
            }
            return bestScore;
        }
    }
    pair<int, int> findBestMove()
    {
        int BestScore = (player == 1) ? INT_MIN : INT_MAX;
        pair<int, int> BestMove = {-1, -1};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (state[i][j] == 0)
                {
                    state[i][j] = player;
                    depth++;
                    player = -player;
                    int score = miniMax();
                    state[i][j] = 0;
                    player = -player;
                    depth--;
                    if ((player == 1 && score > BestScore) || (player == -1 && score < BestScore))
                    {
                        BestScore = score;
                        BestMove = {i, j};
                    }
                }
            }
        }
        return BestMove;
    }
};

int main()
{
    TicTacToe game;
    game.init();

    int i = 1;
    while (!game.checkWinner() && !game.isDraw())
    {
        if (i % 2 == 1)
        {
            int x, y;
            cout << "Enter the position: ";
            cin >> x >> y;
            game.action(x, y);
            cout << "Step " << i++ << endl;
            game.print();
            // pair<int, int> p = game.findBestMove();
            // game.action(p.first, p.second);
            // cout << "Step " << i++ << endl;
            // game.print();
        }
        else
        {
            pair<int, int> p = game.findBestMove();
            game.action(p.first, p.second);
            cout << "Step " << i++ << endl;
            game.print();
        }
    }
    game.isWin();
    return 0;
}
