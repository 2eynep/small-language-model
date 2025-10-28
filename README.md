# 🧠 Small Language Model (SLM)

Lab 5 – Your Own Small Language Model

---

## 📖 Overview

This project implements a small character-based language model (`slm`) that learns from an input text file and generates new text based on k-grams.  

It models the probability of a character appearing after a sequence of `k` previous characters, forming a simple Markov chain over characters.

---

## ⚙️ Compilation & Usage

### **1. Build**
Make sure you have `g++` and `make` installed, then run:
```bash
make
```
This produces an executable named slm.

### **2. Run**
```bash
./slm <k> <training_file> <length>
```
- **k** → the size of the k-gram (context window)

- **training_file** → text used to train the model

- **length** → number of characters to generate

From this, the example input should look like this:
```bash
./slm 3 sample_text.txt 100
```

### 📝 Note
I had a hard time doing this homework and relied heavily on AI. I understand how the algorithm should be structured and learned from the code, but the truth must be told, I couldn't and didn't write this code on my own.




