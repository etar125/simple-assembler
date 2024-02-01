# Simple Assembler
*A personal project via which I aim to learn a bit about assembly by programming an interpretive implementation of select opcode mnemonics.*

**This fork is designed for implement all planned instructions.**

### Implemented Instructions
* ✔ `mov x y` **Mov**e the contents of register `y` into register `x` (`x = y`)
* ✔ `inc x` **Inc**rement register `x` by one (`x++`)
* ✔ `dec x` **Dec**rement register `x` by one (`x--`)
* ✔ `add x y` **Add** the contents of register `y` to `x` (`x += y`)
* ✔ `sub x y` **Sub**tract the contents of register `y` from `x` (`x -= y`)
* ✔ `mul x y` **Mul**tiply the contents of register `x` and `y`, store result in `x` (`x **= y`)
* ✔ `div x y` Integer **div**ide the contents of register `x` by `y`, store result in `x` (`x /= y`)


* ✔ `jnz lbl` **J**ump to `lbl` if register `x` is **N**ot **Z**ero
* ✔ `;` Comment, ignored by the interpreter

* ✔ `label:` Define a position within the code reachable by the `label` identifier
* ✔ `cmp x y` **C**o**MP**are the contents of registers `x` and `y` (result used by other instructions)
* ✔ `jne lbl` **J**ump to the label `lbl` if the values of the previous `cmp` were **N**ot **E**qual
* ✔ `je lbl` **J**ump to the label `lbl` if the values of the previous `cmp` were **E**qual
* ✔ `jmp lbl` **J**u**mp** to the label `lbl`

* ✔ `jge lbl` **J**ump to the label `lbl` if register `x` was **G**reater than or **E**qual to `y` in the previous `cmp`
* ✔ `jg lbl` **J**ump to the label `lbl` if register `x` was **G**reater than `y` in the previous `cmp`
* ✔ `jle lbl` **J**ump to the label `lbl` if register `x` was **L**esser than or **E**qual to `y` in the previous `cmp`
* ✔ `jl lbl` **J**ump to the label `lbl` if register `x` was **L**esser than `y` in the previous `cmp`
* ✔ `nop` **N**o **OP**eration, ignored by the interpreter

### Planned
* ✘ `call lbl` Procedure **call** to the subroutine identified by the label `lbl`
* ✘ `ret` **Ret**urn to the instruction that called the current subroutine

* ✘ The ability to run other code

### Further Instructions
Reference: [Intel 80x86 ASM Opcodes](http://www.mathemainzel.info/files/x86asmref.html)
