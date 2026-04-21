#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid_message(const string& text) {
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

string rail_fence_encrypt(const string& plaintext, int rails) {
    if (rails <= 1 || plaintext.empty()) return plaintext;

    vector<string> fence(rails, "");
    int rail = 0;
    int direction = 1;

    for (char c : plaintext) {
        // TODO(student): Q6 can keep spaces as normal characters.
        fence[rail] += c;
        rail += direction;
        if (rail == rails - 1 || rail == 0) direction = -direction;
    }

    string ciphertext;
    for (const string& row : fence) ciphertext += row;
    return ciphertext;
}

string rail_fence_decrypt(const string& ciphertext, int rails) {
    if (rails <= 1 || ciphertext.empty()) return ciphertext;

    int n = static_cast<int>(ciphertext.size());
    // Determine the rail index for each character in the plaintext order
    vector<int> rail_index(n);
    int rail = 0;
    int direction = 1;
    for (int i = 0; i < n; ++i) {
        rail_index[i] = rail;
        rail += direction;
        if (rail == rails - 1 || rail == 0) direction = -direction;
    }

    // Count how many characters go to each rail
    vector<int> count(rails, 0);
    for (int idx : rail_index) count[idx]++;

    // Fill rails with characters from ciphertext in order
    vector<string> fence(rails);
    int pos = 0;
    for (int r = 0; r < rails; ++r) {
        fence[r] = ciphertext.substr(pos, count[r]);
        pos += count[r];
    }

    // Reconstruct plaintext by taking chars from each rail in the zig-zag order
    vector<int> take_index(rails, 0);
    string plaintext;
    plaintext.reserve(n);
    for (int i = 0; i < n; ++i) {
        int r = rail_index[i];
        plaintext += fence[r][take_index[r]++];
    }

    return plaintext;
}

string read_message_from_file(const string& path) {
    ifstream fin(path);
    string line;
    getline(fin, line);
    return line;
}

int main() {
    cout << "=== Rail Fence Cipher Demo ===\n";
    cout << "1. Encrypt\n2. Decrypt\n3. Read from file and encrypt\nChoose: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string message;
    int rails;

    if (choice == 3) {
        message = read_message_from_file("data/input.txt");
        cout << "Message from file: " << message << "\n";
    }
    else {
        cout << "Enter message: ";
        getline(cin, message);
    }

    cout << "Enter rails: ";
    cin >> rails;

    if (!is_valid_message(message)) {
        cout << "Invalid input. Only letters and spaces are allowed.\n";
        return 0;
    }

    if (choice == 1 || choice == 3) {
        cout << "Ciphertext: " << rail_fence_encrypt(message, rails) << "\n";
    }
    else if (choice == 2) {
        cout << "Plaintext: " << rail_fence_decrypt(message, rails) << "\n";
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
