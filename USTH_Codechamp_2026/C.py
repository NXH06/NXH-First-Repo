def palindrome(s: str, t: str):
    if len(s) != len(t):
        return "No"
    for i in range(len(s)):
        if s[i] != t[len(s) - 1 - i]:
            return "No"
    return "Yes"

def main():
    s = input("")
    t = input("")
    print(palindrome(s, t))
main()

