# minitalk
Create a client/server program in C that can send strings through UNIX signals.

## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Build Instructions](#build-instructions)
- [Usage](#usage)

## Overview

*The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.* (extract from subject)

- [Subject](./subject_en.pdf)
- Mark: 125/100

## Installation

### Prerequisites

- GCC compiler

### Build Instructions

1. Clone the repository:
   ```sh
   git clone https://github.com/BWG31/minitalk
2. Compile the executables:
    ```sh
    make
## Usage
 - In one terminal window, launch the server:
    ```sh
    ./server
    # The server will display it's process ID (PID) on the STD output
 - In another terminal window, connect with a client and send a string:
    ```sh
    ./client <server PID> <string>
 - The server should display the received string on the STD output.
 - The server can be stopped with CTL + C