# 42-Minitalk, by Maxime Rochedy

This repository contains my implementation of **Minitalk**, a project completed during my studies at **École 42**. The objective of this project is to create a small data exchange program between a server and a client using Unix signals. This project was evaluated with a perfect score of **125/100**.

In this repository, you'll find my implementation, which has been thoroughly reviewed by 3 other students. Although I have made every effort to ensure it is error-free, feel free to report any issues or suggest improvements!

<img width="198" alt="125/100 grade" src="https://github.com/user-attachments/assets/708486c1-c045-40d6-ab0c-e5dc3650a50d">

## About the Project

The **Minitalk** project at 42 is designed to teach the basics of inter-process communication (IPC) by utilizing **signals** in Unix-based systems. Specifically, this project involves creating a server that can receive messages in the form of strings from a client, using **SIGUSR1** and **SIGUSR2** signals. My implementation includes both the **mandatory** features and additional **bonus** functionalities, such as handling Unicode characters.

This project was coded by **Maxime Rochedy**, under the login **mrochedy**, as part of the 42 curriculum. While this repository is available for **educational purposes**, please avoid copying or submitting it as your own work. Instead, use it to better understand IPC mechanisms and signal handling in C.

## Getting Started

To get started with this project, you can clone the repository and compile the server and client programs. Here's how:

```bash
git clone https://github.com/mrochedy/42-minitalk.git
cd 42-minitalk
make
```

This will generate two executable files: `server` and `client`.

### Usage

First, run the server to start listening for messages. The server will print its Process ID (PID), which you will use when running the client:

```bash
./server
```

In another terminal, use the client to send a string message to the server by providing the server's PID and the message:

```bash
./client [server_pid] "Your message here"
```

The server will receive the message character by character using signals and print it to the console.

For example, if the server's PID is `12345`, you would run:

```bash
./client 12345 "Hello, world"
```

### Bonus Features

- **Unicode Support**: The server can handle extended UTF-8 characters, allowing it to receive messages that contain non-ASCII symbols.
- **String Length Limitation**: The server can manage long strings without crashing by segmenting signal reception.
- **Signal Handling Robustness**: The client ensures that all signals are sent and received in order, with error handling for signal loss or delays.

## Contributing

If this repository was useful for your learning, please consider ⭐️ **starring** ⭐️ the project to help others find it. You are also welcome to submit pull requests with improvements, but remember not to submit this code as part of your own official 42 assignments.

Thank you for visiting, and I hope this helps you on your coding journey!
