<div align="center">

# 🧮 APC — Arbitrary Precision Calculator

**Crunch numbers bigger than `long long` can dream of — no limits, no overflow.**

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Data%20Structure](https://img.shields.io/badge/data%20structure-Doubly%20Linked%20List-orange.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

</div>

---

## 📖 About

**APC (Arbitrary Precision Calculator)** is a command-line calculator written in pure C that performs **addition, subtraction, multiplication, and division on integers of *any* size** — far beyond the 64-bit limits of native C data types.

Instead of relying on `int` or `long long`, APC stores every digit of a number as a node in a **doubly linked list**. This lets it add, subtract, multiply, and divide numbers that are hundreds (or thousands) of digits long, with zero overflow — the same trick used under the hood by cryptography libraries and big-number math engines.

> Think of it as a mini `BigInteger` / `bignum` library, built from scratch in C — digit by digit, node by node.

---

## ✨ Features

| Feature | Description |
|---|---|
| ➕ **Addition** | Add two arbitrarily large numbers |
| ➖ **Subtraction** | Subtract with automatic sign handling (`5 - 15 = -10`) |
| ✖️ **Multiplication** | Multiply large numbers digit-by-digit |
| ➗ **Division** | Divide arbitrarily large numbers |
| 🔢 **No overflow** | Numbers are limited only by available memory, not by data type size |
| 🧹 **Auto-cleanup** | Leading zeros are stripped automatically (`0002` → `2`) |
| 🧠 **Smart sign handling** | Correctly detects and applies `+` / `-` prefixes on operands |
| 🧼 **Memory-safe** | All dynamically allocated nodes are freed after use — no memory leaks |
| ✅ **Input validation** | Rejects malformed commands with a helpful usage message |

---

## 🏗️ How It Works

Every number is represented as a **doubly linked list**, where **each node stores a single digit**:

```
Number: 9 8 5 2
         |  |  |  |
 head → [9]↔[8]↔[5]↔[2] ← tail
```

* The **head** points to the most significant digit.
* The **tail** points to the least significant digit.
* Arithmetic operations traverse the list from the **tail** (like doing math on paper — right to left), just like you'd add numbers by hand, carrying digits as you go.

This design means APC isn't just "using big libraries" — it implements the actual grade-school arithmetic algorithms (carry propagation, borrow handling, long multiplication, long division) manually on a custom data structure.

### Project Structure

```
APC/
├── main.c     → Driver function: parses CLI args, dispatches operation
├── apc.c      → Core logic (may hold shared helpers)
├── apc.h      → Struct definitions, function prototypes, macros
├── add.c      → Addition logic
├── sub.c      → Subtraction logic
├── mul.c      → Multiplication logic
├── div.c      → Division logic
└── README.md  → You're here!
```

---

## ⚙️ Installation & Build

### Prerequisites
* A C compiler (`gcc`, `clang`, or MSVC)
* Any OS — Linux, macOS, or Windows (via WSL / MinGW)

### Clone the repository

```bash
git clone https://github.com/Manju735/APC.git
cd APC
```

### Compile

```bash
gcc main.c apc.c add.c sub.c mul.c div.c -o apc
```

This produces an executable named `apc` (or `apc.exe` on Windows).

---

## 🚀 Usage

APC runs directly from the command line in the form:

```bash
./apc <operand1> <operator> <operand2>
```

| Operator | Meaning |
|:---:|---|
| `+` | Addition |
| `-` | Subtraction |
| `x` or `X` | Multiplication |
| `/` | Division |

### Examples

```bash
$ ./apc 123456789123456789 + 987654321987654321
Result : 1111111111111111110

$ ./apc 1000000000000000000 - 1
Result : 999999999999999999

$ ./apc 99999999999999999999 x 99999999999999999999
Result : 9999999999999999999800000000000000000001

$ ./apc 5 - 15
Result : -10

$ ./apc 0002 + 0003
Result : 5
```

> 💡 Notice the second-to-last example: numbers **59 digits long** multiplied together — something a standard `int`/`long` could never hold. That's the entire point of APC.

---

## 🧠 Key Concepts Demonstrated

This project is a great showcase of core Data Structures & C fundamentals:

- ✅ Dynamic memory management (`malloc` / `free`)
- ✅ Doubly linked list construction & traversal
- ✅ Command-line argument parsing & validation
- ✅ Digit-by-digit arithmetic algorithms (carry / borrow logic)
- ✅ Sign and edge-case handling (equal operands, negative results, leading zeros)
- ✅ Clean modular C code — one responsibility per file

---

## 🛣️ Roadmap

- [ ] Add support for decimal (floating-point) precision
- [ ] Add exponentiation (`^`) and modulus (`%`) operators
- [ ] Interactive REPL mode (instead of one-shot CLI args)
- [ ] Unit tests for each operation
- [ ] Benchmark against GMP (GNU Multiple Precision library)

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

1. Fork the repo
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

---

## 👤 Author

**Manjunatha H**
🔗 [GitHub @Manju735](https://github.com/Manju735)

---

## 📄 License

This project is open-sourced under the [MIT License](LICENSE).

---

<div align="center">

⭐ **If you found this project interesting, consider giving it a star!** ⭐

</div>
