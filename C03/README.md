# C03 - 42 Piscine

## 📖 Overview

C03 is about **string manipulation** in C.

A string is an array of characters that always ends with the null terminator:

```c
'\0'
```

Example:

```
H e l l o \0
```

---

# Functions

## ex00 - ft_strcmp

### Purpose
Compare two strings character by character.

### Return

- `0` → Strings are equal.
- `< 0` → First string is smaller.
- `> 0` → First string is greater.

Example:

```c
ft_strcmp("abc", "abc");
```

Returns:

```
0
```

---

## ex01 - ft_strncmp

### Purpose

Compare only the first **n** characters of two strings.

Example:

```c
ft_strncmp("abcdef", "abcxyz", 3);
```

Returns:

```
0
```

Because only the first three characters are compared.

---

## ex02 - ft_strcat

### Purpose

Append the source string (`src`) to the end of the destination string (`dest`).

Example:

```
hello
+
world
=
helloworld
```

---

## ex03 - ft_strncat

### Purpose

Append only the first **n** characters of `src` to `dest`.

Example:

```
hello
+
world
n = 3

Result:

hellowor
```

---

## ex04 - ft_strstr

### Purpose

Search for a substring inside another string.

Example:

```
String:

Hello World
```

Search:

```
World
```

Returns a pointer to:

```
World
```

If the substring is not found:

```
NULL
```

---

## ex05 - ft_strlcat

### Purpose

Append `src` to `dest` **without exceeding the destination buffer size**.

It always keeps space for the null terminator (`'\0'`).

Return value:

```
length(dest) + length(src)
```

---

# Important Concepts

- Strings end with `'\0'`.
- Never write outside the buffer.
- Understand pointers (`char *`).
- Understand the return value of each function.

---

# Summary

| Function | Description |
|----------|-------------|
| ft_strcmp | Compare two strings |
| ft_strncmp | Compare the first n characters |
| ft_strcat | Append one string to another |
| ft_strncat | Append only n characters |
| ft_strstr | Search for a substring |
| ft_strlcat | Append safely using the buffer size |

---

# Keywords

- String
- Character
- Pointer
- Buffer
- Length
- Compare
- Append
- Search
- Substring
- Null terminator (`'\0'`)

---

# What I Learned

- How strings are stored in memory.
- How to compare strings.
- How to concatenate strings.
- How to search inside strings.
- How to work safely with buffers.
- How to manipulate pointers and character arrays.

---

**Author:** Houssam Oubaha  
**Project:** 42 Piscine - C03
