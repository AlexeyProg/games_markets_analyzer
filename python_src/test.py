import sys
import requests




def main():
    print("Python script")
    if len(sys.argv) > 1:
        entered_str = sys.argv[1]
        print(f"INCOMING STRING : {entered_str}")

if __name__ == '__main__':
    main()