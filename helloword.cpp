#include <iostream>
#include <vector>
#include <bitset>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <map>
#include <random>
using namespace std;

// Over-engineered Morse code map
map<char, string> morse = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."}, {'D', "-.."},   {'E', "."},
    {'F', "..-."},  {'G', "--."},   {'H', "...."}, {'I', ".."},    {'J', ".---"},
    {'K', "-.-"},   {'L', ".-.."},  {'M', "--"},   {'N', "-."},    {'O', "---"},
    {'P', ".--."},  {'Q', "--.-"},  {'R', ".-."},  {'S', "..."},   {'T', "-"},
    {'U', "..-"},   {'V', "...-"},  {'W', ".--"},  {'X', "-..-"},  {'Y', "-.--"},
    {'Z', "--.."},  {'0', "-----"}, {'1', ".----"},{'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."},{'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {' ', "/"}
};

// Helper for leet speak
char leet(char c) {
    switch (tolower(c)) {
        case 'a': return '4';
        case 'e': return '3';
        case 'i': return '1';
        case 'o': return '0';
        case 's': return '5';
        case 't': return '7';
        default: return c;
    }
}

// Helper for ROT13
char rot13(char c) {
    if ('a' <= c && c <= 'z') return ((c - 'a' + 13) % 26) + 'a';
    if ('A' <= c && c <= 'Z') return ((c - 'A' + 13) % 26) + 'A';
    return c;
}

// Helper for Morse code
string toMorse(const string& s) {
    stringstream out;
    for (char c : s) {
        char up = toupper(c);
        if (morse.count(up)) out << morse[up] << " ";
        else out << "? ";
    }
    return out.str();
}

// Helper for palindrome check
bool isPalindrome(const string& s) {
    string filtered;
    for (char c : s) if (isalnum(c)) filtered += tolower(c);
    string rev = filtered;
    reverse(rev.begin(), rev.end());
    return filtered == rev && !filtered.empty();
}

// Helper for vowel/consonant count
pair<int, int> vowelConsonantCount(const string& s) {
    int v = 0, c = 0;
    for (char ch : s) {
        char l = tolower(ch);
        if (isalpha(l)) {
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') v++;
            else c++;
        }
    }
    return {v, c};
}

// Helper for Caesar cipher (+3)
string caesar(const string& s) {
    string out;
    for (char c : s) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            out += (c - base + 3) % 26 + base;
        } else {
            out += c;
        }
    }
    return out;
}

// Helper for random case
string randomCase(const string& s) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(0, 1);
    string out = s;
    for (char& c : out) {
        if (isalpha(c)) c = dis(gen) ? toupper(c) : tolower(c);
    }
    return out;
}

// Helper for a fake progress bar
void fakeProgressBar(const string& task, int ms = 1000) {
    cout << task << " [";
    for (int i = 0; i < 20; ++i) {
        cout << flush;
        this_thread::sleep_for(chrono::milliseconds(ms / 20));
        cout << "#";
    }
    cout << "] Done!\n";
}

