# Philosopher Project

Welcome to the Philosopher Project! This README will guide you through the setup, usage, and understanding of the project.

## Overview

The Philosopher Project simulates the classic "Dining Philosophers Problem." In this problem, philosophers alternate between thinking, eating, and sleeping. The challenge is to prevent deadlock and starvation while ensuring proper synchronization and timing.

## Requirements

- GCC or any other C compiler
- POSIX threads library

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/philosopher.git
    cd philosopher
    ```

2. Compile the project:
    ```sh
    make
    ```

## Usage

Run the executable with the following parameters:
```sh
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]
```

## Exemple
```sh
./philo 4 310 200 100
```

## Philosopher States 
Philosophers can be in one of the following states:
- EATING
- SLEEPING
- THINKING
Each state has specific actions and timing associated with it, managed by the respective functions.

