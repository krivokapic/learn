from time import sleep

voted = {}

def check_voter(name):
    if name in voted:
        print(f"{name} already in")
    else:
        voted[name] = True
        print(f"let {name} vote")

def main():
    check_voter("vladimir")
    check_voter("dunja")
    check_voter("vladimir")


if __name__ == "__main__":
    main()
