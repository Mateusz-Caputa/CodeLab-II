# Challenge 2 Task
Write a program that responds to the phrase **"Alexa, tell me a joke"** by selecting a random joke from the file provided.

## Dataset
`randomJokes.txt` file contains a dataset of random jokes.

- Each joke is on a **new line**.
- Each joke consists of a **setup** and a **punchline**, separated by a **question mark** (`?`).
- There is no space between **setup** and a **punchline**.

**Example lines from the file:**
```
Why did the chicken cross the road?To get to the other side.
What happens if you boil a clown?You get a laughing stock.
Why did the car get a flat tire?Because there was a fork in the road!
```

## Requirements
1. Respond to the prompt `Alexa, tell me a joke` by selecting a **random joke** from the file.
2. Display the **setup** first.
3. **Wait for user input** before revealing the **punchline**.
4. Allow the user to keep requesting new jokes using the specified prompt **until they choose to quit**.

## Example

```
Alexa: Waiting for commands.
Alexa: Say 'Alexa, tell me a joke' or 'quit'
You: Alexa
Alexa: Say 'Alexa, tell me a joke' or 'quit'
You: Alexa, tell me a joke
Alexa: Why is it impossible to starve in the desert?
You: No clue
Alexa: Because of all the sand which is there!
Alexa: Say 'Alexa, tell me a joke' or 'quit'
You: Alexa, tell me a joke
Alexa: Why shouldn't you tell secrets in a cornfield?
You: Too many ears.
Alexa: Oh, you know that one.
Alexa: Say 'Alexa, tell me a joke' or 'quit'
You: quit
Alexa: Bye Bye.
```

# Alexa, Tell Me a Joke

## Techniques showed in CodeLab II
- OOP
- Encapsulation
- File handling
- Non-primitive data types

## My approach to solving the problem
I divided this problem into three parts loading the dataset, selecting a random joke, and running the Alexa loop.

The jokes are managed by a Jokes class. Its constructor reads the file line by line and splits each line at the first ?, so the setup retains its question mark and the remainder becomes the punchline. Each joke is stored as a pair in a private vector. If the file cannot be opened, a line is malformed, or no jokes are found, the constructor throws an exception with a descriptive message, which is handled in main. The main loop repeatedly prompts the user for a command. When the user says "Alexa, tell me a joke", the program displays the setup, waits for input and then reveals the punchline. Entering quit ends the program.

On reflection, I placed more emphasis on object-oriented design than this task required. Since the jokes are stored within the class, no data needs to be passed between functions, so passing by reference had no practical role in this structure. However, I found this task a good introduction to Challenge 3.