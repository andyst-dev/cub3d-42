# cub3d

A small raycasting-based 3D game developed as part of the 42 curriculum.
This project consists of parsing a `.cub` scene description, validating textures, colors, and map layout, then rendering a first-person view of the maze with MiniLibX using a classic raycasting approach.

`cub3d` was designed to strengthen core C skills around parsing, 2D-to-3D projection, event handling, graphics programming, and state-driven game loops.

## Features
- Raycasting-based first-person rendering
- Parsing and validation of `.cub` configuration files
- Wall textures for the four cardinal directions
- Floor and ceiling color configuration
- Keyboard-based movement and rotation
- Optional bonus features such as a minimap, mouse rotation, and a start menu

## Project structure
- `includes/cub3d.h` — main header file, structures, constants, and function prototypes
- `srcs/parsing/` — `.cub` file parsing, texture/color loading, and map validation
- `srcs/raycasting/` — ray setup, DDA calculations, wall distance computation, and rendering
- `srcs/player/` — player initialization, movement, keyboard handling, and rotation
- `srcs/bonus/` — bonus minimap and mouse rotation support
- `assets/` — textures and menu assets
- `maps/` — valid and invalid `.cub` test maps
- `includes/libft/` — local libft used by the project
- `minilibx_macos/` — macOS version of MiniLibX bundled with the repository
- `Makefile` — builds the `cub3D` executable

## Mandatory part
The mandatory part implements a simple Wolfenstein-like renderer based on a valid `.cub` scene description.

### Program
- `cub3D` — loads a `.cub` file, validates the scene, opens a window, and renders the world from the player point of view

### Core behavior
- parses the scene file and checks the `.cub` extension
- loads texture paths for `NO`, `SO`, `WE`, and `EA`
- parses floor and ceiling colors
- validates the map structure and starting player position
- renders walls with a raycasting loop
- allows movement with `W`, `A`, `S`, and `D`
- allows rotation with the arrow keys
- closes cleanly through the escape key or window close event

### What happens at runtime
- the program parses the `.cub` configuration file and validates its content
- it initializes the player state, raycasting data, textures, and MiniLibX context
- a window and image buffer are created for rendering
- the game loop casts one ray per screen column to detect wall intersections
- wall slices are drawn according to distance and texture sampling
- player movement and rotation update the view in real time

### Subject requirements to respect
- the map must be parsed from a valid `.cub` file
- textures and colors must be defined correctly before the map
- the map must be closed and contain exactly one player start
- movement must respect wall collisions
- rendering must use MiniLibX
- the program must handle invalid input cleanly and avoid crashes

## Bonus part
This repository also includes bonus-oriented files for:
- a minimap
- mouse-based rotation
- a simple start menu

The core of the project remains the mandatory raycasting engine and map parsing workflow.

## Notes
This repository comes from a collaborative 42 project built with [GxLuck02](https://github.com/GxLuck02).

My parts in this project mainly cover the rendering and interaction side of the program.
In practical terms, this includes:
- building the raycasting pipeline
- handling player controls, movement, and rotation
- initializing wall textures
- adding the mouse rotation bonus

The raycasting part is especially central in `cub3d`: the program casts one ray per vertical screen column from the player position into the 2D map, detects where each ray hits a wall, measures the distance to that wall, and then draws a vertical slice with the correct height and texture.
By repeating this process for the whole screen at each frame, the map stays 2D internally, but the player gets a convincing first-person view with depth, direction changes, and real-time movement.

This project was developed on macOS and the repository is currently configured for the macOS version of MiniLibX.
The provided build setup therefore targets macOS first, and no Linux-specific adaptation is included in this repository.

## Build
Build the project:

```bash
make
```

Build the bonus version:

```bash
make bonus
```

Clean object files:

```bash
make clean
```

Remove object files and executable:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

## Output
The project builds one executable:

```bash
cub3D
```

## Usage
Run the program with a valid map file:

```bash
./cub3D maps/map1.cub
```

## Learning outcomes
This project was an introduction to basic 3D rendering techniques in C.
It helped build solid foundations in:
- file parsing and validation
- grid-based raycasting
- DDA traversal
- texture mapping
- input and movement handling
- MiniLibX rendering workflows
