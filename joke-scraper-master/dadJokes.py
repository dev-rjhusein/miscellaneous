import requests
from random import randint as rand
while True:
    while True:
        try: 
            userChoice = input("Let me tell you a joke! Give me a topic: ")
            if userChoice == '0':
                exit()
        except TypeError:
            print("Please enter a valid topic")
        else:
            print("Processing...")
            break

    search = requests.get("https://www.icanhazdadjoke.com/search", headers={"Accept" : "application/json"}, 
    params={"term" : userChoice})

    results = search.json()["results"]

    jokes = list()

    try:
        for i in results:
            jokes.append(i["joke"])

        maxInt = len(jokes) - 1

        jokeNum = rand(0, maxInt)

        print(jokes[jokeNum] + '\n\n')
    except:
        print(f"There were no jokes about {userChoice}.\n\n")

