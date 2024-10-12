#include <iostream>
#include <cmath>
using namespace std; 

// Function to calculate distance
double calculateDistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Function to calculate the sum of first N natural numbers
int calculateSum(int n) { 
    int sum = 0; 
    for (int i = 1; i <= n; i++) 
        sum = sum + i;

    return sum; 
} 

// Main
int main() {
    // Initialize variables to be used
    int N;

    double x1;
    double y1;

    double x2;
    double y2;

    double distance_sum = 0;
    double distance_current;

    cout << "Enter how many Points to be traveled: ";
    cin >> N; // Get N from user input
    cout << endl;

    cout << "Enter x coordinate of Point 1: ";
    cin >> x1; // Get x1 from user input

    cout << "Enter y coordinate of Point 1: ";
    cin >> y1; //Get y1 from user input
    cout << endl;

    for (int i = 1; i < N; i++) {
        cout << "Enter x coorindate of Point " << i + 1 << ": ";
        cin >> x2; // Get x2 from user input

        cout << "Enter y coordinate of Point " << i + 1 << ": ";
        cin >> y2; // Get y2 from user input
        cout << endl;

        distance_current = calculateDistance(x1, y1, x2, y2); // Calculate distance from coordinates
        distance_sum = distance_sum + distance_current; // Add distance to ongoing sum

        // Display current coordinates
        cout << "Point " << i << ": " << x1 << ", " << y1 << endl;
        cout << "Point " << i + 1 << ": " << x2 << ", " << y2 << endl;
        cout << endl;

        // Display current travel values
        cout << "Distance between Point " << i << " and Point " << i + 1 << ": " << distance_current << endl;
        cout << "Distance traveled so far: " << distance_sum << endl;
        cout << endl;

        // Target point becomes current point
        x1 = x2;
        y1 = y2;
    }

    // Print total distance traveled, as well as the sum of the first N natural numbers
    cout << "Total distance traveled: " << distance_sum << endl;
    cout << "Additionally, here is the sum of the first N (" << N << ") natural numbers: " << calculateSum(N) << endl;

    return 0;
}
