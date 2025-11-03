# LVGL ported to STM32MP135F-DK

## Overview

The STM32MP series of processors are MPUs with MMUs capable of running
Linux. The STM32MP135F-DK is a devkit for the 1 GHz Cortex-A7 STM32MP135F MPU. It has a display
and lots of high-level IO such as four USB ports and dual ethernet ports. The external SDRAM chip
on the board is 512 MB.

## Buy

You can purchase a STM32MP135F-DK from https://www.st.com/en/microcontrollers-microprocessors/stm32mp135f.html.

## Benchmark

<!-- <a href="https://www.youtube.com/watch?v=XXXXXXXXXXXXXXXXXXXXXXX">
    <img src="https://github.com/user-attachments/assets/87c1f2e5-0260-4772-b711-13fdab467474" width="75%">
</a> -->

Software rendering using the double-buffered direct LTDC driver.

| Name                      | Avg. CPU | Avg. FPS | Avg. time | render time | flush time |
| :------------------------ | -------: | -------: | --------: | ----------: | ---------: |
| Empty screen              | 50%      | 54       | 9         | 1           | 8          |
| Moving wallpaper          | 48%      | 56       | 7         | 1           | 6          |
| Single rectangle          | 36%      | 59       | 5         | 0           | 5          |
| Multiple rectangles       | 63%      | 56       | 9         | 0           | 9          |
| Multiple RGB images       | 45%      | 57       | 7         | 0           | 7          |
| Multiple ARGB images      | 54%      | 54       | 9         | 1           | 8          |
| Rotated ARGB images       | 42%      | 53       | 8         | 2           | 6          |
| Multiple labels           | 64%      | 53       | 12        | 1           | 11         |
| Screen sized text         | 63%      | 60       | 9         | 6           | 3          |
| Multiple arcs             | 43%      | 59       | 6         | 0           | 6          |
| Containers                | 19%      | 53       | 8         | 1           | 7          |
| Containers with overlay   | 63%      | 60       | 10        | 4           | 6          |
| Containers with opa       | 24%      | 53       | 7         | 1           | 6          |
| Containers with opa_layer | 26%      | 50       | 11        | 4           | 7          |
| Containers with scrolling | 27%      | 60       | 3         | 3           | 0          |
| Widgets demo              | 61%      | 49       | 8         | 3           | 5          |
| All scenes avg.           | 45%      | 55       | 7         | 1           | 6          |

## Specification

### CPU and Memory
- **CPU:** ARM Cortex-A7
- **RAM:** 168 KB internal SRAM, 512 MB external SDRAM
- **Flash:** Micro SD Card

### Display and Touch
- **Resolution:** 480x272
- **Display Size:** 4.3"
- **Interface:** RGB
- **Color Depth:** 16-bit
- **Technology:** LCD
- **DPI:** 128 px/inch
- **Touch Pad:** Capacitive

### Connectivity
- 4x USB
- 2x ethernet
- Camera module
- WiFi
- Bluetooth
- USB Type-C

## Getting started

### Hardware setup
- You will need two USB Type-C cables. Only one
  needs to be data capable.
- Install a Micro SD Card in the slot. Only a very small
  capacity is needed as the binary is under 2 MB in size.

### Software setup
- Install STM32CubeIDE. It can be downloaded
[from here](https://www.st.com/en/development-tools/stm32cubeide.html).
- Ensure Python is available on your system.

### Run the project
1.  Clone this repo and the LVGL submodule.
    ```shell
    git clone --recursive https://github.com/lvgl/lv_port_stm32mp135f_disco_bm.git
    ```
2.  Open the project with STM32CubeIDE.
3.  Build the project by clicking the hammer icon.
4.  While powered-off, set the four switches on the board to the "OPEN" position.
5.  Connect first the USB C port labeled CN7 and then the USB C port labeled
    CN12 (aka PWR_IN).
6.  In a terminal, change the directory to `Binary` and run `Program_lv_port_stm32mp135_bm.sh`
    (`.bat` on Windows).
    ```shell
    cd Binary
    ./Program_lv_port_stm32mp135_bm.sh
    ```
    You will be prompted to choose a "layout" to flash.
    ```
    Flashing the device 000080183031510A30333432
    1) FlashLayout_lv_port_stm32mp135_deleteall.tsv
    2) FlashLayout_lv_port_stm32mp135_bm.tsv
    Which layout do you want to flash ?
    ```
    Enter `1` and press enter. Wait for it to finish.
7.  Press the black RESET button, B5.
8.  Repeat step 6 but choose `2` this time.
9.  Unplug both USBs.
10. Set the switches to 1:up, 2:down(OPEN), 3:up, 4:down(OPEN).
11. Connect the CN12 (aka PWR_IN) USB and the LVGL app should run.

### Debugging

You can launch debugging in STM32CubeIDE by clicking the "bug" icon.

## Contribution and Support

If you find any issues with the development board feel free to open an Issue in this repository. For LVGL related issues (features, bugs, etc) please use the main [lvgl repository](https://github.com/lvgl/lvgl).

If you found a bug and found a solution too please send a Pull request. If you are new to Pull requests refer to [Our Guide](https://docs.lvgl.io/master/CONTRIBUTING.html#pull-request) to learn the basics.

