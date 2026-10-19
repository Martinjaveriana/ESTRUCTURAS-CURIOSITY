# Curiosity Rover Simulator

A command-line simulator of the interaction between NASA's **Curiosity** rover and its mission control center, written in C++20. It was built as the course project for **Data Structures** (*Estructuras de Datos*) at Pontificia Universidad Javeriana, Department of Systems Engineering.

The program works like a small interactive shell. You can load or create movement and analysis commands for the rover, register points of interest found on the Martian surface, simulate where the rover ends up, run spatial queries over the terrain, and build a map of connected points of interest.

## Features

The project was delivered in three stages, each built on a different data structure:

| Stage | Data structure | What it enables |
|-------|----------------|-----------------|
| 1 | `std::queue`, `std::vector`, polymorphic commands | Load, add, save and simulate movement/analysis commands; manage points of interest |
| 2 | **KD-tree** (2-D, custom) | Place points of interest in a spatial index and query which ones fall inside a rectangular quadrant |
| 3 | **Weighted graph** (custom, adjacency lists) + **Dijkstra** | Build a map that connects each point to its nearest neighbors, and find the two points that are farthest apart along the map |

## Building

**Requirements:** a C++20 compiler (GCC or Clang). CMake is optional.

### With g++ directly

The project is header-based (`.h` + `.hxx`), so there is only one translation unit to compile:

```bash
g++ -std=c++20 -I. interfazUsuario.cxx -o curiosity
./curiosity
```

### With CMake

```bash
cmake -S . -B build
cmake --build build
./build/Proyecto_Curiosity
```

> `CMakeLists.txt` currently asks for `cmake_minimum_required(VERSION 4.2)`. If you have an older CMake, lower that number (C++20 support only needs CMake 3.12 or later).

## Usage

When you start the program it shows a `$` prompt. Type `ayuda` to list all commands and `salir` to exit. If you call a command with the wrong number of arguments, the program prints its syntax and a description.

### Command reference

| Command | Description |
|---------|-------------|
| `ayuda` | Show all available commands. |
| `cargar_comandos <file>` | Load movement and analysis commands from a file (replaces the current ones). |
| `cargar_elementos <file>` | Load points of interest from a file (replaces the current ones). |
| `agregar_movimiento <type> <magnitude> <unit>` | Add a movement command. `type`: `avanzar` (move forward) or `girar` (turn). `unit`: `cm`, `dm`, `m`, `km` for moving; `grd` (degrees) or `rad` for turning. |
| `agregar_analisis <type> <object> ['comment']` | Add an analysis command. `type`: `fotografiar` (photograph), `composicion` (composition) or `perforar` (drill). The comment is optional and goes in single quotes. |
| `agregar_elemento <type> <size> <unit> <x> <y>` | Add a point of interest. `type`: `roca` (rock), `crater`, `monticulo` (mound) or `duna` (dune). `unit`: `cm`, `dm`, `m`, `km`. |
| `guardar <comandos\|elementos> <file>` | Save the current commands or points of interest to a file. |
| `simular_comandos <x> <y>` | Simulate the movement commands from the starting position `(x, y)` and print the final position. |
| `ubicar_elementos` | Insert the points of interest into the KD-tree. You must run this before `en_cuadrante`. |
| `en_cuadrante <x_min> <x_max> <y_min> <y_max>` | List the points of interest inside the given rectangle. |
| `crear_mapa <coefficient>` | Build the graph: each point is connected to its `n × coefficient` nearest neighbors, where `n` is the number of points and the edge weight is the Euclidean distance. |
| `ruta_mas_larga` | Using the map, find the two points whose shortest path between them is the longest of all, and print that path. |
| `salir` | Exit the program. |

### Simulation rules

The rover starts facing the positive x-axis. Positive turn angles rotate it counter-clockwise and negative angles rotate it clockwise. Distances are converted to meters before the new position is computed.

### File formats

**Commands file**: one command per line, without the `agregar_*` prefix:

```text
avanzar 10 m
girar 90 grd
avanzar 250 cm
fotografiar roca_1 'sample near the crater'
perforar duna_2
```

**Points of interest file**: one point per line, as `type size unit x y`:

```text
roca 2.5 m 0 0
crater 12 m 3 4
duna 1 km 10 0
monticulo 30 dm -5 7
```

Lines that are empty are skipped. Lines that are invalid are reported and skipped.

### Example session

```text
$ agregar_elemento roca 2 m 0 0
Info: El elemento ha sido agregado exitosamente
$ agregar_elemento crater 5 m 3 4
Info: El elemento ha sido agregado exitosamente
$ agregar_elemento duna 1 m 10 0
Info: El elemento ha sido agregado exitosamente
$ crear_mapa 0.5
El mapa se ha generado exitosamente. Cada elemento tiene 1 vecinos
$ ruta_mas_larga
Los puntos de interés más alejados entre sí son:
tipo: duna   tamaño: 1   unidad: m   coordenada x:10   coordenada y: 0
y
tipo: roca   tamaño: 2   unidad: m   coordenada x:0    coordenada y: 0

La ruta que los conecta tiene una longitud total de 13.0623 y pasa por los siguentes elementos:
...
```

> The program's output messages are in Spanish.

## Project structure

| File(s) | Purpose |
|---------|---------|
| `interfazUsuario.cxx` | Entry point: the interactive shell that reads input and dispatches commands. |
| `Curiosity.h/.hxx` | Main class. Holds the command queue, the points of interest, the KD-tree and the graph, and implements every shell command. |
| `Comando.h/.hxx` | Base class for rover commands. |
| `CMovimiento.h/.hxx` | Movement command (`avanzar` / `girar`, magnitude, unit). |
| `CAnalisis.h/.hxx` | Analysis command (type, object, comment). |
| `Elemento.h/.hxx` | Point of interest (type, size, unit, x, y) and Euclidean distance between points. |
| `KDTree.h/.hxx`, `NodoKD.h/.hxx` | 2-D KD-tree that alternates between x and y at each level. It supports insert, delete, search, traversals and range (quadrant) queries. |
| `Grafo.h/.hxx` | Generic weighted directed graph `Grafo<V, C>` with DFS, BFS, Dijkstra and path reconstruction. |
| `Utilities.h/.hxx` | Input tokenizer, regex-based validators, unit conversion and help messages. |
| `enunciado.pdf` | Original assignment statement (Spanish). |
| `Entrega 3 Murcia-Sanmiguel-Gonzales.pdf` | Report for the third delivery (Spanish). |

## Authors

- Ana María Murcia
- Martín David Sanmiguel
- Alejandro González Ochoa

Pontificia Universidad Javeriana, Data Structures, 2026.
