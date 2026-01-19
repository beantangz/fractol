# fract-ol

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/fract-ole.png" alt="Fract'ol fract-ol 42 project badge"/>
</p>

## Description

**fract-ol** is a project from the **42 school common core**.  
Its goal is to create a **graphical fractal renderer** in **C**, using the **MLX42** graphical library.

The program displays famous fractals such as **Mandelbrot** and **Julia**, with real-time interaction (zoom, movement, etc.).

This project focuses on:
- **Complex numbers**
- **Mathematical iterations**
- **Graphical programming**
- **Keyboard and mouse event handling**


## Preview

### mandelbrot
<img width="1911" height="1082" alt="Screenshot from 2026-01-19 09-59-05" src="https://github.com/user-attachments/assets/8e1f6911-eb71-4da6-96c2-052af0de0794" />

### julia 1
<img width="906" height="991" alt="Screenshot from 2026-01-19 09-59-49" src="https://github.com/user-attachments/assets/a931885f-dba7-4239-8b3c-e04a7f8d321b" />

### julia 2
<img width="1369" height="1068" alt="Screenshot from 2026-01-19 10-00-40" src="https://github.com/user-attachments/assets/64b00c61-4529-4e26-b885-17dd6c204f54" />

## Implemented Fractals

### Mandelbrot
- Generated from the iterative formula: zₙ₊₁ = zₙ² + c
- Each pixel represents a complex number `c`
- The color depends on how fast the sequence diverges


### Julia
- Uses the same formula as Mandelbrot
- The value of `c` is constant and varies depending on the selected set
- Two different Julia sets are implemented

## Install 
1. clone the repository
2. make
3. Run the executable with the appropriate arguments to select and customize the fractal you wish to render :
 - Mandelbrot:
```
./fractol mandelbrot
```

- julia 1:
```
./fractol julia 1
```

- julia 2:
```
./fractol julia 2
```

## Controls
General Controls
   - ESC: Exit the program
   - W, A, S, D: Move the view within the window
   - Mouse Scroll: Zoom in/out

## Author
mleineku
42 School Student

## License 
This project is open-source and intended for educational and personal use.
