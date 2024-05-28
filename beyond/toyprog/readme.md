# Toy programmable calculator/computer

Goal: to create a minimal computing device not unlike programmable calculators or early computers that could be built by a single person and "bootstrapped" using simplest technologies possible.

Therefore:
* Small number of components is preferable
  * That likely means 1-bit/serial processor
  * Only a small amount of register memory will be available
* The lowest common denomiator for the component might not be solid-state
  * RAM and program storage could be implemented using magnetic tapes or drums, delay lines, or even punched tapes
  * Logic elements might be implemented using not only 74xx or transistors, but also valves or relays
* Application areas are going to be very limited
  * Solving some math or science problems? Probably yes.
  * Word processing? Probably not.
  * Batch processing for finances? Maybe.
* Input/output is going to be quite limited
  * IC-based programming calculators were fast enough to allow for interative games, but relay or valve ones are likely to be too slow
  * Early word processors were working on architectures similar in complexity, so maybe it is possible, after all.
  * CRT displays or printers are complicated to make, some simpler output devices will need to be used

## Stage 1: conceptual simulator using high level programming languages
Goal: figure out the command system, expected performance and complexity for the computer.

Starting assumptions:
* A program supplied from a switchboard "ROM", or other type of memory emulating such a ROM.
  * It is conceivable to load the program from magnetic or punch tape into program RAM, but it is impractical to run from tape - if the instruction width is 24 bits, and the tape can reliably provide 2400 bits per second, it will become the bottleneck in machine's speed.
* Registers stored on a magnetic drum, delay line or perhaps core memory. Again, it can be simulated using other types of memory.
* RAM, if any, stored on a magnetic drum, magnetic disk or core memory.
* Data input and output can be done through tapes; likely separate tapes for simplicity.

For the sake of simplicity, let's say:
* the RAM is limited to 8 registers. Reasoning: early programmable calculators had only that much RAM
* the program can have up to 32 steps. Reasoning:  Casio AL-1000 had only 30 program steps (though, arguably, it had more advanced command system than this project)
  * Note: Ferranti Mark 1 had 8 * 64 words of memory (512 words, or 10kB), shared between the program and the data.
  * Note: ZX-80 could run with 1024 * 8 bits of RAM, shared between the program and the data, but the CPU had a much advanced instruction set, allowing for more complex programs to be stored in less space.
* the command set must fit into the power of 2, and include 
  * IN reg - loading from tape
  * OUT reg - output to tape
  * LDA reg - move register to accumulator
  * STA reg - move accumulator to register
  * NOR reg - NOR of register and accumulator
  * SUB reg - R0 = R0 - R1; sets the carry flag
  * JCC reg - jump to address from the register if carry is set (clears the carry flag)
  * [reserved for extensions, used for STOP command for now]

That means, the commmand ROM is 3 bits of commands + 3 bits of register addresses. Input tape will need to have "constants" loaded at the beginning of the program.

The width of the register is not that important for a 1-bit CPU (it will just limit the ops/second). If it is going to be transistored RAM, then 12 bits * 8 registers * 2 transistors per register = 192 transistors already will be a lot. But for magnetic drum memory, it should be relatively easy to store 16, 24 or even 48 bits (providing there are that many magnetic heads). For the sake of the exploration, let's go for 16 bits.


