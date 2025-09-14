# MCU LAB2: Timer Interrupt

## Introduction

I am a student of the Microcontroller course at HCMUT. In this lab, I continued practicing with STM32CubeIDE for embedded development and Proteus for circuit simulation, using the STM32F103C6 microcontroller. Through a new set of exercises, I further developed my skills in writing and debugging code, applying concepts learned in previous labs, and exploring new functionalities as required by the lab instructions.

## Proteus Schematic Image

The schematic below is fully pre-wired and designed to support all exercises in this lab. It provides the necessary connections for the STM32 microcontroller and peripheral components, allowing each exercise to be tested without modifying the circuit. In this lab, the reference voltage is set to 5V instead of 3.3V to ensure proper operation and display for all four 7-segment displays and the LED matrix.
<!-- Replace the link below with your actual schematic image or a relative path to the image in your PROTEUS folder -->
<img width="1734" height="850" alt="image" src="https://github.com/user-attachments/assets/95bb338b-39c9-48e0-964a-0c409c1c5fc8" />

---

## .ioc File Image (STM32CubeMX)

The pin configuration in this .ioc file is set up to support all exercises in the lab. All necessary connections are defined and fully synchronized with the Proteus schematic above, ensuring consistency between the hardware simulation and the project setup.
<!-- Replace the link below with your actual .ioc screenshot or a relative path to the image -->
<img width="699" height="735" alt="image" src="https://github.com/user-attachments/assets/ac7fb4ef-93e3-486c-9e7e-ac31b29b74bd" />


---
## Lab 2 Ideas & Conclusion

The exercises in this lab also focus on controlling GPIO outputs to display various LED animations, but with an upgrade to four 7-segment displays and a LED matrix, making the tasks more advanced than in Lab 1. Instead of using `HAL_Delay`, all timing is handled through timer interrupts. In the later exercises, the structure is further optimized: the timer interrupt handler is used only to call a countdown function, divide time, and set flag variables, while all main operations remain in the main `while` loop. This approach avoids recursive interrupt calls and allows the system timer to be split into multiple software timers for flexible and reusable timing control. Through these exercises, I gained a deeper understanding of using timer interrupts efficiently and structuring embedded code for scalability and reliability.

---

## Source Folder Structure
The main code for each exercise is organized in the `Core/Src/` directory as follows:
```text
Core/
│
├── Src/                        # Main embedded source code
│   ├── ex1.c                   # Exercise 1 implementation
│   ├── ex2.c                   # Exercise 2 implementation
│   ├── ex3_4.c                 # Shared implementation for exercises 3 and 4
│   ├── ex5_6.c                 # Shared implementation for exercises 5 and 6
│   ├── ex7_8.c                 # Shared implementation for exercises 7 and 8
│   ├── ex9.c                   # Exercise 9 implementation
│   ├── ex10.c                  # Exercise 10 implementation
│   ├── software_timer.c        # Common software timer module
│   ├── display7SEG.c           # Common 7-segment display module
│   ├── main.c                  # Entry point, macro to select exercise
│   ├── stm32f1xx_hal_msp.c     # HAL MSP init
│   ├── stm32f1xx_it.c          # Interrupt handlers
│   ├── syscalls.c              # System call stubs
│   ├── sysmem.c                # System memory allocation
│   └── system_stm32f1xx.c      # System clock/config
│
├── Inc/                        # Header files for each exercise and main
│   ├── ex1.h
│   ├── ex2.h
│   ├── ex3_4.h                 # Shared header for exercises 3 and 4
│   ├── ex5_6.h                 # Shared header for exercises 5 and 6   
│   ├── ex7_8.h                 # Shared header for exercises 7 and 8
│   ├── ex9.h
│   ├── ex10.h
│   ├── software_timer.h        # Common software timer header
│   ├── display7SEG.h           # Common 7-segment display header
│   ├── main.h
│   ├── stm32f1xx_hal_conf.h
│   └── stm32f1xx_it.h
│
└── Startup/
    └── startup_stm32f103c6ux.s   # Startup assembly code
```
**Explanation:**

- Each exercise is implemented in its own `.c` file (e.g., `ex1.c`, `ex2.c`, ...), with a corresponding header file in `Inc/` (e.g., `ex1.h`, `ex2.h`, ...). This makes it easy for instructors to review and grade each solution separately.
- In this lab, some exercises are small and closely related, so they are combined into a single `.c` and `.h` file (such as `ex3_4.c`/`.h` for exercises 3 and 4, `ex5_6.c`/`.h` for exercises 5 and 6, and `ex7_8.c`/`.h` for exercises 7 and 8).
- Some common functional modules that are used frequently throughout the lab are separated into their own files, such as `software_timer.c`/`.h` and `display7SEG.c`/`.h`.
- Some files are included and connected as needed, but all exercises are ultimately linked through `main.c`.
- The use of macros in `main.c` allows for easy switching between exercises for demonstration and clarity during class presentations.
---
## Explanation for `software_timer.c` / `.h`

This is the most important new functional module in this lab. The module manages an array of `software_timer` structs and provides three main functions:

- `void timerSet(int idx, int counter)`: Sets the countdown value and resets the flag for the specified software timer.
- `void timerRun()`: The only function called inside the system timer interrupt. Each time it is called, it decrements the countdown of every software timer in the array. When a timer reaches zero, its flag is set.
- `int timerFlag(int idx)`: Checks and returns the flag status of the specified timer, making it easy to use in other functions or main code.

All three functions operate on the timers in the array by looping through them with a `for` loop. This design allows for flexible, reusable, and non-blocking timing control throughout the lab.

---
## How to Build & Run Each Exercise

- Each exercise (`ex1` to `ex10`) is selected via a macro in the `main.c` file.
- To run the desired exercise:
  1. Open the file `Core/Src/main.c`.
  2. Several `#define` lines are already provided for each exercise. Simply **uncomment** the line for the exercise you want to demo, and make sure all other exercise defines are commented out.
     ```c
     // #define ex1
     // #define ex2
     #define ex3_4   // ← Uncomment this line to run exercise 3 and 4
     // #define ex5_6
     // ...
     ```
  3. After building, update the path to the generated `.hex` file in your Proteus simulation to match the new build output.
  4. Rebuild the project and flash it to the board or load the `.hex` file into Proteus.
  5. **Note:** Since the code may use shared resources (e.g., `HAL_Delay`, pins, LEDs) for demo purposes, only run one exercise at a time (i.e., only one `#define` should be active before building) to ensure correct operation.  
   However, for exercise 10, thanks to the use of timer interrupts and software timers, it is possible to run all functionalities from exercises 1 to 10 simultaneously. If you want to test all features at once (e.g., LED blinking, digital clock, moving character 'A' on the LED matrix), simply define and run the demo for lab10.
