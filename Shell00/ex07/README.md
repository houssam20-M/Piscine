# Ex07 — diff

## 📌 Objective

The goal of this exercise is to create a file called `b` and use the `diff` command to compare it with the given file `a`.

The exercise introduces the idea of comparing two files and generating a **diff file** containing the changes between them.

The subject also points to the `patch` command, which can be used to apply those changes.

---

## 📂 Files

```text
ex07/
├── a
├── b
└── sw.diff
```

* `a` → original file provided by the exercise.
* `b` → modified version created for the exercise.
* `sw.diff` → contains the differences between `a` and `b`.

---

## 🔧 Commands

### 1. Check the original file

```bash
cat -e a
```

This displays the content of `a` and `$` shows the end of each line.

---

### 2. Check file `b`

```bash
cat -e b
```

This allows us to verify the content and line endings of `b`.

---

### 3. Create the diff

```bash
diff a b > sw.diff
```

This compares `a` with `b`.

Instead of displaying the result directly in the terminal, `>` redirects the output into `sw.diff`.

So:

```text
a + diff → sw.diff
```

---

### 4. Read the diff

```bash
cat -e sw.diff
```

This displays the differences between the two files.

For example:

```text
1,2c1,3
```

means that lines `1` to `2` from `a` are changed to lines `1` to `3` from `b`.

Other important symbols:

```text
c = change
d = delete
a = add
```

---

## 🩹 Using patch

The exercise also refers to `patch`.

A patch can apply the changes contained in a diff file to another file.

For example, to avoid modifying the original `a`, first create a copy:

```bash
cp a test
```

Then apply the diff:

```bash
patch test < sw.diff
```

Finally, compare the result with `b`:

```bash
diff test b
```

If nothing is displayed, `test` and `b` are identical.

---

## 🧠 Concept

The main idea is:

```text
       diff
a  ───────────►  sw.diff
                  │
                  │ patch
                  ▼
                  b
```

`diff` finds the differences between two files.

`patch` applies a diff to a file.

---

## ✅ Commands to remember

```bash
cat -e a
cat -e b
diff a b > sw.diff
cat -e sw.diff
cp a test
patch test < sw.diff
diff test b
```

### 💡 Important

Be careful when using:

```bash
patch a sw.diff
```

because this modifies `a` directly.

Using:

```bash
cp a test
patch test < sw.diff
```

is safer when practicing.

