#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n; // liczba bloków
    cin >> n;

    int widths[n]; //szerokości bloków - niepotrzebne
    int heights[n]; // wysokości bloków
    for (int i = 0; i < n; ++i) // czytanie wartości
    {
        cin >> widths[i];
        cin >> heights[i];
    }

    stack<int> stack_of_buildings; // stos przechowujący bloki
    int minimum_number_of_posters = 0; // liczba potrzebnych plakatów

    for (int i = 0; i < n; ++i) //implementacja pseudoalgorytmu
    {
        while (!stack_of_buildings.empty() && heights[stack_of_buildings.top()] > heights[i])
        {
            stack_of_buildings.pop();
        }

        if (stack_of_buildings.empty() || heights[i] > heights[stack_of_buildings.top()])
        {
            stack_of_buildings.push(i);
            ++minimum_number_of_posters;
        }
    }

    cout << minimum_number_of_posters << endl;

    return 0;
}