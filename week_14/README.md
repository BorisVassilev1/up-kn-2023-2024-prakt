# Седмица 15: Работа с файлове

### Задача 1
Напишете програма, която създава файл с името "test.txt" и записва "Hello World!!" във него.

### Задача 2
Напишете програма, която прочита файл с името "test.txt" и извежда съдържанието му на стандартния изход.

### Задача 3
Напишете функция, която приема име на файл и връща указател към динамично заделен масив от цели числа. Първите 8 байта на файла са броя цели числа, записани вътре, а остатъка от файла съдържа поредица от точно толкова 4-байтови цели числа. Тествайте функцията си с файла "array.bin"

### Задача 4
Напишете функция, която записва масив от цели числа във текстов файл, чието име получава като артумент. Информацията да се записва във файла във формата от предната задача.

### Задача 5
Нека имаме дефинирана структурата:
```cpp
struct Point {float x, y; };
```
Напишете програма, която прочита масив от точки от файла "points.bin" (първите 8 бита отново съдържат броя точки), прочита от стандартния вход число `n` и координатите на `n` на брой точки и записва сортираната (по сбор от координатите) поредица от всички точки обратно във файла.

### Задача 6
Напишете програма, която прочита поредица от низове от бинарния файл "strings.bin", в който отделните низове са разделени със символа 'EOT' (вижте ascii-таблицата), и ги извежда на стандартния изход.

### Задача 7
Напишете програма, която приема на стандартния вход 4 дробни числа $x_1$, $y_1$, $x_2$, $y_2$ и извежда на стандартния изход броя на точките във файла `points.bin`, чиито координати са съответно в интервалите $[x_1, x_2]$ и $[y_1, y_2]$.
