🧠 Overview (Short Summary)
This project reconstructs core components of machine learning from the ground up using pure C, bypassing common high-level libraries (like TensorFlow, NumPy, or even standard ML toolkits). It emphasizes full transparency, manual memory control, and algorithmic clarity, offering an educational and performance-conscious foundation for understanding and deploying ML models on bare-metal or embedded systems.

🔬 Novelty & Contributions
🧩 Pure C Implementation
No external libraries; every part (forward pass, backpropagation, loss functions, matrix math) is written manually.

Focuses on transparency, making internal computation fully visible for learning or debugging.

⚙️ Custom Lightweight Neural Network Engine
Manually manages layers, weights, and gradients.

Allows building and training feedforward neural networks on small devices or constrained systems.

📚 Educational Value
Aimed at ML learners and system-level developers who want to deeply understand ML internals.

Demonstrates what happens beneath the hood of popular frameworks.

🧠 Targeting Edge Computing
Results can be ported to microcontrollers, embedded Linux, or even custom ML chips due to minimal dependencies.

🚀 Performance & Control
Manual memory and cache-aware design opens room for precise optimization.

Enables deployment where Python/PyTorch/TensorFlow aren't viable.
# Reconstructing Machine Learning from Scratch in C

A lightweight neural network engine built from scratch in pure C for transparency, control, and embedded applications.

## Features

- Feedforward neural network (1 hidden layer)
- Matrix math from scratch
- Forward propagation
- Easy to extend to support full backpropagation

## Build & Run

```bash
make
./test_nn
