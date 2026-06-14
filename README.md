# SpendWise-C 💼

SpendWise-C is a lightweight, terminal-based financial logging utility written in standard C. I built this over a single session lasting 3 hours and 17 minutes to practice manual file tracking, structure formatting, and console menu boundaries. 

The application provides a quick, local framework to log income, track daily debits, and review your balance history directly from the terminal.

## Tech Stack
- **Language:** Core C
- **Compiler:** GCC
- **Core Libraries:** `stdio.h`, `stdlib.h`, `string.h`

## How It Works Under the Hood

The application relies on direct structural mapping and local flat-file storage to stay lightweight and fast:

1. **Structural Data Mapping:** The project uses a custom `struct` array to format and manage transaction metadata, processing cash floats, category labels, and entry timestamps inside a unified memory block.

2. **Persistent File Streams:** Instead of wiping data when the console closes, the logic implements standard file operations (`fopen`, `fprintf`, `fscanf`). Every transaction is appended instantly to a local text-based storage file, which is loaded back into memory the next time the executable runs.

3. **Arithmetic Summarization:** Linear arithmetic loops handle balance calculations. When you request a summary, the program runs through the active file entries, computes total spend vs. total income, and formats a clean breakdown table directly in the console output.

4. **Menu Control Flow:** A continuous `switch-case` block drives the terminal UI. It contains validation checks to catch incorrect numeric inputs (like inputting text where a balance float is expected) to avoid core segmentation faults.

## How to Compile and Run Locally

Ensure you have a standard C compiler like GCC installed on your system path.

1. Clone the repository workspace:
   ```bash
   git clone [https://github.com/YOUR_GITHUB_USERNAME/SpendWise-C.git](https://github.com/YOUR_GITHUB_USERNAME/SpendWise-C.git)
   cd SpendWise-C
