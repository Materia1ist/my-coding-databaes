#include <bits/stdc++.h>
using namespace std;

struct TicTacToe
{
    int state[3][3]; // 棋盘状态
    int player;      // 当前玩家（1: X, -1: O）

    void init()
    {
        memset(state, 0, sizeof(state));
        player = 1; // X 先手
    }

    void print()
    {
        cout << "Current Board:\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << (state[i][j] == 1 ? "X" : (state[i][j] == -1 ? "O" : "."));
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

    bool isDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (state[i][j] == 0)
                    return false;
            }
        }
        return checkWinner() == 0;
    }

    int miniMax(int currentPlayer, int depth)
    {
        int winner = checkWinner();
        if (winner != 0)
            return winner * (10 - depth);
        if (isDraw())
            return 0;

        int bestScore = (currentPlayer == 1) ? INT_MIN : INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (state[i][j] == 0)
                {
                    state[i][j] = currentPlayer;
                    int score = miniMax(-currentPlayer, depth + 1);
                    state[i][j] = 0;
                    if (currentPlayer == 1)
                        bestScore = max(bestScore, score);
                    else
                        bestScore = min(bestScore, score);
                }
            }
        }
        return bestScore;
    }

    pair<int, int> findBestMove()
    {
        int bestScore = (player == 1) ? INT_MIN : INT_MAX;
        pair<int, int> bestMove = {-1, -1};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (state[i][j] == 0)
                {
                    state[i][j] = player;
                    int score = miniMax(-player, 0);
                    state[i][j] = 0;
                    if ((player == 1 && score > bestScore) || (player == -1 && score < bestScore))
                    {
                        bestScore = score;
                        bestMove = {i, j};
                    }
                }
            }
        }
        return bestMove;
    }

    void playAI()
    {
        pair<int, int> move = findBestMove();
        state[move.first][move.second] = player;
        player = -player;
    }

    void playGame()
    {
        init();
        int step = 1;
        while (!checkWinner() && !isDraw())
        {
            cout << "Step " << step++ << endl;
            playAI();
            print();
        }
        int winner = checkWinner();
        if (winner == 1)
            cout << "X wins!" << endl;
        else if (winner == -1)
            cout << "O wins!" << endl;
        else
            cout << "It's a draw!" << endl;
    }
};

int main()
{
    TicTacToe game;
    game.playGame();
    return 0;
}