int main() {
    srand(time(0));
    string input;
    cout << "Welcome to the Over-Engineered Echo Machine 9000!\n";
    cout << "Please enter something (like 'hello world'):\n";
    getline(cin, input);

    fakeProgressBar("Initializing unnecessarily complex subsystems");

    // Step 1: Break input into letters
    cout << "\nStep 1: Atomizing your input into individual letters...\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    vector<string> letters;
    for (char c : input) {
        letters.push_back(string(1, c));
    }

    // Step 2: Dramatic letter-by-letter output
    cout << "\nStep 2: Displaying each letter on its own line:\n";
    this_thread::sleep_for(chrono::milliseconds(600));
    for (const string& s : letters) {
        cout << s << endl;
        this_thread::sleep_for(chrono::milliseconds(120));
    }

    // Step 3: Reassemble the string (phew)
    cout << "\nStep 3: Reassembling the string (hope this works)...\n";
    fakeProgressBar("Recombobulating", 700);
    string rebuilt;
    for (const string& s : letters) {
        rebuilt += s;
    }

    // Step 4: Output in every format imaginable
    cout << "\nStep 4: Outputting your input in every way possible...\n";

    // ASCII codes
    cout << "\nASCII codes:\n";
    for (char c : rebuilt) {
        cout << static_cast<int>(c) << " ";
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;

    // Binary
    cout << "\nBinary representation:\n";
    for (char c : rebuilt) {
        cout << bitset<8>(c) << " ";
        this_thread::sleep_for(chrono::milliseconds(60));
    }
    cout << endl;

    // Hexadecimal
    cout << "\nHexadecimal representation:\n";
    for (char c : rebuilt) {
        cout << hex << uppercase << (int)(unsigned char)c << " ";
        this_thread::sleep_for(chrono::milliseconds(60));
    }
    cout << dec << endl;

    // Octal
    cout << "\nOctal representation:\n";
    for (char c : rebuilt) {
        cout << oct << (int)(unsigned char)c << " ";
        this_thread::sleep_for(chrono::milliseconds(60));
    }
    cout << dec << endl;

    // Reversed
    cout << "\nReversed (because why not):\n";
    string rev = rebuilt;
    reverse(rev.begin(), rev.end());
    cout << rev << endl;

    // Uppercase
    cout << "\nUppercase (LOUD):\n";
    string up = rebuilt;
    transform(up.begin(), up.end(), up.begin(), ::toupper);
    cout << up << endl;

    // Lowercase
    cout << "\nLowercase (quiet):\n";
    string low = rebuilt;
    transform(low.begin(), low.end(), low.begin(), ::tolower);
    cout << low << endl;

    // Leet Speak
    cout << "\nLeet Speak (h4x0r mode):\n";
    for (char c : rebuilt) cout << leet(c);
    cout << endl;

    // Morse Code
    cout << "\nMorse Code (beep beep):\n";
    cout << toMorse(rebuilt) << endl;

    // ROT13
    cout << "\nROT13 (secret code?):\n";
    for (char c : rebuilt) cout << rot13(c);
    cout << endl;

    // Unicode code points
    cout << "\nUnicode code points:\n";
    for (char c : rebuilt) {
        cout << "U+" << hex << uppercase << (int)(unsigned char)c << " ";
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << dec << endl;

    // Palindrome check
    cout << "\nPalindrome check: ";
    if (isPalindrome(rebuilt)) cout << "Yes! Your input is a palindrome!\n";
    else cout << "Nope, not a palindrome.\n";

    // Vowel/Consonant count
    pair<int, int> vc = vowelConsonantCount(rebuilt);
    cout << "\nVowel count: " << vc.first << ", Consonant count: " << vc.second << endl;

    // Caesar cipher
    cout << "\nCaesar Cipher (+3):\n";
    cout << caesar(rebuilt) << endl;

    // Random case
    cout << "\nRandom Case (chaos):\n";
    cout << randomCase(rebuilt) << endl;

    // Pig Latin, because why not? (Just for letters, not real words)
    cout << "\nPig Latin attempt (sorry linguists):\n";
    for (char c : rebuilt) {
        if (isalpha(c)) {
            cout << c << "ay ";
        } else {
            cout << c << " ";
        }
        this_thread::sleep_for(chrono::milliseconds(40));
    }
    cout << endl;

    // Step 5: Dramatic pause before the big reveal
    cout << "\nFinal step: Preparing to reveal your final output...\n";
    fakeProgressBar("Unwrapping", 1200);

    // The big reveal
    cout << "\nAfter all that, here's what you actually entered (sort of):\n";
    cout << ">>> " << rebuilt << " <<<\n";

    // Ask the user to verify the output
    cout << "\nPlease verify: Is this what you entered? (yes/no): ";
    string verify;
    getline(cin, verify);
    if (verify == "yes" || verify == "y" || verify == "Yes" || verify == "Y") {
        cout << "Great! The Over-Engineered Echo Machine 9000 did its job (somehow)!\n";
    } else {
        cout << "Oops! Maybe the machine is too over-engineered for its own good...\n";
    }

    cout << "\nThank you for using the Over-Engineered Echo Machine 9000!\n";
    cout << "This program will now take a nap. Zzz...\n";
    return 0;
}