#include "config.h"

/**
 * Ask the user for the player name and snake speed.
 */
void Config::AskForConfig() {
    std::cout << "Enter player name (1-4 chars): ";
    std::cin >> player_name;
    if (player_name.size() > 4) {
        std::cout << "Invalid player name. Setting to default value of ??\n";
        player_name = "??";
    }
    std::cout << "Enter snake speed (1-3): ";
    std::cin >> snake_speed;
    if (snake_speed < 1 || snake_speed > 3) {
        std::cout << "Invalid snake speed. Setting to default value of 1\n";
        snake_speed = 1;
    }
}

/**
 * Print the scores of all players if there are any.
 */
void Config::PrintScores() const {
    if (scores.empty())
        return;

    std::cout << "Scores:\n";
    for (const auto &pair : scores) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
    std::cout << std::endl;
}

/**
 * Get the highest score of the player.
 */
int Config::GetHighestScore() const {
    if (scores.find(player_name) != scores.end()) {
        return scores.at(player_name);
    }
    return 0;
}

/**
 * Set the highest score of the player.
 */
void Config::SetHighestScore(int score) {
    if (score > GetHighestScore()) {
        scores[player_name] = score;
    }
}

/**
 * Save the scores to a file.
 */
void Config::SaveToFile(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for writing");
    }

    std::ostringstream oss;
    for (const auto &pair : scores) {
        oss << pair.first << '\n' << pair.second << '\n';
    }
    std::string data = oss.str();
    std::string encrypted_data = EncryptDecrypt(data);
    file.write(encrypted_data.c_str(), encrypted_data.size());
    file.close();
}

/**
 * Load the scores from a file.
 */
void Config::LoadFromFile(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        SaveToFile(filename);
        return;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::string encrypted_data(buffer.begin(), buffer.end());
    std::string data = EncryptDecrypt(encrypted_data);

    std::istringstream iss(data);
    std::string name;
    int score;
    while (std::getline(iss, name) && iss >> score) {
        scores[name] = score;
        iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    file.close();
}

/**
 * Encrypt or decrypt the data using a simple XOR operation.
 */
std::string Config::EncryptDecrypt(const std::string &data) {
    constexpr char key = 'K'; // Simple XOR key for encryption/decryption
    std::string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key;
    }
    return result;
}
