# Ex08 — add_chelou.sh

## 🎯 Objective

The goal of this exercise is to add `$FT_NBR1` and `$FT_NBR2`.

The two numbers use a special character mapping instead of normal
decimal digits.

The result must be converted through different number bases and then
translated back into the required character system.

---

## 📂 File

```text
ex08/
└── add_chelou.sh
```

The script starts with:

```bash
#!/bin/sh
```

---

## 🔧 Final Script

```bash
#!/bin/sh
printf '%s + %s' "$FT_NBR1" "$FT_NBR2" |
tr "'\"?!mrdoc\\\\" "0234012341" |
xargs echo "obase=13;ibase=5;" |
bc |
tr "0123456789ABC" "gtaio luSnemf"
```

---

# 🔎 Step by Step

## 1. `printf`

```bash
printf '%s + %s' "$FT_NBR1" "$FT_NBR2"
```

Takes the two environment variables and creates an addition:

```text
FT_NBR1 + FT_NBR2
```

`%s` means a string.

The pipe `|` sends this result to the next command.

---

## 2. First `tr`

```bash
tr "'\"?!mrdoc\\\\" "0234012341"
```

`tr` is used to translate characters.

The first character set:

```text
' " ? ! m r d o c \ \
```

is mapped to:

```text
0 2 3 4 0 1 2 3 4 1
```

The important idea is:

```text
special characters
        ↓
normal digits
```

This converts the special representation of the numbers into digits
that can be processed by `bc`.

---

## 3. `xargs`

```bash
xargs echo "obase=13;ibase=5;"
```

This prepares the input for `bc`.

It adds:

```text
obase=13;
ibase=5;
```

### `ibase`

```text
ibase=5
```

Means the input numbers are interpreted in **base 5**.

### `obase`

```text
obase=13
```

Means the result is displayed in **base 13**.

So the calculation is:

```text
base 5
   ↓
   bc
   ↓
base 13
```

---

## 4. `bc`

```bash
bc
```

`bc` performs the arithmetic operation.

At this point it receives something similar to:

```text
obase=13;ibase=5;NUMBER1 + NUMBER2
```

It calculates the sum using the requested bases.

---

## 5. Final `tr`

```bash
tr "0123456789ABC" "gtaio luSnemf"
```

The result from base 13 contains:

```text
0 1 2 3 4 5 6 7 8 9 A B C
```

The final `tr` maps these characters to the required character system:

```text
0 → g
1 → t
2 → a
3 → i
4 → o
5 → space
6 → l
7 → u
8 → S
9 → n
A → e
B → m
C → f
```

So:

```text
base 13 result
      ↓
   final tr
      ↓
required output
```

---

# 🔗 Understanding the Pipe

The symbol:

```bash
|
```

sends the output of one command to the next command.

The complete flow is:

```text
$FT_NBR1 + $FT_NBR2
        ↓
      printf
        ↓
   first character
      mapping
        ↓
      xargs
        ↓
   ibase=5 / obase=13
        ↓
       bc
        ↓
    base 13 result
        ↓
   final character
      mapping
        ↓
     final output
```

---

# 🧠 Commands to Remember

| Command | Purpose |
|---|---|
| `printf` | Format and print text |
| `tr` | Translate characters |
| `xargs` | Build/execute a command from input |
| `bc` | Perform arithmetic and base conversion |
| `\|` | Send output to the next command |

---

# 🔢 Number Bases

The important part of the exercise is:

```text
ibase=5
obase=13
```

Remember:

```text
ibase → input base
obase → output base
```

So:

```text
input
  ↓
base 5
  ↓
  bc
  ↓
base 13
  ↓
final tr
```

---

# 🔄 Rebuild the Script

If you forget the complete solution, rebuild it in this order:

```bash
printf '%s + %s' "$FT_NBR1" "$FT_NBR2"
```

↓

```bash
printf '%s + %s' "$FT_NBR1" "$FT_NBR2" | tr "'\"?!mrdoc\\\\" "0234012341"
```

↓

```bash
printf '%s + %s' "$FT_NBR1" "$FT_NBR2" | tr "'\"?!mrdoc\\\\" "0234012341" | xargs echo "obase=13;ibase=5;"
```

↓

```bash
printf '%s + %s' "$FT_NBR1" "$FT_NBR2" | tr "'\"?!mrdoc\\\\" "0234012341" | xargs echo "obase=13;ibase=5;" | bc
```

↓

```bash
printf '%s + %s' "$FT_NBR1" "$FT_NBR2" | tr "'\"?!mrdoc\\\\" "0234012341" | xargs echo "obase=13;ibase=5;" | bc | tr "0123456789ABC" "gtaio luSnemf"
```

---

# 💡 Revision

Do not memorize the whole command as one block.

Remember the chain:

```text
printf
  ↓
tr → special characters → digits
  ↓
xargs → prepare bc
  ↓
bc → base 5 → base 13
  ↓
tr → base 13 characters → required characters
```

The three main concepts are:

```text
1. Pipes
2. Character translation with tr
3. Number-base conversion with bc
```

---

# ✅ Final Reminder

The most important commands to remember for this exercise are:

```bash
printf
tr
xargs
bc
```

And the most important `bc` concepts are:

```text
ibase = input base
obase = output base
```

Final script:

```bash
#!/bin/sh
printf '%s + %s' "$FT_NBR1" "$FT_NBR2" |
tr "'\"?!mrdoc\\\\" "0234012341" |
xargs echo "obase=13;ibase=5;" |
bc |
tr "0123456789ABC" "gtaio luSnemf"
```
