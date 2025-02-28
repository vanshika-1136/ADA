#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a program's details
struct Program {
    int startTime;   // Starting time of the program
    int endTime;     // Ending time of the program
    int arrivalTime; // Arrival time of the program
    int duration;    // Duration of the program (endTime - startTime)
    
    // Constructor to calculate the duration
    Program(int start, int end, int arrival)
        : startTime(start), endTime(end), arrivalTime(arrival), duration(end - start) {}
};

// Partition function for Quick Sort
int partition(vector<Program>& programs, int low, int high) {
    int pivot = programs[high].duration; // Pivot is the duration (endTime - startTime) of the last program
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // If current program's duration is smaller than the pivot, swap
        if (programs[j].duration < pivot) {
            i++;
            swap(programs[i], programs[j]);
        }
    }

    // Swap the pivot element with the element at i+1
    swap(programs[i + 1], programs[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<Program>& programs, int low, int high) {
    if (low < high) {
        int pi = partition(programs, low, high); // Find the pivot index
        quickSort(programs, low, pi - 1);         // Recursively sort the left part
        quickSort(programs, pi + 1, high);        // Recursively sort the right part
    }
}

// Function to find the maximum number of programs that can be scheduled
int maxPrograms(vector<Program>& programs) {
    // Sort the programs by their duration (Shortest Job First)
    quickSort(programs, 0, programs.size() - 1);

    // Variable to track the end time of the last selected program
    int lastEndTime = 0;
    int count = 0;

    // Process each program, respecting the arrival time and the shortest duration
    for (const auto& program : programs) {
        if (program.arrivalTime >= lastEndTime) { 
            count++; 
            lastEndTime = program.endTime; 
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter number of programs: ";
    cin >> n;

    vector<Program> programs;

    // Input the details of the programs
    cout << "Enter the start time, end time, and arrival time for each program:\n";
    for (int i = 0; i < n; i++) {
        int start, end, arrival;
        cout << "Program " << i + 1 << ":\n";
        cout << "Start time: ";
        cin >> start;
        cout << "End time: ";
        cin >> end;
        cout << "Arrival time: ";
        cin >> arrival;
        
        
        programs.push_back(Program(start, end, arrival));
    }

    
    int result = maxPrograms(programs);
    cout << "Maximum number of programs that can be scheduled: " << result << endl;

    return 0;
}

   
