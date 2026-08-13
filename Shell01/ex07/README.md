# Ex07 --- r_dwssap.sh

## 📌 Objective

The goal of this exercise is to process `/etc/passwd` using one command
line.

The operations must be done in the exact order required by the exercise.

The final result uses the environment variables `$FT_LINE1` and
`$FT_LINE2` to select a specific range of lines.

------------------------------------------------------------------------

## 📂 Files

``` text
ex07/
├── r_dwssap.sh
└── README.md
```

-   `r_dwssap.sh` → contains the command.
-   `README.md` → explanation and revision notes.

------------------------------------------------------------------------

## 🔧 Final Command

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | sed 's/$/, /' | sed 's/$/, /' | tr -d '\n'
```

------------------------------------------------------------------------

# 🔎 Step by Step

## 1. Read `/etc/passwd`

``` bash
cat /etc/passwd
```

Displays the contents of `/etc/passwd`.

------------------------------------------------------------------------

## 2. Remove comments

``` bash
grep -v "^#"
```

-   `grep` → searches for matching lines.
-   `-v` → reverses the match.
-   `^#` → lines beginning with `#`.

So it keeps lines that do **not** start with `#`.

------------------------------------------------------------------------

## 3. Keep every second line

``` bash
awk 'NR % 2 == 0'
```

-   `NR` → current line number.
-   `%` → modulo.
-   `NR % 2 == 0` → even lines.

Keeps:

``` text
2
4
6
8
...
```

------------------------------------------------------------------------

## 4. Get the login name

``` bash
cut -d: -f1
```

`/etc/passwd` uses `:` as a separator.

Example:

``` text
user:x:1000:1000:User:/home/user:/bin/bash
```

becomes:

``` text
user
```

-   `-d:` → delimiter is `:`
-   `-f1` → first field

------------------------------------------------------------------------

## 5. Reverse the login

``` bash
rev
```

Example:

``` text
houssam
```

becomes:

``` text
massuoh
```

------------------------------------------------------------------------

## 6. Sort in reverse alphabetical order

``` bash
sort -r
```

-   `sort` → sorts lines.
-   `-r` → reverse order.

------------------------------------------------------------------------

## 7. Select the requested range

``` bash
awk "NR >= $FT_LINE1 && NR <= $FT_LINE2"
```

The exercise provides:

``` bash
$FT_LINE1
$FT_LINE2
```

They define the first and last line to keep.

Example:

``` text
FT_LINE1=3
FT_LINE2=7
```

keeps lines:

``` text
3
4
5
6
7
```

-   `>=` → greater than or equal
-   `<=` → less than or equal
-   `&&` → AND

------------------------------------------------------------------------

## 8. Add `,`

``` bash
sed 's/$/, /'
```

Adds `,` at the end of each line.

Example:

``` text
user1
user2
user3
```

becomes:

``` text
user1, 
user2, 
user3, 
```

The final solution uses this command twice.

------------------------------------------------------------------------

## 9. Remove newlines

``` bash
tr -d '\n'
```

-   `tr` → translates/deletes characters.
-   `-d` → delete.
-   `\n` → newline.

This joins the results into one line.

------------------------------------------------------------------------

# 🔗 Pipes

The symbol:

``` bash
|
```

is called a **pipe**.

It sends the output of one command to the next command.

Example:

``` bash
cat /etc/passwd | grep -v "^#"
```

Flow:

``` text
cat
 ↓
grep
 ↓
output
```

------------------------------------------------------------------------

# 🧠 Complete Pipeline

``` text
/etc/passwd
    ↓
cat
    ↓
remove comments
    ↓
keep even lines
    ↓
get login names
    ↓
reverse login names
    ↓
reverse alphabetical sort
    ↓
keep FT_LINE1 → FT_LINE2
    ↓
add ", "
    ↓
add ", "
    ↓
remove newlines
    ↓
final result
```

------------------------------------------------------------------------

# 🔄 Rebuild the Command

If you forget the final command, rebuild it step by step:

``` bash
cat /etc/passwd
```

↓

``` bash
cat /etc/passwd | grep -v "^#"
```

↓

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0'
```

↓

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1
```

↓

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1 | rev
```

↓

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r
```

↓

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2"
```

↓

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | sed 's/$/, /'
```

↓

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | sed 's/$/, /' | sed 's/$/, /'
```

↓

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | sed 's/$/, /' | sed 's/$/, /' | tr -d '\n'
```

------------------------------------------------------------------------

# 📚 Commands to Remember

  Command     Purpose
  ----------- -----------------------
  `cat`       Display file
  `grep -v`   Remove matching lines
  `awk`       Process/filter lines
  `cut`       Extract fields
  `rev`       Reverse characters
  `sort -r`   Reverse sorting
  `sed`       Modify text
  `tr -d`     Delete characters
  `\|`        Pipe output

------------------------------------------------------------------------

# 🧩 Important Concepts

``` text
grep -v        → inverse match
^              → beginning of line
NR             → current line number in awk
%              → modulo
-d:            → use : as delimiter
-f1            → first field
rev            → reverse characters
sort -r        → reverse sort
$FT_LINE1      → starting line
$FT_LINE2      → ending line
&&             → AND
sed s///       → substitution
tr -d '\n'     → delete newlines
|              → pipe
```

------------------------------------------------------------------------

# 💡 Revision

Do not memorize the whole command as one block.

Remember the order:

``` text
cat
 ↓
grep
 ↓
awk → even lines
 ↓
cut → login
 ↓
rev
 ↓
sort -r
 ↓
awk → range
 ↓
sed
 ↓
sed
 ↓
tr
```

If you remember the order and the purpose of each command, you can
rebuild the complete command during revision or an exam.

------------------------------------------------------------------------

# ✅ Final Reminder

The important idea of Ex07 is **combining simple Unix commands with
pipes**.

Each command performs one small operation, and the output becomes the
input of the next command.

Final command:

``` bash
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | sed 's/$/, /' | sed 's/$/, /' | tr -d '\n'
```
