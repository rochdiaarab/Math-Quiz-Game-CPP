# Math Quiz Game CPP

A console-based Math Quiz Game built with C++ that generates random arithmetic questions with different difficulty levels and operation types while tracking the player's score.

## 🎮 Features

- Randomly generated math questions
- Multiple difficulty levels:
  - Easy
  - Medium
  - Hard
  - Mixed
- Multiple arithmetic operations:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
- Score tracking:
  - Correct answers
  - Wrong answers
- Number of questions selection
- Replay option
- Simple and clean console interface

---

## 🛠️ Technologies Used

- C++
- C++ Standard Library
- Structs
- Functions
- References
- Random Number Generation

---

## 📂 Project Structure

```
Math-Quiz-Game-CPP
│
├── MathQuizGame.cpp
└── README.md
```

---

## 🚀 How to Run

### Clone the repository

```bash
git clone https://github.com/your-username/Math-Quiz-Game-CPP.git
```

### Enter the project folder

```bash
cd Math-Quiz-Game-CPP
```

### Compile the program

```bash
g++ MathQuizGame.cpp -o MathQuiz
```

### Run the game

Linux / macOS:

```bash
./MathQuiz
```

Windows:

```bash
MathQuiz.exe
```

---

## 🎯 Gameplay

The player can choose:

1. Number of questions
2. Difficulty level:
   - Easy
   - Medium
   - Hard
   - Mixed

3. Operation type:
   - Addition
   - Subtraction
   - Multiplication
   - Division

The program generates questions randomly and checks the player's answers.

At the end, the game displays:

- Total questions
- Selected difficulty
- Selected operation
- Correct answers
- Wrong answers

---

## 📸 Example

```
How many questions do you want? 5

Question [1/5]

Choose difficulty:
Easy(1) | Mid(2) | Hard(3) | Mix(4): 1

Choose operation:
Add(1) | Sub(2) | Mul(3) | Div(4): 1

7 + 5 equals what? 12

You are right!

--------------------------------

Questions asked: 5
Difficulty level: Easy
Operation type: Addition
Correct answers: 4
Wrong answers: 1
```

---

## 🧠 Concepts Practiced

This project demonstrates:

- Variables and data types
- Functions
- Structures (`struct`)
- Passing by reference
- `const` references
- Loops
- Conditional statements
- Random number generation
- Basic game logic
- Code organization

---

## 🔮 Future Improvements

Possible improvements:

- Add a timer for each question
- Add different question categories
- Add difficulty-based scoring
- Save player scores
- Add a graphical interface
- Use modern C++ random library (`<random>`)

---

## 👨‍💻 Author

**rochdiaarab**

---

## 📄 License

This project is open source and available for educational purposes.

