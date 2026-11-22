#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

enum class Light {
    Red,
    Green,
    Yellow
};

struct SignalPhase {
    Light light;
    const char* name;
    const char* instruction;
    int durationSeconds;
};

void displaySignal(Light activeLight)
{
    const char* red = activeLight == Light::Red ? "[*] RED" : "[ ] RED";
    const char* yellow = activeLight == Light::Yellow ? "[*] YELLOW" : "[ ] YELLOW";
    const char* green = activeLight == Light::Green ? "[*] GREEN" : "[ ] GREEN";

    std::cout << "\n+----------------+\n"
              << "| " << std::left << std::setw(12) << red << " |\n"
              << "| " << std::left << std::setw(12) << yellow << " |\n"
              << "| " << std::left << std::setw(12) << green << " |\n"
              << "+----------------+\n";
}

int main()
{
    int cycles;

    std::cout << "How many signal cycles should run? ";
    if (!(std::cin >> cycles) || cycles < 1) {
        std::cerr << "Please enter a positive whole number.\n";
        return 1;
    }

    const SignalPhase phases[] = {
        {Light::Red, "RED", "STOP", 10},
        {Light::Green, "GREEN", "GO", 10},
        {Light::Yellow, "YELLOW", "SLOW DOWN", 3}
    };

    for (int cycle = 1; cycle <= cycles; ++cycle) {
        std::cout << "\nCycle " << cycle << " of " << cycles << '\n';

        for (const SignalPhase& phase : phases) {
            displaySignal(phase.light);
            std::cout << phase.name << " - " << phase.instruction
                      << " (" << phase.durationSeconds << " seconds)\n";
            std::this_thread::sleep_for(
                std::chrono::seconds(phase.durationSeconds));
        }
    }

    std::cout << "\nSimulation finished.\n";
    return 0;
}
