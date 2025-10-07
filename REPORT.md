# 🧩 LS Command Clone — Programming Assignment 02

### 🎓 Course: Operating Systems  
**Instructor:** Dr. Muhammad Arif Butt  
**Student:** Muhammad Mujtaba  
**Roll No:** BSDSF23A026
**Section:** Afternoon  
**Version:** v1.6.0 (Recursive Listing)

---

## 📘 Overview

This project is a **C implementation of the UNIX `ls` command**, built step-by-step through multiple feature versions as part of an Operating Systems course.  
Each version adds functionality such as long listing, column display, colorized output, and recursive traversal.

The goal is to understand **file system operations, directory handling, and system calls** in Linux.

---

## ⚙️ Features Implemented

| Version | Feature | Description |
|----------|----------|-------------|
| **v1.0.0** | Basic Listing | Lists files in the current directory |
| **v1.1.0** | `-l` Long Listing | Shows detailed file info (permissions, owner, size, time) |
| **v1.2.0** | Column Display | Prints filenames in multiple aligned columns |
| **v1.3.0** | `-x` Horizontal Layout | Lists files across rows instead of columns |
| **v1.4.0** | Alphabetical Sort | Sorts entries alphabetically (case-insensitive) |
| **v1.5.0** | Colorized Output | Adds colors for directories, executables, and symlinks |
| **v1.6.0** | `-R` Recursive Listing | Recursively lists all subdirectories |

---

## 🧠 System Calls and Concepts Used

- **opendir(), readdir(), closedir()** → Directory traversal  
- **stat(), lstat()** → File info retrieval  
- **getpwuid(), getgrgid()** → Owner/group lookup  
- **strftime()** → Time formatting  
- **qsort() with strcasecmp()** → Alphabetical sorting  
- **ioctl()** → Terminal width detection  
- **ANSI color codes** → Colorized output  
- **getopt()** → Command-line option parsing  
- **Recursion** → Directory traversal for `-R`

---

## 🏗️ Project Structure

ROLLNO-OS-A02/
├── src/
│   └── ls-v1.6.0.c
├── obj/
│   └── ls-v1.6.0.o
├── bin/
│   └── ls
├── man/
├── Makefile
├── REPORT.md
└── README.md

---

## 🧩 Build Instructions

### 🛠️ Compile
make

### 🧹 Clean Build Files
make clean

### 🚀 Run
./bin/ls

---

## 🧪 Usage Examples

| Command | Description |
|----------|-------------|
| `./bin/ls` | Default multi-column output |
| `./bin/ls -l` | Long listing with file details |
| `./bin/ls -x` | Horizontal display layout |
| `./bin/ls -R` | Recursive directory listing |
| `./bin/ls -lR` | Long + Recursive |
| `./bin/ls -xR` | Horizontal + Recursive |

---

## 🎨 Color Legend

| File Type | Color | Example |
|------------|--------|----------|
| Directory | **Blue** | 📁 Folder |
| Executable | **Green** | ⚙️ run.sh |
| Symbolic Link | **Cyan** | 🔗 shortcut |
| Regular File | Default | 📄 text.txt |

---

## 🧰 Dependencies
This project uses only **standard C libraries** available on any Linux system:
- `<dirent.h>`
- `<sys/stat.h>`
- `<pwd.h>`
- `<grp.h>`
- `<time.h>`
- `<unistd.h>`
- `<getopt.h>`
- `<sys/ioctl.h>`

No external libraries are required.

---

## 🧾 Git & Versioning Workflow

Each feature was developed on a separate branch and merged into `main` with tags:

| Tag | Description |
|------|--------------|
| `v1.0.0` | Basic Listing |
| `v1.1.0` | Long Listing |
| `v1.2.0` | Column Display |
| `v1.3.0` | Horizontal Layout |
| `v1.4.0` | Alphabetical Sort |
| `v1.5.0` | Colorized Output |
| `v1.6.0` | Recursive Listing |

To view a specific version:
git checkout v1.4.0
