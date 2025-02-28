#include <iostream>
#include <vector>

using namespace std;


struct Program {
    int startTime;  
    int endTime;     
    int arrivalTime; 
    
    Program(int start, int end, int arrival)
        : startTime(start), endTime(end), arrivalTime(arrival) {}
};


int partition(vector<Program>& programs, int low, int high) {
    int pivot = programs[high].arrivalTime; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
       
        if (programs[j].arrivalTime < pivot) {
            i++;
            swap(programs[i], programs[j]);
        }
    }
    swap(programs[i + 1], programs[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<Program>& programs, int low, int high) {
    if (low < high) {
        int pi = partition(programs, low, high);
        quickSort(programs, low, pi - 1);         
        quickSort(programs, pi + 1, high);       
    }
}


int maxPrograms(vector<Program>& programs) {

    quickSort(programs, 0, programs.size() - 1);

    
    int lastEndTime = 0;
    int count = 0;

    
    for (const auto& program : programs) {
        if (program.arrivalTime >= lastEndTime) {
            count++; 
            lastEndTime = program.endTime; 
        }
    }

    return count;
}

int main() {
    // Number of programs
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
        
        // Create a Program object and add it to the vector
        programs.push_back(Program(start, end, arrival));
    }

    // Find and display the maximum number of programs that can be scheduled
    int result = maxPrograms(programs);
    cout << "Maximum number of programs that can be scheduled: " << result << endl;

    return 0;
}
