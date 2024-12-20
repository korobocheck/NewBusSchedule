# Bus Schedules

##
Repository and Code Quality

Project Repository: https://github.com/korobocheck/BusSchedule

SonarCloud Code Quality: https://sonarcloud.io/summary/new_code?id=korobocheck_BusSchedule

    
**Bus Schedules** is a command-line interface (CLI) program that allows users to manage bus schedules using dynamic memory allocation. This system supports basic CRUD operations and validates input fields like the bus number.

## Features:
- **Add, View, Update, and Delete** bus schedules.
- **Bus number validation** (must start with a digit, allows alphanumeric).
- Database for storing schedules.


## Prerequisites:
- **C++17** or later.
- **Make** utility for building the project.

## Build Instructions:
1. Clone the repository to your local machine: ```bash git clone https://github.com/your-repo/Bus_Schedules.git cd Bus_Schedules ```

2. Build the project: ```bash make ```

3. Run the program: ```bash ./bin/bus_schedule_manager ```

## Usage Example:
```bash Bus Schedule Management System 1. Add new schedule 2. View schedule 3. Update schedule 4. Delete schedule 5. Exit Enter your choice: 1 Enter Bus Number: 123A Enter Destination: Central Station Schedule added successfully! ```

## Makefile Targets:
- `make` : Compile the project.
- `make clean` : Remove object files and binaries.

## Code Style:
The project follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) and the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).

## License:
This project is licensed under the MIT License.
