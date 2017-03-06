/* cards.cpp
 * Given a deck of 26 red and 26 black cards, define the game:
 * - For each red card revealed, you receive 1 point
 * - For each black card revealed, you lose one point
 * Cards are drawn without replacement. What is the expected
 * payment, assuming optimal play?
 *
 * Proposed solution:
 * Define the (a,b) game as the game when a red cards and b black
 * cards remain. We determine the optimal payoff by building
 * the optimal play from the (0,0) game upward, to the (26,26)
 * game.
 */

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    double p[27][27];
    // p[a][b] will be the expected payoff from playing the (a, b) game
    // where a is the number of cards in your favour and b otherwise
    // Generally p[a][b] = max(0, a / (a+b) * p[a-1][b] + b / (a+b) * p[a][b-1]

    for (int j=0; j<27; j++) {
        for (int i=0; i<27; i++) {
            if (i == 0 && j == 0)
                p[i][j] = 0;
            else if (i == 0)
                p[i][j] = max(0., p[0][j-1] - 1);
            else if (j == 0)
                p[i][j] = max(0., p[i-1][0] + 1);
            else
                p[i][j] = max(0., ((double) i) / (i+j) * (p[i-1][j]+1) + ((double) j) / (i+j) * (p[i][j-1]-1));
        }
    }

    printf("%f\n", p[26][26]);
}
