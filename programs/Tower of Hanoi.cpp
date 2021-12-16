#include <iostream>
#include <utility>
#include <vector>

#include "Timer.h"

// Move n discs from source to dest, assuming that it is possible
// to do so without moving the discs on the 2 rods other than source
// Moves is a list of pairs - Move[i] stores the source and destination
// rod for the ith move
void MoveDisc(int n, int source, int dest, std::vector<std::pair<int, int>>& Moves) {
    if (n == 1) {
        Moves.push_back({source, dest});
        // std::cout << source << " " << dest << "\n";
        return;
    }
    int otherRod = 6 - source - dest;  // whichever of {1,2,3} is not source or dest
    MoveDisc(n - 1, source, otherRod, Moves);
    Moves.push_back({source, dest});
    // std::cout << source << " " << dest << '\n';
    MoveDisc(n - 1, otherRod, dest, Moves);
}

int main() {
    int n, k;
    std::cout << "Enter the number of discs: ";
    std::cin >> n;
    k = (1 << n) - 1;
    std::cout << "The number of moves needed is " << k << std::endl;

    std::vector<std::pair<int, int>> Moves;
    Moves.reserve(k);

    // This is recursive
    MoveDisc(n, 1, 3, Moves);

    std::cout << "\nThe Moves Are:\n";
    for (auto& it : Moves) std::cout << "Move a disc from " << it.first << " to " << it.second << "\n";

    return 0;
}