### from ICs to AI Accelerators

Deep learning frameworks are still evolving, making it hard to design custom hardware.  Reconfigurable devices such as field-programmable gate arrays (FPGA) make it easier to evolve hardware, frameworks and software alongside each other. In order to design robust hardware, a certain level of knowledge is necessary-- ranging from undergrad elements of CS to embedded systems and definitely Deep Learning . It is becoming harder to find people who understand the full stack from a first principles theory. 
This is a  micro curriculum that I have designed which will help you understand the system stack starting from the Building Block of ICs to AI Accelerators from a first Principles Perspective.

*Note:- This is in NO way complete. I will keep updating this repo*

#### Transistors and Digital Logic
- Building block of ICs. Learn about Transistors- Follow the Book by Sedra-Smith on Microelectronic Circuits. BJT, FETs, Power Transistors . Some basic Circuit Theory:- Divide it into sub-chapters. [IC design wiki](https://en.wikipedia.org/wiki/Integrated_circuit_design).
- Sequential and Combinational Circuits. Synchronous, Asynchronous, Register Transfer level, Introduction to VLSI design, Verilog and VHDL.

#### Microprocessors and Microcontrollers
- 8051 
- 8085, 8086 - Basics, Instruction cycle
- AVR Family :- Arduino, some basic projects like LCD controller, Servo Motors, Sensors etc.
- PIC Family:- Some background knowledge.

#### FPGAs
1) Talk about how FPGAs are Built - An FPGA from 7400s. The most basic building block of an FPGA is the Cell, or Slice. Talk about Programmable LUTs.
- [Build Your Own FPGA](http://blog.notdot.net/2012/10/Build-your-own-FPGA)
- [Internal Functionality of FPGA look Up tables](https://www.allaboutcircuits.com/technical-articles/purpose-and-internal-functionality-of-fpga-look-up-tables/)
Getting Started with FPGAs- https://www.allaboutcircuits.com/technical-articles/getting-started-with-fpgas-look-up-tables-and-flip-flops/
2) [5 easy steps to Building an Embedded Processor System inside an FPGA](https://www.youtube.com/watch?v=xlKoDRCziIg)
Designing an FPGA from Scratch 38 part Tutorial:- Writing a Software device driver and an application program to run on the system. Pick out a suitable development Board.- [Designing an FPGA from SCratch](https://www.eetimes.com/how-to-design-an-fpga-from-scratch/#)
3) [All about FPGAs](https://allaboutfpga.com/)
4) How to Get started with FPGA programming ?
[What is FPGA programming ?](https://www.fpga4student.com/2017/08/what-is-fpga-programming.html)

 - Digital Logic Design- Combinational and sequencial Circuits.
 - Verilog/VHDL language
 - Simulation - Modelsim
 - Synthesis and Implementation
Xilinx ISE desisn Suite:- [Xilinx ISE](https://www.xilinx.com/products/design-tools/ise-design-suite.html)

#### ARM Architecture 
- Read about RISC Architectures - [RISC Wiki](https://en.wikipedia.org/wiki/Reduced_instruction_set_computer)
- Learn about ARM organisation. ARM core dataflow model. 3 stage and 5 stage pipeline. ARM 7 and ARM 9. Explaining Pipelining in ARM Processors.

#### ARM CPU
- ARM Assembly basics Tutorial Series:- [Writing ARM Assembly](https://azeria-labs.com/writing-arm-assembly-part-1/)
Learn about the Assembly language, data types and addressing modes. A good reading source would be from Computer Organization and
Architecture by William Stallings. 32- Bit ARM and 16 -Bit Thumb instruction set.
- ARM Assembly Language.
- ARM Datatypes
- ARM Addressing Modes
- ARM Instruction Formats. 
- ARM Processor/ also cores.
  - ARM Cortex M
  - ARM Cortex A

#### ARM Operating System. 
- Operating System Overview
  - Scheduling.
- Memory Management
  - Translation Lookaside Buffers
- ARM Memory Management:- [Developer ARM :- Learn the Architecture](https://developer.arm.com/architectures/learn-the-architecture). Download the full tutorial pdf.
- ARM Linux distributions:-[Linux ARM distros](https://www.linux.com/training-tutorials/4-fine-linux-arm-distros/), 
(ARM Linux Distributions wiki)[https://en.wikipedia.org/wiki/Category:ARM_Linux_distributions]
- Building an MMU(Verilog, 1000):- ARM9, explain TLBs and other fun things. Maybe also a memory controller, depending on how the FPGA is, then add the init code to your bootloader.

### Building an ARM7 CPU, Coding a BootROM, Coding an Assembler.

- Coding an assembler:-  write in python. Happens in parallel with the CPU building. Initially outputs just binary files, but changed when you write a linker.
- Building a ARM7 CPU(Verilog, 1500):- Break this into subchapters. A simple pipeline to start, decode, fetch, execute.
- Coding a bootrom(Assembler, 40) - *from geohotz*
Memory Management Unit - wiki.
https://developer.arm.com/architectures/learn-the-architecture/memory-management/the-memory-management-unit-mmu

- [Write your own OS](http://mikeos.sourceforge.net/write-your-own-os.html)
- https://medium.com/@g33konaut/writing-an-x86-hello-world-boot-loader-with-assembly-3e4c5bdd96cf
- Bootloader in C:- https://www.codeproject.com/Articles/664165/Writing-a-boot-loader-in-Assembly-and-C-Part

#### Compiler Design
- Read the Compiler Design Tutorial by Tutorials Point. (Tutorials Point Compiler Design)[https://www.tutorialspoint.com/compiler_design/compiler_design_overview.htm]
- Write a Compiler in Haskell. [learn Haskell](http://learnyouahaskell.com/)- Covers the Basics of Compilers.
- Tutorial for implementation of functional languages - https://www.microsoft.com/en-us/research/uploads/prod/1992/01/tutor.pdf
- Write a C compiler - https://github.com/nlsandler/write_a_c_compiler, https://norasandler.com/2017/11/29/Write-a-Compiler.html
- Haskell C Compiler - https://github.com/NunoDasNeves/haskell-c-compiler
- Implementing a JIT Compiled Language with Haskell and LLVM. [LLVM Tutorial](http://www.stephendiehl.com/llvm/#chapter-1-introduction)
A JIT compiler runs after the program has started and compiles the code (usually bytecode or some kind of VM instructions) on the
fly (or just-in-time, as it's called) into a form that's usually faster, typically the host CPU's native instruction set.
A JIT has access to dynamic runtime information whereas a standard compiler doesn't and can make better optimizations like 
inlining functions that are used frequently.This is in contrast to a traditional compiler that compiles all the code to machine 
language before the program is first run.

- Optimizing a Compiler -  Ycombinator:- https://news.ycombinator.com/item?id=15821899

#### System on Chip (SoC)
Needed for System On Chip design for ASICs.

- [SoC wiki](https://en.wikipedia.org/wiki/System_on_a_chip)
- SoC Design Methodology , Overview of the SOC Design Process.
- Canonical SoC Design, System Design Flow,  System Architecture, Components of the system, Hardware & Software, Processor Architectures, System Architecture and Complexity. Parameterized Systems-on-a-Chip ,  System-on-a-chip Peripheral Cores.
-  Overview of SOC external memory, Internal Memory, Size, Cache memory, Cache Organization, Cache data. Types of Cache:- Split Level Caches, Multi Level Cache. SOC Memory System .
- SoC Notes:- [SOC Notes](https://www.cl.cam.ac.uk/teaching/1011/SysOnChip/socdam-notes1011.pdf)

#### Peripheral Devices
- Buffers and latches, Crystal, Reset circuit, Chip select logic circuit, timers and counters.Universal  asynchronous  receiver,  transmitter  (UART),  Pulse  width  modulators.
- Building a UART(Verilog, 100):- An intro chapter to Verilog, copy a real UART, introducing the concept of MMIO. Serial test echo program and led control. Software Serial arduino.cc
- [Implementing a UART in Verilog and Migen](https://lab.whitequark.org/notes/2016-10-18/implementing-an-uart-in-verilog-and-migen/)
- [UART, Serial Port, RS-232 Interface](https://www.nandland.com/vhdl/modules/module-uart-serial-port-rs232.html)


#### Understanding Memory
- Semiconductor Main Memory :- SRAM , DRAM, Chip Logic. Flash Memory:- NOR, NAND flash Memory, External Memory
- DDR DRAM :- DDR SDRAM 

####  Understanding AI Accelerators
- [Tutorial on Hardware accelerators for DNNs](http://eyeriss.mit.edu/tutorial.html)
- [FPGA-based Accelerators of Deep Learning Networks for Learning and Classification: A Review](https://arxiv.org/pdf/1901.00121.pdf)

### Jetson Nano Developer's Kit
Basically a Raspberry Pi on Steroids.
- Jetson Nano embedded Technical Specifications- https://developer.nvidia.com/embedded/develop/hardware
- Jetson nano DL Benchmarks:- https://developer.nvidia.com/embedded/jetson-nano-dl-inference-benchmarks
- Jetson nano Developer's Kit:- https://developer.nvidia.com/embedded/jetson-nano-developer-kit

#### Google TPU
- What is a Tensor Processing Unit ? RISC, CISC , TPU instruction set , the TPU. GPU vs TPU. Matrix Multiplying Unit (MMU). Parallel Processing on Matrix Multiplying Unit. Why Matrix Multiplication ? . Matrix Machine. Systolic Array - 1) Cycle 1 and Cycle 2. Use cases of TPU. 
- [Edge TPU performance benchmarks](https://coral.ai/docs/edgetpu/benchmarks/)
- [Tensorflow Models on the Edge TPU](https://coral.ai/docs/edgetpu/models-intro/#compatibility-overview)
- Implement a Multilayer perceptron for image classification using the CIFAR Dataset (GPU vs TPU).
- [A Survey of Accelerator Architectures for Deep Neural Networks](https://www.sciencedirect.com/science/article/pii/S2095809919306356)
