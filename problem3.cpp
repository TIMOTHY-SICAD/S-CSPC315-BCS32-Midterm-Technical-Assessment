#include <iostream>
using namespace std;

// Sort packages with source, destination, and buffer zone via Tower of Hanoi solution
int movePackages(int N, int steps, string source, string destination, string buffer)
{
    if (N == 0) // Base case
        return steps;

    steps = movePackages(N - 1, steps, source, buffer, destination); // O(n)
    steps++; // Increment counter for number of moves made
    cout << "Step " << steps <<": Moved Package " << N << " from Location " << source << " to Location " << destination << endl; // O(1)
    steps = movePackages(N - 1, steps, buffer, destination, source); // O(n)

    return steps;
} // O(n) * O(1) * O(n)
// = O(n^2)

int main() {
    // Initialize variables
    int N;
    int steps = 0;

    // Get user input for N
    cout << "Please enter number of Packages in Location A to be moved to Location C: ";
    cin >> N;
    cout << endl;

    // Call function
    steps = movePackages(N, steps, "A", "C", "B");
    cout << endl;

    // Display number of moves required
    cout << "Total number of moves required for given N (" << N << "): " << steps;

    return 0;
}