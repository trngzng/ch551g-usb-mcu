# About this repository
We have learned the USB MCU CH551G for educational purpose. All our documents, notes and source during the process will be stored here.

# About CH551 USB MCU
This MCU is 8-bit MCU with **built-in** USB device controller from https://www.wch.cn/. It's very cheap (**only 7.000VND - 0.31$**) but we can **directly** download the program by USB interface (*external debugger/programmer is not necessory*).

![alt text](ch551g.png)

# How to use this repository
## Structure
```
+---docs
+---ref
|   \---USB_Relay_HID
\---src
    +---firmware
    \---hardware
```
1. ```docs```: contains the datasheet, notes,...
2. ```ref```: contains the reference documents and repo.
3. ```source```: 
   
   3.1. ```firmware```: contains the programs, examples, libraries,...
  
   3.2. ```hardware```: contains the schematics, PCBs of development kits and application boards.
## How to run the source
### Prerequisition
- Install [sdcc compiler](https://sourceforge.net/projects/sdcc/files/) and <a href="https://gnuwin32.sourceforge.net/packages/make.htm" target="_blank">Makefile</a>.
- Install [WCHISPTool](https://www.wch-ic.com/downloads/WCHISPTool_Setup_exe.html) for programs downloading.
# Contributors
1. Giang Phan Truong
2. Khoa Dong Thanh
3. Tuan Pham Ho Anh