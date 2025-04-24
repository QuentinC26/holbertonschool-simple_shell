
# .C - Simple Shell

## 📚 Description

This project is a **Unix command line interpreter**, or simple shell, written in C as part of the Holberton School low-level programming curriculum.  
It aims to recreate basic behavior of a shell such as `/bin/sh`, including executing commands and handling built-ins like `exit` and `env`.

---

## 🚀 Features

- Display a prompt and wait for user input
- Execute commands with arguments
- Handle commands found in the `PATH`
- Support for interactive and non-interactive modes
- Handle built-ins:
  - `exit`: exits the shell
  - `env`: prints current environment variables
- Error handling: command not found, memory errors, fork failures, etc.

---

## ❗ Requirements

### ✅ Allowed System Calls

- `access`
- `chdir`
- `close`
- `execve`
- `exit`, `_exit`
- `fork`
- `free`
- `getcwd`
- `getline`
- `isatty`
- `malloc`
- `open`
- `perror`
- `read`
- `signal`
- `stat`
- `wait`
- `write`
- etc.

### ✅ Code Standards

- Code must follow **Betty style**
- **No memory leaks allowed**
- Maximum **5 functions per file**
- **No use of global variables**
- Header files must be **include guarded**

## ✅ Tasks Implemented

- `README`, `AUTHORS`, and man page
- Betty-compliant code
- **Simple shell 0.1**: basic execution
- **Simple shell 0.2**: with arguments
- **Simple shell 0.3**: handle `PATH`
- **Simple shell 0.4**: `exit` built-in
- **Simple shell 1.0**: `env` built-in


## Installation

Clone this repository into your local environment :
```bash
git clone https://github.com/QuentinC26/holbertonschool-simple_shell.git
```
- Then navigate to the project folder :
```bash
cd holbertonschool-simple_shell
```

## 🔧 Compilation

The shell is compiled using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
- Exécutez ensuite le programme compilé :
```bash
./hsh
```

## 💻 Usage

### Interactive Mode

```javascript

$ ./hsh
($) ls -l
total 0
-rw-r--r-- 1 user user 0 Apr 13 17:35 file1
($) exit

```
### Non-Interactive Mode


```javascript

$ echo "ls -l" | ./hsh
total 0
-rw-r--r-- 1 user user 0 Apr 13 17:35 file1

```

## 🧠 Flowchart (Overview)

### The operation of the shell can be summarized as follows :
- file:///C:/Users/firei/Downloads/Flowchart%20of%20Simple%20Shell.drawio.svg

## 📁 Project Structure

```javascript

.
├── AUTHORS
├── README.md
├── man_1_simple_shell
├── shell.h
├── main.c
├── prompt.c
├── exec_cmd.c
├── read_line.c
├── utils.c
├── path_handler.c
├── tokenize_line.c
├── builtins.c
└── ...

```

## 📜 Built-ins Implemented

| Command | Description                  |
|---------|------------------------------|
| `exit`  | Exit the shell               |
| `env`   | Print the environment variables |

## 🧪 Testing

You can test your shell using scripts or manual command entry.  
For example :

```javascript

echo "/bin/ls" | ./hsh
cat test_commands.txt | ./hsh

```

Where test_commands.txt contains :

```javascript

ls -l
env
exit

```

## 👥 Authors

- [@EmmanuelMOUMBOUILOU](https://github.com/QuentinC26/holbertonschool-simple_shell)

- [@QuentinC26](https://github.com/QuentinC26/holbertonschool-simple_shell)

- [@Dj-kvt](https://github.com/QuentinC26/holbertonschool-simple_shell)

## 📖 Manual

You can read the custom man page using:

```javascript
man ./man_1_simple_shell
```

## 🛠️ Future Improvements

- Handle comments with `#`
- Support for `;` separators
- Built-ins: `cd`, `help`, etc.
- Alias support
- Command history


## 🔗 Links
 ### Trello :
- https://trello.com/b/dIb9pGf9/c-simple-shell

