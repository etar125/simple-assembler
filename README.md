# Simple Assembler
*A personal project via which I aim to learn a bit about assembly by programming an interpretive implementation of select opcode mnemonics.* 

**Данный форк сделан для того, чтобы реализовать всё планированное**

Пример кода:
```
; jump to main
jmp main
; a * b function
do_magic:
mul a b
ret
; main
main:
mov a 12
mov b 5
call do_magic
```

### Реализованные инструкции
* ✔ `mov x y` Перемещает содержимое регистра `y` в регистр `x` (`x = y`)
* ✔ `inc x` Увеличевает регистр `x` на один (`x++`)
* ✔ `dec x` Увеличевает регистр `x` на один (`x--`)
* ✔ `add x y` Прибавляет содержимое регистра `y` к регистру `x` (`x += y`)
* ✔ `sub x y` Вычитает содержимое регистра `y` из регистра `x` (`x -= y`)
* ✔ `mul x y` Перемножает содержимое регистров `x` и `y`, кладя результат в регистр `x` (`x **= y`)
* ✔ `div x y` Делит регистр `x` на `y`, кладя результат в регистр `x` (`x /= y`)


* ✔ `jnz lbl` Переходит к метке `lbl` если содержимое регистра `x` не равно нулю
* ✔ `;` Комментарий, игнорируется интерпретатором

* ✔ `label:` Метка
* ✔ `cmp x y` Сверяет содержимое регистров `x` и `y` (результат используется другими инструкциями)
* ✔ `jne lbl` Переходит к метке `lbl` если результат предыдущего `cmp` равен "Не равны"
* ✔ `je lbl` Переходит к метке `lbl` если результат предыдущего `cmp` равен "Равны"
* ✔ `jmp lbl` Переходит к метке `lbl`

* ✔ `jge lbl` Переходит к метке `lbl` если результат предыдущего `cmp` равен "Больше" или "Равны"
* ✔ `jg lbl` Переходит к метке `lbl` если результат предыдущего `cmp` равен "Больше"
* ✔ `jle lbl` Переходит к метке `lbl` если результат предыдущего `cmp` равен "Меньше" или "Равны"
* ✔ `jl lbl` Переходит к метке `lbl` если результат предыдущего `cmp` равен "Меньше"
* ✔ `nop` Нет операции, игнорируется интерпретатором

* ✔ `call lbl` Вызывает метку
* ✔ `ret` Возвращается к инструкции, которая вызвала

* ✔ Возможность запускать код

### Запланированное

Ничего
